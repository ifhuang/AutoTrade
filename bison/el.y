%{
#include <stdio.h>
#include "tree.h"
#include "operator.h"
extern int yylex();
extern void yyerror(char *s, ...);

%}

%union{
  int fn;
}

%token INPUTS VARIABLES IBP
%token NUMBER TRUE FALSE TEXT
%token CLOSE THIS NEXT BAR MARKET STOP LIMIT
%token VOLUMN NAME 
 // operator
%token CMP ASM ADD SUB MUL DIV LSB RSB
%token COL COM

%token BUY SELL SHORT SELLSHORT TO COVER BUYTOCOVER
%token PLOT1
%token IF THEN ELSE AND OR NOT ONCE
%token BBEGIN BEND 


%type <fn> CMP NUMBER NAME TEXT ASM
%type <fn> order_verb asm
%type <fn> exp literal name //ast
%type <fn> variable name_call argu_list
%type <fn> order_stmt other_sstmt order_action if_stmt once_stmt matched unmatched cstmt variables assignment block//stmt
%type <fn> stmts stmt_list //stmts
%type <fn> variable_list //asts

%nonassoc ASM
%left OR
%left AND
%right NOT
%left '=' CMP
%left ADD SUB
%left MUL DIV
%left LSB RSB
%right UNARY

%%

start: stmts { root = $1; }

stmts: /* empty */ { $$ = stmtsV.create(); }
     | stmt_list
     | if_stmt     { $$ = stmtsV.createI($1); }
     | stmt_list if_stmt { $$ = stmtsV.putI($1, $2); }
;

stmt_list: if_stmt ';' { $$ = stmtsV.createI($1); }
         | ';'         { $$ = stmtsV.create();    }
         | cstmt       { $$ = stmtsV.createI($1); }
         | stmt_list ';'
         | stmt_list if_stmt ';' { $$ = stmtsV.putI($1, $2); }
         | stmt_list cstmt       { $$ = stmtsV.putI($1, $2); }
;

other_sstmt: once_stmt
     |       order_stmt
     |       assignment
     |       name_call
{
  func_stmt fs;
  fs.func = $1;
  $$ = stmtV.put(fs);
}
     |       block
;

cstmt: inputs { $$ = -1; }
     | variables
;

inputs: INPUTS COL variable_list ';' 
{
  putInput($3);
}
;

variables: VARIABLES COL variable_list ';'
{
  var_stmt vs;
  vs.vars = $3;
  $$ = stmtV.put(vs);
}
;

variable_list: variable
{
  $$ = astsV.createI($1);
}
| variable_list ',' variable
{
  $$ = astsV.putI($1, $3);
}
;

variable: name '(' exp ')' 
{
  $$ = newast(NodeType::VARDEC, $1, $3);
}
        | IBP name '(' exp ')' 
{
  $$ = newast(NodeType::IBPVARDEC, $2, $4);
}
;

if_stmt:    matched
      |     unmatched
;

matched:    other_sstmt
      |     IF exp THEN matched ELSE matched
{
  if_stmt i;
  i.con = $2;
  i.then = $4;
  i.els = $6;
  $$ = stmtV.put(i);
}
;

unmatched:  IF exp THEN if_stmt
{
  if_stmt i;
  i.con = $2;
  i.then = $4;
  i.els = -1;
  $$ = stmtV.put(i);
}
      |     IF exp THEN matched ELSE unmatched
{
  if_stmt i;
  i.con = $2;
  i.then = $4;
  i.els = $6;
  $$ = stmtV.put(i);
}
;

once_stmt: ONCE block
{
  once_stmt o;
  o.con = -1;
  o.block = $2;
  $$ = stmtV.put(o);
}
         | ONCE exp block
{
  once_stmt o;
  o.con = $2;
  o.block = $3;
  $$ = stmtV.put(o);
}
;

order_stmt: order_verb order_action
{
  auto &oa = boost::get<order_stmt>(stmtV[$$ = $2]);
  oa.num = -1;
  oa.op = $1;
}
;

order_verb: BUY  { $$ = 0; }
      |     SELL { $$ = 1; }
      |     BUY TO COVER { $$ = 2; }
      |     BUYTOCOVER   { $$ = 2; }
      |     SELL SHORT { $$ = 3; }
      |     SELLSHORT  { $$ = 3; }
;

order_action: NEXT BAR MARKET
{
  order_stmt o;
  o.type = 0;
  $$ = stmtV.put(o);
}
      |       NEXT BAR exp STOP
      {
	order_stmt o;
	o.type = 1;
	o.price = $3;
	$$ = stmtV.put(o);
      }
      |       NEXT BAR exp LIMIT
      {
	order_stmt o;
	o.type = 2;
	o.price = $3;
	$$ = stmtV.put(o);
      }
      |       THIS BAR CLOSE
      {
	order_stmt o;
	o.type = 3;
	$$ = stmtV.put(o);
      }
;

assignment: name asm exp //%prec ASM
{
  asm_stmt as;
  as.var = $1;
  as.type = $2;
  as.exp = $3;
  $$ = stmtV.put(as);
}
;

asm: '=' { $$ = 0; }
   | ASM
;

exp: exp MUL exp { $$ = newast(NodeType::MUL, $1, $3); }
   | exp DIV exp { $$ = newast(NodeType::DIV, $1, $3); }
   | exp ADD exp { $$ = newast(NodeType::ADD, $1, $3); }
   | exp SUB exp { $$ = newast(NodeType::SUB, $1, $3); }
   | exp AND exp { $$ = newast(NodeType::AND, $1, $3); }
   | exp OR exp  { $$ = newast(NodeType::OR,  $1, $3); }
   | NOT exp     { $$ = newast(NodeType::NOT, $2, -1); }
   | exp '=' exp { $$ = newcmp(0,  $1, $3); }
   | exp CMP exp { $$ = newcmp($2, $1, $3); }
   | SUB exp %prec UNARY { $$ = newast(NodeType::UMINUS, $2, -1); }
   | ADD exp %prec UNARY  { $$ = $2; }
   | '(' exp ')'  { $$ = $2; }
   | exp LSB exp RSB { $$ = newast(NodeType::BAR, $1, $3); }
   | literal
   | name_call
;

name: NAME  { $$ = newname($1); }
    | CLOSE { $$ = newname(0); }

name_call: name { $$ = newast(NodeType::FUNC, $1, -1); }
      |    name '(' argu_list ')' { $$ = newast(NodeType::FUNC, $1, $3); }
;

argu_list: exp { $$ = newast(NodeType::ARGU, $1, -1); }
      |    argu_list ',' exp { $$ = newast(NodeType::ARGU, $1, $3); }
;

literal: NUMBER { $$ = newdouble($1); }
      |  TRUE   { $$ = newtf(true); }
      |  FALSE  { $$ = newtf(false); }
      |  TEXT   { $$ = newtext($1); }
;

block: BBEGIN stmts BEND
{
  block_stmt bs;
  bs.stmts = $2;
  $$ = stmtV.put(bs);
}
;
%%

