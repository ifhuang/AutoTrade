#include "Strategy.h"

long Strategy::createOrder(char buysell, char openclose, double submitPrice, double qty, int orderType, int validType, int submitter)
{
	return 0;
}

// 分解订单
int Strategy::decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi)
{
	if(poi->getOrderType() == MKT)
	{
		//double minqty = tradeUnit->getQuote()->getMinContractQty(); why double???
		int minqty = tradeUnit->getQuote()->getMinContractQty(); 
		PriceItem* prc = tradeUnit->getPrice();		
		
		LogHandler::getLogHandler().log("Order decomposed by default");
		//poi->log();
		prc->log();
		// 分解成最小单位成交
		for(int i = minqty; i <=poi->getQty(); i+=minqty)
		{
			OrderItem* oiu = new OrderItem(*poi);
			oiu->setQty(minqty);
			oiu->setOrderRefId(ascOrderRefId++);
			oiu->setStatus(ADDING);
			oiu->setAction(ADD_ACTION);					
			
			if(poi->getBuySell()==BUY)
			{
				oiu->setOriginalPrice(prc->askPrice1);
				if(i<=prc->askQty1)
					oiu->setSubmitPrice(prc->askPrice1);
				else if(i<=prc->askQty1+prc->askQty2)
					oiu->setSubmitPrice(prc->askPrice2);
				else if(i<=prc->askQty1+prc->askQty2+prc->askQty3)
					oiu->setSubmitPrice(prc->askPrice3);
				else if(i<=prc->askQty1+prc->askQty2+prc->askQty3+prc->askQty4)
					oiu->setSubmitPrice(prc->askPrice4);
				else if(i<=prc->askQty1+prc->askQty2+prc->askQty3+prc->askQty4+prc->askQty5)
					oiu->setSubmitPrice(prc->askPrice5);
				else
					oiu->setSubmitPrice(prc->askPrice5+tradeUnit->getQuote()->getPriceScale());
			}
			else if(poi->getBuySell()==SELL)
			{
				oiu->setOriginalPrice(prc->bidPrice1);
				if(i<=prc->bidQty1)
					oiu->setSubmitPrice(prc->bidPrice1);
				else if(i<=prc->bidQty1+prc->bidQty2)
					oiu->setSubmitPrice(prc->bidPrice2);
				else if(i<=prc->bidQty1+prc->bidQty2+prc->bidQty3)
					oiu->setSubmitPrice(prc->bidPrice3);
				else if(i<=prc->bidQty1+prc->bidQty2+prc->bidQty3+prc->bidQty4)
					oiu->setSubmitPrice(prc->bidPrice4);
				else if(i<=prc->bidQty1+prc->bidQty2+prc->bidQty3+prc->bidQty4+prc->bidQty5)
					oiu->setSubmitPrice(prc->bidPrice5);
				else
					oiu->setSubmitPrice(prc->bidPrice5-tradeUnit->getQuote()->getPriceScale());
			}
			tradeUnit->addOrder(oiu);

			if(dispatcher->sendOrder(oiu)==MY_ERROR)
				return MY_ERROR;
		}
		return SUCCESS;
	}
	else {
		LogHandler::getLogHandler().alert(3, "Symstem error", "Current version support only for optimize MKT order flow");
		return MY_ERROR;
	}
}

