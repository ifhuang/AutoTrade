#include "signal_executor.h"

namespace lex
{
    SignalExecutor::SignalExecutor(const Program &program) : Executor(program),
        order_actions_(program_.order_info.size())
    {

    }

    void SignalExecutor::SetUp()
    {
        Executor::SetUp();
        for (OrderAction &oa : order_actions_)
        {
            oa.price = 0;
            oa.qty = 0;
        }
    }

    std::vector<OrderAction> SignalExecutor::Execute()
    {
        Executor::Execute();
        return order_actions_;
    }

    void SignalExecutor::SetOrderAction(int id, OrderAction oa)
    {
        order_actions_[id] = oa;
    }
}  // namespace lex
