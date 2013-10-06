#include "Strategy.h"
#include <list>
#include <string> 
#include <windows.h>
#include "LogHandler.h"
using namespace std; 

class Dispatcher;
class TradeUnit;
class OrderItem;
class ComboOrder;
class OrderUnit;
class ComboPosition;
class TradeItem;
class Strategy;

class ComboTrader: public Strategy
{
public:
	ComboTrader(int traderId);
	ComboTrader();
	virtual ~ComboTrader();
	DWORD startTraderThread();
	DWORD startSignalThread();
	int addTradeUnit(TradeUnit* tradeUnit);
	int deleteTradeUnit(int quoteNo);
	void turnOnStrategy();
	//void setStrategy(Strategy* strategy);
	void setOptimizeOrderFlow(int pattern);
	int getOrderFlowPattern();
	int createOrderTemplate(int num, int quoteNo[], double qty[], char buysell[], int rankId[]);
	void setDispatcher(Dispatcher* dispatcher);
	int getTraderId();
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
	int traderId;
	long ss_orderId, buy_orderId, sell_orderId, btc_orderId;
	HANDLE hTraderThread, hSignalThread;
	DWORD TraderThreadId, signalThreadId;
	list<TradeUnit*> tradeUnitList;
	Dispatcher* dispatcher;
	//Strategy* strategy;
	list<OrderUnit*> orderTemplate;
	map<long, ComboOrder*> comboOrderTable;
	list<ComboPosition*> comboPositionList;
	long ascOrderRefId;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1 订单分解标志

	static DWORD WINAPI traderThreadAdapter(LPVOID lpParam);
	static DWORD WINAPI signalThreadAdapter(LPVOID lpParam);
	void process();
	void executeStrategy();
	void triggerWaitingOrder(TradeUnit* tradeUnit);
	long createOrder(OrderUnit* orderUnit, char buysell, char openclose, double submitPrice, double qty, int orderType, int validType, int submitter, long comboRefId);
	long deleteOrder(int quoteNo, long orderRefId);
	long updateOrder(OrderUnit* orderUnit, long orderRefId, char buysell, char openclose, double submitPrice, double qty, int validType);
	TradeUnit* getTradeUnit(int quoteNo);
	TradeUnit* getTradeUnit(int tradePlatform, string quoteId);
	int decomposeOrder(TradeUnit* tradeUnit, OrderItem* poi);
	int decomposeOrderByDefault(TradeUnit* tradeUnit, OrderItem* poi);
	int decomposeOrderByStep(TradeUnit* tradeUnit, OrderItem* poi);
	int submitComboOrder(ComboOrder* comboOrder);
	int createComboOrder(long& comboRefId,  char buysell, char openclose, double qty, int orderType, int validType, double skippage, int orderRank, int submitter);
	int updateComboOrder(long& comboRefId,  char buysell, char openclose, double qty, int validType, double skippage);
	void updateTradeUnitPosition(TradeUnit* tradeUnit, TradeItem* ti);
	bool double_divide(double divisor , double dividend);
	ComboPosition* getComboPosition(int pos_ago);
};