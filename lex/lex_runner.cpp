#include "lex_runner.h"

namespace lex
{
    LexRunner::LexRunner(Program p, TCBarInterface *bar) : p_(p), bar_(bar),
        exe_(&p)
    {

    }

    LexRunner::~LexRunner()
    {

    }

    std::vector<OrderInfo> LexRunner::GetOrderInfo()
    {
        return std::vector<OrderInfo>();
    }

    std::vector<OrderAction> LexRunner::Run()
    {
        exe_.execute();
        return std::vector<OrderAction>();
    }
}  // namespace lex
