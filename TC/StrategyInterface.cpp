#include "StrategyInterface.h"
#define UI_DEBUG

StrategyInterface::StrategyInterface(int traderId, int optimizeOrderFlow
    , Dispatcher *disp) : dispatcher_(disp)
{
    this->ascOrderRefId = 1;
    this->traderId = traderId;
    this->optimizeOrderFlow = optimizeOrderFlow;
}

StrategyInterface::~StrategyInterface(void)
{
}

void StrategyInterface::setOptimizeOrderFlow(int pattern)
{
    this->optimizeOrderFlow = pattern;
}

void StrategyInterface::buy(double submitPrice, double qty, int orderType, int validType)
{
	createOrder(BUY, OPEN, submitPrice, qty, orderType, validType, STRATEGY_SUBMITTER);
}

void StrategyInterface::sell(double submitPrice, double qty, int orderType, int validType)
{
	createOrder(SELL, CLOSE, submitPrice, qty, orderType, validType, STRATEGY_SUBMITTER);
}

void StrategyInterface::buytocover(double submitPrice, double qty, int orderType, int validType)
{
	createOrder(BUY,CLOSE, submitPrice, qty, orderType, validType, STRATEGY_SUBMITTER);
}

void StrategyInterface::sellshort(double submitPrice, double qty, int orderType, int validType)
{
	createOrder(SELL, OPEN, submitPrice, qty, orderType, validType, STRATEGY_SUBMITTER);
}

void StrategyInterface::setTradeUnit(TradeUnit* tradeUnit)
{
    this->tradeUnit = tradeUnit;
}

Bar* StrategyInterface::getBar(int position)
{
    if (tradeUnit != NULL) {
        return tradeUnit->getBar(position);
    }
    else {
        return NULL;
    }
}

long StrategyInterface::createOrder(OrderItem* oi)
{
	return createOrder(oi->getBuySell(), oi->getOpenClose(), oi->getSubmitPrice(), 
		oi->getQty(), oi->getOrderType(), oi->getValidType(), oi->getSubmitter());
}

long StrategyInterface::createOrder(char buysell, string openclose, double submitPrice,
    double qty, int orderType, int validType, int submitter)
{
    int minqty = tradeUnit->getQuote()->getMinContractQty();

    OrderItem* oi = new OrderItem(tradeUnit->getQuoteId(), submitPrice, qty,
        buysell, orderType, validType, openclose);
    oi->setOrderRefId(ascOrderRefId++);
    oi->setSubmitter(submitter);
    oi->setStatus(ADDING);
    oi->setTraderId(traderId);
    if (orderType == MKT) // Market order
    {
        if (buysell == BUY)
            oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
        else if (buysell == SELL)
            oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);

        // decompose large order into small ones to decrease impact cost
        if (optimizeOrderFlow == OPTIMIZE_OFP && qty > tradeUnit->getQuote()->getMinContractQty())
        {
            tradeUnit->addOrder(oi);
            decomposeOrder(tradeUnit, oi);
        }
        else
        {
            oi->setAction(ADD_ACTION);
            tradeUnit->addOrder(oi);
            dispatcher_->sendOrder(oi);
        }
    }
    else if (orderType != MKT)
    {
        if (dispatcher_->isSupport(orderType)) //Limit order
        {
            oi->setAction(ADD_ACTION);
            oi->setStatus(ADDING);
            tradeUnit->addOrder(oi);
            dispatcher_->sendOrder(oi);

        }
        else
        {
            oi->setAction(WAITING);
            oi->setStatus(WAITING);
            tradeUnit->addOrder(oi);
        }
    }

#ifdef UI_DEBUG
    iMainWindow->displaySwingAddWorkingOrders(oi);
#endif

    return oi->getOrderRefId();
}

long StrategyInterface::updateOrder(OrderItem* oi)
{
	return updateOrder(oi->getOrderRefId(), oi->getBuySell(), 
		oi->getOpenClose(), oi->getSubmitPrice(), oi->getQty(), oi->getValidType());
}

