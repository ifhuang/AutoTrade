#include <sstream>
#include <unordered_map>
#include <boost/algorithm/string.hpp>

#include "../ast.h"
#include "../vv.h"
using namespace std;

namespace{
    int strTableSize;
    unordered_map<string, int> strTable;
}

vector<string> strVector;
string errorMessage;

VV<ast> VVN(astV);

int find(string s)
{
    boost::algorithm::to_lower(s);
    if (strTable.count(s))
    {
        return strTable[s];
    }
    return strTable[s] = strTableSize++;
}

int find(const char *cs, int length)
{
    string s(cs, cs + length);
    return find(s);
}

int newast(YYLTYPE loc, NodeType type, ast_t left, ast_t right, ast_t mid)
{
    ast node(type, loc);
    node.left = left;
    node.right = right;
    node.mid = mid;
    return astV.put(node);
}

int newname(YYLTYPE loc, int idx)
{
    ast node(NodeType::VAR, loc);
    node.idx = idx;
    return astV.put(node);
}

int newdouble(YYLTYPE loc, int idx)
{
    ast node(NodeType::NUMERIC, loc);
    node.idx = idx;
    return astV.put(node);
}

int newtext(YYLTYPE loc, int idx)
{
    ast node(NodeType::TEXT, loc);
    node.idx = idx;
    return astV.put(node);
}

int newtf(YYLTYPE loc, bool bv)
{
    ast node(NodeType::TF, loc);
    node.bv = bv;
    return astV.put(node);
}

int newcmp(YYLTYPE loc, int fn, int lhs, int rhs)
{
    ast node(NodeType(100 + fn), loc);
    node.left = lhs;
    node.right = rhs;
    return astV.put(node);
}

int newprint(YYLTYPE loc, ast_t exp, ast_t n, ast_t m)
{
    ast node(NodeType::PRINT, loc);
    node.left = exp;
    node.mid = n;
    node.right = m;
    return astV.put(node);
}

int newcase(YYLTYPE loc, ast_t left, ast_t right, int type)
{
    ast node(NodeType::CASE, loc);
    node.left = left;
    node.right = right;
    node.mid = type;
    return astV.put(node);
}

void applyBar(ast *node, int bar)
{
    switch (node->type)
    {
    case NodeType::NUMERIC:
    case NodeType::TF:
    case NodeType::TEXT:
        /* ignore */
        break;
    case NodeType::VAR:
    case NodeType::FUNC:
        break;
    default:
        break;
    }
}

std::string location_print(YYLTYPE const * const yylocp)
{
    std::stringstream res;
    int end_col = yylocp->last_column ? yylocp->last_column - 1 : 0;
    if (0 <= yylocp->first_line)
    {
        res << yylocp->first_line;
        if (0 <= yylocp->first_column)
            res << '.' << yylocp->first_column;
    }
    if (0 <= yylocp->last_line)
    {
        if (yylocp->first_line < yylocp->last_line)
        {
            res << '-' << yylocp->last_line;
            if (0 <= end_col)res << '.' << end_col;
        }
        else if (0 <= end_col && yylocp->first_column < end_col)
            res << '-' << end_col;
    }
    return res.str();
}

void yyerror(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    static char str[1000];
    vsprintf_s(str, s, ap);
    va_end(ap);
    errorMessage += "(" + location_print(&yylloc) + "): error: ";
    errorMessage += str;
}

const YYLTYPE* GetLocation(ast_t idx)
{
    return &astV[idx].loc;
}

void astpre()
{
    strTable.clear();
    strTableSize = 0;
    astV.clear();
    find("close");
    errorMessage.clear();
}

void astpost()
{
    strVector.resize(strTableSize);
    for (auto var : strTable)
    {
        strVector[var.second] = var.first;
    }
}
