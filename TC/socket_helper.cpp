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
    Spliter spliter(message);
    Message me;
    if (!spliter.Exists(1))throw - 2;
    me.id = spliter.Get<int>(0);
    me.type = spliter.Get<int>(1);
    me.fileds = spliter.Sub(2);
    return me;
}
