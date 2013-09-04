/* A Bison parser, made by GNU Bison 2.7.1.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "el.y"

#include <stdio.h>
#include "tree.h"
#include "operator.h"
extern int yylex();
extern void yyerror(char *s, ...);


/* Line 371 of yacc.c  */
#line 77 "el.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "el.tab.h".  */
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
     NUMBER = 260,
     TRUE = 261,
     FALSE = 262,
     TEXT = 263,
     CLOSE = 264,
     THIS = 265,
     NEXT = 266,
     BAR = 267,
     MARKET = 268,
     STOP = 269,
     LIMIT = 270,
     VOLUMN = 271,
     NAME = 272,
     CMP = 273,
     ASM = 274,
     ADD = 275,
     SUB = 276,
     MUL = 277,
     DIV = 278,
     LSB = 279,
     RSB = 280,
     COL = 281,
     COM = 282,
     BUY = 283,
     SELL = 284,
     SHORT = 285,
     SELLSHORT = 286,
     TO = 287,
     COVER = 288,
     BUYTOCOVER = 289,
     PLOT1 = 290,
     IF = 291,
     THEN = 292,
     ELSE = 293,
     AND = 294,
     OR = 295,
     BBEGIN = 296,
     BEND = 297,
     ASS = 298,
     UNARY = 299
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 10 "el.y"

  int fn;


