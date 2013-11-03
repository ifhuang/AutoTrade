#ifndef LEX_TYPE_CHECKER_INTERFACE_H_
#define LEX_TYPE_CHECKER_INTERFACE_H_

#include "program.h"
#include "table.h"

namespace lex
{
    class TypeCheckerInterface
    {
    public:
        virtual ~TypeCheckerInterface() {}
        virtual VType GetType(ast_t idx) = 0;
        virtual void Check(stmt_t stmt) = 0;
        virtual void CheckStmts(stmts_t idx) = 0;
        virtual std::string GetVar(ast_t idx) = 0;
        virtual int Reserve(ast_t exp) = 0;
        virtual int ReserverTrue() = 0;
        virtual Table& GetTable() = 0;
    };

}  // namespace lex

#endif // LEX_TYPE_CHECKER_INTERFACE_H_
