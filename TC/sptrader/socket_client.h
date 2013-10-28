#ifndef TC_SPTRADER_SOCKET_CLIENT_H_
#define TC_SPTRADER_SOCKET_CLIENT_H_

#include <condition_variable>
#include <deque>
#include <mutex>
#include <string>
#include <boost/asio.hpp>
#include "../global.h"
#include "message_processor.h"
using boost::asio::ip::tcp;

class SocketClient
{
public:
    SocketClient(boost::asio::io_service& io_service,
        MessageProcessor &mp);
    ~SocketClient();

    bool Connect(tcp::resolver::iterator endpoint_iterator);
    void DoRead();
   
protected:
    void sync_write(const std::string &msg);
    std::string sync_read();

    void write(const std::string &msg);

    void close();
    void sync_close();
    boost::asio::io_service& io_service_;

private:
    typedef std::deque<std::string> message_queue;

    void do_write();

    tcp::socket socket_;
    bool connected_;
    bool ready_;
    std::mutex mutex_;
    std::condition_variable cond_;
    boost::asio::streambuf b_;
    MessageProcessor &mp_;
    message_queue write_msgs_;
    DISALLOW_COPY_AND_ASSIGN(SocketClient);
};

#endif  // TC_SPTRADER_SOCKET_CLIENT_H_
