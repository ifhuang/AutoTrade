   /* -*-mode: flex-mode-*- */
%{
#include <stdarg.h>
#include <sstream>
#include "el.tab.h"
#include "lex.h"

int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng; \
    yycolumn += yyleng;

%}
%option noyywrap
%option caseless
%option never-interactive
%option nounistd
%option yylineno

%x COMMENT
%%

"{"          { BEGIN(COMMENT); }
<COMMENT>"}" { BEGIN(INITIAL); }
<COMMENT>\n  { yycolumn = 1; }
<COMMENT>.
<COMMENT><<EOF>> { yyerror("Unterminated comment\n"); return '{'; }

if          { return IF; }
then        { return THEN; }
else        { return ELSE; }
once        { return ONCE; }
inputs |
input       { return INPUTS; }
variables |
variable |
vars |
var         { return VARIABLES; }
array |
arrays      { return ARRAYS; }
buy         { return BUY; }
sell        { return SELL; }
short       { return SHORT; }
sellshort   { return SELLSHORT; }
to          { return TO; }
cover       { return COVER; }
buytocover  { return BUYTOCOVER; }
this        { return THIS; }
next        { return NEXT; }
bar         { return BAR; }
market      { return MARKET; }
stop        { return STOP; }
limit       { return LIMIT; }
open        { return OPEN; }
close       { return CLOSE; }
and         { return AND; }
or          { return OR; }
not         { return NOT; }
true        { return TRUE; }
false       { return FALSE; }
begin       { return BBEGIN; }
end         { return BEND; }
intrabarpersist { return IBP; }
share |
shares |
contract |
contracts   { return SHARE; }
cross |
crosses     { return CROSS; }
above |
over        { return ABOVE; }
below |
under       { return BELOW; }
for         { return FOR; }
downto      { return DOWNTO; }
while       { return WHILE; }
repeat      { return REPEAT; }
until       { return UNTIL; }
all         { return ALL; }
print       { return PRINT; }
printer     { return PRINTER; }
file        { return PFILE; }
switch      { return SWITCH; }
default     { return DEFAULT; }
case        { return CASE; }

\"[^"]*\"  { 
yylval.fn = find(yytext + 1, yyleng - 2);
return TEXT; }
                             
([0-9]*\.?[0-9]+|[0-9]+\.)(E[+-]?[0-9]+)? { 
yylval.fn = find(yytext);
return NUMBER; }

    /* Skip words */
a |
an |
at |
based |
by |
does |
from |
is |
of |
on |
place |
than |
the |
was     /* ignore */

[_a-z][_a-z0-9]* { 
yylval.fn = find(yytext);
return NAME; }

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"[" { return LSB; }
"]" { return RSB; }

[(),:;=] { return yytext[0]; }

"+=" { yylval.fn = 1; return ASM; }
"-=" { yylval.fn = 2; return ASM; }
"*=" { yylval.fn = 3; return ASM; }
"/=" { yylval.fn = 4; return ASM; }

    /* comparison ops, all are a CMP token */
">"  { yylval.fn = 1; return CMP; }
"<"  { yylval.fn = 2; return CMP; }
"<>" { yylval.fn = 3; return CMP; }
">=" { yylval.fn = 4; return CMP; }
"<=" { yylval.fn = 5; return CMP; }

\/\/.*    /* ignore */
[ \t\r]   /* ignore */
\n   { yycolumn = 1; }
.    { yyerror("Mystery character %c\n", *yytext); return *yytext; }
%%

std::string location_print(YYLTYPE const * const yylocp)
{
    std::stringstream res;
    int end_col = yylocp->last_column ? yylocp->last_column - 1 : 0;
    if (0 <= yylocp->first_line)
    {
        res << yylocp->first_line;
        if (0 <= yylocp->first_column)
            res << '.' << yylocp->first_column;
    }
    if (0 <= yylocp->last_line)
    {
        if (yylocp->first_line < yylocp->last_line)
        {
            res << '-' << yylocp->last_line;
            if (0 <= end_col)res << '.' << end_col;
        }
        else if (0 <= end_col && yylocp->first_column < end_col)
            res << '-' << end_col;
    }
    return res.str();
}

void yyerror(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    static char str[1000];
    vsprintf_s(str, s, ap);
	va_end(ap);
	errorMessage += "(" + location_print(&yylloc) + "): error: ";
	errorMessage += str;
}

