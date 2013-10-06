#include <time.h>
#include <iostream>
#include <string> 
#include <windows.h>
#include<sstream>


class Dispatcher;
class TradeUnit;
class Strategy;

class SwingTrader
{
private:
	int traderId;
	HANDLE hTraderThread;
	DWORD TraderThreadId;
	TradeUnit* tradeUnit;
	Dispatcher* dispatcher;
	Strategy* strategy;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1
	UINT_PTR iTimerID ; 
	long ascOrderRefId;

protected:
	static DWORD WINAPI traderThreadAdapter(LPVOID lpParam);
	void process();
	void triggerWaitingOrder();
	long createOrder(char buysell, char openclose, double submitPrice, double qty, int orderType, int validType, int submitter);
	int deleteOrder(long orderRefId);
	long updateOrder( long orderRefId, char buysell, char openclose, double submitPrice, double qty, int validType);
	void postStrategySignal();
	void deleteStrategyOrder();	
	bool double_divide(double divisor , double dividend);

	int decomposeOrder(OrderItem* orderItem);
	long buy(long& orderRefId, string quoteId, double submitPrice, double qty, int orderType, int validType, int submitter);
	long sell(long& orderRefId, string quoteId, double submitPrice, double qty, int orderType, int validType, int submitter);
	long buytocover(long& orderRefId, string quoteId, double submitPrice, double qty, int orderType, int validType, int submitter);
	long sellshort(long& orderRefId, string quoteId, double submitPrice, double qty, int orderType, int validType, int submitter);
	double marketposition(int pos_ago);
public:
	DWORD startTraderThread();
	int setTradeUnit(TradeUnit* tradeUnit);
	int deleteTradeUnit();
	void setOptimizeOrderFlow(int orderFlow);
	void turnOnStrategy();
	void turnOffStrategy();
	SwingTrader(int traderId);
	virtual ~SwingTrader();
	void setDispatcher(Dispatcher* dispatcher);
};