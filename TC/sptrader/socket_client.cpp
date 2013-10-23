#include "socket_client.h"

using std::string;

SocketClient::SocketClient(boost::asio::io_service& io_service,
    MessageProcessor &mp)
    : io_service_(io_service), socket_(io_service), mp_(mp)
{
}

void SocketClient::connect(tcp::resolver::iterator endpoint_iterator)
{
    boost::asio::connect(socket_, endpoint_iterator);
}

void SocketClient::do_connect(tcp::resolver::iterator endpoint_iterator)
{
    boost::asio::async_connect(socket_, endpoint_iterator,
        [this](boost::system::error_code ec, tcp::resolver::iterator)
    {
        if (!ec)
        {
            do_read();
        }
    });
}

void SocketClient::do_read()
{
    boost::asio::async_read_until(socket_, b_, "\r\n",
        [this](boost::system::error_code ec, std::size_t bt)
    {
        if (!ec)
        {
            std::istream is(&b_);
            std::string line;
            std::getline(is, line, '\r');
            b_.consume(1);
            mp_.Processor(line);
            do_read();
        }
        else
        {
            socket_.close();
        }
    });
}

void SocketClient::write(const string &msg)
{
    io_service_.post(
        [this, msg]()
    {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            do_write();
        }
    });
}

void SocketClient::do_write()
{
    boost::asio::async_write(socket_, boost::asio::buffer(write_msgs_.front()),
        [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec)
        {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
                do_write();
            }
        }
        else
        {
            socket_.close();
        }
    });
}

void SocketClient::close()
{
    io_service_.post([this]() { socket_.close(); });
}

void SocketClient::sync_write(const std::string &msg)
{
    boost::asio::write(socket_, boost::asio::buffer(msg));
}

std::string SocketClient::sync_read()
{
    boost::asio::streambuf b;
    boost::asio::read_until(socket_, b, "\r\n");
    std::istream is(&b);
    std::string response;
    std::getline(is, response, '\r');
    return response;
}
