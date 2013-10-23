#ifndef __COMBO_TRADER__
#define __COMBO_TRADER__
#include <list>
#include <string> 
#include <windows.h>
#include <tchar.h>
#include "TradeCube.h"
#include "TradeUnit.h"
#include "Strategy.h"
#include "Dispatcher.h"

using namespace std; 

class ComboTrader: public Strategy
{
public:
	ComboTrader(int traderId);
	virtual ~ComboTrader();
	int addTradeUnit(TradeUnit* tradeUnit);
	int deleteTradeUnit(int quoteNo);
	int createOrderTemplate(int num, int quoteNo[], double qty[], char buysell[], int rankId[]);
	virtual void signal();
protected:
	int buy(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter);
	int sell(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter);
	int buytocover(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter);
	int sellshort(long& comboRefId,  double qty, int orderType, int validType, double skippage, int orderRank, int submitter);
	double marketposition(int quoteNo, int pos_ago);
	double comboposition(int pos_ago);
	double price(int quoteNo);
	double askprice(int quoteNo);
	double bidprice(int quoteNo);
	double open(int quoteNo, int pos_ago);
	double high(int quoteNo, int pos_ago);
	double low(int quoteNo, int pos_ago);
	double close(int quoteNo, int pos_ago);

private:
	long ss_orderId, buy_orderId, sell_orderId, btc_orderId;

	list<TradeUnit*> tradeUnitList;
	list<OrderUnit*> orderTemplate;
	map<long, ComboOrder*> comboOrderTable;
	list<ComboPosition*> comboPositionList;

	virtual void processTickPrice(MSG& msg);
	virtual void updateBars();
	virtual void processOrderAccepted(MSG& msg);
	virtual void processTradeDone(MSG& msg); 
	virtual void processPrice(MSG& msg); 
	void executeStrategy();
	bool isBarsEnough();

	void triggerWaitingOrder(TradeUnit* tradeUnit);

	long createOrder(OrderUnit* orderUnit, char buysell, string openclose,
        double submitPrice, double qty, int orderType, int validType, int submitter, long comboRefId);

    long updateOrder(OrderUnit* orderUnit, long orderRefId, char buysell,
        string openclose, double submitPrice, double qty, int validType);

	TradeUnit* getTradeUnit(int quoteNo);
	TradeUnit* getTradeUnit(int tradePlatform, string quoteId);
	int submitComboOrder(ComboOrder* comboOrder);

	int createComboOrder(long& comboRefId,  char buysell, string openclose,
        double qty, int orderType, int validType, double skippage, int orderRank, int submitter);

    int updateComboOrder(long& comboRefId, char buysell, string openclose,
        double qty, int validType, double skippage);

	void updateTradeUnitPosition(TradeUnit* tradeUnit, TradeItem* ti);
	bool double_divide(double divisor , double dividend);
	ComboPosition* getComboPosition(int pos_ago);

	// 先这样吧，让他编译通过，这个需要加到StrategyInterface中的
	long ascOrderRefId;
};
#endif