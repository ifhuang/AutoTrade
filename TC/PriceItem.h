#ifndef __PRICEITEM__
#define __PRICEITEM__

#include <string> 
#include <boost/date_time/posix_time/posix_time.hpp>

class PriceItem
{
    
public:

    void log() const;

	int tradePlatform;
	std::string quoteId;
    std::string quoteName;
	int qouteType; // Futures=1; Options=2; Spreads=3;
	int contractSize;
	int ExpiryDate; // 
    std::string instrumentCode;
    std::string currency;
	double strike;
	char callPut;
    std::string underlying;
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

	boost::posix_time::ptime currentTime;
};
#endif