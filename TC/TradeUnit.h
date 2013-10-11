#ifndef __TRADE_UNIT__
#define __TRADE_UNIT__
#include <tchar.h>
#include <time.h>
#include <iostream>
#include <map>
#include <string> 
#include <vector>
#include <direct.h>
#include <io.h>
#include <windows.h>
#include "TradeCube.h"

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
    int getStepTickNum() const
    {
        return stepTickNum;
    }

    void setStepTickNum(int num)
    {
        this->stepTickNum = num;
    }

    double getStepMoney() const
    {
        return stepMoney;
    }

    void setStepMoney(double money)
    {
        this->stepMoney = money;
    }

    double getStepQty() const
    {
        return stepQty;
    }

    void setStepQty(double qty)
    {
        this->stepQty = qty;
    }
protected:
    int saveTradeRecord();
    int openPriceFile();
    int savePrice();
private:
    QuoteItem* quote;
    PriceItem* price, *tickPrice;
    map<long, TradeItem*> tradeQueue;
    vector<Position*> positionQueue;
    map<long, OrderItem*> orderQueue;
    map<long, OrderItem*> orderFlow;
    FILE* pricefp, *tradefp;

    // added by xie
    vector<Bar*> bars;
    int barPeriod; // unit=second
    time_t barStartTime, timeDiff;
    int stepTickNum;
    double stepMoney;
    double stepQty;
    int maxRefBarNum;
};
#endif