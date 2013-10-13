#ifndef __SPTRADER__
#define __SPTRADER__
#include <list>
#include "TradeCube.h"
#include "Dispatcher.h" 

// 重构sptrader和dispatcher的关系
class SPTrader : public Dispatcher
{
public:
	SPTrader(PlatformInfo& platformInfo);
	int addQuote(QuoteItem *pQuoteItem);
	HANDLE startOrderThread();
	HANDLE startPriceThread();
	HANDLE startCheckConnectionThread();
	HANDLE startTickerThread();
	void stopOrderThread();
	int sendOrder(OrderItem* pOrderItem);
	bool isSupport(int orderType);
	int deleteQuote(QuoteItem *pQuoteItem);
	map<int, TradeItem*>& getDoneTrades();
	map<int, OrderItem*>& getCurrentOrders();
	void getPosition(Position& position);
private:
	int login();
	bool requestLinkState(LinkID linkID);
	static DWORD WINAPI orderThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI priceThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI checkConnectionThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI tickerThreadAdapter(LPVOID lpParam);
	int initTickConnection();
	int initPriceConnection();
	int confirmTradeInfo(int tradeRecordNo);
	int confirmPriceInfo(string quoteId);
	
	OrderItem* str2OrderItem(string orderStr);
	TradeItem* str2TradeItem(string orderStr);
	string orderItem2Str(OrderItem* po);
	OrderItem* str2UpdatedOrder(string orderStr);
	Position* str2Position(string orderStr);
	void processOrder();
	void processPrice();
	void processTickerMessage();
	SOCKET orderSocket, priceSocket, tickSocket;
	HANDLE hOrderThread, hPriceThread, hCheckConnectionThread, hTickerThread;
	DWORD orderThreadId, priceThreadId, checkConnectionThreadId, tickerThreadId;
	HANDLE quoteEvent, doneTradeEvent, curOrderEvent;
	map<string, HANDLE> positionEvents;
	int timerInterval; // seconds
	int currentTime;

};
#endif