#ifndef LEX_ABSTRACT_EXECUTOR_H_
#define LEX_ABSTRACT_EXECUTOR_H_

#include "executor_interface.h"

namespace lex
{
    class AbstractExecutor : public ExecutorInterface
    {
    public:
        template<typename T>
        T CheckGetValue(ast_t idx)
        {
            return boost::get<T>(GetValue(idx));
        }

        template<typename T>
        T& CheckGetVar(int position)
        {
            Value &v = GetVar(position);
            T& t = boost::get<T>(v);
            return t;
        }
    };
}  // namespace lex
#endif  // LEX_ABSTRACT_EXECUTOR_H_
