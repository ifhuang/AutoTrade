#include "QuoteItem.h"
#include "PriceItem.h"
#include "TradeItem.h"
#include "OrderItem.h"
#include "Position.h"
#include "TradeUnit.h"
#include "ComboTrader.h"
#include "Dispatcher.h"
#include "TradeCube.h"
#include "ComboOrder.h"
#include <tchar.h>

DWORD WINAPI ComboTrader::traderThreadAdapter(LPVOID lpParam)
{
	ComboTrader *pct = (ComboTrader *)lpParam;
	pct->process();
	return 0; 
}

DWORD WINAPI ComboTrader::signalThreadAdapter(LPVOID lpParam)
{
	ComboTrader *pct = (ComboTrader *)lpParam;
	
	pct->executeStrategy();
	return 0; 
}

ComboTrader::ComboTrader(int traderId)
{
	this->traderId = traderId;
	this->ascOrderRefId = 1;
	dispatcher = NULL;
	 this->ss_orderId = 0;
	 this->buy_orderId = 0;
	 this->sell_orderId = 0;
	 this->btc_orderId = 0;
	 this->optimizeOrderFlow = NO_OPTIMIZE_OFP;
	//strategy = NULL;
}

ComboTrader::ComboTrader()
{
	this->ascOrderRefId = 1;
	dispatcher = NULL;
	this->ss_orderId = 0;
	this->buy_orderId = 0;
	this->sell_orderId = 0;
	this->btc_orderId = 0;
	this->optimizeOrderFlow = NO_OPTIMIZE_OFP;
}

ComboTrader::~ComboTrader()
{
}


int ComboTrader::getOrderFlowPattern()
{
	return this->optimizeOrderFlow;
}

DWORD ComboTrader::startTraderThread()
{
     hTraderThread = CreateThread(NULL, 0, traderThreadAdapter, this, 0, &TraderThreadId);
	return TraderThreadId;
}


DWORD ComboTrader::startSignalThread()
{
      hSignalThread = CreateThread(NULL, 0, signalThreadAdapter, this, 0, &signalThreadId);
	return TraderThreadId;
}

