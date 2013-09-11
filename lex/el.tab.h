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
    ARRAYS = 261,
    NUMBER = 262,
    TRUE = 263,
    FALSE = 264,
    TEXT = 265,
    OPEN = 266,
    CLOSE = 267,
    THIS = 268,
    NEXT = 269,
    BAR = 270,
    MARKET = 271,
    STOP = 272,
    LIMIT = 273,
    ALL = 274,
    VOLUMN = 275,
    NAME = 276,
    CMP = 277,
    ASM = 278,
    ADD = 279,
    SUB = 280,
    MUL = 281,
    DIV = 282,
    LSB = 283,
    RSB = 284,
    CROSS = 285,
    ABOVE = 286,
    BELOW = 287,
    BUY = 288,
    SELL = 289,
    SHORT = 290,
    SELLSHORT = 291,
    TO = 292,
    COVER = 293,
    BUYTOCOVER = 294,
    SHARE = 295,
    PLOT1 = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    AND = 300,
    OR = 301,
    NOT = 302,
    ONCE = 303,
    FOR = 304,
    DOWNTO = 305,
    WHILE = 306,
    REPEAT = 307,
    UNTIL = 308,
    SWITCH = 309,
    DEFAULT = 310,
    CASE = 311,
    BBEGIN = 312,
    BEND = 313,
    PRINT = 314,
    PRINTER = 315,
    PFILE = 316,
    UNARY = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 6 "el.y" /* yacc.c:1909  */

  int fn;

#line 121 "el.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_EL_TAB_H_INCLUDED  */
