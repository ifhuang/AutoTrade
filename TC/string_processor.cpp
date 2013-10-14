#include "string_processor.h"

#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>
#include "constants.h"

using std::string;
using std::vector;
using boost::bad_lexical_cast;
using boost::lexical_cast;

PriceItem* StringProcessor::StringToPriceItem(std::string price_str)
{
    vector<string> price_split;
    boost::split(price_split, price_str, boost::is_any_of(","));
    PriceItem* pi = new PriceItem();
    pi->tradePlatform = SPTRADER;
    pi->quoteId = price_split[2];
    pi->quoteName = price_split[3];
    pi->qouteType = atoi(price_split[4].c_str());
    pi->contractSize = atoi(price_split[5].c_str());
    pi->ExpiryDate = atoi(price_split[6].c_str());
    pi->instrumentCode = price_split[7];
    pi->currency = price_split[8];
    pi->strike = atof(price_split[9].c_str());
    pi->callPut = price_split[10][0];
    pi->underlying = price_split[11];
    pi->bidPrice1 = atof(price_split[12].c_str());
    pi->bidQty1 = atoi(price_split[13].c_str());
    pi->bidPrice2 = atof(price_split[14].c_str());
    pi->bidQty2 = atoi(price_split[15].c_str());
    pi->bidPrice3 = atof(price_split[16].c_str());
    pi->bidQty3 = atoi(price_split[17].c_str());
    pi->bidPrice4         = atof(price_split[18].c_str());
    pi->bidQty4           = atoi(price_split[19].c_str());
    pi->bidPrice5         = atof(price_split[20].c_str());
    pi->bidQty5           = atoi(price_split[21].c_str());
    pi->askPrice1         = atof(price_split[22].c_str());
    pi->askQty1           = atoi(price_split[23].c_str());
    pi->askPrice2         = atof(price_split[24].c_str());
    pi->askQty2           = atoi(price_split[25].c_str());
    pi->askPrice3         = atof(price_split[26].c_str());
    pi->askQty3           = atoi(price_split[27].c_str());
    pi->askPrice4         = atof(price_split[28].c_str());
    pi->askQty4           = atoi(price_split[29].c_str());
    pi->askPrice5         = atof(price_split[30].c_str());
    pi->askQty5           = atoi(price_split[31].c_str());
    pi->lastPrice1        = atof(price_split[32].c_str());
    pi->lastQty1          = atoi(price_split[33].c_str());
    pi->lastPrice2        = atof(price_split[34].c_str());
    pi->lastQty2          = atoi(price_split[35].c_str());
    pi->lastPrice3        = atof(price_split[36].c_str());
    pi->lastQty3          = atoi(price_split[37].c_str());
    pi->lastPrice4        = atof(price_split[38].c_str());
    pi->lastQty4          = atoi(price_split[39].c_str());
    pi->lastPrice5        = atof(price_split[40].c_str());
    pi->lastQty5          = atoi(price_split[41].c_str());
    pi->openInterest      = atoi(price_split[42].c_str());
    pi->turnOverAmount    = atof(price_split[43].c_str());
    pi->turnOverVolume    = atoi(price_split[44].c_str());
    pi->equilibriumPrice  = atof(price_split[47].c_str());
    pi->openD             = atof(price_split[48].c_str());
    pi->highD             = atof(price_split[49].c_str());
    pi->lowD              = atof(price_split[50].c_str());
    pi->previousClose     = atof(price_split[51].c_str());
    pi->previousCloseDate = atof(price_split[52].c_str());
    pi->tradeStateNo      = atof(price_split[54].c_str());
    return pi;
}

Position* StringProcessor::StringToPosition(std::string order_str)
{
    vector<string> message_split;
    boost::split(message_split, order_str, boost::is_any_of(","));
    Position* pos = new Position();
    pos->accountNo = message_split[2];
    pos->setQuoteId(message_split[3]);
    try
    {
        pos->preqty = lexical_cast<int>(message_split[4]);
        pos->preavg = lexical_cast<double>(message_split[5]);
        pos->longqty = lexical_cast<int>(message_split[6]);
        pos->longavg = lexical_cast<double>(message_split[7]);
        pos->shortqty = lexical_cast<int>(message_split[8]);
        pos->shortavg = lexical_cast<double>(message_split[9]);
        pos->netqty = lexical_cast<int>(message_split[10]);
        pos->netavg = lexical_cast<double>(message_split[11]);
    }
    catch (bad_lexical_cast &)
    {
        delete pos;
        return nullptr;
    }
    return pos;
}
