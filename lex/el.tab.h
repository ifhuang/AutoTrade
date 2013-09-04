/* A Bison parser, made by GNU Bison 2.7.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_EL_TAB_H_INCLUDED
# define YY_YY_EL_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INPUTS = 258,
     VARIABLES = 259,
     IBP = 260,
     NUMBER = 261,
     TRUE = 262,
     FALSE = 263,
     TEXT = 264,
     CLOSE = 265,
     THIS = 266,
     NEXT = 267,
     BAR = 268,
     MARKET = 269,
     STOP = 270,
     LIMIT = 271,
     VOLUMN = 272,
     NAME = 273,
     CMP = 274,
     ASM = 275,
     ADD = 276,
     SUB = 277,
     MUL = 278,
     DIV = 279,
     LSB = 280,
     RSB = 281,
     COL = 282,
     COM = 283,
     BUY = 284,
     SELL = 285,
     SHORT = 286,
     SELLSHORT = 287,
     TO = 288,
     COVER = 289,
     BUYTOCOVER = 290,
     PLOT1 = 291,
     IF = 292,
     THEN = 293,
     ELSE = 294,
     AND = 295,
     OR = 296,
     ONCE = 297,
     BBEGIN = 298,
     BEND = 299,
     UNARY = 300
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 10 "el.y"

  int fn;


/* Line 2053 of yacc.c  */
#line 107 "el.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_EL_TAB_H_INCLUDED  */
