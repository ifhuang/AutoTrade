#ifndef TC_SOCKET_HELPER_H_
#define TC_SOCKET_HELPER_H_

#include <string>
#include <vector>

#include "string_processor.h"

struct Message
{
    int id;
    int type;
    Spliter fileds;
};

class SocketHelper
{
public:
    SocketHelper(int socket_no);
    Message Get();

private:
    int socket_no_;
    char buf_[4096];
};

#endif  // TC_SOCKET_HELPER_H_
