#ifndef LEX_LEX_RUNNER_H_
#define LEX_LEX_RUNNER_H_

#include "interface/lex_interface.h"
#include "executor.h"

namespace lex
{
    class LexRunner : public SignalRunnerInterface
    {
    public:
        LexRunner(Program p, TCBarInterface *bar);
        ~LexRunner();
        virtual std::vector<OrderInfo> GetOrderInfo() override;

        virtual std::vector<OrderAction> Run() override;

    private:
        Program p_;
        Executor exe_;
        TCBarInterface *bar_;
    };

}  // namespace lex

#endif  // LEX_LEX_RUNNER_INTERFACE_H_
