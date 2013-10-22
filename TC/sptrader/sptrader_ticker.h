#ifndef TC_SPTRADER_SPTRADER_TICKER_H_
#define TC_SPTRADER_SPTRADER_TICKER_H_

#include "socket_client.h"
#include "../Dispatcher.h"

#include <set>
#include <string>

class SPTraderTicker
{
public:
    SPTraderTicker(boost::asio::io_service& io_service,
        tcp::resolver::iterator endpoint_iterator,
        Dispatcher &dispatcher);

    ~SPTraderTicker();

    void Request(std::string product);

    void Release(std::string product);

private:
    boost::asio::io_service& io_service_;
    MessageProcessor *mp_;
    SocketClient sc_;
};

#endif  // TC_SPTRADER_SPTRADER_TICKER_H_
