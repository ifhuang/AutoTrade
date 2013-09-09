%{
#include "tree.h"
extern int yylex();
%}

%union{
  int fn;
}

%define parse.error verbose
%define parse.lac full

%token INPUTS VARIABLES IBP
%token NUMBER TRUE FALSE TEXT
%token OPEN CLOSE THIS NEXT BAR MARKET STOP LIMIT ALL
%token VOLUMN NAME 
 // operator
%token CMP ASM ADD SUB MUL DIV LSB RSB
%token COL COM CROSS ABOVE BELOW

%token BUY SELL SHORT SELLSHORT TO COVER BUYTOCOVER SHARE
%token PLOT1
%token IF THEN ELSE AND OR NOT ONCE FOR DOWNTO WHILE REPEAT UNTIL
%token BBEGIN BEND 


%type <fn> CMP NUMBER NAME TEXT ASM
%type <fn> order_verb asm order_amount order_name for_type order_time
%type <fn> exp literal name text //ast
%type <fn> variable name_call
%type <fn> order_stmt other_sstmt order_action if_stmt matched_once unmatched_once once_matched for_stmt while_stmt repeat_stmt matched unmatched cstmt variables assignment block //stmt
%type <fn> stmts stmt_list //stmts
%type <fn> variable_list argu_list //asts

%left OR
%left AND
%precedence NOT
%left '=' CMP CROSS ABOVE BELOW
%left ADD SUB
%left MUL DIV
%precedence LSB
%precedence UNARY

%%

start: stmts { root = $1; }

stmts: %empty { $$ = stmtsV.create(); }
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

other_sstmt: matched_once
     |       for_stmt
     |       while_stmt
     |       repeat_stmt
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

unmatched:  unmatched_once
      |     IF exp THEN if_stmt
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

unmatched_once: ONCE unmatched             { $$ = new_once(-1, $2); }
              | ONCE '(' exp ')' unmatched { $$ = new_once($3, $5); }
;

matched_once: ONCE once_matched             { $$ = new_once(-1, $2); }
            | ONCE '(' exp ')' once_matched { $$ = new_once($3, $5); }
;

once_matched: %empty { $$ = -1; }
            | matched
;

for_stmt: FOR name '=' exp for_type exp block
{
    for_stmt fs;
    fs.var = $2;
    fs.type = $5;
    fs.from = $4;
    fs.to = $6;
    fs.block = $7;
    $$ = stmtV.put(fs);
}
;

for_type: TO { $$ = 0; }
        | DOWNTO { $$ = 1; }
        ;

while_stmt: WHILE exp block
{
  while_stmt ws;
  ws.type = 0;
  ws.con = $2;
  ws.block = $3;
  $$ = stmtV.put(ws);
}
;

repeat_stmt: REPEAT stmt_list UNTIL exp
{
  while_stmt ws;
  ws.type = 1;
  ws.con = $4;
  ws.block = $2;
  $$ = stmtV.put(ws);
}
           | REPEAT UNTIL exp
{
  while_stmt ws;
  ws.type = 1;
  ws.con = $3;
  ws.block = -1;
  $$ = stmtV.put(ws);
}
;

order_stmt: order_verb order_name order_amount order_time order_action
{
  auto &oa = boost::get<order_stmt>(stmtV[$$ = $5]);
  oa.op = $1;
  oa.name = $2;
  oa.num = $3;
  oa.time = $4;
}
;

order_verb: BUY  { $$ = 0; }
      |     SELL { $$ = 1; }
      |     BUY TO COVER { $$ = 2; }
      |     BUYTOCOVER   { $$ = 2; }
      |     SELL SHORT { $$ = 3; }
      |     SELLSHORT  { $$ = 3; }
;

order_name: %empty  { $$ = -1; }
 //  |     exp { $$ = $1; }
      ;

order_amount: %empty { $$ = -1; }
      |       exp SHARE
      |       ALL SHARE { $$ = -2; }
      ;

order_time: THIS BAR { $$ = 0; }
          | NEXT BAR { $$ = 1; }
;

order_action: MARKET    { $$ = new_order(0, -1); }
            | OPEN      { $$ = new_order(0, -1); }
            | exp STOP  { $$ = new_order(1, $1); }
            | exp LIMIT { $$ = new_order(2, $1); }
            | CLOSE     { $$ = new_order(3, -1); }
            | %empty    { $$ = new_order(3, -1); }
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
   | exp CROSS ABOVE exp { $$ = newcmp(6, $1, $4); }
   | exp CROSS BELOW exp { $$ = newcmp(7, $1, $4); }
   | SUB exp %prec UNARY { $$ = newast(NodeType::UMINUS, $2, -1); }
   | ADD exp %prec UNARY  { $$ = $2; }
   | '(' exp ')'  { $$ = $2; }
   | exp LSB exp RSB { $$ = newast(NodeType::BAR, $1, $3); }
   | literal
   | name_call
;

name: NAME  { $$ = newname($1); }
    | CLOSE { $$ = newname(0); }
;

name_call: name { $$ = newast(NodeType::FUNC, $1, -1); }
      |    name '(' ')' { $$ = newast(NodeType::FUNC, $1, -1); }
      |    name '(' argu_list ')' { $$ = newast(NodeType::FUNC, $1, $3); }
;

argu_list: exp { $$ = astsV.createI($1); }
      |    argu_list ',' exp { $$ = astsV.putI($1, $3); }
;

literal: NUMBER { $$ = newdouble($1); }
      |  TRUE   { $$ = newtf(true); }
      |  FALSE  { $$ = newtf(false); }
      |  text
;

text: TEXT   { $$ = newtext($1); } ;

block: BBEGIN stmt_list BEND
{
  block_stmt bs;
  bs.stmts = $2;
  $$ = stmtV.put(bs);
}
     | BBEGIN BEND { $$ = -1; }
;
%%
