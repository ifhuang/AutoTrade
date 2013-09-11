#ifndef AST_H
# define AST_H

#include <string>
#include <vector>

#include "lex.h"
#include "vv.h"

typedef int ast_t;

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

	ast(NodeType type) :type(type){}
};

extern std::vector<std::string> strVector;

extern VV<ast> astV;

int newast(NodeType type, ast_t left, ast_t right, ast_t mid = -1);
int newname(int idx);
int newdouble(int idx);
int newtext(int idx);
int newtf(bool bv);
int newcmp(int fn, ast_t lhs, ast_t rhs);
int newprint(ast_t exp, ast_t n = -1, ast_t m = -1);
int newcase(ast_t left, ast_t right, int type);

void astpre();
void astpost();
void printTree(ast* node);

#endif