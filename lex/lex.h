#ifndef LEX_H
# define LEX_H

#include <string>
#include <vector>
using namespace std;

void yyerror(const char *s, ...);
int find(const char *cs);
extern string errorMessage;

#endif