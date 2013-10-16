#ifndef __POSITION__
#define __POSITION__

#include <list>
#include "TradeItem.h"

class Position
{
private:
	int tradePlatform;
	int longshort;
	std::string quoteId;
	double size;
    std::list<TradeItem*> tradeList;
public:
    std::string accountNo;
	int preqty; 
	double preavg; 
	int longqty;
	double longavg;
	int shortqty;
	double shortavg;
	int netqty;
	double netavg;
	void log();

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
    void setQuoteId(std::string quoteId)
	{
		this->quoteId = quoteId;
	}

    std::string getQuoteId()
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

    std::list<TradeItem*>& getTradeList()
	{
		return this->tradeList;
	}
};
#endif