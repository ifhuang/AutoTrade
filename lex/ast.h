#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
using namespace std;
#include "vv.h"

typedef int ast_t;

int find(char* cs);

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
	IBPVARDEC,

	NUMERIC,
	TF,
	TEXT,

	VAR,
	FUNC,

	EQ = 100,
	GT,
	LT,
	NE,
	GE,
	LE
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
			ast_t right;
		};
	};

	ast(NodeType type) :type(type){}
};

extern vector<string> strVector;

extern VV<ast> astV;

int newast(NodeType type, ast_t left, ast_t right);
int newname(int idx);
int newdouble(int idx);
int newtext(int idx);
int newtf(bool bv);
int newcmp(int fn, ast_t lhs, ast_t rhs);

void astpre();
void astpost();
void printTree(ast* node);

#endif