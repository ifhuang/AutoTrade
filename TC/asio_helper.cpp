#include "asio_helper.h"

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string AsioHelper::Get(std::string request)
{
    boost::asio::io_service io_service;
    tcp::resolver r(io_service);
    tcp::resolver::query q("localhost", "8092");
    tcp::socket s(io_service);
    auto e = r.resolve(q);
    boost::asio::connect(s, e);
    boost::asio::write(s, boost::asio::buffer(request));

    boost::asio::streambuf b;
    boost::asio::read_until(s, b, "\r\n");
    std::istream is(&b);
    std::string response;
    std::getline(is, response);
    return response;
}


