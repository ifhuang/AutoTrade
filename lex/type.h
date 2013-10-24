#ifndef LEX_TYPE_H_
#define LEX_TYPE_H_

#include <string>
#include <vector>

#include "ast.h"
#include "global.h"
#include "tree.h"
#include "vv.h"

namespace lex{

    enum VType { NUMERIC, TF, TEXT, VOID };
    enum AsmType { kEQ, kADD, kSUB, kMUL, kDIV };

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
        SetUpEnviroment *sue;
        std::vector<std::string> *strVector;
        VV<ast> *astV;
        VV<std::vector<stmt_t>> *astsV;
        VV<stmt> *stmtV;
        VV<std::vector<ast_t>> *stmtsV;
    };

    class SemanticError : public std::exception
    {
    public:
        SemanticError() : loc_(nullptr) {}
        SemanticError(const char * const & message, const YYLTYPE * const loc)
            : exception(message), loc_(loc) {}

        const YYLTYPE * const loc_;
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

    void type_check();
}  // namespace lex

#endif  // LEX_TYPE_H_