long StrategyInterface::updateOrder(long orderRefId, char buysell, string openclose,
    double submitPrice, double qty, int validType)
{
    OrderItem* oi = tradeUnit->getOrder(orderRefId);
    oi->addCounter();
    if (oi != NULL)
    {
        if (dispatcher_->isSupport(oi->getOrderType()))
        {
            oi->setValidType(validType);
            oi->setBuySell(buysell);
            oi->setQty(qty);
            oi->setOpenClose(openclose);
            if (oi->getOrderType() != MKT)
            {
                oi->setStatus(CHANGING);
                oi->setAction(CHG_ACTION);
                oi->setSubmitPrice(submitPrice);
                dispatcher_->sendOrder(oi); // transimit order 
            }
        }
        else if (!dispatcher_->isSupport(oi->getOrderType()))// tradeplatform don't support new ordertype
        {
            if (oi->getOrderType() == MKT && oi->getParentRefId() != 0)
            {
                oi->setBuySell(buysell);
                oi->setQty(qty);
                oi->setOpenClose(openclose);
                oi->setStatus(CHANGING);
                oi->setAction(CHG_ACTION);
                if (buysell == BUY)
                    oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
                else if (buysell == SELL)
                    oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);
                dispatcher_->sendOrder(oi); // transimit order 
            }  // tradeplatform don't support original ordertype				
            else
            {
                oi->setValidType(validType);
                oi->setBuySell(buysell);
                oi->setQty(qty);
                oi->setOpenClose(openclose);
                oi->setSubmitPrice(submitPrice);
            }
        }
    }

#ifdef UI_DEBUG
    iMainWindow->displaySwingUpdateWorkingOrders(orderRefId, oi);
#endif

    return orderRefId;
}

int StrategyInterface::deleteOrder(long orderRefId)
{
    OrderItem* oi = tradeUnit->getOrder(orderRefId);
    if (oi != NULL) {
        if (dispatcher_->isSupport(oi->getOrderType())) {
            oi->setAction(DEL_ACTION);
            oi->setStatus(DELETING);
            dispatcher_->sendOrder(oi);
        }
        else {
            tradeUnit->deleteOrder(orderRefId);
        }
        return SUCCESS;
    }
    else {
        return MY_ERROR;
    }

#ifdef UI_DEBUG
    iMainWindow->displaySwingRemoveWorkingOrders(orderRefId);
#endif

}

// 分解订单
int StrategyInterface::decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi)
{
    if (poi->getOrderType() == MKT)
    {
        //double minqty = tradeUnit->getQuote()->getMinContractQty(); why double???
        int minqty = tradeUnit->getQuote()->getMinContractQty();
        PriceItem* prc = tradeUnit->getPrice();

        LogHandler::getLogHandler().log("Order decomposed by default");
        //poi->log();
        prc->log();
        // 分解成最小单位成交
        for (int i = minqty; i <= poi->getQty(); i += minqty)
        {
            OrderItem* oiu = new OrderItem(*poi);
            oiu->setQty(minqty);
            oiu->setOrderRefId(ascOrderRefId++);
            oiu->setStatus(ADDING);
            oiu->setAction(ADD_ACTION);

            if (poi->getBuySell() == BUY)
            {
                oiu->setOriginalPrice(prc->askPrice1);
                if (i <= prc->askQty1)
                    oiu->setSubmitPrice(prc->askPrice1);
                else if (i <= prc->askQty1 + prc->askQty2)
                    oiu->setSubmitPrice(prc->askPrice2);
                else if (i <= prc->askQty1 + prc->askQty2 + prc->askQty3)
                    oiu->setSubmitPrice(prc->askPrice3);
                else if (i <= prc->askQty1 + prc->askQty2 + prc->askQty3 + prc->askQty4)
                    oiu->setSubmitPrice(prc->askPrice4);
                else if (i <= prc->askQty1 + prc->askQty2 + prc->askQty3 + prc->askQty4 + prc->askQty5)
                    oiu->setSubmitPrice(prc->askPrice5);
                else
                    oiu->setSubmitPrice(prc->askPrice5 + tradeUnit->getQuote()->getPriceScale());
            }
            else if (poi->getBuySell() == SELL)
            {
                oiu->setOriginalPrice(prc->bidPrice1);
                if (i <= prc->bidQty1)
                    oiu->setSubmitPrice(prc->bidPrice1);
                else if (i <= prc->bidQty1 + prc->bidQty2)
                    oiu->setSubmitPrice(prc->bidPrice2);
                else if (i <= prc->bidQty1 + prc->bidQty2 + prc->bidQty3)
                    oiu->setSubmitPrice(prc->bidPrice3);
                else if (i <= prc->bidQty1 + prc->bidQty2 + prc->bidQty3 + prc->bidQty4)
                    oiu->setSubmitPrice(prc->bidPrice4);
                else if (i <= prc->bidQty1 + prc->bidQty2 + prc->bidQty3 + prc->bidQty4 + prc->bidQty5)
                    oiu->setSubmitPrice(prc->bidPrice5);
                else
                    oiu->setSubmitPrice(prc->bidPrice5 - tradeUnit->getQuote()->getPriceScale());
            }
            tradeUnit->addOrder(oiu);

            if (dispatcher_->sendOrder(oiu) == MY_ERROR)
                return MY_ERROR;
        }
        return SUCCESS;
    }
    else {
        LogHandler::getLogHandler().alert(3, "Symstem error",
            "Current version support only for optimize MKT order flow");
        return MY_ERROR;
    }
}

