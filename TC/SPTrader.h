#ifndef __SPTRADER__
#define __SPTRADER__
#include <list>
#include <thread>
#include <boost/asio.hpp>
#include "sptrader/sptrader_ticker.h"
#include "TradeCube.h"
#include "Dispatcher.h" 

// 重构sptrader和dispatcher的关系
class SPTrader : public Dispatcher
{
public:
	SPTrader(PlatformInfo& platformInfo);
    ~SPTrader();
	int addQuote(QuoteItem *pQuoteItem);
	HANDLE startOrderThread();
	HANDLE startPriceThread();
	HANDLE startCheckConnectionThread();
	void startTickerThread();
	void stopOrderThread();
	int sendOrder(OrderItem* pOrderItem);
	bool isSupport(int orderType);
	int deleteQuote(QuoteItem *pQuoteItem);
	map<int, TradeItem*>& getDoneTrades();
	map<int, OrderItem*>& getCurrentOrders();
	void getPosition(Position& position);
private:
    int SetUp();
	int login();
	bool requestLinkState(LinkID linkID);
	static DWORD WINAPI orderThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI priceThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI checkConnectionThreadAdapter(LPVOID lpParam);
	int initTickConnection();
	int initPriceConnection();
	int confirmTradeInfo(int tradeRecordNo);
	int confirmPriceInfo(string quoteId);
	
	OrderItem* str2UpdatedOrder(string orderStr);
	void processOrder();
	void processPrice();
	void processTickerMessage();
	SOCKET orderSocket, priceSocket, tickSocket;
	HANDLE hOrderThread, hPriceThread, hCheckConnectionThread;
	DWORD orderThreadId, priceThreadId, checkConnectionThreadId;
	HANDLE quoteEvent, doneTradeEvent, curOrderEvent;
	map<string, HANDLE> positionEvents;
	int timerInterval; // seconds
	int currentTime;


    boost::asio::io_service io_service_;
    SPTraderTicker *ticker_;
    std::thread *ticker_thread_;
};
#endif