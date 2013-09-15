#ifndef TYPE_H_
#define TYPE_H_

#include <string>
#include <vector>

#include "tree.h"

namespace lex{

    enum VType { NUMERIC, TF, TEXT, VOID };

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
        int ReserveSpace(ast_t exp, int size = 1);

        std::vector<Input> inputs;

        int num_variables;
        std::vector<Initialize> initialize_list;
    };

    class SemanticError : public std::exception
    {
    public:
        SemanticError() {}
        SemanticError(const char * const & message) : exception(message) {}
    };

    struct InvalidTypeOperation : SemanticError{
        InvalidTypeOperation() : SemanticError("invalid type operation") {}
    };

    struct LogicalExpressionExpected : SemanticError{
        LogicalExpressionExpected() : SemanticError("logical expression expected") {}
    };

    struct TypesNotCompatible : SemanticError{
        TypesNotCompatible() : SemanticError("types not compatible") {}
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