void ComboTrader::process()
{
	// added by xie
	// 如果不允许k线内交易，启动定时器，定时更新k线，暂定为1秒钟更新一次
	if (!getIntraBarTrading()) {
		SetTimer(NULL, 3, 1000, NULL);
	}

	MSG msg;
	//while(GetMessage(&msg,NULL,WM_USER+1, WM_USER+4))
	// 这里改一下，以便获取WM_TIMER by xie
	while(GetMessage(&msg, NULL, 0, 0))
	{
		switch(msg.message)
		{
		case ORDER_ACCEPT_MSG:
			{
				OrderItem* new_oi = (OrderItem*)msg.lParam;
				TradeUnit* tu = getTradeUnit(new_oi->getTradePlatform(), new_oi->getQuoteId());
				LogHandler::getLogHandler().log("Order accepted");
				new_oi->log();
				if(tu != NULL)
				{
					OrderItem* ori_oi = tu->getOrder(new_oi->getOrderRefId());

					ori_oi->setOrderNo(new_oi->getOrderNo());
					ori_oi->setReturnCode(new_oi->getReturnCode());
					ori_oi->setReturnMessage(new_oi->getReturnMessage());
					ori_oi->setStatus(new_oi->getStatus());
	
					long comboRefId = ori_oi->getComboRefId();
					if(comboOrderTable.count(comboRefId)==1)
					{
						ComboOrder* pco = comboOrderTable[comboRefId];
						OrderUnit* ou = pco->getOrderUnit(new_oi->getOrderRefId());
						ou->setStatus(new_oi->getStatus());
						pco->updateStatus();
						delete new_oi;
					}
					else
					{
						LogHandler::getLogHandler().alert(1, "Process ORDER_ACCEPT_MSG error", "Don't find the correspoding combo order");
					}				
				}
				else
				{
					LogHandler::getLogHandler().alert(1, "Process ORDER_ACCEPT_MSG error", "Trade Unit is not found for order return from server");
				}
				break;
			}
		case TRADE_DONE_MSG:
			{
				TradeItem* ti = (TradeItem*)msg.lParam;
				TradeUnit* tu = getTradeUnit(ti->getTradePlatform(), ti->getQuoteId());
				if(tu != NULL)
				{
					OrderItem* oi = tu->getOrder(ti->getOrderRefId());					
					if(oi != NULL)
					{
						oi->setStatus(ALLTRADED);
						LogHandler::getLogHandler().log("Trade done");
						oi->log();
						if(ti->getStatus()!=DELETED)
						{							
							// update the contract's position
							updateTradeUnitPosition(tu,ti);

							// update combo position							
							long comboRefId = oi->getComboRefId();
							if(comboOrderTable.count(comboRefId)==1)
							{
								ComboOrder* pco = comboOrderTable[comboRefId];
								if(optimizeOrderFlow==OPTIMIZE_OFP && oi->getParentRefId() != 0)
								{
									OrderItem* parent_oi = tu->getOrder(oi->getParentRefId());
									if(parent_oi == NULL)
										cout<<"Don't find the parent order, order Id:"<<oi->getParentRefId()<<endl;
									else
									{
										parent_oi->addTradedQty(ti->getQty());	
										// 订单分解
										if(parent_oi->getTradedQty() == parent_oi->getQty()) // all child orders are traded, then update combo position
										{
											if(pco->getOrderRank() != NO_RANK)
												PostThreadMessage(signalThreadId,ORDER_UNIT_TRADED,0,(LPARAM)parent_oi);
											OrderUnit* ou = pco->getOrderUnit(parent_oi->getOrderRefId());
											ou->setStatus(ALLTRADED);
											pco->updateStatus();		
											tu->deleteOrder(oi->getOrderRefId());	
											parent_oi->setStatus(ALLTRADED);
										}
										else
											parent_oi->setStatus(PARTIALTRADED);
									}
								}
								else if(optimizeOrderFlow==NO_OPTIMIZE_OFP && oi->getParentRefId() == 0)
								{
									oi->addTradedQty(ti->getQty());
									if(oi->getTradedQty() == oi->getQty())
									{
										if(pco->getOrderRank() != NO_RANK)
											PostThreadMessage(signalThreadId,ORDER_UNIT_TRADED,0,(LPARAM)oi);
										OrderUnit* ou = pco->getOrderUnit(oi->getOrderRefId());
										ou->setStatus(ALLTRADED);
										pco->updateStatus();	
										tu->deleteOrder(oi->getOrderRefId());	
									}
								}	

								// 所有品种都成交时 组合仓位计算
								if(pco->isAllOrderTraded())
								{
									ComboPosition* cmb_pos = getComboPosition(0);
									if(cmb_pos != NULL)
									{
										if(cmb_pos->getSize() ==0)   // current position is flat
										{
											ComboPosition* cmb_pos = new ComboPosition();														
											cmb_pos->setLongShort(pco->getBuySell()==BUY?1:-1);
											cmb_pos->setSize(cmb_pos->getLongShort()*pco->getQty());
											cmb_pos->addComboOrder(pco);
											comboPositionList.push_front(cmb_pos);
										}
										else if(cmb_pos->getSize()>0)  // current position is long
										{
											if(pco->getBuySell()==BUY)   // open some long position
											{
												cmb_pos->setSize(cmb_pos->getSize()+pco->getQty());
												cmb_pos->addComboOrder(pco);
											}
											else if(pco->getBuySell()==SELL)
											{
												if(cmb_pos->getSize()>=pco->getQty())  // close some long position
												{
													cmb_pos->setSize(cmb_pos->getSize()-pco->getQty());
													cmb_pos->addComboOrder(pco);
												}
												else if(cmb_pos->getSize()<pco->getQty()) // reverse long to short position
												{
													cmb_pos->setSize(0);
													ComboPosition* new_cmbpos = new ComboPosition();														
													new_cmbpos->setLongShort(-1);
													new_cmbpos->setSize(-1*pco->getQty());
													new_cmbpos->addComboOrder(pco);
													comboPositionList.push_front(new_cmbpos);
												}
											}
										}
										else if(cmb_pos->getSize()<0)  // current position is short
										{ 
											if(pco->getBuySell()==SELL)   // add some short position size
											{
												cmb_pos->setSize(cmb_pos->getSize()-pco->getQty()); 
												cmb_pos->addComboOrder(pco);
											}
											else if(pco->getBuySell()==BUY)
											{
												if(abs(cmb_pos->getSize())>=pco->getQty())  // close some short position
												{
													cmb_pos->setSize(cmb_pos->getSize()+pco->getQty());
													cmb_pos->addComboOrder(pco);
												}
												else if(abs(cmb_pos->getSize())<pco->getQty()) // reverse short to long position
												{
													cmb_pos->setSize(0);
													ComboPosition* new_cmbpos = new ComboPosition();														
													new_cmbpos->setLongShort(1);
													new_cmbpos->setSize(pco->getQty());
													new_cmbpos->addComboOrder(pco);
													comboPositionList.push_front(new_cmbpos);
												}
											}
										}
									}
									else // ComboPosition==NULL
									{
										cmb_pos = new ComboPosition();														
										cmb_pos->setLongShort(pco->getBuySell()==BUY?1:-1);
										cmb_pos->setSize(cmb_pos->getLongShort()*pco->getQty());
										cmb_pos->addComboOrder(pco);
										comboPositionList.push_front(cmb_pos);
										}
									}
								}
							else
							{
								//MessageBox(NULL,_T("Don't find the correspoding combo order"),_T("Process TRADE_DONE_MSG error"),MB_OK|MB_ICONSTOP);
							}	
						}																	
					}
					else
					{
						//Messagebox(NULL,_T("Done trade is not found in local order queues"),_T("Process TRADE_DONE_MSG error"),MB_OK|MB_ICONSTOP);
					}
				}
				break;
			}
		case PRICE_MSG:
			{
				
				PriceItem* pi = (PriceItem*)msg.lParam;			
				//cout<<"receive "<<pi->quoteId<<" price"<<endl;
				TradeUnit* tu = getTradeUnit(pi->tradePlatform, pi->quoteId);
				if(tu != NULL)
				{
					tu->updatePrice(pi);
					//pi->log();
					triggerWaitingOrder(tu);
					PostThreadMessage(signalThreadId,PRICE_MSG,0,0);
				}
				else
				{
					//Messagebox(NULL,_T("Trade Unit is not found for price message"),_T("Process PRICE_MSG error"),MB_OK|MB_ICONSTOP);
				}
				break;
			}
		case WM_TIMER:
			// 更新k线，但是用计数器可能会错过最高价和最低价。by xie
			for (list<TradeUnit*>::iterator it = tradeUnitList.begin(); it != tradeUnitList.end(); it++) {
				(*it)->updateBars();
				LogHandler::getLogHandler().log("timer update bar(" + (*it)->getQuote()->getQuoteId() + ")");
			}
			break;
		case TICK_PRICE:
			PriceItem* pi = (PriceItem*)msg.lParam;	
			LogHandler::getLogHandler().log("Tick price");
			pi->log();
			TradeUnit* tu = getTradeUnit(pi->tradePlatform, pi->quoteId);
			if (tu != NULL) { 
				tu->updateTickPrice(pi);
			}
			break;
		}
	}
}

