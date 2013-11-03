#ifndef LEX_AST_H_
#define LEX_AST_H_

#include <string>
#include <vector>

#include "bison/el.tab.h"
#include "vv.h"

typedef int ast_t;

const YYLTYPE kDefaultLocation = { -1, -1, -1, -1 };

enum class NodeType
{
    ADD,
    SUB,
    MUL,
    DIV,
    AND,
    OR,
    NOT,
    BAR,
    UPLUS,
    UMINUS,

    VARDEC,
    ARRDEC,
    IBPVARDEC,

    PRINT,

    NUMERIC,
    TF,
    TEXT,

    VAR,
    INPUT,
    FUNC,
    VOID,

    CASE,
    SECTION,

    EQ = 100,
    GT,
    LT,
    NE,
    GE,
    LE,
    CA,
    CB
};

struct ast
{
    ast(NodeType type, YYLTYPE loc) :type(type), loc(loc) {}

    NodeType type;
    union
    {
        double dv;
        bool bv;
        char *sv;
        int idx;
        struct
        {
            ast_t left;
            ast_t mid;
            ast_t right;
        };
    };
    YYLTYPE loc;
};

#endif  // LEX_AST_H_
