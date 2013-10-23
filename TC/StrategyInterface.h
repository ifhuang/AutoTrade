#ifndef __STARTEGY_INTERFACE__
#define __STARTEGY_INTERFACE__
#include "TradeUnit.h"
#include "Dispatcher.h"
#include "../TradeCube/imainwindow.h"

class StrategyInterface
{
public:
	StrategyInterface(void);
	~StrategyInterface(void);
	void setTradeUnit(TradeUnit* tradeUnit);
	void buy(double submitPrice, double qty, int orderType, int validType);
    void sell(double submitPrice, double qty, int orderType, int validType);
    void buytocover(double submitPrice, double qty, int orderType, int validType);
    void sellshort(double submitPrice, double qty, int orderType, int validType);
	Bar* getBar(int position);
	int decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi);
	int deleteOrder(long orderRefId);
private:
    long createOrder(char buysell, string openclose, double submitPrice,
        double qty, int orderType, int validType, int submitter);
	long updateOrder(long orderRefId, char buysell, string openclose,
        double submitPrice, double qty, int validType);
	int decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi);
	int decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi);

	TradeUnit* tradeUnit;
    IMainWindow* iMainWindow;
	Dispatcher* dispatcher;
	long ascOrderRefId;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1
	int traderId;
};
#endif