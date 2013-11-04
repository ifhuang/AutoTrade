#ifndef LEX_BISON_FRONT_H_
#define LEX_BISON_FRONT_H_

#include <cstdio>
#include <string>
#include "static.h"

int ElParse(FILE *f);
const YYLTYPE * GetLocation(ast_t idx);
int newtf(YYLTYPE loc, bool bv);
std::string LocationPrint(YYLTYPE const * const yylocp);

extern std::vector<ast_t> inputVector;
extern std::string errorMessage;

#endif  // LEX_BISON_FRONT_H_
