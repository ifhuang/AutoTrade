#ifndef __POSITION__
#define __POSITION__
#include <list>
#include <sstream>
#include "TradeItem.h"
#include "LogHandler.h"

class Position
{
private:
	int tradePlatform;
	int longshort;
	string quoteId;
	double size;
	list<TradeItem*> tradeList;
public:
	string accountNo;
	int preqty; 
	double preavg; 
	int longqty;
	double longavg;
	int shortqty;
	double shortavg;
	int netqty;
	double netavg;
	void log() {
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
	void setLongShort(int longshort)
	{
		this->longshort = longshort;
	}

	int getLongShort()
	{
		return longshort;
	}

	void setTradePlatform(int tradePlatform)
	{
		this->tradePlatform = tradePlatform;
	}
	int getTradePlatform()
	{
		return this->tradePlatform;
	}
	void setQuoteId(string quoteId)
	{
		this->quoteId = quoteId;
	}

	string getQuoteId()
	{
		return this->quoteId;
	}

	void setSize(double size)
	{
		this->size = size;
	}

	double getSize()
	{
		return this->size;
	}

	list<TradeItem*>& getTradeList()
	{
		return this->tradeList;
	}
};
#endif