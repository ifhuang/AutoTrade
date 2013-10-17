#ifndef LEX_BISON_STATIC_H_
#define LEX_BISON_STATIC_H_

#include "../ast.h"
#include "../tree.h"
#include "../vv.h"

extern stmts_t root;
extern std::vector<std::string> strVector;
extern VV<ast> astV;
extern VV<stmt> stmtV;
extern VV<std::vector<stmt_t> > stmtsV;
extern VV<std::vector<ast_t> >astsV;

#endif  // LEX_BISON_STATIC_H_
