#ifndef __PRICEITEM__
#define __PRICEITEM__
#include <string> 
#include <iostream>
#include <sstream>
#include "LogHandler.h"
using namespace std; 

class PriceItem
{
public:
	int tradePlatform;
	string quoteId;
	string quoteName;
	int qouteType; // Futures=1; Options=2; Spreads=3;
	int contractSize;
	int ExpiryDate; // 
	string instrumentCode;
	string currency;
	double strike;
	char callPut;
	string underlying;
	int openInterest;
	double turnOverAmount;
	int turnOverVolume;
	double equilibriumPrice;
	double openD;
	double highD;
	double lowD;
	double previousClose;
	double previousCloseDate;
	double tradeStateNo; // Undefined=0;preopen=1;pre_open_alloc=2;open_alloc=3;pause=4;open=5;close=6;pre_market_activity=7
	
	double lastPrice1;
	int lastQty1;
	double lastPrice2;
	int lastQty2;
	double lastPrice3;
	int lastQty3;
	double lastPrice4;
	int lastQty4;
	double lastPrice5;
	int lastQty5;

	double bidPrice1;
	int bidQty1;
	double bidPrice2;
	int bidQty2;
	double bidPrice3;
	int bidQty3;
	double bidPrice4;
	int bidQty4;
	double bidPrice5;
	int bidQty5;

	double askPrice1;
	int askQty1;
	double askPrice2;
	int askQty2;
	double askPrice3;
	int askQty3;
	double askPrice4;
	int askQty4;
	double askPrice5;
	int askQty5;
	
	void log() const {
		stringstream str;
		str << "Price Detail(" << quoteId << ")";
		str << " ask price: " << askPrice1 << "(" << askQty1 << ") "
							<< askPrice2 << "(" << askQty2 << ") "
							<< askPrice3 << "(" << askQty3 << ") "
							<< askPrice4 << "(" << askQty4 << ") "
							<< askPrice5 << "(" << askQty5 << ")";	

		str << " bid price: " << bidPrice1 << "(" << bidQty1 << ") "
							<< bidPrice2 << "(" << bidQty2 << ") "
							<< bidPrice3 << "(" << bidQty3 << ") "
							<< bidPrice4 << "(" << bidQty4 << ") "
							<< bidPrice5 << "(" << bidQty5 << ")";	

		str << " last price: " << lastPrice1 << "(" << lastQty1 << ") "
							<< lastPrice2 << "(" << lastQty2 << ") "
							<< lastPrice3 << "(" << lastQty3 << ") "
							<< lastPrice4 << "(" << lastQty4 << ") "
							<< lastPrice5 << "(" << lastQty5 << ")";	
		char buff[256] = {0}; 
		if (currentTime > 0) {
			strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S",localtime(&currentTime)); 
			str << " " << buff;
		}
		LogHandler::getLogHandler().log(str.str());
	}

	time_t currentTime;
};
#endif