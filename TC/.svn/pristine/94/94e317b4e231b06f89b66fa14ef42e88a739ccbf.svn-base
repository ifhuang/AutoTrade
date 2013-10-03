#ifndef __ORDERITEM__
#define __ORDERITEM__

#include <string> 
#include <iostream>
#include <sstream>
#include "LogHandler.h"
using namespace std; 

class OrderItem
{
private:
	int tradePlatform;
	string quoteId;
	int action;
	double submitPrice;
	double qty;
	double tradedQty;
	char buysell;
	int orderType;
	int validType;
	int status;
	int orderNo;
	long orderRefId;
	char openclose;
	double originalPrice;
	double originalQty;
	int returnCode;
	string returnMessage;
	long comboRefId;
	int parentRefId;
	long counter;
	int submitter; 
	int traderId;
	string account;
	time_t validTime;
	

public:

	OrderItem()
	{
	}

	OrderItem(int tradePlatform, string quoteId, double submitPrice, double qty, char buysell,  int orderType, int validType, char openclose)
	{
		this->tradePlatform = tradePlatform;
		this->quoteId = quoteId;
		this->submitPrice = submitPrice;
		this->qty = qty;
		this->buysell = buysell;
		this->orderType = orderType;
		this->validType = validType;
		this->openclose = openclose;
		this->counter = 1;
		this->tradedQty = 0;
		this->parentRefId = 0;
		this->originalPrice = submitPrice;
		this->originalQty = qty;
		this->orderNo = 0;
		this->orderRefId = 0;
		this->returnCode = 0;
	}

	void setAccount(string account)
	{
		this->account = account;
	}
	string getAccount()
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

	void addCounter()
	{
		this->counter++;
	}
	 
	long getCounter()
	{
		return this->counter;
	}

	void addTradedQty(double qty)
	{
		this->tradedQty += qty;
	}

	double getTradedQty()
	{
		return this->tradedQty;
	}

	void setSubmitter(int submitter)
	{
		this->submitter = submitter;
	}

	int getSubmitter()
	{
		return this->submitter;
	}

	int getParentRefId()
	{
		return this->parentRefId;
	}
	void setParentRefId(int parentRefId)
	{
		this->parentRefId = parentRefId;
	}

	void setComboRefId(long refId)
	{
		this->comboRefId = refId;
	}

	long getComboRefId()
	{
		return this->comboRefId;
	}

	void setReturnCode(int returnCode)
	{
		this->returnCode = returnCode;
	}
	int getReturnCode()
	{
		return this->returnCode;
	}
	void setReturnMessage(string message)
	{
		this->returnMessage= message;
	}
	string getReturnMessage()
	{
		return this->returnMessage;
	}

	void setOriginalPrice(double originalPrice)
	{
		this->originalPrice = originalPrice;
	}
	double getOriginalPrice()
	{
		return this->originalPrice;
	}
	void setOriginalQty(double originalQty)
	{
		this->originalQty = originalQty;
	}
	double getOriginalQty()
	{
		return this->originalQty;
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
	void setAction(int action)
	{
		this->action = action;
	}
	void setSubmitPrice(double submitPrice)
	{
		this->submitPrice = submitPrice;
	}
	void setQty(double qty){
		this->qty = qty;
	}
	void setBuySell(char buysell)
	{
		this->buysell = buysell;
	}
	void setOrderType(int orderType)
	{
		this->orderType = orderType;
	}
	void setValidType(int validType)
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
	void setOpenClose(char openclose)
	{
		this->openclose = openclose;
	}

	string getQuoteId()
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
	double getQty(){
		return this->qty;
	}
	char getBuySell()
	{
		return this->buysell;
	}
	int getOrderType()
	{
		return this->orderType;
	}
	int getValidType()
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
	char getOpenClose()
	{
		return this->openclose;
	}
	time_t getValidTime() const {
		return this->validTime;
	}
	void setValidTime(time_t t) {
		this->validTime = t;
	}
	void log() const {
		stringstream str;
		string actionString = "";
		if (action == 1) actionString = "Add";
		else if (action == 2) actionString = "Change";
		else if (action == 3) actionString = "Delete";
		str << actionString << " order(" << orderRefId << "): " 
			<< buysell << " " << quoteId << " SubmitPrice(" << submitPrice 
			<< ") OriginalPrice(" << originalPrice << ") Qty("  << qty
			<< ") OriginalQty(" << originalQty << ") tradedQty(" << tradedQty
			<< ") status(" << status << ") OpenClose(" << openclose 
			<< ") OrderNo(" << orderNo << ") ComboRefID(" << comboRefId
			<< ") ParentRefID(" << parentRefId << ") TraderID(" << traderId
			<< ") OrderType(" << orderType << ") ValidType(" << validType
			<< ") ReturnCode(" << returnCode << ") ReturnMessage(" << returnMessage << ")";	
		
		LogHandler::getLogHandler().log(str.str());
	}
};
#endif