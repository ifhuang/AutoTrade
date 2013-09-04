%{
#include <stdarg.h>
int find(char* cs);
#include "el.tab.h"
void yyerror(char *s, ...);
%}
%option noyywrap
%option caseless
%option never-interactive
%option nounistd

%%

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
next        { return NEXT; }
bar         { return BAR; }
market      { return MARKET; }
stop        { return STOP; }
limit       { return LIMIT; }
close       { return CLOSE; }
and         { return AND; }
or          { return OR; }
true        { return TRUE; }
false       { return FALSE; }
begin       { return BBEGIN; }
end         { return BEND; }
intrabarpersist { return IBP; }

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
by |
is |
of |
on |
than |
the     /* ignore */

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
.     { yyerror("Mystery character %c\n", *yytext); }
%%

void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "error: ");
    vfprintf(stderr, s, ap);
    va_end(ap);
    fprintf(stderr, "\n");
}

void yyl()
{
	int d;
	while(d=yylex())
	{
		printf("%d\n", d);
	}
}


