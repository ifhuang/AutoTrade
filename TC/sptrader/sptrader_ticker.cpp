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
    tcp::resolver::iterator endpoint_iterator, Dispatcher &dispatcher)
    : io_service_(io_service),
    mp_(new TickerMessageProcessor(dispatcher)),
    sc_(io_service, *mp_)
{
    sc_.do_connect(endpoint_iterator);
}

SPTraderTicker::~SPTraderTicker()
{
    delete mp_;
}

void SPTraderTicker::Request(string product)
{
    string quote_msg = "5107,0," + product + "\r\n";
    io_service_.post(
        [this, quote_msg]()
    {
        sc_.write(quote_msg);
    });
}

void SPTraderTicker::Release(std::string product)
{
    string quote_msg = "5108,0," + product + "\r\n";
    io_service_.post(
        [this, quote_msg]()
    {
        sc_.write(quote_msg);
    });
}
