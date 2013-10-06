#ifndef __COMBO_ORDER__
#define __COMBO_ORDER__
#include <list>
#include <string> 
#include "OrderItem.h"
#include "QuoteItem.h"

class OrderUnit
{
private:
	int qouteNo;
	double qty;
	char buysell;
	int status;
	long orderRefId;
	int rankId;
	OrderItem* orderItem;
	int optimizeOrderFlow; // NO_OPTIMIZE_OFP=0, OPTIMIZE_OFP=1;

public:

	bool comp(const OrderUnit* lpou, const OrderUnit* rpou)
	{
		return lpou->rankId < rpou->rankId ;
	}

	void setRankId(int rankId)
	{
		this->rankId = rankId;
	}
	int getRankId()
	{
		return this->rankId;
	}
	
	char getBuySell()
	{
		return this->buysell;
	}
	int getQuoteNo()
	{
		return this->qouteNo;
	}
	double getQty()
	{
		return this->qty;
	}

	OrderUnit(int quoteNo, double qty, char buysell, int rankId)
	{
		this->qouteNo = quoteNo;
		this->qty =qty;
		this->buysell = buysell;
		this->rankId = rankId;
		this->status = WAITING;
	}

	void setStatus(int status)
	{
		this->status = status;
	}
	
	int getStatus()
	{
		return this->status;
	}

	void setOrderRefId(long orderRefId)
	{
		this->orderRefId = orderRefId;
	}
	long getOrderRefId()
	{
		return this->orderRefId;
	}

	void setOrderItem(OrderItem* orderItem)
	{
		this->orderItem = orderItem;
	}

	// by xie
	OrderItem* getOrderItem() const 
	{
		return this->orderItem;
	}
};

class ComboOrder
{
private:
	char openclose;
	double qty;
	char buysell;
	int orderType;
	int validType;
	int status;  // waiting=0; working=1; partiltraded=8
	list<OrderUnit*>* orderTemplate;
	string formula;
	double skippage;
	long comboRefId;
	int orderRank;
	int counter;
	int timespan;
	int submitter;
public:

	
	list<OrderUnit*>* getOrderTemplate()
	{
		return this->orderTemplate;
	}
	int getSubmitter()
	{
		return this->submitter;
	}
	void addCounter()
	{
		counter++;
	}
	int getCounter()
	{
		return this->counter;
	}
	void setOrderRank(int orderRank)
	{
		this->orderRank = orderRank;
	}

	int getOrderRank()
	{
		return this->orderRank;
	}

	char getOpenClose()
	{
		return this->openclose;
	}
	char getBuySell()
	{
		return this->buysell;
	}
	double getQty()
	{
		return this->qty;
	}

	int getValidType()
	{
		return this->validType;
	}

	int getOrderType()
	{
		return this->orderType;
	}

	OrderUnit* getOrderUnit(long orderRefId)
	{
		OrderUnit* ou = NULL;
		list<OrderUnit*>::iterator iter;
		for(iter=orderTemplate->begin(); iter!=orderTemplate->end(); iter++)
		{
			ou = *iter;
			if(ou->getOrderRefId() == orderRefId)
				break;
		}
		return ou;
	}

	bool isAllOrderTraded()
	{
		list<OrderUnit*>::iterator iter;
		for(iter=orderTemplate->begin(); iter!=orderTemplate->end(); iter++)
		{
			if((*iter)->getStatus() != ALLTRADED)
					return false;
		}			
		return true;
	}

	void setOrderRankId(int rankNum, int rankId[])
	{
		if(orderTemplate->size()>1 && rankNum>=orderTemplate->size()){
			list<OrderUnit*>::iterator iter;
			int i = 0;
			for(iter=orderTemplate->begin(); iter!=orderTemplate->end(); iter++)
			{
				(*iter)->setRankId(rankId[i]);
				i++;
			}
		}
	}

	void setTimespan(int timespan)
	{
		this->timespan = timespan;
	}

	int getTimespan()
	{
		return this->timespan;
	}

	void updateStatus()
	{
		int flag = 0;
		list<OrderUnit*>::iterator iter;
		if(this->status == WAITING)
		{
			for(iter=orderTemplate->begin(); iter!=orderTemplate->end(); iter++)
			{
				if((*iter)->getStatus() == WORKING)
					status = ADDING;
				if((*iter)->getStatus() == WAITING)
					flag = 1;
			}
			if(status==ADDING && flag==1)
				status = ADDING;
			else if(status==ADDING && flag ==0)
				status = WORKING;
		}
		flag = 0;
		if(this->status == WORKING)
		{
			for(iter=orderTemplate->begin(); iter!=orderTemplate->end(); iter++)
			{
				if((*iter)->getStatus() == ALLTRADED)
					status = PARTIALTRADED;
				if((*iter)->getStatus() == WORKING)
					flag = 1;
			}
			if(status==PARTIALTRADED && flag==1)
				status = PARTIALTRADED;
			else if(status==PARTIALTRADED && flag==0)
				status = ALLTRADED;
		}		
	}

	ComboOrder(char buysell, char openclose, double qty, int orderType,int validType, double skippage, list<OrderUnit*>* orderTemplate, int orderRank, int submitter)
	{
		this->buysell = buysell;
		this->openclose = openclose;
		this->qty = qty;
		this->orderType = orderType;
		this->validType = validType;
		this->skippage = skippage;
		this->orderTemplate = orderTemplate;
		this->submitter = submitter;
		this->status = WAITING;
		this->orderRank = orderRank;
		this->counter = 1;
		this->timespan = 0;
	}

	long getComboRefId()
	{
		return this->comboRefId;
	}
	void setComboRefId(long refId)
	{
		this->comboRefId = refId;
	}
};



class ComboPosition
{
private:
	int longshort;
	double size;
	list<ComboOrder*> comboOrderList;
public:

	void setLongShort(int longshort)
	{
		this->longshort = longshort;
	}

	int getLongShort()
	{
		return longshort;
	}

	void setSize(double size)
	{
		this->size = size;
	}

	double getSize()
	{
		return this->size;
	}

	void addComboOrder(ComboOrder* comboOrder)
	{
		comboOrderList.push_front(comboOrder);
	}

	list<ComboOrder*>& getComboOrderList()
	{
		return this->comboOrderList;
	}
	 void setComboOrderList(list<ComboOrder*> orderList)
	 {
		 this->comboOrderList = orderList;
	 }
};
#endif