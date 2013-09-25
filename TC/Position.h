#include <list>
#include <string>
using namespace std;

class TradeItem;

class Position
{
private:
	int tradePlatform;
	int longshort;
    string quoteId;
	double size;
	list<TradeItem*> tradeList;
public:

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
