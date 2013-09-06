#ifndef TREE_H
#define TREE_H

#include <unordered_map>
#include <vector>
#include <string>
#include <boost/variant.hpp>
using namespace std;
#include "ast.h"
#include "vv.h"

typedef int stmt_t;
typedef int asts_t;
typedef int stmts_t;

extern stmts_t root;

struct if_stmt
{
	ast_t con;
	stmt_t then;
	stmt_t els;
};

struct once_stmt
{
	ast_t con;
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

struct order_stmt
{
	int op;
	ast_t name;
	ast_t num;
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
	int type;
	ast_t exp;
};

struct var_stmt
{
	asts_t vars;
};

struct block_stmt
{
	stmts_t stmts;
};

typedef boost::variant<if_stmt, once_stmt, for_stmt, order_stmt, func_stmt,
	asm_stmt, block_stmt, var_stmt> stmt;

extern VV<stmt> stmtV;
extern VV<vector<stmt_t> > stmtsV;
extern VV<vector<ast_t> >astsV;

extern vector<ast_t> inputVector;

int new_once(ast_t con, stmt_t stmt);
void putInput(asts_t asts);
void pre();
void post();

#endif