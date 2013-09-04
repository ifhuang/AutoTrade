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
	yydebug = 1;
	yyrestart(f);
	pre();
	int g = yyparse();
	post();
	return g;
}