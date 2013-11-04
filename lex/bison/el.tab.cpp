/* A Bison parser, made by GNU Bison 3.0.  */

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "el.y" /* yacc.c:339  */

#include "bison.h"
extern int yylex();

#line 71 "el.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "el.tab.h".  */
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
#line 6 "el.y" /* yacc.c:355  */

  int fn;

#line 178 "el.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 207 "el.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   807

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      67,    68,     2,     2,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,    64,
       2,    62,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    50,    51,    52,    53,    56,    57,    58,
      59,    60,    61,    64,    65,    68,    69,    70,    71,    72,
      73,    74,    75,    81,    82,    85,    86,    87,    90,    92,
      94,    95,    98,   102,   104,   105,   108,   113,   114,   117,
     118,   121,   122,   125,   126,   127,   130,   131,   134,   135,
     138,   139,   142,   154,   155,   158,   161,   163,   172,   173,
     176,   178,   179,   182,   183,   186,   187,   188,   191,   202,
     203,   204,   205,   206,   207,   210,   214,   215,   216,   219,
     220,   223,   224,   225,   226,   227,   228,   231,   242,   243,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   265,   266,   267,
     268,   269,   270,   271,   272,   275,   276,   279,   280,   281,
     284,   285,   288,   289,   290,   291,   294,   296,   298,   304,
     307,   308,   309,   310,   313,   314,   317,   318,   321,   322,
     323
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INPUTS", "VARIABLES", "IBP", "ARRAYS",
  "NUMBER", "TRUE", "FALSE", "TEXT", "OPEN", "CLOSE", "THIS", "NEXT",
  "BAR", "MARKET", "STOP", "LIMIT", "ALL", "VOLUMN", "NAME", "CMP", "ASM",
  "ADD", "SUB", "MUL", "DIV", "LSB", "RSB", "CROSS", "ABOVE", "BELOW",
  "BUY", "SELL", "SHORT", "SELLSHORT", "TO", "COVER", "BUYTOCOVER",
  "SHARE", "PLOT1", "IF", "THEN", "ELSE", "AND", "OR", "NOT", "ONCE",
  "FOR", "DOWNTO", "WHILE", "REPEAT", "UNTIL", "SWITCH", "DEFAULT", "CASE",
  "BBEGIN", "BEND", "PRINT", "PRINTER", "PFILE", "'='", "UNARY", "';'",
  "':'", "','", "'('", "')'", "$accept", "start", "stmts", "stmt_list",
  "stmt_list_optional", "other_sstmt", "cstmt", "inputs", "variables",
  "variable_list", "variable", "arrays", "array_list", "array",
  "dimension_list", "if_stmt", "matched", "unmatched", "unmatched_once",
  "matched_once", "once_matched", "for_stmt", "for_type", "while_stmt",
  "repeat_stmt", "switch_stmt", "section_list", "section", "case_option",
  "case_list", "case", "order_stmt", "order_verb", "order_name",
  "order_amount", "order_time", "order_action", "assignment", "asm", "exp",
  "nexp", "name", "name_call", "argu_list", "literal", "number", "text",
  "block", "print_stmt", "print_location", "print_list", "print_element", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    61,   317,    59,    58,    44,    40,    41
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     284,   -58,   -13,   -10,  -124,  -124,    23,    46,  -124,  -124,
     407,   408,    -4,   407,   284,    30,   160,    52,  -124,    78,
    -124,   318,  -124,  -124,  -124,  -124,  -124,    27,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    65,
    -124,  -124,  -124,    -4,    -4,    -4,    75,  -124,  -124,  -124,
    -124,  -124,   407,   407,   407,   407,   642,    53,  -124,  -124,
    -124,  -124,   407,  -124,  -124,  -124,    64,   654,   318,    76,
      27,   407,  -124,   250,    55,  -124,  -124,  -124,    66,  -124,
     388,  -124,  -124,   337,   407,   -37,  -124,    61,   -36,    -5,
    -124,   105,  -124,  -124,  -124,   732,   248,   407,   407,   407,
     407,   407,   407,    39,   437,   407,   407,   407,   473,   407,
     284,    66,   407,   480,  -124,  -124,    67,  -124,   557,    70,
      21,  -124,  -124,    97,    87,   667,  -124,   719,    24,   719,
    -124,    -4,   407,  -124,  -124,    -4,    32,  -124,   132,    14,
      14,   116,   116,   693,   407,   407,  -124,   108,   732,   207,
     132,   437,   601,    96,   719,   104,   152,   407,   407,   407,
    -124,  -124,   150,   153,   378,  -124,   407,  -124,  -124,   487,
    -124,    32,    32,    32,   -19,    11,  -124,  -124,   132,   132,
     437,  -124,  -124,  -124,  -124,   407,  -124,    51,    99,   571,
      43,  -124,  -124,  -124,  -124,     2,  -124,  -124,   546,   719,
    -124,  -124,  -124,     7,   102,    32,    32,    32,    32,    32,
    -124,  -124,   706,  -124,   407,   -32,  -124,   106,  -124,   407,
    -124,  -124,  -124,  -124,   407,    11,    91,    91,  -124,  -124,
    -124,   109,  -124,   615,  -124,  -124,   284,   719,   532,   407,
     407,   407,   318,  -124,  -124,   719,   719
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,   116,   115,    69,    70,    74,    72,
       0,    50,     0,     0,    13,     0,     0,   130,     8,     0,
       2,     4,    41,     9,    25,    26,    27,     5,    39,    40,
      43,    15,    16,    17,    18,    19,    20,    75,    21,   117,
      22,    23,    24,     0,     0,     0,     0,    73,   126,   123,
     124,   127,     0,     0,     0,     0,     0,   117,   106,   105,
     122,   125,     0,    51,    46,    48,     0,     0,    14,     0,
       0,     0,   129,     0,     0,     1,    10,    12,     6,     7,
      76,    89,    88,     0,     0,     0,    30,     0,     0,     0,
      34,     0,    71,   102,   101,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,   128,   134,     0,   131,   138,     0,
       0,   136,    11,     0,     0,     0,   118,   120,     0,    87,
      28,     0,     0,    29,    33,     0,     0,   103,    98,    92,
      93,    90,    91,     0,     0,     0,    44,    39,    94,    95,
      97,    50,     0,     0,    56,     0,     0,     0,     0,     0,
     132,    78,     0,     0,    86,    77,     0,   119,    31,     0,
      35,     0,     0,     0,     0,    37,   114,   104,    99,   100,
       0,    47,    49,    53,    54,     0,    55,     0,     0,   139,
       0,   137,    79,    80,    82,   116,    81,    68,     0,   121,
      32,   112,   111,     0,     0,     0,     0,     0,     0,     0,
      42,    45,     0,    61,     0,     0,    58,     0,   135,     0,
     133,    83,    84,   113,     0,    38,   109,   110,   107,   108,
      52,    62,    63,    65,    57,    59,     0,   140,     0,     0,
       0,     0,    60,    36,    64,    66,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,     3,    60,  -124,   -15,  -124,  -124,   133,
      45,  -124,  -124,    44,  -124,     1,    -6,    -2,  -124,  -124,
      31,  -124,  -124,  -124,  -124,  -124,  -124,   -28,  -124,  -124,
     -56,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    41,
     598,     0,     4,  -124,  -124,  -123,    33,   -24,  -124,  -124,
      34,    36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    68,    69,    22,    23,    24,    25,    85,
      86,    26,    89,    90,   174,    70,    28,    29,    30,    31,
      65,    32,   185,    33,    34,    35,   215,   216,   217,   231,
     232,    36,    37,    80,   124,   164,   197,    38,    84,   118,
     175,    57,    58,   128,    59,    60,    61,    41,    42,   119,
     120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    27,   -85,    21,    40,    63,    77,    43,     4,    64,
     204,    39,    66,   176,    39,    40,    39,     5,    40,    73,
      40,    39,    78,   213,   214,    40,   234,   130,   133,   131,
     131,   206,   207,   208,   209,   206,   207,   208,   209,    48,
     100,   101,   102,    87,    87,    91,   -85,   205,   176,   176,
     176,    56,    44,    77,    67,    45,   171,   172,    77,   134,
      46,   135,    48,    49,    50,    51,   -85,     4,    39,   111,
     144,   145,    40,    39,   111,   223,     5,    40,    75,    52,
      53,    47,   176,   176,   176,   176,   176,   159,    81,   160,
     166,    79,   167,    93,    94,    95,    96,    71,   147,   173,
     162,   163,    54,   108,    39,   146,   213,   214,    40,   159,
      39,   220,   113,    92,    40,   115,   116,   208,   209,    74,
      83,   125,    55,   117,   127,   129,   109,    82,   132,   112,
     122,    87,    83,   136,   156,    91,   158,   161,   138,   139,
     140,   141,   142,   143,   102,    63,   148,   149,   150,   181,
     152,    39,   180,   154,   186,    40,    98,    99,   100,   101,
     102,   187,    51,     1,     2,   192,     3,   218,   193,   224,
     153,   236,     4,   169,   210,   239,   168,    88,   211,   170,
      39,     5,   182,   244,    40,   178,   179,   235,   230,   188,
       0,     0,   190,     6,     7,   191,     8,     0,   189,     9,
       0,     0,    10,     0,     0,   198,     0,   199,    11,    12,
       0,    13,    14,     0,    15,     0,     0,    16,    72,    17,
       0,     0,     0,     0,    18,     0,   212,    77,     0,    97,
       0,    98,    99,   100,   101,   102,    39,   103,     0,   242,
      40,     0,    39,   111,     0,     0,    40,     0,     0,     0,
       0,     0,   105,     1,     2,   233,     3,     0,     0,     0,
     237,     0,     4,     0,     0,   238,     0,     0,     0,   107,
      97,     5,    98,    99,   100,   101,   102,     0,   103,     0,
     233,   245,   246,     6,     7,     0,     8,     1,     2,     9,
       3,     0,    10,   105,   106,     0,     4,     0,    11,    12,
       0,    13,    14,     0,    15,     5,     0,    16,   114,    17,
     107,     0,     0,     0,    76,     0,   137,     6,     7,     0,
       8,     1,     2,     9,     3,     0,    10,     0,     0,     0,
       4,     0,    11,    12,     0,    13,    14,     0,    15,     5,
       0,    16,     0,    17,    48,    49,    50,    51,    18,     4,
       0,     6,     7,     0,     8,     0,     0,     9,     5,     0,
      10,    52,    53,     0,     0,     0,    11,    12,     0,    13,
      14,     0,    15,     0,     0,    16,     0,    17,     0,     0,
       0,     0,    76,     0,    54,    48,    49,    50,    51,   194,
     195,     0,     0,     0,   196,    48,    49,    50,    51,     5,
       4,     0,    52,    53,    55,   126,     0,   123,     0,     5,
       0,     0,    52,    53,    48,    49,    50,    51,     0,     4,
       4,     0,     0,     0,     0,    54,     0,     0,     5,     5,
       0,    52,    53,     0,     0,    54,     0,     0,     0,     0,
       0,     6,     7,     0,     8,    55,     0,     9,     0,     4,
      10,     0,     0,     0,    54,    55,    11,    12,     5,    13,
      14,     0,    15,     0,     0,    16,     0,    17,     0,     0,
       6,     7,     0,     8,    55,    62,     9,     0,     0,    10,
       0,     0,     0,     0,     0,    11,    12,     0,    13,    14,
       0,    15,     0,     0,    16,    97,    17,    98,    99,   100,
     101,   102,    97,   103,    98,    99,   100,   101,   102,    97,
     103,    98,    99,   100,   101,   102,     0,   103,   105,   106,
       0,     0,     0,     0,     0,   105,   106,     0,     0,     0,
       0,     0,   105,   106,     0,   107,     0,     0,     0,     0,
       0,   151,   107,     0,     0,     0,     0,     0,   155,   107,
       0,     0,     0,     0,    97,   200,    98,    99,   100,   101,
     102,     0,   103,   221,   222,     0,     0,     0,    97,     0,
      98,    99,   100,   101,   102,     0,   103,   105,   106,    97,
       0,    98,    99,   100,   101,   102,     0,   103,     0,     0,
       0,   105,   106,    97,   107,    98,    99,   100,   101,   102,
     243,   103,   105,   106,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,   107,
       0,     0,   157,    97,     0,    98,    99,   100,   101,   102,
       0,   103,     0,   107,     0,     0,   219,    97,   183,    98,
      99,   100,   101,   102,     0,   103,   105,   106,     0,     0,
       0,   184,   240,     0,     0,     0,     0,     0,     0,     0,
     105,   106,     0,   107,    97,   241,    98,    99,   100,   101,
     102,     0,   103,     0,     0,     0,    97,   107,    98,    99,
     100,   101,   102,     0,   103,   104,     0,   105,   106,    97,
       0,    98,    99,   100,   101,   102,     0,   103,     0,   105,
     106,     0,     0,     0,   107,     0,     0,   165,     0,     0,
       0,   110,   105,   106,     0,    97,   107,    98,    99,   100,
     101,   102,   177,   103,     0,     0,     0,     0,    97,   107,
      98,    99,   100,   101,   102,     0,   103,     0,   105,   106,
       0,    97,     0,    98,    99,   100,   101,   102,     0,   103,
       0,   105,   106,     0,    97,   107,    98,    99,   100,   101,
     102,     0,   103,    16,   105,   106,     0,     0,   107,   201,
     202,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,   228,   229
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,     0,     0,    11,    21,    65,    12,    11,
      29,    11,    12,   136,    14,    11,    16,    21,    14,    16,
      16,    21,    21,    55,    56,    21,    58,    64,    64,    66,
      66,    24,    25,    26,    27,    24,    25,    26,    27,     7,
      26,    27,    28,    43,    44,    45,    44,    66,   171,   172,
     173,    10,    65,    68,    13,    65,    24,    25,    73,    64,
      37,    66,     7,     8,     9,    10,    64,    12,    68,    68,
      31,    32,    68,    73,    73,    68,    21,    73,     0,    24,
      25,    35,   205,   206,   207,   208,   209,    66,    23,    68,
      66,    64,    68,    52,    53,    54,    55,    67,   104,    67,
      13,    14,    47,    62,   104,   104,    55,    56,   104,    66,
     110,    68,    71,    38,   110,    60,    61,    26,    27,    67,
      67,    80,    67,    68,    83,    84,    62,    62,    67,    53,
      64,   131,    67,    28,    67,   135,    66,    40,    97,    98,
      99,   100,   101,   102,    28,   151,   105,   106,   107,   151,
     109,   151,    44,   112,    58,   151,    24,    25,    26,    27,
      28,    57,    10,     3,     4,    15,     6,    68,    15,    67,
     110,    65,    12,   132,   180,    66,   131,    44,   180,   135,
     180,    21,   151,   239,   180,   144,   145,   215,   212,   156,
      -1,    -1,   158,    33,    34,   159,    36,    -1,   157,    39,
      -1,    -1,    42,    -1,    -1,   164,    -1,   166,    48,    49,
      -1,    51,    52,    -1,    54,    -1,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,   185,   242,    -1,    22,
      -1,    24,    25,    26,    27,    28,   236,    30,    -1,   236,
     236,    -1,   242,   242,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    45,     3,     4,   214,     6,    -1,    -1,    -1,
     219,    -1,    12,    -1,    -1,   224,    -1,    -1,    -1,    62,
      22,    21,    24,    25,    26,    27,    28,    -1,    30,    -1,
     239,   240,   241,    33,    34,    -1,    36,     3,     4,    39,
       6,    -1,    42,    45,    46,    -1,    12,    -1,    48,    49,
      -1,    51,    52,    -1,    54,    21,    -1,    57,    58,    59,
      62,    -1,    -1,    -1,    64,    -1,    68,    33,    34,    -1,
      36,     3,     4,    39,     6,    -1,    42,    -1,    -1,    -1,
      12,    -1,    48,    49,    -1,    51,    52,    -1,    54,    21,
      -1,    57,    -1,    59,     7,     8,     9,    10,    64,    12,
      -1,    33,    34,    -1,    36,    -1,    -1,    39,    21,    -1,
      42,    24,    25,    -1,    -1,    -1,    48,    49,    -1,    51,
      52,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    64,    -1,    47,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,     7,     8,     9,    10,    21,
      12,    -1,    24,    25,    67,    68,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,     7,     8,     9,    10,    -1,    12,
      12,    -1,    -1,    -1,    -1,    47,    -1,    -1,    21,    21,
      -1,    24,    25,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    67,    -1,    39,    -1,    12,
      42,    -1,    -1,    -1,    47,    67,    48,    49,    21,    51,
      52,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,
      33,    34,    -1,    36,    67,    67,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,    52,
      -1,    54,    -1,    -1,    57,    22,    59,    24,    25,    26,
      27,    28,    22,    30,    24,    25,    26,    27,    28,    22,
      30,    24,    25,    26,    27,    28,    -1,    30,    45,    46,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    62,    -1,    -1,    -1,    -1,    -1,    68,    62,
      -1,    -1,    -1,    -1,    22,    68,    24,    25,    26,    27,
      28,    -1,    30,    17,    18,    -1,    -1,    -1,    22,    -1,
      24,    25,    26,    27,    28,    -1,    30,    45,    46,    22,
      -1,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    45,    46,    22,    62,    24,    25,    26,    27,    28,
      68,    30,    45,    46,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    62,
      -1,    -1,    65,    22,    -1,    24,    25,    26,    27,    28,
      -1,    30,    -1,    62,    -1,    -1,    65,    22,    37,    24,
      25,    26,    27,    28,    -1,    30,    45,    46,    -1,    -1,
      -1,    50,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    62,    22,    50,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    22,    62,    24,    25,
      26,    27,    28,    -1,    30,    43,    -1,    45,    46,    22,
      -1,    24,    25,    26,    27,    28,    -1,    30,    -1,    45,
      46,    -1,    -1,    -1,    62,    -1,    -1,    40,    -1,    -1,
      -1,    57,    45,    46,    -1,    22,    62,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    22,    62,
      24,    25,    26,    27,    28,    -1,    30,    -1,    45,    46,
      -1,    22,    -1,    24,    25,    26,    27,    28,    -1,    30,
      -1,    45,    46,    -1,    22,    62,    24,    25,    26,    27,
      28,    -1,    30,    57,    45,    46,    -1,    -1,    62,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    12,    21,    33,    34,    36,    39,
      42,    48,    49,    51,    52,    54,    57,    59,    64,    70,
      71,    72,    74,    75,    76,    77,    80,    84,    85,    86,
      87,    88,    90,    92,    93,    94,   100,   101,   106,   110,
     111,   116,   117,    65,    65,    65,    37,    35,     7,     8,
       9,    10,    24,    25,    47,    67,   108,   110,   111,   113,
     114,   115,    67,    85,    86,    89,   110,   108,    72,    73,
      84,    67,    58,    72,    67,     0,    64,    75,    84,    64,
     102,    23,    62,    67,   107,    78,    79,   110,    78,    81,
      82,   110,    38,   108,   108,   108,   108,    22,    24,    25,
      26,    27,    28,    30,    43,    45,    46,    62,   108,    62,
      57,    84,    53,   108,    58,    60,    61,    68,   108,   118,
     119,   120,    64,    19,   103,   108,    68,   108,   112,   108,
      64,    66,    67,    64,    64,    66,    28,    68,   108,   108,
     108,   108,   108,   108,    31,    32,    84,    85,   108,   108,
     108,    68,   108,    73,   108,    68,    67,    65,    66,    66,
      68,    40,    13,    14,   104,    40,    66,    68,    79,   108,
      82,    24,    25,    67,    83,   109,   114,    29,   108,   108,
      44,    86,    89,    37,    50,    91,    58,    57,   115,   108,
     119,   120,    15,    15,    11,    12,    16,   105,   108,   108,
      68,   109,   109,   109,    29,    66,    24,    25,    26,    27,
      85,    86,   108,    55,    56,    95,    96,    97,    68,    65,
      68,    17,    18,    68,    67,   109,   109,   109,   109,   109,
     116,    98,    99,   108,    58,    96,    65,   108,   108,    66,
      37,    50,    72,    68,    99,   108,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    76,    77,
      78,    78,    79,    80,    81,    81,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    87,    87,    88,    88,
      89,    89,    90,    91,    91,    92,    93,    94,    95,    95,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   101,
     101,   101,   101,   101,   101,   102,   103,   103,   103,   104,
     104,   105,   105,   105,   105,   105,   105,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   114,   115,   116,   116,
     117,   117,   117,   117,   118,   118,   119,   119,   120,   120,
     120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     2,     1,     1,
       2,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       1,     3,     4,     4,     1,     3,     7,     1,     3,     1,
       1,     1,     6,     1,     4,     6,     2,     5,     2,     5,
       0,     1,     7,     1,     1,     5,     4,     7,     1,     2,
       3,     1,     2,     1,     3,     1,     3,     3,     5,     1,
       1,     3,     1,     2,     1,     0,     0,     2,     2,     2,
       2,     1,     1,     2,     2,     1,     0,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     4,
       4,     2,     2,     3,     4,     1,     1,     3,     3,     3,
       3,     2,     2,     3,     1,     1,     1,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     3,     4,     6,     1,     4,     1,     3,     1,     3,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
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
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex ();
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 48 "el.y" /* yacc.c:1646  */
    { root = (yyvsp[0].fn); }
