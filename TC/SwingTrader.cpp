#include "SwingTrader.h"

#define UI_DEBUG

SwingTrader::SwingTrader(int traderId, ISwingTradeDialog* iSwingTradeDialog, IMainWindow* iMainWindow):Strategy(traderId)
{
	this->iSwingTradeDialog = iSwingTradeDialog;
    this->iMainWindow = iMainWindow;
	tradeUnit = NULL;
	testOrderID = 0;
}

void SwingTrader::processTickPrice(MSG& msg) {
	PriceItem* pi = (PriceItem*)msg.lParam;	
	//LogHandler::getLogHandler().log("Tick price");
	//pi->log();
	if (tradeUnit != NULL) { 
		tradeUnit->updateTickPrice(pi);
	}
}

void SwingTrader::updateBars() {
	if (tradeUnit != NULL) { 
		tradeUnit->updateBars();
		//LogHandler::getLogHandler().log("timer update bar(" + tradeUnit->getQuote()->getQuoteId() + ")");
	}
}
void SwingTrader::processOrderAccepted(MSG& msg) {
	OrderItem* new_oi = (OrderItem*)msg.lParam;
	OrderItem* ori_oi = tradeUnit->getOrder(new_oi->getOrderRefId());
	// 为什么是在队列中查找？
	if(ori_oi != NULL)
	{
		ori_oi->setOrderNo(new_oi->getOrderNo());
		ori_oi->setReturnCode(new_oi->getReturnCode());
		ori_oi->setReturnMessage(new_oi->getReturnMessage());
		ori_oi->setStatus(new_oi->getStatus());
	}
	else
	{
		LogHandler::getLogHandler().alert(3, "Process ORDER_ACCEPT_MSG error", "Returned Order from server is not found in local order queues");
	}		
	delete new_oi;
}

void SwingTrader::processTradeDone(MSG& msg) {
	TradeItem* ti = (TradeItem*)msg.lParam;

	// added by xie
	doneTradeIDs[ti->getOrderNo()] = ti->getOrderNo();

	if(tradeUnit != NULL)
	{
		OrderItem* oi = tradeUnit->getOrder(ti->getOrderRefId());
		if(oi != NULL)
		{
			LogHandler::getLogHandler().log("Trade done");
			oi->log();
			if(ti->getStatus()!=DELETED)
			{							
				Position* cpos = tradeUnit->getPosition(0);
				if(cpos != NULL)
				{
					if(cpos->getSize()==0 && ti->getPositionSize()!=0) //  open a position
					{
						Position* pos = new Position();
						pos->setQuoteId(ti->getQuoteId());
						pos->setSize(ti->getPositionSize());
						pos->setLongShort(ti->getPositionSize()>0?1:-1);
						pos->setTradePlatform(ti->getTradePlatform());
						pos->getTradeList().push_front(ti);
						tradeUnit->addPosition(pos);
					}
					else if(cpos->getSize() > 0)  // current position is long
					{
						if(ti->getPositionSize() > cpos->getSize())  // add long position size
						{
							cpos->setSize(ti->getPositionSize());
							cpos->getTradeList().push_front(ti);
						}
						else if(ti->getPositionSize() < cpos->getSize() && ti->getPositionSize()>=0) // close some long position
						{
							cpos->setSize(ti->getPositionSize());
							cpos->getTradeList().push_front(ti);
						}
						else if(ti->getPositionSize()<0) // reverse position
						{
							Position* pos = new Position();
							pos->setQuoteId(ti->getQuoteId());
							pos->setSize(ti->getPositionSize());
							pos->setLongShort(ti->getPositionSize()>0?1:-1);
							pos->setTradePlatform(ti->getTradePlatform());
							pos->getTradeList().push_front(ti);
							tradeUnit->addPosition(pos);
						}
					}
					else if(cpos->getSize() < 0)
					{
						if(ti->getPositionSize() < cpos->getSize())
						{
							cpos->setSize(ti->getPositionSize());
							cpos->getTradeList().push_front(ti);
						}
						else if(ti->getPositionSize() > cpos->getSize() && ti->getPositionSize()<=0)
						{
							cpos->setSize(ti->getPositionSize());
							cpos->getTradeList().push_front(ti);
						}
						else if(ti->getPositionSize()>0)
						{
							Position* pos = new Position();
							pos->setQuoteId(ti->getQuoteId());
							pos->setSize(ti->getPositionSize());
							pos->setLongShort(ti->getBuySell()==BUY?1:-1);
							pos->setTradePlatform(ti->getTradePlatform());
							pos->getTradeList().push_front(ti);
							tradeUnit->addPosition(pos);
						}
					}
				}
				else
				{
					Position* pos = new Position();
					pos->setQuoteId(ti->getQuoteId());
					pos->setSize(ti->getPositionSize());
					pos->setLongShort(ti->getBuySell()==BUY?1:-1);
					pos->setTradePlatform(ti->getTradePlatform());
					pos->getTradeList().push_front(ti);
					tradeUnit->addPosition(pos);
				}
				tradeUnit->addTrade(ti);
			}
						
						

			if(optimizeOrderFlow==OPTIMIZE_OFP && oi->getParentRefId() != 0)
			{
				OrderItem* parent_oi = tradeUnit->getOrder(oi->getParentRefId());
				if(parent_oi != NULL)
				{
					parent_oi->addTradedQty(ti->getQty());
					if(parent_oi->getTradedQty() == parent_oi->getQty())		
					{
						tradeUnit->deleteOrder(parent_oi->getOrderRefId());
						parent_oi->setStatus(ALLTRADED);
					}
					else
						parent_oi->setStatus(PARTIALTRADED);
				}
			}
			else if(optimizeOrderFlow==NO_OPTIMIZE_OFP && oi->getParentRefId() == 0)
			{
				oi->addTradedQty(ti->getQty());
				if(oi->getTradedQty()==oi->getQty())
				{
					oi->setStatus(ALLTRADED);
					tradeUnit->deleteOrder(oi->getOrderRefId());
				}
				else
					oi->setStatus(PARTIALTRADED);
			}
		}
		else
		{
			LogHandler::getLogHandler().alert(3, "Process TRADE_DONE_MSG error", "Done trade is not found in local order queues");
		}
	}
}

