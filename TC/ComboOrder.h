#ifndef __COMBO_ORDER__
#define __COMBO_ORDER__
#include <list>
#include <string> 
#include "constants.h"
#include "OrderItem.h"
#include "QuoteItem.h"

class OrderUnit
{
private:
    int qouteNo;
    double qty;
    char buysell;
    int status;
    long orderRefId;
    int rankId;
    OrderItem* orderItem;
    int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1;

public:

    bool comp(const OrderUnit* lpou, const OrderUnit* rpou)
    {
        return lpou->rankId < rpou->rankId;
    }

    void setRankId(int rankId)
    {
        this->rankId = rankId;
    }
    int getRankId()
    {
        return this->rankId;
    }

    char getBuySell()
    {
        return this->buysell;
    }
    int getQuoteNo()
    {
        return this->qouteNo;
    }
    double getQty()
    {
        return this->qty;
    }

    OrderUnit(int quoteNo, double qty, char buysell, int rankId)
    {
        this->qouteNo = quoteNo;
        this->qty = qty;
        this->buysell = buysell;
        this->rankId = rankId;
        this->status = WAITING;
    }

    void setStatus(int status)
    {
        this->status = status;
    }

    int getStatus()
    {
        return this->status;
    }

    void setOrderRefId(long orderRefId)
    {
        this->orderRefId = orderRefId;
    }
    long getOrderRefId()
    {
        return this->orderRefId;
    }

    void setOrderItem(OrderItem* orderItem)
    {
        this->orderItem = orderItem;
    }

    // by xie
    OrderItem* getOrderItem() const
    {
        return this->orderItem;
    }
};

class ComboOrder
{
private:
    string openclose;
    double qty;
    char buysell;
    int orderType;
    int validType;
    int status;  // waiting=0; working=1; partiltraded=8
    list<OrderUnit*>* orderTemplate;
    string formula;
    double skippage;
    long comboRefId;
    int orderRank;
    int counter;
    int timespan;
    int submitter;
public:

    ComboOrder(char buysell, string openclose, double qty, int orderType,
        int validType, double skippage, list<OrderUnit*>* orderTemplate, int orderRank, int submitter);

    list<OrderUnit*>* getOrderTemplate()
    {
        return this->orderTemplate;
    }
    int getSubmitter()
    {
        return this->submitter;
    }
    void addCounter()
    {
        counter++;
    }
    int getCounter()
    {
        return this->counter;
    }
    void setOrderRank(int orderRank)
    {
        this->orderRank = orderRank;
    }

    int getOrderRank()
    {
        return this->orderRank;
    }

    string getOpenClose()
    {
        return this->openclose;
    }
    char getBuySell()
    {
        return this->buysell;
    }
    double getQty()
    {
        return this->qty;
    }

    int getValidType()
    {
        return this->validType;
    }

    int getOrderType()
    {
        return this->orderType;
    }

    OrderUnit* getOrderUnit(long orderRefId);

    bool isAllOrderTraded();

    void setOrderRankId(int rankNum, int rankId[]);

    void setTimespan(int timespan)
    {
        this->timespan = timespan;
    }

    int getTimespan()
    {
        return this->timespan;
    }

    void updateStatus();

    
    long getComboRefId()
    {
        return this->comboRefId;
    }
    void setComboRefId(long refId)
    {
        this->comboRefId = refId;
    }
};



class ComboPosition
{
private:
    int longshort;
    double size;
    list<ComboOrder*> comboOrderList;
public:

    void setLongShort(int longshort)
    {
        this->longshort = longshort;
    }

    int getLongShort()
    {
        return longshort;
    }

    void setSize(double size)
    {
        this->size = size;
    }

    double getSize()
    {
        return this->size;
    }

    void addComboOrder(ComboOrder* comboOrder)
    {
        comboOrderList.push_front(comboOrder);
    }

    list<ComboOrder*>& getComboOrderList()
    {
        return this->comboOrderList;
    }
    void setComboOrderList(list<ComboOrder*> orderList)
    {
        this->comboOrderList = orderList;
    }
};
#endif