#include "OrderItem.h"

#include <iostream>
#include <sstream>
#include "LogHandler.h"
using namespace std;

OrderItem::OrderItem(string quoteId, double submitPrice,
    double qty, char buysell, int orderType, int validType, string openclose)
{
    this->init(quoteId, submitPrice, qty, buysell, orderType, validType, openclose);
}

void OrderItem::init(string quoteId, double submitPrice, double qty,
    char buysell, int orderType, int validType, string openclose)
{
    this->quoteId = quoteId;
    this->submitPrice = submitPrice;
    this->qty = qty;
    this->buysell = buysell;
    this->orderType = orderType;
    this->validType = validType;
    this->openclose = openclose;
    this->counter = 1;
    this->tradedQty = 0;
    this->parentRefId = 0;
    this->originalPrice = submitPrice;
    this->originalQty = qty;
    this->orderNo = 0;
    this->orderRefId = 0;
    this->returnCode = 0;
}

void OrderItem::log() const
{
    stringstream str;
    string actionString = "";
    if (action == 1) actionString = "Add";
    else if (action == 2) actionString = "Change";
    else if (action == 3) actionString = "Delete";
    str << actionString << " order(" << orderRefId << "): "
        << buysell << " " << quoteId << " SubmitPrice(" << submitPrice
        << ") OriginalPrice(" << originalPrice << ") Qty(" << qty
        << ") OriginalQty(" << originalQty << ") tradedQty(" << tradedQty
        << ") status(" << status << ") OpenClose(" << openclose
        << ") OrderNo(" << orderNo << ") ComboRefID(" << comboRefId
        << ") ParentRefID(" << parentRefId << ") TraderID(" << traderId
        << ") OrderType(" << orderType << ") ValidType(" << validType
        << ") ReturnCode(" << returnCode << ") ReturnMessage(" << returnMessage << ")";

    LogHandler::getLogHandler().log(str.str());
}