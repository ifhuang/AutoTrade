#include "Position.h"

#include <sstream>
#include "LogHandler.h"
using std::stringstream;

void Position::log()
{
    stringstream str;
    str << "Position:accountNo(" << accountNo << ") "
        << "quoteID(" << quoteId << ") "
        << "preqty(" << preqty << ") "
        << "preavg(" << preavg << ") "
        << "longqty(" << longqty << ") "
        << "longav(" << longavg << ") "
        << "shortqty(" << shortqty << ") "
        << "shortavg(" << shortavg << ") "
        << "netqty(" << netqty << ") "
        << "netavg(" << netavg << ") ";
    LogHandler::getLogHandler().log(str.str());
}
