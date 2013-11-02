#ifndef LEX_PROGRAM_H_
#define LEX_PROGRAM_H_

#include <string>
#include <vector>
#include "ast.h"
#include "global.h"
#include "interface/lex_interface.h"
#include "tree.h"
#include "vv.h"

namespace lex
{
    enum VType { NUMERIC, TF, TEXT, VOID };

    struct Input
    {
        std::string name;
        VType type;
        ast_t exp;
        std::string exp_string;
    };

    struct Initialize{
        int size;
        ast_t exp;
    };

    class SetUpEnviroment{
    public:
        SetUpEnviroment() : num_variables(0) {}
        int ReserveSpace(ast_t exp, int size = 1);

        std::vector<Input> inputs;
        std::vector<Initialize> initialize_list;
    private:
        int num_variables;

        DISALLOW_COPY_AND_ASSIGN(SetUpEnviroment);
    };

    struct Program{
        stmts_t root;
        const SetUpEnviroment *sue;
        std::vector<std::string> *strVector;
        VV<ast> *astV;
        VV<std::vector<stmt_t>> *astsV;
        VV<stmt> *stmtV;
        VV<std::vector<ast_t>> *stmtsV;
        std::vector<OrderInfo> order_info;
    };
}  // namespace lex
#endif // LEX_PROGRAM_H_
