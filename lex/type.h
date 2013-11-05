#ifndef LEX_TYPE_H_
#define LEX_TYPE_H_

#include <exception>
#include <string>
#include "bison/el.tab.h"

namespace lex
{
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

    void type_check(const std::string &study_name);
}  // namespace lex

#endif  // LEX_TYPE_H_