void ComboTrader::updateTradeUnitPosition(TradeUnit* tradeUnit, TradeItem* ti)
{
	Position* cpos = tradeUnit->getPosition(0);
	if(cpos != NULL)
	{
		if(cpos->getSize()==0 && ti->getPositionSize()!=0) //  open a position
		{
			Position* pos = new Position();
			pos->setQuoteId(ti->getQuoteId());
			pos->setSize(ti->getPositionSize());
			pos->setLongShort(ti->getBuySell()==BUY?1:-1);
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
				cpos->setSize(0);
				Position* pos = new Position();
				pos->setQuoteId(ti->getQuoteId());
				pos->setSize(ti->getPositionSize());
				pos->setLongShort(ti->getBuySell()==BUY?1:-1);
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
				cpos->setSize(0);
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

int ComboTrader::addTradeUnit(TradeUnit* tradeUnit)
{

	if(dispatcher!=NULL && dispatcher->addQuote(tradeUnit->getQuote()))
	{
		this->tradeUnitList.push_back(tradeUnit);
		return SUCCESS;
	}
	return MY_ERROR;
}

void ComboTrader::setDispatcher(Dispatcher* dispatcher)
{
	this->dispatcher = dispatcher;
}

TradeUnit* ComboTrader::getTradeUnit(int quoteNo)
{
	TradeUnit* tu = NULL;
	if(tradeUnitList.size()>=quoteNo)
	{
		list<TradeUnit*>::iterator iter = tradeUnitList.begin();
		for(int i = 1; i<quoteNo; i++)
			iter++;
		tu = *iter;
	}
	return tu;
}

TradeUnit* ComboTrader::getTradeUnit(int tradePlatform, string quoteId)
{
	TradeUnit* tu = NULL;
	list<TradeUnit*>::iterator iter = tradeUnitList.begin();
	for(; iter!=tradeUnitList.end(); iter++)
	{
		tu = *iter;
		if(tu->getTradePlatform()==tradePlatform && tu->getQuoteId()==quoteId)
			break;
	}
	return tu;
}

int ComboTrader::deleteTradeUnit(int quoteNo)
{
	if(tradeUnitList.size()>=quoteNo)
	{
		list<TradeUnit*>::iterator iter = tradeUnitList.begin();
		for(int i = 0; i<quoteNo; i++)
		{
			iter++;
		}
		TradeUnit* tu = *iter;
		dispatcher->deleteQuote(tu->getQuote());
		delete tu;
		tradeUnitList.erase(iter);
		return 0;
	}
	else
	{
		return -1;
	}
}


long ComboTrader::createOrder(OrderUnit* orderUnit, char buysell, char openclose, double submitPrice, double qty, int orderType, int validType, int submitter, long comboRefId)
{	
	TradeUnit* tradeUnit = getTradeUnit(orderUnit->getQuoteNo());
	OrderItem* oi = new OrderItem(tradeUnit->getQuote()->getTradePlatform(), tradeUnit->getQuoteId(), submitPrice, qty, buysell, orderType, validType, openclose);
	oi->setOrderRefId(ascOrderRefId++);
	oi->setComboRefId(comboRefId);
	oi->setSubmitter(submitter);
	oi->setStatus(ADDING);
	oi->setTraderId(traderId);

	orderUnit->setOrderRefId(oi->getOrderRefId());
	orderUnit->setStatus(ADDING);		
	orderUnit->setOrderItem(oi);

	if(orderType == MKT) // Market order
	{				
		// decompose large order into small ones to decrease impact cost
		if(optimizeOrderFlow==OPTIMIZE_OFP && qty>tradeUnit->getQuote()->getMinContractQty())
		{
			tradeUnit->addOrder(oi);
			decomposeOrder(tradeUnit, oi);
		}
		else
		{
			if(buysell==BUY)
				oi->setSubmitPrice(tradeUnit->getPrice()->askPrice1);
			else if(buysell==SELL)
				oi->setSubmitPrice(tradeUnit->getPrice()->bidPrice1);
			oi->setAction(ADD_ACTION);
			tradeUnit->addOrder(oi);
			dispatcher->submitOrder(oi);
		}
	}
	else if(orderType != MKT ) 
	{		
		if(dispatcher->isSupport(tradeUnit->getTradePlatform(), orderType))
		{
			oi->setSubmitPrice(submitPrice);
			oi->setAction(ADD_ACTION);
			oi->setStatus(ADDING);
			tradeUnit->addOrder(oi);
			dispatcher->submitOrder(oi);
		}
		else
		{
			oi->setAction(WAITING);
			oi->setStatus(WAITING);
			oi->setSubmitPrice(submitPrice);
			tradeUnit->addOrder(oi);
		}
	}	

	return oi->getOrderRefId();
}


long ComboTrader::updateOrder(OrderUnit* orderUnit, long orderRefId, char buysell, char openclose, double submitPrice, double qty, int validType)
{
	TradeUnit* tradeUnit = getTradeUnit(orderUnit->getQuoteNo());
	OrderItem* oi = tradeUnit->getOrder(orderRefId);
	oi->addCounter();
	int tradePlatform = tradeUnit->getTradePlatform();
	if(oi != NULL)
	{
		if(dispatcher->isSupport(tradePlatform, oi->getOrderType()))
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
				dispatcher->submitOrder(oi); // transimit order 
			}

		}
		else if(!dispatcher->isSupport(tradePlatform, oi->getOrderType()))// tradeplatform don't support new ordertype
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
				dispatcher->submitOrder(oi); // transimit order 
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

int ComboTrader::decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi)
{
	return decomposeOrderByStep(tradeUnit, poi);
	//return decomposeOrderByDefault(tradeUnit, poi);
}

// 分解订单
int ComboTrader::decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi)
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
			OrderItem* oiu = new OrderItem(poi->getTradePlatform(), 
											poi->getQuoteId(), 
											poi->getSubmitPrice(), 
											minqty, 
											poi->getBuySell(), 
											poi->getOrderType(), 
											poi->getValidType(),
											poi->getOpenClose());
			oiu->setOrderRefId(ascOrderRefId++);
			oiu->setComboRefId(poi->getComboRefId());
			oiu->setParentRefId(poi->getOrderRefId());
			oiu->setTraderId(poi->getTraderId());
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
			//oiu->log();
			if(dispatcher->submitOrder(oiu)==MY_ERROR)
				return MY_ERROR;
		}
		return SUCCESS;
	}
	else
	{
		//Messagebox(NULL,_T("Current version support only for optimize MKT order flow"),_T("Decompose Order Error"),MB_OK|MB_ICONSTOP);
		return MY_ERROR;
	}
}

