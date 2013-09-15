#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include "execution.h"
#include "run_time_environment.h"
#include "type.h"

namespace lex{
    class Executor
    {
    public:
        Executor(SetUpEnviroment sue);
        void execute();

        Value value(ast_t idx);
        void exec(stmt_t stmt);
        void exec_stmts(stmts_t idx);

        template<typename T>
        T check_value(ast_t idx)
        {
            return boost::get<T>(value(idx));
        }
    private:
        RunTimeEnvironment *rte_;
        DISALLOW_COPY_AND_ASSIGN(Executor);
    };

}  // namespace lex
#endif  // EXECUTOR_H_
