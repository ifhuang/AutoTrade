#ifndef TC_SPTRADER_SOCKET_CLIENT_H_
#define TC_SPTRADER_SOCKET_CLIENT_H_

#include <deque>
#include <string>
#include <boost/asio.hpp>
#include "message_processor.h"
using boost::asio::ip::tcp;

class SocketClient
{
public:
    SocketClient(boost::asio::io_service& io_service,
        MessageProcessor &mp);

    void connect(tcp::resolver::iterator endpoint_iterator);
    void sync_write(const std::string &msg);
    std::string sync_read();

    void do_connect(tcp::resolver::iterator endpoint_iterator);
    void do_read();
    void write(const std::string &msg);

    void close();

private:
    typedef std::deque<std::string> message_queue;

    void do_write();

    boost::asio::io_service& io_service_;
    tcp::socket socket_;
    boost::asio::streambuf b_;
    MessageProcessor &mp_;
    message_queue write_msgs_;
};

#endif  // TC_SPTRADER_SOCKET_CLIENT_H_
