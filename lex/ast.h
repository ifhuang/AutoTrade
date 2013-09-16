#ifndef AST_H_
#define AST_H_

#include <string>
#include <vector>

#include "el.tab.h"
#include "lex.h"
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

extern std::vector<std::string> strVector;

extern VV<ast> astV;

int newast(YYLTYPE loc, NodeType type, ast_t left, ast_t right, ast_t mid = -1);
int newname(YYLTYPE loc, int idx);
int newdouble(YYLTYPE loc, int idx);
int newtext(YYLTYPE loc, int idx);
int newtf(YYLTYPE loc, bool bv);
int newcmp(YYLTYPE loc, int fn, ast_t lhs, ast_t rhs);
int newprint(YYLTYPE loc, ast_t exp, ast_t n = -1, ast_t m = -1);
int newcase(YYLTYPE loc, ast_t left, ast_t right, int type);

void astpre();
void astpost();
void printTree(ast* node);

#endif  // AST_H_
