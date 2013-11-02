#ifndef LEX_EXECUTOR_INTERFACE_H_
#define LEX_EXECUTOR_INTERFACE_H_

#include "ast.h"
#include "execution.h"
#include "tree.h"

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
    };
}  // namespace lex
#endif  // LEX_EXECUTOR_INTERFACE_H_
