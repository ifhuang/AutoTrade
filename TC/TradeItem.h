#ifndef __TRADEITEM__
#define __TRADEITEM__

#include <string> 
#ifndef Q_MOC_RUN
#include <boost/date_time/posix_time/posix_time.hpp>
#endif

class TradeItem
{
private:
	std::string account;
	int traderId;
	int tradePlatform;
    std::string quoteId;
	int action;
	double tradePrice;
	long tradeNo;
	double submitPrice;
	//double qty;//why double ??
	int qty;
	char buysell;
	char orderType;
	char validType;
	int status;
	int orderNo;
	long orderRefId;
	int positionSize;
    std::string openclose;
	int tradeRecordNo;
    boost::posix_time::ptime tradeTime;

public:

	void setTradeRecordNo(int tradeRecordNo)
	{
		this->tradeRecordNo = tradeRecordNo;
	}

	int getTradeRecordNo() const
	{
		return this->tradeRecordNo;
	}

    void setAccount(std::string account)
	{
		this->account = account;
	}

    std::string getAccount()
	{
		return this->account;
	}

	void setTraderId(int traderId)
	{
		this->traderId = traderId;
	}

	int getTraderId()
	{
		return this->traderId;
	}

	void setTradePlatform(int tradePlatform)
	{
		this->tradePlatform = tradePlatform;
	}

	int getTradePlatform()
	{
		return this->tradePlatform;
	}

	void setTradePrice(double tradePrice)
	{
		this->tradePrice = tradePrice;
	}

	void setTradeNo(long tradeNo)
	{
		this->tradeNo = tradeNo;
	}

	void setPositionSize(int positionSize)
	{
		this->positionSize = positionSize;
	}
	
    void setTradeTime(boost::posix_time::ptime tradeTime)
	{
		this->tradeTime = tradeTime;
	}

    void setQuoteId(std::string quoteId)
	{
		this->quoteId = quoteId;
	}

	void setAction(int action)
	{
		this->action = action;
	}

	void setSubmitPrice(double submitPrice)
	{
		this->submitPrice = submitPrice;
	}

	void setQty(int qty)
    {
		this->qty = qty;
	}

	void setBuySell(char buysell)
	{
		this->buysell = buysell;
	}

	void setOrderType(char orderType)
	{
		this->orderType = orderType;
	}

	void setValidType(char validType)
	{
		this->validType = validType;
	}

	void setStatus(int status)
	{
		this->status = status;
	}

	void setOrderNo(int orderNo)
	{
		this->orderNo = orderNo;
	}

	void setOrderRefId(long orderRefId)
	{
		this->orderRefId = orderRefId;
	}

    void setOpenClose(std::string openclose)
	{
		this->openclose = openclose;
	}

    std::string getQuoteId()
	{
		return this->quoteId;
	}

	int getAction()
	{
		return this->action;
	}

	double getSubmitPrice()
	{
		return this->submitPrice;
	}

	int getQty(){
		return this->qty;
	}

	char getBuySell()
	{
		return this->buysell;
	}

	char getOrderType()
	{
		return this->orderType;
	}

	char getValidType()
	{
		return this->validType;
	}

	int getStatus()
	{
		return this->status;
	}

	int getOrderNo()
	{
		return this->orderNo;
	}

	long getOrderRefId()
	{
		return this->orderRefId;
	}

    std::string getOpenClose()
	{
		return this->openclose;
	}

	double getTradePrice()
	{
		return this->tradePrice;
	}

	long getTradeNo()
	{
		return this->tradeNo;
	}

	int getPositionSize()
	{
		return this->positionSize;
	}
	
    boost::posix_time::ptime getTradeTime()
	{
		return this->tradeTime;
	}

	void log();
    std::string ToString();
};
#endif
