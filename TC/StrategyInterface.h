#ifndef __STARTEGY_INTERFACE__
#define __STARTEGY_INTERFACE__
#include "TradeUnit.h"
#include "Dispatcher.h"
#include "../TradeCube/imainwindow.h"

class StrategyInterface
{
public:
	StrategyInterface(int traderId, int optimizeOrderFlow, Dispatcher *disp);
	~StrategyInterface(void);
	void setTradeUnit(TradeUnit* tradeUnit);
	void setOptimizeOrderFlow(int pattern);
	void setMainWindow(IMainWindow* iMainWindow) { this->iMainWindow = iMainWindow; }
	vector<OrderItem*>& getOrderList() { return this->strategyOrderList;}
	void resetStrategyOrdersPointer() { this->orderListPointer = 0; }
	PriceItem* getCurrentPriceItem() const { return this->tradeUnit->getPrice();}
	void buy(double submitPrice, double qty, int orderType, int validType);
    void sell(double submitPrice, double qty, int orderType, int validType);
    void buytocover(double submitPrice, double qty, int orderType, int validType);
    void sellshort(double submitPrice, double qty, int orderType, int validType);
	Bar* getBar(int position);
	int decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi);
	int deleteOrder(long orderRefId);
    long createOrder(char buysell, string openclose, double submitPrice,
        double qty, int orderType, int validType, int submitter);
	long updateOrder(long orderRefId, char buysell, string openclose,
        double submitPrice, double qty, int validType);
private:
	int decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi);
	int decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi);

	int orderListPointer;
	vector<OrderItem*> strategyOrderList;
	TradeUnit* tradeUnit;
    IMainWindow* iMainWindow;
	Dispatcher* dispatcher_;
	long ascOrderRefId;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1
	int traderId;
};
#endif