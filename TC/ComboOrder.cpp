#include "ComboOrder.h"


ComboOrder::ComboOrder(char buysell, string openclose, double qty, int orderType,
    int validType, double skippage, list<OrderUnit*>* orderTemplate, int orderRank, int submitter)
{
    this->buysell = buysell;
    this->openclose = openclose;
    this->qty = qty;
    this->orderType = orderType;
    this->validType = validType;
    this->skippage = skippage;
    this->orderTemplate = orderTemplate;
    this->submitter = submitter;
    this->status = WAITING;
    this->orderRank = orderRank;
    this->counter = 1;
    this->timespan = 0;
}

OrderUnit* ComboOrder::getOrderUnit(long orderRefId)
{
    OrderUnit* ou = NULL;
    list<OrderUnit*>::iterator iter;
    for (iter = orderTemplate->begin(); iter != orderTemplate->end(); iter++)
    {
        ou = *iter;
        if (ou->getOrderRefId() == orderRefId)
            break;
    }
    return ou;
}

bool ComboOrder::isAllOrderTraded()
{
    list<OrderUnit*>::iterator iter;
    for (iter = orderTemplate->begin(); iter != orderTemplate->end(); iter++)
    {
        if ((*iter)->getStatus() != ALLTRADED)
            return false;
    }
    return true;
}

void ComboOrder::setOrderRankId(int rankNum, int rankId[])
{
    if (orderTemplate->size() > 1 && rankNum >= orderTemplate->size()){
        list<OrderUnit*>::iterator iter;
        int i = 0;
        for (iter = orderTemplate->begin(); iter != orderTemplate->end(); iter++)
        {
            (*iter)->setRankId(rankId[i]);
            i++;
        }
    }
}

void ComboOrder::updateStatus()
{
    int flag = 0;
    list<OrderUnit*>::iterator iter;
    if (this->status == WAITING)
    {
        for (iter = orderTemplate->begin(); iter != orderTemplate->end(); iter++)
        {
            if ((*iter)->getStatus() == WORKING)
                status = ADDING;
            if ((*iter)->getStatus() == WAITING)
                flag = 1;
        }
        if (status == ADDING && flag == 1)
            status = ADDING;
        else if (status == ADDING && flag == 0)
            status = WORKING;
    }
    flag = 0;
    if (this->status == WORKING)
    {
        for (iter = orderTemplate->begin(); iter != orderTemplate->end(); iter++)
        {
            if ((*iter)->getStatus() == ALLTRADED)
                status = PARTIALTRADED;
            if ((*iter)->getStatus() == WORKING)
                flag = 1;
        }
        if (status == PARTIALTRADED && flag == 1)
            status = PARTIALTRADED;
        else if (status == PARTIALTRADED && flag == 0)
            status = ALLTRADED;
    }
}