void SwingTrader::processPrice(MSG& msg) {
	PriceItem* pi = (PriceItem*)msg.lParam;			
	if(tradeUnit != NULL) {
		tradeUnit->updatePrice(pi);						
		triggerWaitingOrder();
		PostThreadMessage(signalThreadId,PRICE_MSG,0,0);
	} else {
		LogHandler::getLogHandler().alert(3, "Price Message", "Trade Unit is not found for price message");
	}

#ifdef UI_DEBUG
	iSwingTradeDialog->displayPriceItem(pi);
#endif

}

void SwingTrader::signal() {
	//LogHandler::getLogHandler().log("signal");
	/*double price = 0;
	if (tradeUnit != NULL) {
		price = tradeUnit->getPrice()->lastPrice1;
	}
	if (price > 3225) {
		//buy(testOrderID, price, 3, MKT, DAY, STRATEGY_SUBMITTER);
		sell(testOrderID, price, 1, MKT, DAY, STRATEGY_SUBMITTER);
	} */
	/*Position pos;
	pos.accountNo = dispatcher->getPlatformInfo().accountNo;
	pos.setQuoteId(tradeUnit->getQuoteId());
	dispatcher->getPosition(pos);
	pos.log();*/
	/*map<int, TradeItem*>& donelist = dispatcher->getDoneTrades();
	LogHandler::getLogHandler().log("done list:");
	for (map<int, TradeItem*>::iterator it = donelist.begin(); it != donelist.end(); it++) {
		it->second->log();
	}*/
	/*map<int, OrderItem*>& orderlist = dispatcher->getCurrentOrders();
	for (map<int, OrderItem*>::iterator it = orderlist.begin(); it != orderlist.end(); it++) {
		it->second->log();
	}*/
	closeAllPositions();
	//LogHandler::getLogHandler().log("signal:" + tradeUnit->getQuoteId());
}

int SwingTrader::deleteOrder(long orderRefId)
{
	OrderItem* oi = tradeUnit->getOrder(orderRefId);
	if(oi != NULL)
	{
		if(dispatcher->isSupport(oi->getOrderType()))
		{
			oi->setAction(DEL_ACTION);
			oi->setStatus(DELETING);
			dispatcher->sendOrder(oi);
		}
		else
		{
			tradeUnit->deleteOrder(orderRefId);
		}
	}
	return SUCCESS;
}

int SwingTrader::setTradeUnit(TradeUnit* tradeUnit)
{
	int flag = -1;

	if(dispatcher!=NULL && dispatcher->addQuote(tradeUnit->getQuote()))
	{
		this->tradeUnit = tradeUnit;
		flag = 0;
	}
	return flag;
}

int SwingTrader::deleteTradeUnit()
{
	/** Clear all order and save trade record before delete the quote**/
	dispatcher->deleteQuote(tradeUnit->getQuote());
	delete tradeUnit;
	tradeUnit = NULL;
	return 0;
}