// added by xie
int StrategyInterface::decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi)
{
    if (tradeUnit == NULL || poi->getOrderType() != MKT || tradeUnit->getStepQty() <= 0) {
        LogHandler::getLogHandler().alert(1, "Order decomposition", "Order decomposition failed");
        return MY_ERROR;
    }

    double minqty = tradeUnit->getQuote()->getMinContractQty();
    PriceItem* prc = tradeUnit->getPrice();
    double qty = 1, price = 0;
    if (poi->getBuySell() == BUY) {
        price = prc->askPrice1;
    }
    else if (poi->getBuySell() == SELL) {
        price = prc->bidPrice1;
    }
    double stepTickNum = 0;
    if (tradeUnit->getStepTickNum() > 0) {
        stepTickNum = tradeUnit->getStepTickNum();
    }
    else if (tradeUnit->getStepMoney() > 0) {

        // 这些值是什么？ bigPointValue 好像还没设
        stepTickNum = tradeUnit->getStepMoney() / (tradeUnit->getQuote()->getBigPointValue()
            * tradeUnit->getQuote()->getPriceScale());
    }
    else {
        LogHandler::getLogHandler().alert(1, "Order decomposition",
            "Order decomposition failed, step not set!");
        return MY_ERROR;
    }
    for (int i = minqty; i <= poi->getQty(); i += minqty, qty += minqty) {
        OrderItem* oiu = new OrderItem(*poi);
        oiu->setQty(minqty);
        oiu->setOrderRefId(ascOrderRefId++);
        oiu->setStatus(ADDING);
        oiu->setAction(ADD_ACTION);
        if (qty > tradeUnit->getStepQty()) {
            qty = 1;
            if (poi->getBuySell() == BUY) {
                price -= stepTickNum;
            }
            else if (poi->getBuySell() == SELL) {
                price += stepTickNum;
            }
            LogHandler::getLogHandler().log("price changed by step");
        }
        oiu->setOriginalPrice(price);
        oiu->setSubmitPrice(price);

        tradeUnit->addOrder(oiu);
        if (dispatcher_->sendOrder(oiu) == MY_ERROR) {
            LogHandler::getLogHandler().alert(1, "Order decomposition", "Send decomposed order failed!");
            return MY_ERROR;
        }
    }
}

int StrategyInterface::decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi)
{
    //return decomposeOrderByStep(tradeUnit, poi);
    return decomposeOrderByDefault(tradeUnit, poi);
}