// added by xie
int ComboTrader::decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi)
{
	OrderUnit* orderUnit = NULL;
	for (list<OrderUnit*>::iterator it = orderTemplate.begin();
		it != orderTemplate.end(); it++) {
			if ((*it)->getOrderRefId() == poi->getOrderRefId()) {
				orderUnit = *it;
			}
	}
	if (orderUnit == NULL || poi->getOrderType() != MKT || orderUnit->getStepQty() <= 0) {
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
	if (orderUnit->getStepTickNum() > 0) {
		stepTickNum = orderUnit->getStepTickNum();
	} else if (orderUnit->getStepMoney() > 0) {

		// 这些值是什么？ bigPointValue 好像还没设
		stepTickNum = orderUnit->getStepMoney() / (tradeUnit->getQuote()->getBigPointValue() * tradeUnit->getQuote()->getPriceScale());
	} else {
		LogHandler::getLogHandler().alert(1, "Order decomposition", "Order decomposition failed, step not set!");
		return MY_ERROR;
	}
	for(int i = minqty; i <= poi->getQty(); i += minqty, qty += minqty) {	
		OrderItem* oiu = new OrderItem(poi->getTradePlatform(), 
										poi->getQuoteId(), 
										poi->getSubmitPrice(), 
										minqty, 
										poi->getBuySell(), 
										poi->getOrderType(), 
										poi->getValidType(),
										poi->getOpenClose());
		oiu->setOrderRefId(ascOrderRefId++);
		oiu->setComboRefId(poi->getComboRefId());
		oiu->setParentRefId(poi->getOrderRefId());
		oiu->setTraderId(poi->getTraderId());
		oiu->setStatus(ADDING);
		oiu->setAction(ADD_ACTION);
		if (qty > orderUnit->getStepQty()) {
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
		if(dispatcher->submitOrder(oiu)==MY_ERROR) {
			LogHandler::getLogHandler().alert(1, "Order decomposition", "Send decomposed order failed!");
			return MY_ERROR;
		}
	}
}

double ComboTrader::marketposition(int quoteNo, int pos_ago)
{
	TradeUnit* tu = getTradeUnit(quoteNo);
	Position* pos = tu->getPosition(pos_ago);
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

double ComboTrader::comboposition(int pos_ago)
{
	ComboPosition* pos = NULL;
	
	if(comboPositionList.size() >= pos_ago+1)
	{
		list<ComboPosition*>::iterator iter = comboPositionList.begin();
		for(int i = 0; i<pos_ago; i++)
			iter++;
		pos = *iter;
	}
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

ComboPosition* ComboTrader::getComboPosition(int pos_ago)
{
	ComboPosition* pos = NULL;
	if(comboPositionList.size()>=pos_ago+1)
	{
		list<ComboPosition*>::iterator iter = comboPositionList.begin();
		for(int i = 0; i<pos_ago; i++)
			iter++;
		pos = *iter;
	}
	return pos;
}

double ComboTrader::price(int quoteNo)
{
	TradeUnit* tu = getTradeUnit(quoteNo);
	if(tu != NULL)
	{
		PriceItem* prc = tu->getPrice();
		if(prc != NULL)
			return tu->getPrice()->lastPrice1;
		else 
			return 0;
	}
	else
	{
		return 0;
	}
}
double ComboTrader::askprice(int quoteNo)
{
	TradeUnit* tu = getTradeUnit(quoteNo);
	if(tu != NULL)
	{
		return tu->getPrice()->askPrice1;
	}
	else
	{
		return 0;
	}
}
double ComboTrader::bidprice(int quoteNo)
{
	TradeUnit* tu = getTradeUnit(quoteNo);
	if(tu != NULL)
	{
		return tu->getPrice()->bidPrice1;
	}
	else
	{
		return 0;
	}
}

// 追价
void ComboTrader::triggerWaitingOrder(TradeUnit* tradeUnit)
{
	PriceItem* pi = tradeUnit->getPrice();
	map<long,OrderItem*>::iterator iter;
	map<long, OrderItem*> orderQueue = tradeUnit->getOrderQueue();
	if(orderQueue.size()>0)
	{		
		for(iter=orderQueue.begin(); iter != orderQueue.end(); iter++)
		{
			OrderItem* oi = iter->second;

			// 订单如果还没被接收
			if (oi->getOrderNo() == 0) continue;

			// 订单如果已经成交了
			if (oi->getStatus() == ALLTRADED) continue;

			if(!dispatcher->isSupport(oi->getTradePlatform(), oi->getOrderType()))
			{
				if(oi->getOrderType() == MKT)
				{
					if((optimizeOrderFlow==OPTIMIZE_OFP && oi->getParentRefId() != 0) || optimizeOrderFlow==NO_OPTIMIZE_OFP)
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
							dispatcher->submitOrder(oi);
						}
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
							dispatcher->submitOrder(oi);
						}
					}
				}	
			}
		}
	}
}


//void ComboTrader::setStrategy(Strategy* strategy)
//{
//	this->strategy = strategy;
//}

void ComboTrader::executeStrategy()
{
	MSG msg;
	while(GetMessage(&msg,NULL,WM_USER+4, WM_USER+6))
	{
		// 在这里控制策略的执行与否
		if (!getAutoTrading()) {
			LogHandler::getLogHandler().alert(3, "Strategy", "Strategy is tentatively stopped!");
			continue;
		}
		//LogHandler::getLogHandler().log("Strategy executed!");
		switch(msg.message)
		{
			// 某一个品种成交之后
		case ORDER_UNIT_TRADED:
			{
				// 成交下一个
				OrderItem* oi = (OrderItem*)msg.lParam;
				ComboOrder* pco = comboOrderTable[oi->getComboRefId()];
				if(pco->getOrderRank() != NO_RANK)
				{
					submitComboOrder(pco);
				}
				else
					cout<<"error: in NO_RANK order model but ORDER_UNIT_TRADED message is received"<<endl;
				break;
			}
			// 价格更新 k线内交易
		case PRICE_MSG:
			{			

				// 其实这里也判断了是否是自动交易
				//cout<<"Signal Thread: PRICE_MSG"<<endl;
				if(getAutoTrading() && getIntraBarTrading())
				{
					//cout<<"Signal run times: "<<getCounter()<<endl;
					addCounter();
					signal();
					//deleteStrategyOrder();
				}
				break;
			}
			// 定时器
		case STRATEGY_MSG:
			{
				if(getAutoTrading() && !getIntraBarTrading())
				{
					addCounter();
					signal();
					//deleteStrategyOrder();
				}
				break;
			}
		}
	}
}

int ComboTrader::createOrderTemplate(int num, int quoteNo[], double qty[], char buysell[], int rankId[])
{	
	for(int i = 0; i < num; i++)
	{
		TradeUnit* tradeUnit = getTradeUnit(quoteNo[i]);
		if (tradeUnit == NULL) continue;
		int minqty = (tradeUnit->getQuote()->getMinContractQty())*MULTIPLIER;
		int submitQty = qty[i]*MULTIPLIER;
		if(submitQty%minqty != 0)
		{
			cout<<"The quantity is not the integer multiples of the unit contract"<<endl;
			return MY_ERROR;
		}
		OrderUnit* ou = new OrderUnit(quoteNo[i], qty[i], buysell[i], rankId[i]);
		
		// test
		//ou->setStepTickNum(1);
		//ou->setStepQty(2);

		orderTemplate.push_back(ou);
	}

	// 这里是按照rank id 进行排序了。所以通过这个来确定先后顺序。
	orderTemplate.sort();
	return 0;
}

int ComboTrader::updateComboOrder(long& comboRefId,  char buysell, char openclose, double qty, int validType, double skippage)
{
	return SUCCESS;
}

int ComboTrader::submitComboOrder(ComboOrder* pco)
{
	int orderRank = pco->getOrderRank();
	list<OrderUnit*>* order_template = pco->getOrderTemplate();

	// 这样虽然是有顺序，但是不能保证在服务器上就是按照这个发出订单的顺序吧
	if(orderRank != NO_RANK)
	{		
		if(orderRank==ORDINAL_RANK)
		{
			list<OrderUnit*>::iterator start_iter, end_iter;
			start_iter = order_template->begin();
			end_iter = order_template->end();
			for(; start_iter != end_iter;)
			{
				OrderUnit* ou  = *start_iter;
				if(ou->getStatus() != ALLTRADED)
				{
					if(ou->getStatus()!=WAITING)
						break;

					TradeUnit* tu = getTradeUnit(ou->getQuoteNo());
					char tmp_buysell=ou->getBuySell();
					double tmp_price = 0;
					if(pco->getBuySell()==SELL)
					{
						if(ou->getBuySell()==BUY)
						{
							tmp_buysell = SELL;
							tmp_price =  tu->getPrice()->askPrice1;
						}
						else if(ou->getBuySell()==SELL)
						{
							tmp_buysell = BUY;
							tmp_price =  tu->getPrice()->bidPrice1;
						}
					}
					createOrder(ou, tmp_buysell, pco->getOpenClose(),tmp_price, pco->getQty()*ou->getQty(), pco->getOrderType(), pco->getValidType(), pco->getSubmitter(), pco->getComboRefId());
					list<OrderUnit*>::iterator mid_iter= start_iter;
					mid_iter++;
					while(mid_iter!=end_iter && (*mid_iter)->getRankId()==(*start_iter)->getRankId())
					{
						ou  = *mid_iter;
						tu = getTradeUnit(ou->getQuoteNo());
						char tmp_buysell=ou->getBuySell();
						double tmp_price = 0;
						if(pco->getBuySell()==SELL)
						{
							if(ou->getBuySell()==BUY)
							{
								tmp_buysell = SELL;
								tmp_price =  tu->getPrice()->askPrice1;
							}
							else if(ou->getBuySell()==SELL)
							{
								tmp_buysell = BUY;
								tmp_price =  tu->getPrice()->bidPrice1;
							}
						}
						createOrder(ou,  tmp_buysell, pco->getOpenClose(), tmp_price, pco->getQty()*ou->getQty(), pco->getOrderType(), pco->getValidType(), pco->getSubmitter(), pco->getComboRefId());

						mid_iter++;
					}
					
					start_iter = mid_iter;
				}
				else if(ou->getStatus() == ALLTRADED)
					start_iter++;
			}
		}
		else if(orderRank==REVERSE_RNAK)
		{
			list<OrderUnit*>::reverse_iterator start_iter, end_iter;
			start_iter = order_template->rbegin();
			end_iter = order_template->rend();
			for(; start_iter != end_iter;)
			{
				OrderUnit* ou  = *start_iter;
				if(ou->getStatus() != ALLTRADED)
				{
					if(ou->getStatus()!=WAITING) // why must be waiting?
						break;
					TradeUnit* tu = getTradeUnit(ou->getQuoteNo());
					char tmp_buysell=ou->getBuySell();
					double tmp_price = 0;
					if(pco->getBuySell()==SELL)
					{
						if(ou->getBuySell()==BUY)
						{
							tmp_buysell = SELL;
							tmp_price =  tu->getPrice()->askPrice1;
						}
						else if(ou->getBuySell()==SELL)
						{
							tmp_buysell = BUY;
							tmp_price =  tu->getPrice()->bidPrice1;
						}
					}
					createOrder(ou, tmp_buysell, pco->getOpenClose(), tmp_price, pco->getQty()*ou->getQty(), pco->getOrderType(), pco->getValidType(), pco->getSubmitter(), pco->getComboRefId());
					
					list<OrderUnit*>::reverse_iterator mid_iter= start_iter;
					mid_iter++;
					while(mid_iter!=end_iter && (*mid_iter)->getRankId()==(*start_iter)->getRankId())
					{
						ou  = *mid_iter;
						tu = getTradeUnit(ou->getQuoteNo());
						char tmp_buysell=ou->getBuySell();
						double tmp_price = 0;
						if(pco->getBuySell()==SELL)
						{
							if(ou->getBuySell()==BUY)
							{
								tmp_buysell = SELL;
								tmp_price =  tu->getPrice()->askPrice1;
							}
							else if(ou->getBuySell()==SELL)
							{
								tmp_buysell = BUY;
								tmp_price =  tu->getPrice()->bidPrice1;
							}
						}
						createOrder(ou,  tmp_buysell, pco->getOpenClose(), tmp_price, pco->getQty()*ou->getQty(), pco->getOrderType(), pco->getValidType(), pco->getSubmitter(), pco->getComboRefId());
						mid_iter++;
					}
					// waiting for message from trader thread that previous order is traded
					start_iter = mid_iter;
				}		
				else if(ou->getStatus()==ALLTRADED)
					start_iter++;
			}
		}
	} // if(orderRank!=NO_RANK) end;
	else
	{
		list<OrderUnit*>::iterator iter = order_template->begin();
		for(; iter != order_template->end(); iter++)
		{
			OrderUnit* ou  = *iter;
			TradeUnit* tu = getTradeUnit(ou->getQuoteNo());
			double tmp_price = 0;
			char tmp_buysell=ou->getBuySell();
			if(pco->getBuySell()==SELL)
			{
				if(ou->getBuySell()==BUY)
				{
					tmp_buysell = SELL;
					tmp_price =  tu->getPrice()->askPrice1;
				}
				else if(ou->getBuySell()==SELL)
				{
					tmp_buysell = BUY;
					tmp_price =  tu->getPrice()->bidPrice1;
				}
			}
			createOrder(ou,  tmp_buysell, pco->getOpenClose(), tmp_price, pco->getQty()*ou->getQty(), pco->getOrderType(), pco->getValidType(), pco->getSubmitter(), pco->getComboRefId());
			if(pco->getTimespan() >0)
				Sleep(pco->getTimespan()*1000);
		}
	}
	return SUCCESS;
}

int ComboTrader::createComboOrder(long& comboRefId,  char buysell, char openclose, double qty, int orderType, int validType, double skippage, int orderRank, int submitter)
{
	if(orderTemplate.size() <= 1){
		//Messagebox(NULL,_T("Please create order template for ComboTrader before putting order"),_T(" Submit combo order error"),MB_OK|MB_ICONSTOP);
		return - 1;
	}
	if(orderType==MKT)
	{
		list<OrderUnit*>* order_template = new list<OrderUnit*>(orderTemplate);
		ComboOrder* pco = new ComboOrder(buysell, openclose, qty, orderType, validType, skippage, order_template, orderRank, submitter);
		pco->setComboRefId(ascOrderRefId++);
		comboRefId = pco->getComboRefId();
		comboOrderTable.insert(map<long, ComboOrder*>::value_type(pco->getComboRefId(), pco));
		submitComboOrder(pco);
	}
	else
	{
		//Messagebox(NULL,_T("Sorry, the current version support only MKT order for combo trade"),_T(" Submit combo order error"),MB_OK|MB_ICONSTOP);
		return MY_ERROR;		
	}
	return SUCCESS;
}

bool ComboTrader::double_divide(double divisor , double dividend)
{
	double result; 
	char result_buf[20],*tmp;	 
	result = divisor/dividend;		
	sprintf(result_buf,"%.15lf",result);
	tmp = result_buf;
	//cout<<tmp<<endl;
	while (*tmp != '.')
		tmp++;
	//cout<<tmp<<endl;
	 tmp++;
	 //cout<<tmp<<endl;
	while (*tmp != '\0')
	{	 
		 if(*tmp != '0')
			return false;
		tmp++;
	 }	
	return true;
}

void ComboTrader::setOptimizeOrderFlow(int pattern)
{
	this->optimizeOrderFlow = pattern;
}

int ComboTrader::getTraderId()
{
	return this->traderId;
}

int ComboTrader::buy(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter)
{
	if(comboRefId==0)
	{
		createComboOrder(comboRefId,  BUY, OPEN, qty, orderType, validType, skippage, orderRank, submitter);
	}
	else
	{

	}
	return SUCCESS;
}

int ComboTrader::sell(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter)
{
	if(comboRefId==0)
	{
		createComboOrder(comboRefId,  SELL, CLOSE, qty, orderType, validType, skippage, orderRank, submitter);
	}
	else
	{

	}
	return SUCCESS;
}

int ComboTrader::sellshort(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter)
{
	if(comboRefId==0)
	{
		createComboOrder(comboRefId,  SELL, OPEN, qty, orderType, validType, skippage, orderRank, submitter);
	}
	else
	{

	}
	return SUCCESS;
}

int ComboTrader::buytocover(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter)
{
	if(comboRefId==0)
	{
		createComboOrder(comboRefId,  BUY, CLOSE, qty, orderType, validType, skippage, orderRank, submitter);
	}
	else
	{

	}
	return SUCCESS;
}

void ComboTrader::turnOnStrategy()
{
	setAutoTrading(true);

	//这里要先检查是否已经接收或者读历史数据文件中读取了足够的数据，如果数据不足，则不能开启策略交易
	// added by xie
	if(!getIntraBarTrading()) {
		bool isBarsEnough = true;
		for (list<TradeUnit*>::iterator it = tradeUnitList.begin(); it != tradeUnitList.end(); it++) {
			if (!(*it)->isBarsEnough()) {
				isBarsEnough = false;
				break;
			}
		}
		if (!isBarsEnough) {
			LogHandler::getLogHandler().alert(3, "Strategy Start", "Not enough bars!");
			return;
		}
	}
	startSignalThread();
//	if(strategy != NULL)
//	{
//		strategy->setAutoTrading(true);
//		startSignalThread();
//		if(!strategy->getIntraBarTrading())
//		{
			
			//int timeInterval = tradeUnit->getBar(0)->getPeriod();
			//iTimerID = SetTimer(NULL, 0, );
//		}
//	}
}

	//测试策略
void ComboTrader::signal()
{
	long& sellshort_RefId=ss_orderId, &buy_RefId=buy_orderId, &sell_RefId=sell_orderId, &btc_RefId=btc_orderId;
	//cout<<"price differece = "<<price(2)-4*price(1)<<endl;
	//做多与平仓
	if(price(2)-4*price(1)>2480 && comboposition(0)==0) {
		buy(buy_RefId,  1, MKT, DAY, 50, NO_RANK, STRATEGY_SUBMITTER);
	}
	if(price(2)-4*price(1)<=2475 && comboposition(0)>0) {
		sell(sell_RefId,  1, MKT, DAY, 50, NO_RANK, STRATEGY_SUBMITTER);	
	}

	//做空与平仓
	if(price(2)-4*price(1)<2475 && comboposition(0)==0) {
		sellshort(sellshort_RefId, 1, MKT, DAY, 50, NO_RANK, STRATEGY_SUBMITTER);
	}
	if(price(2)-4*price(1)>2480 && comboposition(0)<0) {
		buytocover(btc_RefId, 1, MKT, DAY, 50, NO_RANK, STRATEGY_SUBMITTER);
	}
}