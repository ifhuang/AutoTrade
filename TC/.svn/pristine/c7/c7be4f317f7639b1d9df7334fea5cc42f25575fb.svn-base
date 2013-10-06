#include <iostream>
#include <string> 
#include <windows.h>
#include<sstream>
#include <time.h>
#include <stdio.h>
#include "TradeCube.h"
#include "LogHandler.h"
using namespace std; 
//using namespace stdext;

class Dispatcher;
class OrderItem;
class TradeItem;
class PriceItem;

class SPOrderInterface
{
public:
	SPOrderInterface();
	bool getConnectStatus();
	void setConnectStatus(bool);
	void setDispatcher(Dispatcher* dispatcher);
	static SPOrderInterface& startSPTrader(string server, string account_no, string password, int orderPort, int pricePort, int tickPort);
	HANDLE startOrderThread();
	HANDLE startPriceThread();
	HANDLE startCheckConnectionThread();
	HANDLE startTickerThread();
	void stopPriceThread();
	void stopOrderThread();
	int sendOrder(OrderItem* pOrderItem);
	bool isSupport(int orderType);
	int addQuote(string quoteId);
	int deleteQuote(string quoteId);
	int requestTick(string quoteId);
	int releaseTick(string quoteId);
protected:
	bool requestLinkState(LinkID linkID);
	int login(string server, string account_no, string password, int orderPort, int pricePort, int tickPort);
	void logout();
	int initPriceConnection();
	int initTickConnection();
	static DWORD WINAPI orderThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI priceThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI checkConnectionThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI tickerThreadAdapter(LPVOID lpParam);
	void processOrder();
	void processPrice();
	void processTickerMessage();
	int confirmTradeInfo(int tradeRecordNo);
	int confirmPriceInfo(string quoteId);
private:
	OrderItem* str2OrderItem(string orderStr);
	TradeItem* str2TradeItem(string orderStr);
	string orderItem2Str(OrderItem* po);
	PriceItem* str2PriceItem(string priceStr);
	int orderPort, pricePort, tickPort;
	string server, accountNo;
	SOCKET orderSocket, priceSocket, tickSocket;
	bool connectStatus;
	HANDLE hOrderThread, hPriceThread, hCheckConnectionThread, hTickerThread;
	DWORD orderThreadId, priceThreadId, checkConnectionThreadId, tickerThreadId;
	HANDLE quoteEvent;
	Dispatcher* dispatcher;
	int timerInterval; // seconds
	int currentTime;
};