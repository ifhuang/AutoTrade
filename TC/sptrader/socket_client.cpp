#include "socket_client.h"

using std::string;

SocketClient::SocketClient(boost::asio::io_service& io_service,
    MessageProcessor &mp)
    : io_service_(io_service), socket_(io_service), mp_(mp),
    connected_(false), ready_(false)
{
}

SocketClient::~SocketClient()
{
    close();
}

bool SocketClient::Connect(tcp::resolver::iterator endpoint_iterator)
{
    boost::system::error_code ec;
    boost::asio::connect(socket_, endpoint_iterator, ec);
    if (ec)
    {
        return false;
    }
    return connected_ = true;
}

void SocketClient::DoRead()
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
            DoRead();
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
    puts("...closing...");
    if (!connected_)return;
    io_service_.post([this]()
    {
        std::unique_lock<std::mutex> _(mutex_);
        socket_.close();
        ready_ = true;
        connected_ = false;
        cond_.notify_one();
    });
    std::unique_lock<std::mutex> lock(mutex_);
    while (!ready_)
    {
        cond_.wait(lock);
    }
}

void SocketClient::sync_close()
{
    if (!connected_)return;
    socket_.close();
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
