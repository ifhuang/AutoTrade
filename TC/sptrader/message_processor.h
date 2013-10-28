#ifndef TC_SPTRADER_MESSAGE_PROCESSOR_H_
#define TC_SPTRADER_MESSAGE_PROCESSOR_H_

#include <string>
#include "../global.h"
#include "../socket_helper.h"
#include "../LogHandler.h"

class MessageProcessor
{
public:
    MessageProcessor() {}
    virtual ~MessageProcessor() {}
    virtual void Processor(std::string msg) = 0;
private:
    DISALLOW_COPY_AND_ASSIGN(MessageProcessor);
};

class SplitedMessageProcessor : public MessageProcessor
{
public:
    SplitedMessageProcessor() {}
    virtual void Processor(std::string msg) override final
    {
        LogHandler::getLogHandler().log(msg);
        Message message(msg);
        Processor(message);
    }

private:
    virtual void Processor(Message &msg) = 0;
    DISALLOW_COPY_AND_ASSIGN(SplitedMessageProcessor);
};

#endif  // TC_SPTRADER_MESSAGE_PROCESSOR_H_