/* Line 387 of yacc.c  */
#line 169 "el.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 197 "el.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    13,    16,    18,
      20,    23,    27,    30,    32,    34,    36,    38,    40,    42,
      47,    52,    54,    58,    63,    65,    67,    69,    76,    81,
      88,    91,    93,    95,    99,   101,   104,   106,   110,   115,
     120,   124,   128,   132,   136,   140,   144,   148,   152,   156,
     160,   163,   166,   170,   175,   177,   179,   181,   183,   185,
     190,   192,   196,   198,   200,   202,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    -1,    52,    -1,    59,    -1,
      52,    59,    -1,    59,    45,    -1,    45,    -1,    54,    -1,
      52,    45,    -1,    52,    59,    45,    -1,    52,    54,    -1,
      62,    -1,    65,    -1,    68,    -1,    71,    -1,    55,    -1,
      56,    -1,     3,    26,    57,    45,    -1,     4,    26,    57,
      45,    -1,    58,    -1,    57,    46,    58,    -1,    67,    47,
      66,    48,    -1,    60,    -1,    61,    -1,    53,    -1,    36,
      66,    37,    60,    38,    60,    -1,    36,    66,    37,    59,
      -1,    36,    66,    37,    60,    38,    61,    -1,    63,    64,
      -1,    28,    -1,    29,    -1,    28,    32,    33,    -1,    34,
      -1,    29,    30,    -1,    31,    -1,    11,    12,    13,    -1,
      11,    12,    66,    14,    -1,    11,    12,    66,    15,    -1,
      10,    12,     9,    -1,    67,    19,    66,    -1,    66,    22,
      66,    -1,    66,    23,    66,    -1,    66,    20,    66,    -1,
      66,    21,    66,    -1,    66,    39,    66,    -1,    66,    40,
      66,    -1,    66,    19,    66,    -1,    66,    18,    66,    -1,
      21,    66,    -1,    20,    66,    -1,    47,    66,    48,    -1,
      66,    24,    66,    25,    -1,    70,    -1,    68,    -1,    17,
      -1,     9,    -1,    67,    -1,    67,    47,    69,    48,    -1,
      66,    -1,    69,    46,    66,    -1,     5,    -1,     6,    -1,
       7,    -1,     8,    -1,    41,    51,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    49,    50,    51,    52,    55,    56,    57,
      58,    59,    60,    63,    64,    65,    71,    74,    75,    78,
      84,    92,    96,   102,   108,   109,   112,   113,   123,   131,
     141,   149,   150,   151,   152,   153,   154,   157,   163,   170,
     177,   185,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   210,   211,   213,   214,
     217,   218,   221,   222,   223,   224,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INPUTS", "VARIABLES", "NUMBER", "TRUE",
  "FALSE", "TEXT", "CLOSE", "THIS", "NEXT", "BAR", "MARKET", "STOP",
  "LIMIT", "VOLUMN", "NAME", "CMP", "ASM", "ADD", "SUB", "MUL", "DIV",
  "LSB", "RSB", "COL", "COM", "BUY", "SELL", "SHORT", "SELLSHORT", "TO",
  "COVER", "BUYTOCOVER", "PLOT1", "IF", "THEN", "ELSE", "AND", "OR",
  "BBEGIN", "BEND", "ASS", "UNARY", "';'", "','", "'('", "')'", "$accept",
  "start", "stmts", "stmt_list", "other_sstmt", "cstmt", "inputs",
  "variables", "variable_list", "variable", "if_stmt", "matched",
  "unmatched", "order_stmt", "order_verb", "order_action", "assignment",
  "exp", "name", "name_call", "argu_list", "literal", "block", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    59,    44,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    53,    53,    53,    53,    54,    54,    55,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     2,     1,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     3,     4,     1,     1,     1,     6,     4,     6,
       2,     1,     1,     3,     1,     2,     1,     3,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     4,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    57,    56,    31,    32,    36,    34,     0,
       3,     8,     0,     2,     4,    26,     9,    17,    18,     5,
      24,    25,    13,     0,    14,    58,    15,    16,     0,     0,
       0,    35,    62,    63,    64,    65,     0,     0,     0,     0,
      58,    55,    54,     0,     1,    10,    12,     6,     7,     0,
       0,    30,     0,     0,     0,    21,     0,     0,    33,    51,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    11,     0,     0,    41,    60,     0,    19,
       0,     0,    20,    52,    49,    48,    44,    45,    42,    43,
       0,    28,    24,    46,    47,    40,    37,     0,     0,    59,
      22,     0,    53,     0,    38,    39,    61,    23,    27,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    54,    55,
      19,    20,    21,    22,    23,    51,    24,    39,    40,    41,
      78,    42,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
      43,   -13,    15,   -67,   -67,    10,    14,   -67,   -67,   122,
      43,   -67,    45,   -67,    64,   -67,   -67,   -67,   -67,     3,
     -67,   -67,   -67,    12,   -67,    -7,   -67,   -67,    -1,    -1,
      17,   -67,   -67,   -67,   -67,   -67,   122,   122,   122,   197,
       4,   -67,   -67,    11,   -67,   -67,   -67,     9,   -67,    44,
      46,   -67,   122,   122,   -21,   -67,     8,   -19,   -67,   -67,
     -67,   152,   122,   122,   122,   122,   122,   122,   122,   127,
     122,   122,   -67,   -67,    50,   105,   228,   228,   -39,   -67,
      -1,   122,   -67,   -67,   166,   166,    -5,    -5,    37,    37,
     220,   -67,    24,   204,   251,   -67,   -67,   190,   122,   -67,
     -67,   159,   -67,   127,   -67,   -67,   228,   -67,   -67,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,    53,   -67,   -67,    51,   -67,   -67,    35,    -4,
     -12,   -66,   -28,   -67,   -67,   -67,   -67,   -32,     0,     1,
     -67,   -67,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int8 yytable[] =
{
      25,    26,    47,    92,    59,    60,    61,    98,     3,    99,
      25,    26,    52,    28,    25,    26,     4,    66,    67,    68,
      76,    77,    49,    50,    79,    80,    82,    80,    56,    56,
      84,    85,    86,    87,    88,    89,    90,   108,    93,    94,
      53,    29,    30,    97,    31,    44,     1,     2,    48,   101,
      58,    53,     3,    72,    73,    81,    74,    91,    75,    95,
       4,    68,   103,    43,    57,    46,   106,     1,     2,    25,
      26,     5,     6,     3,     7,   109,   100,     8,     0,     9,
      56,     4,     0,     0,    10,     0,     0,     0,    11,     0,
       0,     0,     5,     6,     0,     7,     0,     0,     8,     0,
       9,     0,     0,    25,    26,    10,     0,     0,     0,    45,
      32,    33,    34,    35,     3,     0,     0,     0,    96,     0,
       0,     0,     4,     0,     0,    36,    37,    32,    33,    34,
      35,     3,     0,     0,     0,     0,     3,     0,     0,     4,
       0,     0,    36,    37,     4,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     5,     6,     0,     7,     0,
       0,     8,     0,     9,     0,     0,     0,     0,    10,    38,
      62,    63,    64,    65,    66,    67,    68,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    64,    65,    66,    67,
      68,    70,    71,     0,     0,     0,     0,     0,    70,    71,
      83,     0,     0,     0,   104,   105,     0,   107,    62,    63,
      64,    65,    66,    67,    68,    62,    63,    64,    65,    66,
      67,    68,    62,    63,    64,    65,    66,    67,    68,    70,
      71,     0,     0,     0,    69,     0,    70,    71,    62,    63,
      64,    65,    66,    67,    68,   102,    62,    63,    64,    65,
      66,    67,    68,     0,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,     0,     0,     0,    70,    71,    62,
      63,    64,    65,    66,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int8 yycheck[] =
{
       0,     0,    14,    69,    36,    37,    38,    46,     9,    48,
      10,    10,    19,    26,    14,    14,    17,    22,    23,    24,
      52,    53,    10,    11,    45,    46,    45,    46,    28,    29,
      62,    63,    64,    65,    66,    67,    68,   103,    70,    71,
      47,    26,    32,    75,    30,     0,     3,     4,    45,    81,
      33,    47,     9,    42,    45,    47,    12,    69,    12,     9,
      17,    24,    38,    10,    29,    14,    98,     3,     4,    69,
      69,    28,    29,     9,    31,   103,    80,    34,    -1,    36,
      80,    17,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    28,    29,    -1,    31,    -1,    -1,    34,    -1,
      36,    -1,    -1,   103,   103,    41,    -1,    -1,    -1,    45,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,     9,    -1,    -1,    17,
      -1,    -1,    20,    21,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    28,    29,    -1,    31,    -1,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    47,
      18,    19,    20,    21,    22,    23,    24,    18,    19,    20,
      21,    22,    23,    24,    18,    19,    20,    21,    22,    23,
      24,    39,    40,    -1,    -1,    -1,    -1,    -1,    39,    40,
      48,    -1,    -1,    -1,    14,    15,    -1,    48,    18,    19,
      20,    21,    22,    23,    24,    18,    19,    20,    21,    22,
      23,    24,    18,    19,    20,    21,    22,    23,    24,    39,
      40,    -1,    -1,    -1,    37,    -1,    39,    40,    18,    19,
      20,    21,    22,    23,    24,    25,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    17,    28,    29,    31,    34,    36,
      41,    45,    50,    51,    52,    53,    54,    55,    56,    59,
      60,    61,    62,    63,    65,    67,    68,    71,    26,    26,
      32,    30,     5,     6,     7,     8,    20,    21,    47,    66,
      67,    68,    70,    51,     0,    45,    54,    59,    45,    10,
      11,    64,    19,    47,    57,    58,    67,    57,    33,    66,
      66,    66,    18,    19,    20,    21,    22,    23,    24,    37,
      39,    40,    42,    45,    12,    12,    66,    66,    69,    45,
      46,    47,    45,    48,    66,    66,    66,    66,    66,    66,
      66,    59,    60,    66,    66,     9,    13,    66,    46,    48,
      58,    66,    25,    38,    14,    15,    66,    48,    60,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 47 "el.y"
    { root = (yyvsp[(1) - (1)].fn); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 49 "el.y"
    { (yyval.fn) = stmtsV.create(); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 51 "el.y"
    { (yyval.fn) = stmtsV.createI((yyvsp[(1) - (1)].fn)); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 52 "el.y"
    { (yyval.fn) = stmtsV.putI((yyvsp[(1) - (2)].fn), (yyvsp[(2) - (2)].fn)); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 55 "el.y"
    { (yyval.fn) = stmtsV.createI((yyvsp[(1) - (2)].fn)); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 56 "el.y"
    { (yyval.fn) = stmtsV.create();    }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 57 "el.y"
    { (yyval.fn) = stmtsV.createI((yyvsp[(1) - (1)].fn)); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 59 "el.y"
    { (yyval.fn) = stmtsV.putI((yyvsp[(1) - (3)].fn), (yyvsp[(2) - (3)].fn)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 60 "el.y"
    { (yyval.fn) = stmtsV.putI((yyvsp[(1) - (2)].fn), (yyvsp[(2) - (2)].fn)); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 66 "el.y"
    {
  func_stmt fs;
  fs.func = (yyvsp[(1) - (1)].fn);
  (yyval.fn) = stmtV.put(fs);
}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 74 "el.y"
    { (yyval.fn) = -1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 79 "el.y"
    {
  putInput((yyvsp[(3) - (4)].fn));
}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 85 "el.y"
    {
  var_stmt vs;
  vs.vars = (yyvsp[(3) - (4)].fn);
  (yyval.fn) = stmtV.put(vs);
}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 93 "el.y"
    {
  (yyval.fn) = astsV.createI((yyvsp[(1) - (1)].fn));
}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 97 "el.y"
    {
  (yyval.fn) = astsV.putI((yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn));
}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 103 "el.y"
    {
  (yyval.fn) = newast(NodeType::VARDEC, (yyvsp[(1) - (4)].fn), (yyvsp[(3) - (4)].fn));
}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 114 "el.y"
    {
  if_stmt i;
  i.con = (yyvsp[(2) - (6)].fn);
  i.then = (yyvsp[(4) - (6)].fn);
  i.els = (yyvsp[(6) - (6)].fn);
  (yyval.fn) = stmtV.put(i);
}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 124 "el.y"
    {
  if_stmt i;
  i.con = (yyvsp[(2) - (4)].fn);
  i.then = (yyvsp[(4) - (4)].fn);
  i.els = -1;
  (yyval.fn) = stmtV.put(i);
}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 132 "el.y"
    {
  if_stmt i;
  i.con = (yyvsp[(2) - (6)].fn);
  i.then = (yyvsp[(4) - (6)].fn);
  i.els = (yyvsp[(6) - (6)].fn);
  (yyval.fn) = stmtV.put(i);
}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 142 "el.y"
    {
  auto oa = boost::get<order_stmt>(stmtV[(yyval.fn) = (yyvsp[(2) - (2)].fn)]);
  oa.num = -1;
  oa.op = (yyvsp[(1) - (2)].fn);
}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 149 "el.y"
    { (yyval.fn) = 0; }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 150 "el.y"
    { (yyval.fn) = 1; }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 151 "el.y"
    { (yyval.fn) = 2; }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 152 "el.y"
    { (yyval.fn) = 2; }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 153 "el.y"
    { (yyval.fn) = 3; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 154 "el.y"
    { (yyval.fn) = 3; }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 158 "el.y"
    {
  order_stmt o;
  o.type = 0;
  (yyval.fn) = stmtV.put(o);
}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 164 "el.y"
    {
	order_stmt o;
	o.type = 1;
	o.price = (yyvsp[(3) - (4)].fn);
	(yyval.fn) = stmtV.put(o);
      }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 171 "el.y"
    {
	order_stmt o;
	o.type = 2;
	o.price = (yyvsp[(3) - (4)].fn);
	(yyval.fn) = stmtV.put(o);
      }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 178 "el.y"
    {
	order_stmt o;
	o.type = 3;
	(yyval.fn) = stmtV.put(o);
      }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 186 "el.y"
    {
  asm_stmt as;
  as.var = (yyvsp[(1) - (3)].fn);
  as.exp = (yyvsp[(3) - (3)].fn);
  (yyval.fn) = stmtV.put(as);
}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 194 "el.y"
    { (yyval.fn) = newast(NodeType::MUL, (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 195 "el.y"
    { (yyval.fn) = newast(NodeType::DIV, (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 196 "el.y"
    { (yyval.fn) = newast(NodeType::ADD, (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 197 "el.y"
    { (yyval.fn) = newast(NodeType::SUB, (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 198 "el.y"
    { (yyval.fn) = newast(NodeType::AND, (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 199 "el.y"
    { (yyval.fn) = newast(NodeType::OR,  (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 200 "el.y"
    { (yyval.fn) = newcmp(0,  (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 201 "el.y"
    { (yyval.fn) = newcmp((yyvsp[(2) - (3)].fn), (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 202 "el.y"
    { (yyval.fn) = newast(NodeType::UMINUS, (yyvsp[(2) - (2)].fn), NULL); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 203 "el.y"
    { (yyval.fn) = (yyvsp[(2) - (2)].fn); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 204 "el.y"
    { (yyval.fn) = (yyvsp[(2) - (3)].fn); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 205 "el.y"
    { (yyval.fn) = newast(NodeType::BAR, (yyvsp[(1) - (4)].fn), (yyvsp[(3) - (4)].fn)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 210 "el.y"
    { (yyval.fn) = newname((yyvsp[(1) - (1)].fn)); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 211 "el.y"
    { (yyval.fn) = newname(0); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 213 "el.y"
    { (yyval.fn) = newast(NodeType::FUNC, (yyvsp[(1) - (1)].fn), -1); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 214 "el.y"
    { (yyval.fn) = newast(NodeType::FUNC, (yyvsp[(1) - (4)].fn), (yyvsp[(3) - (4)].fn)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 217 "el.y"
    { (yyval.fn) = newast(NodeType::ARGU, (yyvsp[(1) - (1)].fn), -1); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 218 "el.y"
    { (yyval.fn) = newast(NodeType::ARGU, (yyvsp[(1) - (3)].fn), (yyvsp[(3) - (3)].fn)); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 221 "el.y"
    { (yyval.fn) = newdouble((yyvsp[(1) - (1)].fn)); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 222 "el.y"
    { (yyval.fn) = newtf(true); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 223 "el.y"
    { (yyval.fn) = newtf(false); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 224 "el.y"
    { (yyval.fn) = newtext((yyvsp[(1) - (1)].fn)); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 228 "el.y"
    {
  block_stmt bs;
  bs.stmts = (yyvsp[(2) - (3)].fn);
  (yyval.fn) = stmtV.put(bs);
}
    break;


/* Line 1787 of yacc.c  */
#line 1913 "el.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 234 "el.y"


