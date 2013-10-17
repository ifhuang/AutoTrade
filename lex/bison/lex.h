#ifndef LEX_H_
#define LEX_H_

#include <cstdio>
#include <string>
#include "el.tab.h"

void yyrestart(FILE * input_file);
void yyerror(const char *s, ...);
int find(std::string s);
int find(const char *cs, int length);

extern std::string errorMessage;

#endif  // LEX_H_
