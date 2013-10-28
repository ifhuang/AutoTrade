#ifndef TC_SPTRADER_SPTRADER_TICKER_H_
#define TC_SPTRADER_SPTRADER_TICKER_H_

#include "socket_client.h"
#include "../Dispatcher.h"
#include "../global.h"

#include <set>
#include <string>

class SPTraderTicker : public SocketClient
{
public:
    SPTraderTicker(boost::asio::io_service& io_service,
        Dispatcher &dispatcher);

    ~SPTraderTicker();

    void Request(std::string product);

    void Release(std::string product);

private:
    DISALLOW_COPY_AND_ASSIGN(SPTraderTicker);
};

#endif  // TC_SPTRADER_SPTRADER_TICKER_H_
