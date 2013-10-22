#ifndef TC_SPTRADER_MESSAGE_PROCESSOR_H_
#define TC_SPTRADER_MESSAGE_PROCESSOR_H_

#include <string>
#include "../socket_helper.h"
#include "../LogHandler.h"

class MessageProcessor
{
public:
    virtual ~MessageProcessor() {}
    virtual void Processor(std::string msg) = 0;
};

class SplitedMessageProcessor : public MessageProcessor
{
public:
    virtual void Processor(std::string msg) override final
    {
        LogHandler::getLogHandler().log(msg);
        Message message(msg);
        Processor(message);
    }

private:
    virtual void Processor(Message &msg) = 0;
};

#endif  // TC_SPTRADER_MESSAGE_PROCESSOR_H_
