#include "string_processor.h"

#include <vector>
#ifndef Q_MOC_RUN
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>
#endif
#include "constants.h"

using std::string;
using std::vector;
using boost::bad_lexical_cast;
using boost::lexical_cast;

namespace{
    class Spliter
    {
    public:
        Spliter(string str)
        {
            boost::split(message_split, str, boost::is_any_of(","));
        }

        bool Exists(size_t idx)
        {
            return message_split.size() > idx;
        }

        template<class T>
        T Get(size_t idx)
        {
            if (!Exists(idx))return T();
            return lexical_cast<T>(message_split[idx]);
        }

    private:
        vector<string> message_split;
    };
}

PriceItem* StringProcessor::StringToPriceItem(std::string price_str)
{
    Spliter spliter(price_str);
    PriceItem* pi = new PriceItem();
    pi->tradePlatform = SPTRADER;
    try
    {
        pi->quoteId           = spliter.Get<string>(2);
        pi->quoteName         = spliter.Get<string>(3);
        pi->qouteType         = spliter.Get<int>(4);
        pi->contractSize      = spliter.Get<int>(5);
        pi->ExpiryDate        = spliter.Get<int>(6);
        pi->instrumentCode    = spliter.Get<string>(7);
        pi->currency          = spliter.Get<string>(8);
        pi->strike            = spliter.Get<double>(9);
        pi->callPut           = spliter.Get<string>(10)[0];
        pi->underlying        = spliter.Get<string>(11);
        pi->bidPrice1         = spliter.Get<double>(12);
        pi->bidQty1           = spliter.Get<int>(13);
        pi->bidPrice2         = spliter.Get<double>(14);
        pi->bidQty2           = spliter.Get<int>(15);
        pi->bidPrice3         = spliter.Get<double>(16);
        pi->bidQty3           = spliter.Get<int>(17);
        pi->bidPrice4         = spliter.Get<double>(18);
        pi->bidQty4           = spliter.Get<int>(19);
        pi->bidPrice5         = spliter.Get<double>(20);
        pi->bidQty5           = spliter.Get<int>(21);
        pi->askPrice1         = spliter.Get<double>(22);
        pi->askQty1           = spliter.Get<int>(23);
        pi->askPrice2         = spliter.Get<double>(24);
        pi->askQty2           = spliter.Get<int>(25);
        pi->askPrice3         = spliter.Get<double>(26);
        pi->askQty3           = spliter.Get<int>(27);
        pi->askPrice4         = spliter.Get<double>(28);
        pi->askQty4           = spliter.Get<int>(29);
        pi->askPrice5         = spliter.Get<double>(30);
        pi->askQty5           = spliter.Get<int>(31);
        pi->lastPrice1        = spliter.Get<double>(32);
        pi->lastQty1          = spliter.Get<int>(33);
        pi->lastPrice2        = spliter.Get<double>(34);
        pi->lastQty2          = spliter.Get<int>(35);
        pi->lastPrice3        = spliter.Get<double>(36);
        pi->lastQty3          = spliter.Get<int>(37);
        pi->lastPrice4        = spliter.Get<double>(38);
        pi->lastQty4          = spliter.Get<int>(39);
        pi->lastPrice5        = spliter.Get<double>(40);
        pi->lastQty5          = spliter.Get<int>(41);
        pi->openInterest      = spliter.Get<int>(42);
        pi->turnOverAmount    = spliter.Get<double>(43);
        pi->turnOverVolume    = spliter.Get<int>(44);
        pi->equilibriumPrice  = spliter.Get<double>(47);
        pi->openD             = spliter.Get<double>(48);
        pi->highD             = spliter.Get<double>(49);
        pi->lowD              = spliter.Get<double>(50);
        pi->previousClose     = spliter.Get<double>(51);
        pi->previousCloseDate = spliter.Get<double>(52);
        pi->tradeStateNo      = spliter.Get<double>(54);
    }
    catch (bad_lexical_cast &)
    {
        delete pi;
        return nullptr;
    }
    return pi;
}

Position* StringProcessor::StringToPosition(std::string order_str)
{
    Spliter spliter(order_str);
    Position* pos = new Position();
    try
    {
        pos->accountNo = spliter.Get<string>(2);
        pos->setQuoteId(spliter.Get<string>(3));
        pos->preqty = spliter.Get<int>(4);
        pos->preavg = spliter.Get<double>(5);
        pos->longqty = spliter.Get<int>(6);
        pos->longavg = spliter.Get<double>(7);
        pos->shortqty = spliter.Get<int>(8);
        pos->shortavg = spliter.Get<double>(9);
        pos->netqty = spliter.Get<int>(10);
        pos->netavg = spliter.Get<double>(11);
    }
    catch (bad_lexical_cast &)
    {
        delete pos;
        return nullptr;
    }
    return pos;
}

OrderItem* StringProcessor::StrintToOrderItem(string order_str)
{
    Spliter spliter(order_str);
    if (spliter.Get<string>(2) != "0")
    {
        LogHandler::getLogHandler().alert(1, "",
            "order is not correctly processed by server! Maybe the order has been deleted or traded.("
            + order_str + ")");
        return nullptr;
    }
    OrderItem* oi = new OrderItem();
    oi->setTradePlatform(SPTRADER);
    try
    {
        oi->setReturnCode(spliter.Get<int>(2));
        oi->setReturnMessage(spliter.Get<string>(3));
        oi->setStatus(spliter.Get<int>(4));
        oi->setAction(spliter.Get<int>(5));
        oi->setAccount(spliter.Get<string>(6));
        oi->setOrderNo(spliter.Get<int>(7));
        oi->setQuoteId(spliter.Get<string>(8));
        oi->setBuySell(spliter.Get<string>(9)[0]);
        oi->setSubmitPrice(spliter.Get<double>(10));
        oi->setQty(spliter.Get<double>(2));
        oi->setOpenClose(spliter.Get<string>(12));
        oi->setValidType(spliter.Get<int>(14));
        string ref = spliter.Get<string>(16);
        if (!ref.empty())
        {
            char tmp2[20] = "";
            char *elem2 = NULL;
            char *delims2 = ":";
            strcpy(tmp2, ref.c_str());
            elem2 = strtok(tmp2, delims2);
            elem2 = strtok(NULL, delims2);
            oi->setTraderId(atoi(elem2));
            elem2 = strtok(NULL, delims2);
            oi->setOrderRefId(atol(elem2));
        }
        oi->setOriginalPrice(spliter.Get<double>(17));
        oi->setOriginalQty(spliter.Get<double>(18));
    }
    catch (bad_lexical_cast &)
    {
        delete oi;
        return nullptr;
    }
    return oi;
}
