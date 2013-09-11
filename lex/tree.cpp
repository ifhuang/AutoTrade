#include "tree.h"

#include <stdio.h>
using namespace std;

#include "el.tab.h"

stmts_t root;

VV<stmt> VVN(stmtV);
VV<vector<stmt_t> > VVN(stmtsV);
VV<vector<ast_t> > VVN(astsV);

vector<ast_t> inputVector;

void putInput(asts_t asts)
{
	for (ast_t ast : astsV[asts])
	{
		inputVector.push_back(ast);
	}
}

int new_if(ast_t con, stmt_t then, stmt_t els)
{
	if_stmt i;
	i.con = con;
	i.then = then;
	i.els = els;
	return stmtV.put(i);
}

int new_once(ast_t con, stmt_t stmt)
{
	once_stmt o;
	o.con = con;
	o.stmt = stmt;
	return stmtV.put(o);
}

int new_order(int type, ast_t price)
{
	order_stmt o;
	o.type = type;
	o.price = price;
	return stmtV.put(o);
}

int new_while(int type, ast_t con, stmt_t block)
{
	while_stmt ws;
	ws.type = type;
	ws.con = con;
	ws.block = block;
	return stmtV.put(ws);
}

int new_print(int location, asts_t list)
{
	print_stmt ps;
	ps.location = location;
	ps.list = list;
	return stmtV.put(ps);
}

int new_var(int type, asts_t vars)
{
	var_stmt vs;
	vs.type = type;
	vs.vars = vars;
	return stmtV.put(vs);
}

void pre()
{
	astpre();
	stmtV.clear();
	stmtsV.clear();
	astsV.clear();
	inputVector.clear();
}

void post()
{
	astpost();
}

int elparse(FILE *f)
{
	yydebug = 1;
	yyrestart(f);
	pre();
	int g = yyparse();
	post();
	return g;
}