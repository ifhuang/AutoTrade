#ifndef LEX_EXECUTOR_H_
#define LEX_EXECUTOR_H_

#include <vector>

#include "execution.h"
#include "run_time_environment.h"
#include "type.h"

namespace lex {
    class Executor
    {
    public:
        Executor(const Program *program);
        ~Executor();

        void execute();
        Value value(ast_t idx);
        void exec(stmt_t stmt);
        void exec_stmts(stmts_t idx);

        template<typename T>
        T check_value(ast_t idx)
        {
            return boost::get<T>(value(idx));
        }

        RunTimeEnvironment *rte_;
        const Program *program_;
        const SetUpEnviroment &sue_;
        const std::vector<std::string> &strVector_;
        const VV<ast> &astV_;
        const VV<std::vector<stmt_t>> &astsV_;
        const VV<stmt> &stmtV_;
        const VV<std::vector<ast_t>> &stmtsV_;
    private:
        void SetUp();
        std::vector<Value> exec_paras(asts_t idx);
        std::string get_var(ast_t idx);
        Value exec_func(ast_t idx);

        DISALLOW_COPY_AND_ASSIGN(Executor);
    };

}  // namespace lex
#endif  // LEX_EXECUTOR_H_
