#ifndef TC_SOCKET_HELPER_H_
#define TC_SOCKET_HELPER_H_

#include <string>
#include <vector>

#include "string_processor.h"

struct Message
{
    Message(std::string msg)
    {
        Spliter spliter(msg);
        if (!spliter.Exists(1))throw - 2;
        id = spliter.Get<int>(0);
        type = spliter.Get<int>(1);
        fileds = spliter.Sub(2);
    }
    int id;
    int type;
    Spliter fileds;
};

#endif  // TC_SOCKET_HELPER_H_
