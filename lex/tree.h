#ifndef TREE_H
# define TREE_H

#include <vector>
#include <boost/variant.hpp>

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

struct while_stmt
{
	int type;
	ast_t con;
	stmt_t block;
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
	int type;
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

extern VV<stmt> stmtV;
extern VV<std::vector<stmt_t> > stmtsV;
extern VV<std::vector<ast_t> >astsV;

extern std::vector<ast_t> inputVector;

int new_if(ast_t con, stmt_t then, stmt_t els = -1);
int new_once(ast_t con, stmt_t stmt);
int new_order(int type, ast_t price);
int new_while(int type, ast_t con, stmt_t block);
int new_print(int location, asts_t list);
int new_var(int type, asts_t vars);

void putInput(asts_t asts);
void pre();
void post();
int elparse(FILE *f);

#endif