#ifndef LEX_EXECUTION_EXECUTOR_H_
#define LEX_EXECUTION_EXECUTOR_H_

#include <vector>

#include "../program.h"
#include "abstract_executor.h"
#include "exec_visitor.h"
#include "execution.h"
#include "run_time_environment.h"

namespace lex
{
    class Executor : public AbstractExecutor
    {
    public:
        Executor(const Program *program);
        virtual ~Executor();

        void execute();
        virtual Value GetValue(ast_t idx) override;
        virtual Value& GetVar(int position) override;

        virtual void Exec(stmt_t stmt) override;
        virtual void ExecStmts(stmts_t idx) override;

    private:
        void SetUp();
        std::vector<Value> exec_paras(asts_t idx);
        std::string get_var(ast_t idx);
        Value exec_func(ast_t idx);

        virtual const ast& GetAst(ast_t idx);
        virtual const std::vector<ast_t>& GetAsts(asts_t idx);

        ExecVisitor visitor_;
        RunTimeEnvironment *rte_;
        const Program *program_;
        const SetUpEnviroment &sue_;
        const std::vector<std::string> &strVector_;
        const VV<ast> &astV_;
        const VV<std::vector<stmt_t>> &astsV_;
        const VV<stmt> &stmtV_;
        const VV<std::vector<ast_t>> &stmtsV_;

        DISALLOW_COPY_AND_ASSIGN(Executor);
    };

}  // namespace lex
#endif  // LEX_EXECUTION_EXECUTOR_H_