#line 1893 "el.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 50 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.create(); }
#line 1899 "el.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.createI((yyvsp[0].fn)); }
#line 1905 "el.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 53 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.putI((yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 1911 "el.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 56 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.createI((yyvsp[-1].fn)); }
#line 1917 "el.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.create();    }
#line 1923 "el.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 58 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.createI((yyvsp[0].fn)); }
#line 1929 "el.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 60 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.putI((yyvsp[-2].fn), (yyvsp[-1].fn)); }
#line 1935 "el.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 61 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.putI((yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 1941 "el.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 1947 "el.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 76 "el.y" /* yacc.c:1646  */
    {
         func_stmt fs;
         fs.func = (yyvsp[0].fn);
         (yyval.fn) = stmtV.put(fs);
     }
#line 1957 "el.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 85 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 1963 "el.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 90 "el.y" /* yacc.c:1646  */
    { putInput((yyvsp[-1].fn)); }
#line 1969 "el.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_var(0, (yyvsp[-1].fn)); }
#line 1975 "el.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 94 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 1981 "el.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 95 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1987 "el.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 98 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::VARDEC, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 1993 "el.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 102 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_var(1, (yyvsp[-1].fn)); }
#line 1999 "el.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 104 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2005 "el.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 105 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2011 "el.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 109 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::ARRDEC, (yyvsp[-6].fn), (yyvsp[-1].fn), (yyvsp[-4].fn)); }
#line 2017 "el.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 113 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2023 "el.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 114 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2029 "el.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 122 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_if((yyvsp[-4].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2035 "el.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_if((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2041 "el.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_if((yyvsp[-4].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2047 "el.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 130 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once(-1, (yyvsp[0].fn)); }
#line 2053 "el.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2059 "el.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 134 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once(-1, (yyvsp[0].fn)); }
#line 2065 "el.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2071 "el.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2077 "el.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 143 "el.y" /* yacc.c:1646  */
    {
        for_stmt fs;
        fs.var = (yyvsp[-5].fn);
        fs.type = (yyvsp[-2].fn);
        fs.from = (yyvsp[-3].fn);
        fs.to = (yyvsp[-1].fn);
        fs.block = (yyvsp[0].fn);
        (yyval.fn) = stmtV.put(fs);
    }
