#ifndef __STRATEGY__
#define __STRATEGY__
class Strategy
{
private:	
	bool autoTrading;
	int maxRefBarNum;
	bool intraBarTrading;
	long counter;

public:
	void addCounter()
	{
		counter++;
	}
	long getCounter()
	{
		return this->counter;
	}
	void setMaxRefBarNum(int refbar)
	{
		this->maxRefBarNum = refbar;
	}
	void setIntraBarTrading(bool intraBarTrading)
	{
		this->intraBarTrading = intraBarTrading;
	}

	void setAutoTrading(bool autoTrading)
	{
		this->autoTrading = autoTrading;
	}
	int getMaxRefBarNum()
	{
		return this->maxRefBarNum;
	}
	bool getIntraBarTrading()
	{
		return this->intraBarTrading;
	}
	bool getAutoTrading()
	{
		return this->autoTrading;
	}
	Strategy()
	{
		maxRefBarNum = 50;
		intraBarTrading = false;
		autoTrading = false;
		counter = 0;
	}
	
	virtual void turnOffStrategy() 
	{
		setAutoTrading(false);
	};
	virtual void signal()=0;
};
#endif