#include <vector>
#include <iostream>
#include <string> 
#include <map>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <list>
#include "Bar.h"
class OrderItem;
class TradeItem;
class PriceItem;
class Position;
class QuoteItem;

class TradeUnit
{
public:
	TradeUnit(QuoteItem* quote);
	TradeUnit();
	virtual ~TradeUnit();
	OrderItem* getOrder(long orderRefId);
	Position* getPosition(int pos_ago);
	TradeItem* getTrade(int tradeNo);
	Bar* getBar(int pos_ago);
	QuoteItem* getQuote();
	string getQuoteId();
	int getTradePlatform();
	PriceItem* getPrice();
	bool isBarsEnough();
	map<long, OrderItem*>& getOrderQueue();

	void setQuote(QuoteItem* quote);
	void updatePrice(PriceItem* price);
	void updateTickPrice(PriceItem* price);
	int addTrade(TradeItem* tradeRecord);
	void updateBars();
	int addPosition(Position* position);
	int addOrder(OrderItem* order);	
	int updateOrder(OrderItem* oi);
	int deleteOrder(long orderRefId);	
	void setMaxRefBarNum(int num);
protected:
	int saveTradeRecord();
	int openPriceFile();
	int savePrice();
private:
	QuoteItem* quote;
	PriceItem* price, *tickPrice;
	map<long, TradeItem*> tradeQueue;
	list<Position*> positionQueue;
	map<long, OrderItem*> orderQueue;
	map<long, OrderItem*> orderFlow;
	FILE* pricefp, *tradefp;
	vector<Bar*> bars;
	int barPeriod; // unit=second
	time_t barStartTime, timeDiff;

	int maxRefBarNum;
};