#line 2091 "el.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 154 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2097 "el.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 155 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 1; }
#line 2103 "el.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 159 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_while(0, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2109 "el.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 161 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_while(1, (yyvsp[0].fn), (yyvsp[-2].fn)); }
#line 2115 "el.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 164 "el.y" /* yacc.c:1646  */
    {
        switch_stmt ss;
        ss.con = (yyvsp[-4].fn);
        ss.sections = (yyvsp[-1].fn);
        (yyval.fn) = stmtV.put(ss);
    }
#line 2126 "el.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2132 "el.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 2138 "el.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 176 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::SECTION, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2144 "el.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 178 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2150 "el.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 179 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[0].fn); }
#line 2156 "el.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2162 "el.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2168 "el.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 186 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcase((yyloc), (yyvsp[0].fn), -1, 0); }
#line 2174 "el.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 187 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcase((yyloc), (yyvsp[-2].fn), (yyvsp[0].fn), 1); }
#line 2180 "el.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 188 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcase((yyloc), (yyvsp[-2].fn), (yyvsp[0].fn), 2); }
#line 2186 "el.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 192 "el.y" /* yacc.c:1646  */
    {
      auto &os = boost::get<order_stmt>(stmtV[(yyval.fn) = (yyvsp[0].fn)]);
      os.op = (yyvsp[-4].fn);
      os.name = (yyvsp[-3].fn);
      os.num = (yyvsp[-2].fn);
      os.time = (yyvsp[-1].fn);
      os.loc = (yyloc);
    }
