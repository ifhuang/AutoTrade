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
        int id;
        ast_t exp;
        std::string exp_string;
    };

    struct Initialize
    {
        int size;
        ast_t exp;
    };

    struct SetUpEnviroment
    {
        std::vector<Input> inputs;
        std::vector<Initialize> initialize_list;
    };

    struct Program
    {
        stmts_t root;
        SetUpEnviroment sue;
        std::vector<std::string> strVector;
        VV<ast> astV;
        VV<std::vector<stmt_t>> astsV;
        VV<stmt> stmtV;
        VV<std::vector<ast_t>> stmtsV;
        std::vector<OrderInfo> order_info;
    };
}  // namespace lex
#endif // LEX_PROGRAM_H_
