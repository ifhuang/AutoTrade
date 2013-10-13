#include "PriceItem.h"

#include <sstream>
#include "LogHandler.h"

using std::string;
using std::stringstream;
using boost::date_time::not_a_date_time;
using boost::posix_time::to_iso_extended_string;

void PriceItem::log() const
{
    string a;
    stringstream str;
    str << "Price Detail(" << quoteId << ")";
    str << " ask price: " << askPrice1 << "(" << askQty1 << ") "
        << askPrice2 << "(" << askQty2 << ") "
        << askPrice3 << "(" << askQty3 << ") "
        << askPrice4 << "(" << askQty4 << ") "
        << askPrice5 << "(" << askQty5 << ")";

    str << " bid price: " << bidPrice1 << "(" << bidQty1 << ") "
        << bidPrice2 << "(" << bidQty2 << ") "
        << bidPrice3 << "(" << bidQty3 << ") "
        << bidPrice4 << "(" << bidQty4 << ") "
        << bidPrice5 << "(" << bidQty5 << ")";

    str << " last price: " << lastPrice1 << "(" << lastQty1 << ") "
        << lastPrice2 << "(" << lastQty2 << ") "
        << lastPrice3 << "(" << lastQty3 << ") "
        << lastPrice4 << "(" << lastQty4 << ") "
        << lastPrice5 << "(" << lastQty5 << ")";
    if (currentTime != not_a_date_time) {
        str << " " << to_iso_extended_string(currentTime);
    }
    LogHandler::getLogHandler().log(str.str());
}

