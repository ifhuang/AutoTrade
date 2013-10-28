#include "sptrader_price.h"

#include <boost/date_time/posix_time/posix_time.hpp>

using std::string;

class PriceMessageProcessor : public SplitedMessageProcessor
{
public:
    PriceMessageProcessor(SPTraderPrice &price,
        Dispatcher &dispatcher) : price_(price), dispatcher_(dispatcher) {}

    virtual void Processor(Message &msg) override
    {
        switch (msg.id)
        {
        case 4102:
            Processor4102(msg.fileds);
            break;
        }
    }

private:
    void Processor4102(Spliter &spliter)
    {
        PriceItem* pi = StringProcessor::StringToPriceItem(spliter);
        //LogHandler::getLogHandler().log(priceStr);
        //pi->log();
        price_.ConfirmPriceInfo(pi->quoteId);
        dispatcher_.forwardPrice(pi);
    }

    SPTraderPrice &price_;
    Dispatcher &dispatcher_;
    std::set<std::string> product_set_;
};

SPTraderPrice::SPTraderPrice(boost::asio::io_service& io_service,
    Dispatcher &dispatcher)
    : SocketClient(io_service, *new PriceMessageProcessor(*this, dispatcher))
{
}

SPTraderPrice::~SPTraderPrice()
{
}

void SPTraderPrice::Request(string product)
{
    string quote_msg = "4107,0," + product + "\r\n";
    write(quote_msg);
}

void SPTraderPrice::Release(std::string product)
{
    string quote_msg = "4108,0," + product + "\r\n";
    write(quote_msg);
}

void SPTraderPrice::ConfirmPriceInfo(string quote_id)
{
    string price_rep = "4102,3," + quote_id + ",0\r\n";
    write(price_rep);
}
