%{
#include "tree.h"
extern int yylex();
%}

%union{
  int fn;
}

%define parse.error verbose
%define parse.lac full

%token INPUTS VARIABLES IBP ARRAYS
%token NUMBER TRUE FALSE TEXT
%token OPEN CLOSE THIS NEXT BAR MARKET STOP LIMIT ALL
%token VOLUMN NAME 
 // operator
%token CMP ASM ADD SUB MUL DIV LSB RSB
%token CROSS ABOVE BELOW

%token BUY SELL SHORT SELLSHORT TO COVER BUYTOCOVER SHARE
%token PLOT1
%token IF THEN ELSE AND OR NOT ONCE FOR DOWNTO WHILE REPEAT UNTIL
%token SWITCH DEFAULT CASE
%token BBEGIN BEND 
%token PRINT PRINTER PFILE


%type <fn> CMP NUMBER NAME TEXT ASM
%type <fn> order_verb asm order_amount order_name for_type order_time print_location
%type <fn> exp nexp literal number name text variable array name_call print_element //ast
%type <fn> order_stmt other_sstmt order_action if_stmt matched_once unmatched_once once_matched for_stmt while_stmt repeat_stmt matched unmatched cstmt variables arrays assignment block print_stmt //stmt
%type <fn> stmts stmt_list //stmts
%type <fn> variable_list argu_list print_list array_list dimension_list //asts

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
     |       switch_stmt
     |       order_stmt
     |       assignment
     |       name_call
     {
         func_stmt fs;
         fs.func = $1;
         $$ = stmtV.put(fs);
     }
     |       block
     |       print_stmt
     ;

cstmt: inputs { $$ = -1; }
     | variables
     | arrays
     ;

inputs: INPUTS ':' variable_list ';' { putInput($3); } ;

variables: VARIABLES ':' variable_list ';' { $$ = new_var(0, $3); } ;

variable_list: variable                   { $$ = astsV.createI($1); }
             | variable_list ',' variable { $$ = astsV.putI($1, $3); }
             ;

variable: name '(' exp ')'     { $$ = newast(NodeType::VARDEC, $1, $3); }
  //      | IBP name '(' exp ')' { $$ = newast(NodeType::IBPVARDEC, $2, $4); }
        ;

arrays: ARRAYS ':' array_list ';' { $$ = new_var(1, $3); } ;

array_list: array                { $$ = astsV.createI($1); }
          | array_list ',' array { $$ = astsV.putI($1, $3); }
          ;

array: name LSB dimension_list RSB '(' exp ')'
       { $$ = newast(NodeType::ARRDEC, $1, $6, $3); }
 //    | IBP name LSB dimension_list RSB '(' exp ')'
     ;

dimension_list: nexp                    { $$ = astsV.createI($1); }
              | dimension_list ',' nexp { $$ = astsV.putI($1, $3); }
              ;

if_stmt:    matched
      |     unmatched
      ;

matched:    other_sstmt
      |     IF exp THEN matched ELSE matched   { $$ = new_if($2, $4, $6); }
      ;

unmatched:  unmatched_once
      |     IF exp THEN if_stmt                { $$ = new_if($2, $4); }
      |     IF exp THEN matched ELSE unmatched { $$ = new_if($2, $4, $6); }
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

while_stmt: WHILE exp block { $$ = new_while(0, $2, $3); } ;

repeat_stmt: REPEAT stmt_list UNTIL exp { $$ = new_while(1, $4, $2); }
           | REPEAT UNTIL exp { $$ = new_while(1, $3, -1); }
           ;

switch_stmt: SWITCH '(' exp ')' BBEGIN section_list BEND ;

section_list: section
            | section_list section
            ;

section: case_option ':' stmt_list ;

case_option: DEFAULT
           | CASE case_list
           ;

case_list: case
         | case_list ',' case
         ;

case: exp
    | exp TO exp
    | exp DOWNTO exp
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
   | ADD exp %prec UNARY { $$ = $2; }
   | '(' exp ')' { $$ = $2; }
   | exp LSB exp RSB { $$ = newast(NodeType::BAR, $1, $3); }
   | literal
   | name_call
   ;

nexp: nexp MUL nexp { $$ = newast(NodeType::MUL, $1, $3); }
    | nexp DIV nexp { $$ = newast(NodeType::DIV, $1, $3); }
    | nexp ADD nexp { $$ = newast(NodeType::ADD, $1, $3); }
    | nexp SUB nexp { $$ = newast(NodeType::SUB, $1, $3); }
    | SUB nexp %prec UNARY { $$ = newast(NodeType::UMINUS, $2, -1); }
    | ADD nexp %prec UNARY { $$ = $2; }
    | '(' nexp ')'  { $$ = $2; }
    | number
    ;

name: NAME  { $$ = newname($1); }
    | CLOSE { $$ = newname(0); }
    ;

name_call: name { $$ = newast(NodeType::FUNC, $1, -2); }
      |    name '(' ')' { $$ = newast(NodeType::FUNC, $1, -1); }
      |    name '(' argu_list ')' { $$ = newast(NodeType::FUNC, $1, $3); }
      ;

argu_list: exp { $$ = astsV.createI($1); }
      |    argu_list ',' exp { $$ = astsV.putI($1, $3); }
      ;

literal: number
      |  TRUE   { $$ = newtf(true); }
      |  FALSE  { $$ = newtf(false); }
      |  text
      ;

number: NUMBER { $$ = newdouble($1); } ;

text: TEXT { $$ = newtext($1); } ;

block: BBEGIN stmt_list BEND
     {
         block_stmt bs;
         bs.stmts = $2;
         $$ = stmtV.put(bs);
     }
     | BBEGIN BEND { $$ = -1; }
     ;

print_stmt: PRINT { $$ = new_print(-1, -1); }
          | PRINT '(' ')' { $$ = new_print(-1, -1); }
          | PRINT '(' print_list ')' { $$ = new_print(-1, $3); }
          | PRINT '(' print_location ',' print_list ')' { $$ = new_print($3, $5); }
          ;

print_location: PRINTER { $$ = -1; }
              | PFILE '(' text ')' { $$ = $3; }
              ;

print_list: print_element                { $$ = astsV.createI($1); }
          | print_list ',' print_element { $$ = astsV.putI($1, $3); }
          ;

print_element: exp                 { $$ = newprint($1); }
             | exp ':' exp         { $$ = newprint($1, $3); }
             | exp ':' exp ':' exp { $$ = newprint($1, $3, $5); }
             ;
%%
