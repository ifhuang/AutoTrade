#ifndef LEX_H_
#define LEX_H_

#include <sstream>
#include <string>
#include <vector>

void yyrestart(FILE * input_file);
void yyerror(const char *s, ...);
int find(std::string s);
int find(const char *cs, int length);
std::string location_print(YYLTYPE const * const yylocp);

extern std::string errorMessage;

#endif  // LEX_H_
