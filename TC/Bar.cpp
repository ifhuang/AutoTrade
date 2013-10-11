#include "Bar.h"

#include <sstream>
#include "LogHandler.h"
using namespace std;

void Bar::log() const
{
    stringstream ss;
    ss << "||||Bar|||||low(" << low << ") ";
    if (open > close) {
        ss << "close(" << close << ") open(" << open << ") ";
    }
    else {
        ss << "open(" << open << ") close(" << close << ") ";
    }
    ss << "high(" << high << ")";
    LogHandler::getLogHandler().log(ss.str());
}
