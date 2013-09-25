#include "Dispatcher.h" 
#include "OrderItem.h"
#include "TradeItem.h"
#include "PriceItem.h"
#include "SPTrader.h"
#include "QuoteItem.h"
#include "TradeCube.h"

Dispatcher::Dispatcher():UIThreadID(-1)
 {
	 spoi = NULL;
}
 
    
Dispatcher::~Dispatcher()
{
 
}
 

void Dispatcher::setSPOrderInterface(SPOrderInterface* spoi)
{
	this->spoi = spoi;
}

int Dispatcher::addQuote(QuoteItem *pQuoteItem)
{
	if(pQuoteItem->getTradePlatform() == SPTRADER)
	{					
		if(spoi == NULL)
		{
			SPOrderInterface* sptrader = &SPOrderInterface::startSPTrader("127.0.0.1","DEMO258","12341234", 8092, 8089, 8090);
			setSPOrderInterface(sptrader);
			sptrader->setDispatcher(this);
			Sleep(3000);
		}
		return spoi->addQuote(pQuoteItem->getQuoteId());
	}
	else if(pQuoteItem->getTradePlatform() == CTP)
	{
	}
	return SUCCESS;
}

int Dispatcher::deleteQuote(QuoteItem *pQuoteItem)
{
	int flag = 0;
	if(pQuoteItem->getTradePlatform() == SPTRADER)
	{					
		flag = spoi->deleteQuote(pQuoteItem->getQuoteId());
	}
	else if(pQuoteItem->getTradePlatform() == CTP)
	{
	}
	return flag;
}

int Dispatcher::submitOrder(OrderItem* pOrderItem)
{
	int flag = 0;
	if(pOrderItem->getTradePlatform() == SPTRADER)
	{					
		flag = spoi->sendOrder(pOrderItem);
	}
	else if(pOrderItem->getTradePlatform() == CTP)
	{
	}
	return flag;
}

int Dispatcher::returnTrade(TradeItem* pTradeItem)
{	
	int flag=0;
	if(pTradeItem->getTradePlatform() == SPTRADER)
	{
		int traderId = pTradeItem->getTraderId();
		// 这里可能trader还没加上就收到消息了。
		if (orderThreadIdTable.empty()) return -1;
		DWORD traderThreadId = orderThreadIdTable[traderId];
		if(PostThreadMessage(traderThreadId,TRADE_DONE_MSG,0,(LPARAM)pTradeItem))
			flag = 0;
		else 
			flag = -1;
	}
	else if(pTradeItem->getTradePlatform() == CTP)
	{
	}
	return flag;
}

int Dispatcher::returnOrder(OrderItem* pOrderItem)
{
	int flag = 0;
	if(pOrderItem->getTradePlatform() == SPTRADER)
	{
		int traderId = pOrderItem->getTraderId();
		DWORD traderThreadId = orderThreadIdTable[traderId];
		if(PostThreadMessage(traderThreadId,ORDER_ACCEPT_MSG,0,(LPARAM)pOrderItem))
			flag = 0;
		else
			flag = -1;
	}
	else if(pOrderItem->getTradePlatform() == CTP)
	{
	}
	return flag;
}

int Dispatcher::forwardPrice(PriceItem* pPriceItem)
{
	int flag = 0;
	if(pPriceItem->tradePlatform == SPTRADER)
	{
		string quoteId = pPriceItem->quoteId;
		int tradePlatform = pPriceItem->tradePlatform;
		list<quoteId_threadId*>::iterator iter = priceThreadIdQueue.begin();
		for(; iter != priceThreadIdQueue.end(); iter++)
		{
			if((*iter)->quoteId == quoteId && (*iter)->tradePlatform==tradePlatform) {
				PostThreadMessage((*iter)->threadId,PRICE_MSG,0,(LPARAM)pPriceItem);

				// 在UI上更新价格数据
				if (UIThreadID > 0) {
					PostThreadMessage(UIThreadID,PRICE_MSG,0,(LPARAM)pPriceItem);
				}
			}
		}
	}
	else if(pPriceItem->tradePlatform == CTP)
	{
	}
	return flag;
}

    int Dispatcher::addOrderThreadId(int traderId, DWORD traderThreadId)
    {
	    if(orderThreadIdTable.count(traderId) == 0)
	    {
		    orderThreadIdTable.insert(map<int,DWORD>::value_type(traderId, traderThreadId));
	    }
	    else
	    {
		    cout<<"This quote has been registered."<<endl;
		    return -1;
	    }
	    return 0;
    }

int Dispatcher::addPriceThreadId(int tradePlatform, string quoteId, DWORD traderThreadId)
{
	list<quoteId_threadId*>::iterator iter = priceThreadIdQueue.begin();
	for(; iter != priceThreadIdQueue.end(); iter++)
	{
		if((*iter)->quoteId ==quoteId && (*iter)->threadId ==traderThreadId &&(*iter)->tradePlatform==tradePlatform)
		{
			cout<<"This quote has been registered."<<endl;
			  return SUCCESS;
		    }
	}
	quoteId_threadId* qtid = new quoteId_threadId;
	qtid->quoteId = quoteId;
	qtid->threadId = traderThreadId;
	qtid->tradePlatform = tradePlatform;
	priceThreadIdQueue.push_front(qtid);
	return SUCCESS;
    }

void Dispatcher::addUIThreadId(DWORD UIThreadId) 
{
	this->UIThreadID = UIThreadId; 
}

bool Dispatcher::isSupport(int tradePlatform, int orderType)
{
	if(tradePlatform == SPTRADER)
	{
		return spoi->isSupport(orderType);
	}
	else if(tradePlatform==CTP)
	{
		return false;
	}
}

void Dispatcher::loseConnection()
{
	for (list<Strategy*>::iterator it = strategies.begin(); it != strategies.end(); it++) {
		(*it)->turnOffStrategy();
	}
}

void Dispatcher::addStrategy(Strategy* strategy)
{
}

// added by xie
int Dispatcher::forwardTickPrice(PriceItem* pPriceItem)
{
	int flag = 0;
	if(pPriceItem->tradePlatform == SPTRADER)
	{
		string quoteId = pPriceItem->quoteId;
		int tradePlatform = pPriceItem->tradePlatform;
		list<quoteId_threadId*>::iterator iter = priceThreadIdQueue.begin();
		for(; iter != priceThreadIdQueue.end(); iter++)
		{
			if((*iter)->quoteId == quoteId && (*iter)->tradePlatform==tradePlatform) {
				PostThreadMessage((*iter)->threadId,TICK_PRICE,0,(LPARAM)pPriceItem);
			}
		}
	}
	else if(pPriceItem->tradePlatform == CTP)
	{
	}
	return flag;
}