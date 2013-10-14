#ifndef __STRATEGY__
#define __STRATEGY__
#include "TradeCube.h"
#include "TradeUnit.h"
#include "Dispatcher.h"

class Strategy
{
public:
	Strategy(int traderId)
	{
		maxRefBarNum = 50;
		intraBarTrading = false;
		autoTrading = false;
		counter = 0;
		this->ascOrderRefId = 1;
		dispatcher = NULL;
		this->traderId = traderId;
		hTraderThread = NULL;
		this->optimizeOrderFlow = NO_OPTIMIZE_OFP;
	}
	
	void addCounter()
	{
		counter++;
	}
	long getCounter()
	{
		return this->counter;
	}
	void setMaxRefBarNum(int refbar)
	{
		this->maxRefBarNum = refbar;
	}
	void setIntraBarTrading(bool intraBarTrading)
	{
		this->intraBarTrading = intraBarTrading;
	}

	void setAutoTrading(bool autoTrading)
	{
		this->autoTrading = autoTrading;
	}
	int getMaxRefBarNum()
	{
		return this->maxRefBarNum;
	}
	bool getIntraBarTrading()
	{
		return this->intraBarTrading;
	}
	bool getAutoTrading()
	{
		return this->autoTrading;
	}

	void setDispatcher(Dispatcher* dispatcher)
	{
		this->dispatcher = dispatcher;
	}

	void turnOffStrategy() 
	{
		autoTrading = false;
	};

	int getTraderId()
	{
		return this->traderId;
	}

	int getOrderFlowPattern()
	{
		return this->optimizeOrderFlow;
	}

	void setOptimizeOrderFlow(int pattern)
	{
		this->optimizeOrderFlow = pattern;
	}

	// reconstructed and tested by xie
	long createOrder(char buysell, string openclose, double submitPrice,
        double qty, int orderType, int validType, int submitter);
	int decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi);
	int decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi);
	int decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi);
	DWORD startTraderThread();
	DWORD startSignalThread();
	static DWORD WINAPI traderThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI signalThreadAdapter(LPVOID lpParam);
	void turnOnStrategy();

protected:
	Dispatcher* dispatcher;
	long ascOrderRefId;
	int traderId;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1
	DWORD TraderThreadId;
	DWORD signalThreadId;
	map<int, int> doneTradeIDs;
private:
	void process();
	// 这是由服务器触发价格的处理函数，这个有些平台可能没有
	virtual void processTickPrice(MSG& msg) {};
	// 这是定时器更新k线的处理函数
	virtual void updateBars() = 0;
	virtual void processOrderAccepted(MSG& msg) = 0;
	virtual void processTradeDone(MSG& msg) = 0; 
	virtual void processPrice(MSG& msg) = 0; 
	virtual void executeStrategy() = 0;
	virtual bool isBarsEnough() = 0;

	/** 策略执行函数 */
	virtual void signal() = 0;

	HANDLE hTraderThread;
	HANDLE hSignalThread;
	bool autoTrading;
	int maxRefBarNum;
	bool intraBarTrading;
	long counter;
};
#endif