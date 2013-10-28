#ifndef __SPTRADER__
#define __SPTRADER__
#include <thread>
#include <boost/asio.hpp>
#include "global.h"
#include "Dispatcher.h" 
#include "TradeCube.h"

class SPTraderOrder;
class SPTraderPrice;
class SPTraderTicker;
class OrderMessageProcessor;

// 重构sptrader和dispatcher的关系
class SPTrader : public Dispatcher
{
public:
	~SPTrader();
    static SPTrader* GetSPTrader(PlatformInfo& platformInfo);

	int addQuote(QuoteItem *pQuoteItem);
	
	void stopOrderThread();
	int sendOrder(OrderItem* pOrderItem);
	bool isSupport(int orderType);
	int deleteQuote(QuoteItem *pQuoteItem);
	map<int, TradeItem*>& getDoneTrades();
	map<int, OrderItem*>& getCurrentOrders();
	void getPosition(Position& position);
private:
    friend OrderMessageProcessor;
    SPTrader(PlatformInfo& platformInfo);
	int login();
    bool startPriceThread();
    void startCheckConnection();
    void HitCheckConnection();
	void checkConnection();
    bool startTickerThread();
	int confirmTradeInfo(int tradeRecordNo);
	int confirmPriceInfo(string quoteId);
	
	OrderItem* str2UpdatedOrder(string orderStr);

    boost::asio::ip::tcp::resolver::iterator Resolve(int port);

    PlatformInfo platformInfo_;
	int timerInterval; // seconds

    boost::asio::io_service io_service_;
    boost::asio::ip::tcp::resolver resolver_;
    boost::asio::deadline_timer check_timer_;
    SPTraderOrder *order_;
    SPTraderPrice *price_;
    SPTraderTicker *ticker_;
    std::thread *io_service_thread_;

    DISALLOW_COPY_AND_ASSIGN(SPTrader);
};
#endif