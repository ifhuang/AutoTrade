#ifndef LEX_H
# define LEX_H

#include <string>
#include <vector>

void yyerror(const char *s, ...);
int find(const char *cs);
extern std::string errorMessage;

#endif