// added by xie
int Strategy::decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi)
{
	if (tradeUnit == NULL || poi->getOrderType() != MKT || tradeUnit->getStepQty() <= 0) {
		LogHandler::getLogHandler().alert(1, "Order decomposition", "Order decomposition failed");
		return MY_ERROR;
	}

	double minqty = tradeUnit->getQuote()->getMinContractQty(); 
	PriceItem* prc = tradeUnit->getPrice();	
	double qty = 1, price = 0;
	if(poi->getBuySell()==BUY) {
		price = prc->askPrice1;
	}
	else if(poi->getBuySell()==SELL) {
		price = prc->bidPrice1;
	}
	double stepTickNum = 0;
	if (tradeUnit->getStepTickNum() > 0) {
		stepTickNum = tradeUnit->getStepTickNum();
	} else if (tradeUnit->getStepMoney() > 0) {

		// 这些值是什么？ bigPointValue 好像还没设
		stepTickNum = tradeUnit->getStepMoney() / (tradeUnit->getQuote()->getBigPointValue() * tradeUnit->getQuote()->getPriceScale());
	} else {
		LogHandler::getLogHandler().alert(1, "Order decomposition", "Order decomposition failed, step not set!");
		return MY_ERROR;
	}
	for(int i = minqty; i <= poi->getQty(); i += minqty, qty += minqty) {	
		OrderItem* oiu = new OrderItem(*poi);
		oiu->setQty(minqty);
		oiu->setOrderRefId(ascOrderRefId++);
		oiu->setStatus(ADDING);
		oiu->setAction(ADD_ACTION);
		if (qty > tradeUnit->getStepQty()) {
			qty = 1;
			if(poi->getBuySell()==BUY) {
				price -= stepTickNum;
			} else if(poi->getBuySell()==SELL) {
				price += stepTickNum;
			}
			LogHandler::getLogHandler().log("price changed by step");
		}
		oiu->setOriginalPrice(price);
		oiu->setSubmitPrice(price);
			
		tradeUnit->addOrder(oiu);
		if(dispatcher->sendOrder(oiu)==MY_ERROR) {
			LogHandler::getLogHandler().alert(1, "Order decomposition", "Send decomposed order failed!");
			return MY_ERROR;
		}
	}
}

int Strategy::decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi)
{
	//return decomposeOrderByStep(tradeUnit, poi);
	return decomposeOrderByDefault(tradeUnit, poi);
}

DWORD Strategy::startTraderThread()
{
     hTraderThread = CreateThread(NULL, 0, traderThreadAdapter, this, 0, &TraderThreadId);
	return TraderThreadId;

}

DWORD Strategy::startSignalThread()
{
      hSignalThread = CreateThread(NULL, 0, signalThreadAdapter, this, 0, &signalThreadId);
	return signalThreadId;
}

DWORD WINAPI Strategy::traderThreadAdapter(LPVOID lpParam)
{
	Strategy* pct = (Strategy*)lpParam;
	pct->process();
	return 0; 
}

DWORD WINAPI Strategy::signalThreadAdapter(LPVOID lpParam)
{
	Strategy* pct = (Strategy*)lpParam;
	
	pct->executeStrategy();
	return 0; 
}

void Strategy::turnOnStrategy()
{
	setAutoTrading(true);

	//这里要先检查是否已经接收或者读历史数据文件中读取了足够的数据，如果数据不足，则不能开启策略交易
	// added by xie
	if(!getIntraBarTrading()) {		
		if (!isBarsEnough()) {
			LogHandler::getLogHandler().alert(3, "Strategy Start", "Not enough bars!");
			return;
		}
	}
	startSignalThread();
}

// added by xie
void Strategy::process()
{
	// 启动定时器，定时更新k线，暂定为1秒钟更新一次
	int updateBarTimeID = SetTimer(NULL, UPDATE_BAR_TIMER_ID, 1000, NULL);
	MSG msg;
	// 这里改一下，以便获取WM_TIMER by xie
	while(GetMessage(&msg, NULL, 0, 0)) {
		switch(msg.message) {
			case ORDER_ACCEPT_MSG: processOrderAccepted(msg); break;
			case TRADE_DONE_MSG: processTradeDone(msg); break;
			case PRICE_MSG: processPrice(msg); break;
			case TICK_PRICE: processTickPrice(msg); break;
			case LOSE_CONN_MSG: turnOffStrategy(); LogHandler::getLogHandler().log("strategy is off"); break;
			case WM_TIMER:
				// 更新k线，但是用计数器可能会错过最高价和最低价。by xie
				if (msg.wParam  == updateBarTimeID) {
					updateBars();
				}
				break;
		}
	}
}