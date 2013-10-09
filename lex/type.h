#ifndef TYPE_H_
#define TYPE_H_

#include <string>
#include <vector>

#include "global.h"
#include "tree.h"

namespace lex{

    enum VType { NUMERIC, TF, TEXT, VOID };
    enum AsmType { kEQ, kADD, kSUB, kMUL, kDIV };

    struct Input
    {
        std::string name;
        VType type;
        std::string exp_string;
        ast_t exp;
    };

    struct Initialize{
        int size;
        ast_t exp;
    };

    class SetUpEnviroment{
    public:
        SetUpEnviroment() {}
        int ReserveSpace(ast_t exp, int size = 1);

        std::vector<Input> inputs;
        std::vector<Initialize> initialize_list;
    private:
        int num_variables = 0;

        DISALLOW_COPY_AND_ASSIGN(SetUpEnviroment);
    };

    class SemanticError : public std::exception
    {
    public:
        SemanticError() {}
        SemanticError(const char * const & message, const YYLTYPE * const loc)
            : exception(message), loc_(loc) {}

        const YYLTYPE * const loc_ = nullptr;
    };

    struct InvalidTypeOperation : SemanticError{
        InvalidTypeOperation(const YYLTYPE * const loc) : SemanticError("invalid type operation", loc) {}
    };

    struct LogicalExpressionExpected : SemanticError{
        LogicalExpressionExpected(const YYLTYPE * const loc) : SemanticError("logical expression expected", loc) {}
    };

    struct TypesNotCompatible : SemanticError{
        TypesNotCompatible(const YYLTYPE * const loc) : SemanticError("types not compatible", loc) {}
    };

    extern int kAstTrue;
    extern SetUpEnviroment enviroment;

    VType get_type(ast_t &idx, bool is_input = false);
    std::string get_var(ast_t idx);
    VType check_func(ast_t &idx, bool is_input = false);
    void check(stmt_t stmt);
    void check_stmts(stmts_t idx);
    void type_check();
}  // namespace lex

#endif  // TYPE_H_
