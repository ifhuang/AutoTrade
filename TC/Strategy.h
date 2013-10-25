#ifndef __STRATEGY__
#define __STRATEGY__
#include "TradeCube.h"
#include "TradeUnit.h"
#include "Dispatcher.h"
#include "StrategyInterface.h"

class Strategy
{
public:
	Strategy(int traderId)
	{
		maxRefBarNum = 50;
		intraBarTrading = false;
		autoTrading = false;
		counter = 0;
		dispatcher = NULL;
		hTraderThread = NULL;
		this->traderId = traderId;
		this->optimizeOrderFlow = NO_OPTIMIZE_OFP;
		this->strategyInterface = new StrategyInterface(traderId, optimizeOrderFlow);
	}

	virtual ~Strategy() 
	{
		if (strategyInterface != NULL) {
			delete strategyInterface;
		}
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
		this->strategyInterface->setDispatcher(dispatcher);
	}

	void turnOffStrategy() 
	{
		autoTrading = false;
	}

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
		this->strategyInterface->setOptimizeOrderFlow(pattern);
	}

	// reconstructed and tested by xie
	DWORD startTraderThread();
	static DWORD WINAPI traderThreadAdapter(LPVOID lpParam);
	void turnOnStrategy();

protected:
	Dispatcher* dispatcher;
	DWORD TraderThreadId;
	map<int, int> doneTradeIDs;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1
	int traderId;
	StrategyInterface* strategyInterface;
private:
	void process();
	// 这是由服务器触发价格的处理函数，这个有些平台可能没有
	virtual void processTickPrice(MSG& msg) {};
	// 这是定时器更新k线的处理函数
	virtual void updateBars() = 0;
	virtual void processOrderAccepted(MSG& msg) = 0;
	virtual void processTradeDone(MSG& msg) = 0; 
	virtual void processPrice(MSG& msg) = 0; 
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