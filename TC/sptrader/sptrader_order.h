#ifndef TC_SPTRADER_SPTRADER_ORDER_H_
#define TC_SPTRADER_SPTRADER_ORDER_H_

#include "socket_client.h"
#include "sptrader_task.h"
#include "../global.h"
#include "../SPTrader.h"

#include <set>
#include <string>

class OrderMessageProcessor;

class SPTraderOrder
{
public:
    SPTraderOrder(boost::asio::io_service& io_service,
        tcp::resolver::iterator endpoint_iterator,
        SPTrader &sptrader);

    ~SPTraderOrder();

    int Login(std::string user_id, std::string password, std::string server);
    void Do();
    void RequestLinkState(int link_id);
    void Send(std::string msg);
    Position GetPosition(std::string quote_id, std::string acc_no);

private:
    friend OrderMessageProcessor;
    boost::asio::io_service& io_service_;
    MessageProcessor *mp_;
    SocketClient sc_;
    SPTraderTask<Position> postion_task_;
    DISALLOW_COPY_AND_ASSIGN(SPTraderOrder);
};

#endif  // TC_SPTRADER_SPTRADER_ORDER_H_
