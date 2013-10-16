#include "TradeItem.h"

#include <sstream>
#include "LogHandler.h"
using std::stringstream;

void TradeItem::log()
{
    stringstream str;
    str << "TradeItem: Account(" << account << ") "
        << "traderId(" << traderId << ") "
        << "tradePlatform(" << tradePlatform << ") "
        << "quoteId(" << quoteId << ") "
        << "action(" << action << ") "
        << "tradePrice(" << tradePrice << ") "
        << "tradeNo(" << tradeNo << ") "
        << "submitPrice(" << submitPrice << ") "
        << "qty(" << qty << ") "
        << "buysell(" << buysell << ") "
        << "orderType(" << orderType << ") "
        << "validType(" << validType << ") "
        << "status(" << status << ") "
        << "orderNo(" << orderNo << ") "
        << "orderRefId(" << orderRefId << ") "
        << "positionSize(" << positionSize << ") "
        << "openclose(" << openclose << ") "
        << "tradeRecordNo(" << tradeRecordNo << ") "
        << "tradeTime(" << tradeTime << ")";
    LogHandler::getLogHandler().log(str.str());
}