#line 2199 "el.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 202 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2205 "el.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 203 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 1; }
#line 2211 "el.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 204 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 2; }
#line 2217 "el.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 205 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 2; }
#line 2223 "el.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 206 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 3; }
#line 2229 "el.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 207 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 3; }
#line 2235 "el.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 210 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2241 "el.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 214 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2247 "el.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 216 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -2; }
#line 2253 "el.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 219 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2259 "el.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 220 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 1; }
#line 2265 "el.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 223 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(0, -1); }
#line 2271 "el.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 224 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(0, -1); }
#line 2277 "el.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 225 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(1, (yyvsp[-1].fn)); }
#line 2283 "el.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 226 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(2, (yyvsp[-1].fn)); }
#line 2289 "el.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 227 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(3, -1); }
#line 2295 "el.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 228 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(3, -1); }
#line 2301 "el.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 232 "el.y" /* yacc.c:1646  */
    {
      asm_stmt as;
      as.var = (yyvsp[-2].fn);
      as.type = static_cast<AsmType>((yyvsp[-1].fn));
      as.type_loc = (yylsp[-1]);
      as.exp = (yyvsp[0].fn);
      (yyval.fn) = stmtV.put(as);
    }
#line 2314 "el.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 242 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2320 "el.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 246 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::MUL, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2326 "el.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 247 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::DIV, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2332 "el.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 248 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::ADD, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2338 "el.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 249 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::SUB, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2344 "el.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 250 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::AND, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2350 "el.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 251 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::OR,  (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2356 "el.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 252 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::NOT, (yyvsp[0].fn), -1); }
#line 2362 "el.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 253 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp((yyloc), 0,  (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2368 "el.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 254 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp((yyloc), (yyvsp[-1].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2374 "el.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 255 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp((yyloc), 6, (yyvsp[-3].fn), (yyvsp[0].fn)); }
#line 2380 "el.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 256 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp((yyloc), 7, (yyvsp[-3].fn), (yyvsp[0].fn)); }
#line 2386 "el.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 257 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::UMINUS, (yyvsp[0].fn), -1); }
#line 2392 "el.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 258 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[0].fn); }
#line 2398 "el.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 259 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[-1].fn); }
#line 2404 "el.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 260 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::BAR, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2410 "el.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 265 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::MUL, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2416 "el.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 266 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::DIV, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2422 "el.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 267 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::ADD, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2428 "el.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 268 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::SUB, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2434 "el.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 269 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::UMINUS, (yyvsp[0].fn), -1); }
#line 2440 "el.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 270 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::UPLUS, (yyvsp[0].fn), -1); }
#line 2446 "el.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 271 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[-1].fn); }
#line 2452 "el.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 275 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newname((yyloc), (yyvsp[0].fn)); }
#line 2458 "el.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 276 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newname((yyloc), 0); }
#line 2464 "el.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 279 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::FUNC, (yyvsp[0].fn), -2); }
#line 2470 "el.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 280 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::FUNC, (yyvsp[-2].fn), -1); }
#line 2476 "el.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 281 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast((yyloc), NodeType::FUNC, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2482 "el.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 284 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2488 "el.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 285 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2494 "el.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 289 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newtf((yyloc), true); }
#line 2500 "el.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 290 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newtf((yyloc), false); }
#line 2506 "el.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 294 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newdouble((yyloc), (yyvsp[0].fn)); }
#line 2512 "el.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 296 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newtext((yyloc), (yyvsp[0].fn)); }
#line 2518 "el.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 299 "el.y" /* yacc.c:1646  */
    {
         block_stmt bs;
         bs.stmts = (yyvsp[-1].fn);
         (yyval.fn) = stmtV.put(bs);
     }
#line 2528 "el.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 304 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2534 "el.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 307 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print(-1, -1); }
#line 2540 "el.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 308 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print(-1, -1); }
#line 2546 "el.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 309 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print(-1, (yyvsp[-1].fn)); }
#line 2552 "el.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 310 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print((yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2558 "el.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 313 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2564 "el.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 314 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[-1].fn); }
#line 2570 "el.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 317 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2576 "el.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 318 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2582 "el.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 321 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newprint((yyloc), (yyvsp[0].fn)); }
#line 2588 "el.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 322 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newprint((yyloc), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2594 "el.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 323 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newprint((yyloc), (yyvsp[-4].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2600 "el.tab.c" /* yacc.c:1646  */
    break;


#line 2604 "el.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if 1
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 325 "el.y" /* yacc.c:1906  */


