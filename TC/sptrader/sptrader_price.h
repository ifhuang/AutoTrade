#ifndef TC_SPTRADER_SPTRADER_PRICE_H_
#define TC_SPTRADER_SPTRADER_PRICE_H_

#include "socket_client.h"
#include "../Dispatcher.h"
#include "../global.h"

#include <set>
#include <string>

class SPTraderPrice : public SocketClient
{
public:
    SPTraderPrice(boost::asio::io_service& io_service,
        Dispatcher &dispatcher);

    ~SPTraderPrice();

    void Request(std::string product);

    void Release(std::string product);

    void ConfirmPriceInfo(string quote_id);
private:
    DISALLOW_COPY_AND_ASSIGN(SPTraderPrice);
};

#endif  // TC_SPTRADER_SPTRADER_PRICE_H_
