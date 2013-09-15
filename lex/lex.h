#ifndef LEX_H
# define LEX_H

#include <string>
#include <vector>

void yyrestart(FILE * input_file);
void yyerror(const char *s, ...);
int find(std::string s);
int find(const char *cs, int length);
extern std::string errorMessage;

#endif
