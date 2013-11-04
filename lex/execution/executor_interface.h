#ifndef LEX_EXECUTION_EXECUTOR_INTERFACE_H_
#define LEX_EXECUTION_EXECUTOR_INTERFACE_H_

#include "../ast.h"
#include "../interface/lex_interface.h"
#include "../tree.h"
#include "execution.h"

namespace lex
{
    class ExecutorInterface
    {
    public:
        virtual ~ExecutorInterface() {}

        virtual Value GetValue(ast_t idx) = 0;
        virtual Value& GetVar(int position) = 0;

        virtual void Exec(stmt_t stmt) = 0;
        virtual void ExecStmts(stmts_t idx) = 0;

        virtual const ast& GetAst(ast_t idx) = 0;
        virtual const std::vector<ast_t>& GetAsts(asts_t idx) = 0;

        virtual void SetOrderAction(int id, OrderAction oa) = 0;
    };
}  // namespace lex
#endif  // LEX_EXECUTION_EXECUTOR_INTERFACE_H_
