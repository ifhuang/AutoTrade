#include "socket_helper.h"

#include <windows.h>
#include <boost/algorithm/string.hpp>

using std::string;

SocketHelper::SocketHelper(int socket_no) : socket_no_(socket_no) {}

Message SocketHelper::Get()
{
    int len = recv(socket_no_, buf_, sizeof(buf_), 0);
    if (len < 0)
    {
        throw len;
    }
    string message(buf_, len);
    if (!boost::ends_with(message, "\r\n"))
    {
        throw - 1;
    }
    Message me(message);
    return me;
}