long SwingTrader::createOrder(char buysell, char openclose, double submitPrice, double qty, int orderType, int validType, int submitter)
{	
	int minqty = tradeUnit->getQuote()->getMinContractQty();
	if(!double_divide(qty, minqty))
	{
		LogHandler::getLogHandler().alert(3, "Create Order Error", "The quantity is not the integer multiples of the unit contract");
		return MY_ERROR;
	}

	OrderItem* oi = new OrderItem(tradeUnit->getQuote()->getTradePlatform(), tradeUnit->getQuoteId(), submitPrice, qty, buysell, orderType, validType, openclose);
	oi->setOrderRefId(ascOrderRefId++);
	oi->setSubmitter(submitter);
	oi->setStatus(ADDING);
	oi->setTraderId(traderId);
	if(orderType == MKT) // Market order
	{						
		if(buysell==BUY)
			oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
		else if(buysell==SELL)
			oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);

		// decompose large order into small ones to decrease impact cost
		if(optimizeOrderFlow==OPTIMIZE_OFP && qty>tradeUnit->getQuote()->getMinContractQty())
		{
			tradeUnit->addOrder(oi);
			decomposeOrder(tradeUnit, oi);
		}
		else
		{
			oi->setAction(ADD_ACTION);
			tradeUnit->addOrder(oi);
			dispatcher->sendOrder(oi);
		}
	}
	else if(orderType != MKT ) 
	{		
		if(dispatcher->isSupport(orderType)) //Limit order
		{
			oi->setAction(ADD_ACTION);
			oi->setStatus(ADDING);
			tradeUnit->addOrder(oi);
			dispatcher->sendOrder(oi);

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


long SwingTrader::updateOrder( long orderRefId, char buysell, char openclose, double submitPrice, double qty, int validType)
{
	OrderItem* oi = tradeUnit->getOrder(orderRefId);
	oi->addCounter();
	int tradePlatform = tradeUnit->getTradePlatform();
	if(oi != NULL)
	{
		if(dispatcher->isSupport(oi->getOrderType()))
		{				
			oi->setValidType(validType);
			oi->setBuySell(buysell);
			oi->setQty(qty);
			oi->setOpenClose(openclose);
			if(oi->getOrderType() != MKT)
			{
				oi->setStatus(CHANGING);
				oi->setAction(CHG_ACTION);
				oi->setSubmitPrice(submitPrice);
				dispatcher->sendOrder(oi); // transimit order 
			}

		}
		else if(!dispatcher->isSupport(oi->getOrderType()))// tradeplatform don't support new ordertype
		{
			if(oi->getOrderType() == MKT && oi->getParentRefId()!=0)
			{				
				oi->setBuySell(buysell);
				oi->setQty(qty);
				oi->setOpenClose(openclose);
				oi->setStatus(CHANGING);
				oi->setAction(CHG_ACTION);
				if(buysell==BUY)
					oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
				else if(buysell==SELL)
					oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);
				dispatcher->sendOrder(oi); // transimit order 
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
	return orderRefId;
}

void SwingTrader::deleteStrategyOrder()
{
	map<long,OrderItem*>::iterator iter;
	for(iter=tradeUnit->getOrderQueue().begin(); iter != tradeUnit->getOrderQueue().end(); iter++)
	{
		OrderItem* oi = iter->second;
		/* if order's counter is not equal to strategy's counter, indicating this order is not update at the last round execute */
		// ? 不理解这个counter的具体含义
		if(oi->getOrderType() != MKT && oi->getCounter() != getCounter()) 
		{
			deleteOrder(oi->getOrderRefId());
		}		
	}
}

long SwingTrader::buy(long& orderRefId, double submitPrice, double qty, int orderType, int validType, int submitter)
{
	if(orderRefId == 0)
		return createOrder(BUY, OPEN, submitPrice, qty, orderType, validType, submitter);
	else
		return updateOrder(orderRefId,BUY, OPEN, submitPrice, qty, validType);
}

long SwingTrader::sellshort(long& orderRefId, double submitPrice, double qty, int orderType, int validType, int submitter)
{
	if(orderRefId == 0)
		return createOrder(SELL, OPEN, submitPrice, qty, orderType, validType, submitter);
	else
		return updateOrder(orderRefId,SELL, OPEN, submitPrice, qty, validType);
}

long SwingTrader::sell(long& orderRefId, double submitPrice, double qty, int orderType, int validType, int submitter)
{
	if(orderRefId == 0 )
		return createOrder(SELL, CLOSE, submitPrice, qty, orderType, validType, submitter);
	else
		return updateOrder(orderRefId, SELL,CLOSE, submitPrice, qty, validType);
}

long SwingTrader::buytocover(long& orderRefId, double submitPrice, double qty, int orderType, int validType, int submitter)
{
	if(orderRefId == 0 )
		return createOrder(BUY,CLOSE, submitPrice, qty, orderType, validType, submitter);
	else
		return updateOrder(orderRefId, BUY,CLOSE, submitPrice, qty, validType);
}

double SwingTrader::marketposition(int pos_ago)
{
	Position* pos = tradeUnit->getPosition(pos_ago);
	if(pos != NULL)
	{
		if(pos_ago == 0)
			return pos->getSize();
		else
			return pos->getLongShort();
	
	}
	else
		return 0;
}

SwingTrader::~SwingTrader()
{
}

// 追价
void SwingTrader::triggerWaitingOrder()
{
	map<long,OrderItem*>::iterator iter;
	for(iter=tradeUnit->getOrderQueue().begin(); iter != tradeUnit->getOrderQueue().end(); iter++)
	{
		OrderItem* oi = iter->second;
		if(!dispatcher->isSupport(oi->getOrderType()))
		{
			if(oi->getOrderType() == MKT && oi->getParentRefId() != 0)
			{

				if((oi->getBuySell()==BUY && oi->getSubmitPrice()<tradeUnit->getPrice()->lastPrice1) ||
					(oi->getBuySell()==SELL && oi->getSubmitPrice()>tradeUnit->getPrice()->lastPrice1))
				{
					oi->setStatus(CHANGING);
					oi->setAction(CHG_ACTION);
					if(oi->getBuySell()==BUY)
						oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
					else if(oi->getBuySell()==SELL)
						oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);
					dispatcher->sendOrder(oi);
				}
			}
			else if(oi->getOrderType() == STP || oi->getOrderType()==MIT)
			{
				if((oi->getBuySell()==BUY && oi->getSubmitPrice()>=tradeUnit->getPrice()->lastPrice1) ||
					(oi->getBuySell()==SELL && oi->getSubmitPrice()<=tradeUnit->getPrice()->lastPrice1))
				{
					if(optimizeOrderFlow==OPTIMIZE_OFP && oi->getQty()>tradeUnit->getQuote()->getMinContractQty())
					{
						oi->setStatus(ADDING);
						oi->setOrderType(MKT);
						decomposeOrder(tradeUnit, oi);
					}
					else
					{
						oi->setOrderType(MKT);
						oi->setStatus(ADDING);
						oi->setAction(ADD_ACTION);
						if(oi->getBuySell()==BUY)
							oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
						else if(oi->getBuySell()==SELL)
							oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);
						dispatcher->sendOrder(oi);
					}
				}
			}	
		}	
	}
}

bool SwingTrader::double_divide(double divisor , double dividend)
{
	/*double result; 
	char result_buf[1000],*tmp;	 
	result = divisor/dividend;		
	sprintf(result_buf,"%lf",result);
	tmp = result_buf;
	while (*tmp++ != '.')
	 tmp++;
	while (*tmp != '\0') 
	{	 
		 if(*tmp != '0')
			return false;
		tmp++;
	 }	
	return true;*/
	return true;
}

void SwingTrader::executeStrategy()
{
	MSG msg;
	while(GetMessage(&msg,NULL,0, 0)) {
		
		// 在这里控制策略的执行与否
		if (!getAutoTrading()) {
			LogHandler::getLogHandler().alert(3, "Strategy", "Strategy is tentatively stopped!");
			continue;
		}

		switch(msg.message) {

			// 价格更新 k线内交易
			case PRICE_MSG:
				if(getIntraBarTrading()) {
					addCounter();
					signal();
				}
				break;
			case STRATEGY_MSG:
				if(!getIntraBarTrading()) {
					addCounter();
					signal();
				}
				break;
		}
	}
}

// added by xie
bool SwingTrader::isBarsEnough()
{
	return tradeUnit->isBarsEnough();
}

// 平仓
void SwingTrader::closeAllPositions()
{
	Position pos;
	pos.accountNo = dispatcher->getPlatformInfo().accountNo;
	pos.setQuoteId(tradeUnit->getQuoteId());
	dispatcher->getPosition(pos);
	pos.log();
	double price = 0;
	if (tradeUnit != NULL) {
		price = tradeUnit->getPrice()->lastPrice1;
	}
	if (pos.netqty == 0) return;
	else if (pos.netqty > 0) {
		sell(testOrderID, price, pos.netqty, MKT, DAY, STRATEGY_SUBMITTER);
	}else {
		buytocover(testOrderID, price, -pos.netqty, MKT, DAY, STRATEGY_SUBMITTER);
	}
}

TradeUnit* SwingTrader::getTradeUnit()
{
    return tradeUnit;
}
