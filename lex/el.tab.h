/* A Bison parser, made by GNU Bison 3.0.  */

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INPUTS = 258,
    VARIABLES = 259,
    IBP = 260,
    NUMBER = 261,
    TRUE = 262,
    FALSE = 263,
    TEXT = 264,
    OPEN = 265,
    CLOSE = 266,
    THIS = 267,
    NEXT = 268,
    BAR = 269,
    MARKET = 270,
    STOP = 271,
    LIMIT = 272,
    ALL = 273,
    VOLUMN = 274,
    NAME = 275,
    CMP = 276,
    ASM = 277,
    ADD = 278,
    SUB = 279,
    MUL = 280,
    DIV = 281,
    LSB = 282,
    RSB = 283,
    CROSS = 284,
    ABOVE = 285,
    BELOW = 286,
    BUY = 287,
    SELL = 288,
    SHORT = 289,
    SELLSHORT = 290,
    TO = 291,
    COVER = 292,
    BUYTOCOVER = 293,
    SHARE = 294,
    PLOT1 = 295,
    IF = 296,
    THEN = 297,
    ELSE = 298,
    AND = 299,
    OR = 300,
    NOT = 301,
    ONCE = 302,
    FOR = 303,
    DOWNTO = 304,
    WHILE = 305,
    REPEAT = 306,
    UNTIL = 307,
    BBEGIN = 308,
    BEND = 309,
    PRINT = 310,
    PRINTER = 311,
    PFILE = 312,
    UNARY = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 6 "el.y" /* yacc.c:1909  */

  int fn;

#line 117 "el.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EL_TAB_H_INCLUDED  */
