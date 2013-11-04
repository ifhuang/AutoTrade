#ifndef LEX_EXECUTION_SIGNAL_EXECUTOR_H_
#define LEX_EXECUTION_SIGNAL_EXECUTOR_H_

#include "executor.h"

namespace lex
{
    class SignalExecutor : public Executor
    {
    public:
        SignalExecutor(const Program &program);
        std::vector<OrderAction> Execute();
    private:
        virtual void SetUp() override;
        virtual void SetOrderAction(int id, OrderAction oa) override;
        std::vector<OrderAction> order_actions_;
    };
}  // namespace lex
#endif  // LEX_EXECUTION_SIGNAL_EXECUTOR_H_
