#ifndef LEX_TREE_H_
#define LEX_TREE_H_

#include <boost/variant.hpp>
#include "bison/el.tab.h"

typedef int ast_t;
typedef int asts_t;
typedef int stmt_t;
typedef int stmts_t;

enum class AsmType { kEQ, kADD, kSUB, kMUL, kDIV };

struct if_stmt
{
    ast_t con;
    stmt_t then;
    stmt_t els;
};

struct once_stmt
{
    ast_t con;
    int con_position;
    stmt_t stmt;
};

struct for_stmt
{
    ast_t var;
    int type;
    ast_t from;
    ast_t to;
    stmt_t block;
};

struct while_stmt
{
    int type;
    ast_t con;
    stmts_t stmts;
};

struct switch_stmt
{
    ast_t con;
    asts_t sections;
};

struct order_stmt
{
    int op;
    ast_t name;
    ast_t num;
    int time;
    int type;
    ast_t price;
};

struct func_stmt
{
    ast_t func;
};

struct asm_stmt
{
    ast_t var;
    AsmType type;
    YYLTYPE type_loc;
    ast_t exp;
};

struct var_stmt
{
    int type;
    asts_t vars;
};

struct block_stmt
{
    stmts_t stmts;
};

struct print_stmt
{
    int location;
    asts_t list;
};

typedef boost::variant<if_stmt, once_stmt, for_stmt, while_stmt, switch_stmt,
    order_stmt, func_stmt, asm_stmt, block_stmt, var_stmt, print_stmt> stmt;

#endif  // LEX_TREE_H_
