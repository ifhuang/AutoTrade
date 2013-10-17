#ifndef LEX_TYPE_CHECKER_H_
#define LEX_TYPE_CHECKER_H_

#include "global.h"
#include "table.h"
#include "type.h"

namespace lex
{
    class TypeChecker
    {
    public:
        TypeChecker();
        void check();
        VType get_type(ast_t &idx, bool is_input = false);
        std::string get_var(ast_t idx);
        VType check_func(ast_t &idx, bool is_input = false);
        void check(stmt_t stmt);
        void check_stmts(stmts_t idx);

        SetUpEnviroment enviroment_;
        int kAstTrue;
    private:
        void check_input();
        void check_paras(const StdFunction *function, asts_t idx,
            const YYLTYPE *loc, bool is_input = false);

        DISALLOW_COPY_AND_ASSIGN(TypeChecker);
    };
}
#endif  // LEX_TYPE_CHECKER_H_
