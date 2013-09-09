#include <stdio.h>
#include "el.tab.h"
#include "tree.h"

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

void yyrestart(FILE * input_file);

int elparse(FILE *f)
{
	//yydebug = 1;
	yyrestart(f);
	pre();
	int g = yyparse();
	post();
	return g;
}