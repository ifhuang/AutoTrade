#include "sptrader_ticker.h"

#include <boost/date_time/posix_time/posix_time.hpp>

using std::string;

class TickerMessageProcessor : public SplitedMessageProcessor
{
public:
    TickerMessageProcessor(Dispatcher &dispatcher) : dispatcher_(dispatcher) {}

    virtual void Processor(Message &msg)
    {
        switch (msg.id)
        {
        case 5102:{
                       PriceItem* pi = new PriceItem();
                       pi->quoteId = msg.fileds.Get<string>(0);
                       pi->lastPrice1 = msg.fileds.Get<double>(1);
                       pi->lastQty1 = msg.fileds.Get<int>(2);
                       pi->currentTime = boost::posix_time::from_time_t(msg.fileds.Get<time_t>(3));
                       dispatcher_.forwardTickPrice(pi);
                       break;
        }
        }
    }

private:
    Dispatcher &dispatcher_;
    std::set<std::string> product_set_;
};

SPTraderTicker::SPTraderTicker(boost::asio::io_service& io_service,
    Dispatcher &dispatcher)
    : SocketClient(io_service, *new TickerMessageProcessor(dispatcher))
{
}

SPTraderTicker::~SPTraderTicker()
{
}

void SPTraderTicker::Request(string product)
{
    string quote_msg = "5107,0," + product + "\r\n";
    write(quote_msg);
}

void SPTraderTicker::Release(std::string product)
{
    string quote_msg = "5108,0," + product + "\r\n";
    write(quote_msg);
}
