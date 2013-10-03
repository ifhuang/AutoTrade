#include "Dispatcher.h" 

Dispatcher::Dispatcher(PlatformInfo& platformInfo):platformInfo(platformInfo), connectStatus(false), doneTradeCount(0), currentOrderCount(0)
{		
}
 
    
Dispatcher::~Dispatcher()
{
 
}

// added by xie
void Dispatcher::loseConnection()
{
	for (map<int, DWORD>::iterator it = orderThreadIdTable.begin(); it != orderThreadIdTable.end(); it++) {
		PostThreadMessage(it->second, LOSE_CONN_MSG, 0, NULL);
	}
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

void Dispatcher::returnTrade(TradeItem* ti)
{	
	int traderId = ti->getTraderId();
	if (orderThreadIdTable.find(traderId) != orderThreadIdTable.end()) {
		DWORD traderThreadId = orderThreadIdTable[traderId];
		PostThreadMessage(traderThreadId,TRADE_DONE_MSG,0,(LPARAM)ti);
	}
}

void Dispatcher::returnOrder(OrderItem* po)
{
	int traderId = po->getTraderId();
	if (orderThreadIdTable.find(traderId) != orderThreadIdTable.end()) {
		DWORD traderThreadId = orderThreadIdTable[traderId];
		PostThreadMessage(traderThreadId,ORDER_ACCEPT_MSG,0,(LPARAM)po);
	}
}

void Dispatcher::forwardPrice(PriceItem* pPriceItem)
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

// added by xie
void Dispatcher::forwardTickPrice(PriceItem* pPriceItem)
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