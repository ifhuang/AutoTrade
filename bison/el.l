   /* -*-mode: flex-mode-*- */
%{
#include <stdarg.h>
#include "el.tab.h"
#include "lex.h"
%}
%option noyywrap
%option caseless
%option never-interactive
%option nounistd

%x COMMENT
%%

"{"          { BEGIN(COMMENT); }
<COMMENT>"}" { BEGIN(INITIAL); }
<COMMENT>\n|.
<COMMENT><<EOF>> { yyerror("Unterminated comment"); }

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

\"[^"]*\"  { 
yylval.fn = find(yytext);
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
":" { return COL; }

[(),;=] { return yytext[0]; }

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

\/\/.*      /* ignore */
[ \t\r\n] /* ignore */
.     { yyerror("Mystery character %c\n", *yytext); return *yytext; }
%%

void yyerror(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    static char str[1000];
    vsprintf_s(str, s, ap);
	va_end(ap);
	errorMessage += "error: ";
	errorMessage += str;
}


