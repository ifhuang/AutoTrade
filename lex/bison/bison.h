#ifndef LEX_BISON_BISON_H_
#define LEX_BISON_BISON_H_

#include "../ast.h"
#include "../tree.h"
#include "el.tab.h"
#include "static.h"

void yyerror(const char *s, ...);

int newast(YYLTYPE loc, NodeType type, ast_t left, ast_t right, ast_t mid = -1);
int newname(YYLTYPE loc, int idx);
int newdouble(YYLTYPE loc, int idx);
int newtext(YYLTYPE loc, int idx);
int newtf(YYLTYPE loc, bool bv);
int newcmp(YYLTYPE loc, int fn, ast_t lhs, ast_t rhs);
int newprint(YYLTYPE loc, ast_t exp, ast_t n = -1, ast_t m = -1);
int newcase(YYLTYPE loc, ast_t left, ast_t right, int type);

int new_if(ast_t con, stmt_t then, stmt_t els = -1);
int new_once(ast_t con, stmt_t stmt);
int new_order(int type, ast_t price);
int new_while(int type, ast_t con, stmts_t stmts);
int new_print(int location, asts_t list);
int new_var(int type, asts_t vars);

void putInput(asts_t asts);

#endif  // LEX_BISON_BISON_H_
