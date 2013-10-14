#ifndef __QUOTEITEM__
#define __QUOTEITEM__
#include <string> 
using namespace std; 

// 品种
class QuoteItem
{
public:
	void setMinContractQty(int minqty)
	{
		this->minContractQty = minqty;
	}
	double getMinContractQty()
	{
		return this->minContractQty;
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
	void setExchange(string exchange)
	{
		this->exchange = exchange;
	}
	void setMargin(double margin)
	{
		this->margin = margin;
	}
	void setPriceScale(double priceScale)
	{
		this->priceScale = priceScale;
	}
	void setBigPointValue(double bigPointValue)
	{
		this->bigPointValue = bigPointValue;
	}

	string getQuoteId()
	{
		return this->quoteId;
	}

	string getExchange()
	{
		return this->exchange;
	}
	double getMargin()
	{
		return this->margin;
	}
	double getPriceScale()
	{
		return this->priceScale;
	}
	double getBigPointValue()
	{
		return this->bigPointValue;
	}
private:
	int tradePlatform;
	string quoteId;
	string exchange;
	double margin;
	double priceScale;
	double bigPointValue;
	double minContractQty; 
};
#endif