#include <iostream>
#include <string>    
#include <list>
#include <map>
#include <windows.h>
#include "Strategy.h"
using namespace std; 
//using namespace stdext;

class SPOrderInterface;
class OrderItem;
class TradeItem;
class PriceItem;
class QuoteItem;

typedef struct
{
	int tradePlatform;
	string quoteId;
	DWORD threadId;
} quoteId_threadId;

class Dispatcher
{
public:
	Dispatcher();
	virtual ~Dispatcher();
	int submitOrder(OrderItem* pOrderItem);
	int returnOrder(OrderItem* pOrderItem);
	int returnTrade(TradeItem* pTradeItem);
	int forwardPrice(PriceItem* pPriceItem);
	int forwardTickPrice(PriceItem* pPriceItem);
	int addQuote(QuoteItem *pOuoteItem);
	int deleteQuote(QuoteItem *pOuoteItem);
	bool isSupport(int tradePlatform, int orderType);
	void setSPOrderInterface(SPOrderInterface* spoi);
	int addOrderThreadId(int traderId, DWORD traderThreadId);
	int addPriceThreadId(int tradePlatform, string quoteId, DWORD traderThreadId);
	void addUIThreadId(DWORD UIThreadID);
	void loseConnection();
	void addStrategy(Strategy* strategy);

private:
	SPOrderInterface* spoi;
	map<int, DWORD> orderThreadIdTable;
	list<quoteId_threadId*> priceThreadIdQueue;
	DWORD UIThreadID;
	list<Strategy*> strategies;
};


