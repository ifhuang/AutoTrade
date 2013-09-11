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

#include "tree.h"
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


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 193 "el.tab.c" /* yacc.c:358  */

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
#define YYLAST   851

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

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
       0,    47,    47,    49,    50,    51,    52,    55,    56,    57,
      58,    59,    60,    63,    64,    65,    66,    67,    68,    69,
      70,    76,    77,    80,    81,    82,    85,    87,    89,    90,
      93,    97,    99,   100,   103,   108,   109,   112,   113,   116,
     117,   120,   121,   122,   125,   126,   129,   130,   133,   134,
     137,   149,   150,   153,   155,   156,   159,   168,   169,   172,
     174,   175,   178,   179,   182,   183,   184,   187,   197,   198,
     199,   200,   201,   202,   205,   209,   210,   211,   214,   215,
     218,   219,   220,   221,   222,   223,   226,   236,   237,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   259,   260,   261,   262,
     263,   264,   265,   266,   269,   270,   273,   274,   275,   278,
     279,   282,   283,   284,   285,   288,   290,   292,   298,   301,
     302,   303,   304,   307,   308,   311,   312,   315,   316,   317
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
  "other_sstmt", "cstmt", "inputs", "variables", "variable_list",
  "variable", "arrays", "array_list", "array", "dimension_list", "if_stmt",
  "matched", "unmatched", "unmatched_once", "matched_once", "once_matched",
  "for_stmt", "for_type", "while_stmt", "repeat_stmt", "switch_stmt",
  "section_list", "section", "case_option", "case_list", "case",
  "order_stmt", "order_verb", "order_name", "order_amount", "order_time",
  "order_action", "assignment", "asm", "exp", "nexp", "name", "name_call",
  "argu_list", "literal", "number", "text", "block", "print_stmt",
  "print_location", "print_list", "print_element", YY_NULL
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

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     408,   -59,   -52,   -30,  -123,  -123,    51,     6,  -123,  -123,
     531,   532,    15,   531,   244,    36,   306,    41,  -123,    71,
    -123,   442,  -123,  -123,  -123,  -123,  -123,    60,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    -5,
    -123,  -123,  -123,    15,    15,    15,    87,  -123,  -123,  -123,
    -123,  -123,   531,   531,   531,   531,   725,    59,  -123,  -123,
    -123,  -123,   531,  -123,  -123,  -123,    67,   750,   531,   340,
      60,   531,  -123,   374,   193,  -123,  -123,  -123,    79,  -123,
     512,  -123,  -123,   461,   531,   -41,  -123,    63,   -36,   -11,
    -123,    70,  -123,  -123,  -123,   611,    65,   531,   531,   531,
     531,   531,   531,    16,   561,   531,   531,   531,   245,   531,
    -123,   775,   531,    79,   304,  -123,  -123,    64,  -123,   655,
      69,     4,  -123,  -123,   104,    54,   764,  -123,   775,    28,
     775,  -123,    15,   531,  -123,  -123,    15,    13,  -123,    89,
      37,    37,   117,   117,   789,   531,   531,  -123,   103,   611,
     159,    89,   561,   682,   775,    97,   145,   531,   531,   531,
    -123,  -123,   141,   142,   502,  -123,   531,  -123,  -123,   597,
    -123,    13,    13,    13,   -12,    34,  -123,  -123,    89,    89,
     561,  -123,  -123,  -123,  -123,   531,    46,    90,   669,    31,
    -123,  -123,  -123,  -123,     2,  -123,  -123,   630,   775,  -123,
    -123,  -123,     7,    92,    13,    13,    13,    13,    13,  -123,
    -123,   750,  -123,   531,   -16,  -123,   105,  -123,   531,  -123,
    -123,  -123,  -123,   531,    34,    96,    96,  -123,  -123,  -123,
      95,  -123,   711,  -123,  -123,   408,   775,   604,   531,   531,
     531,   442,  -123,  -123,   775,   775
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,   115,   114,    68,    69,    73,    71,
       0,    48,     0,     0,     0,     0,     0,   129,     8,     0,
       2,     4,    39,     9,    23,    24,    25,     5,    37,    38,
      41,    13,    14,    15,    16,    17,    18,    74,    19,   116,
      20,    21,    22,     0,     0,     0,     0,    72,   125,   122,
     123,   126,     0,     0,     0,     0,     0,   116,   105,   104,
     121,   124,     0,    49,    44,    46,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     1,    10,    12,     6,     7,
      75,    88,    87,     0,     0,     0,    28,     0,     0,     0,
      32,     0,    70,   101,   100,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    55,     0,     0,     0,   127,   133,     0,   130,   137,
       0,     0,   135,    11,     0,     0,     0,   117,   119,     0,
      86,    26,     0,     0,    27,    31,     0,     0,   102,    97,
      91,    92,    89,    90,     0,     0,     0,    42,    37,    93,
      94,    96,    48,     0,    54,     0,     0,     0,     0,     0,
     131,    77,     0,     0,    85,    76,     0,   118,    29,     0,
      33,     0,     0,     0,     0,    35,   113,   103,    98,    99,
       0,    45,    47,    51,    52,     0,     0,     0,   138,     0,
     136,    78,    79,    81,   115,    80,    67,     0,   120,    30,
     111,   110,     0,     0,     0,     0,     0,     0,     0,    40,
      43,     0,    60,     0,     0,    57,     0,   134,     0,   132,
      82,    83,   112,     0,    36,   108,   109,   106,   107,    50,
      61,    62,    64,    56,    58,     0,   139,     0,     0,     0,
       0,    59,    34,    63,    65,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,  -123,   -13,  -123,   -17,  -123,  -123,   118,    42,
    -123,  -123,    33,  -123,     5,    -4,    -1,  -123,  -123,    25,
    -123,  -123,  -123,  -123,  -123,  -123,   -32,  -123,  -123,   -48,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    66,   -66,
       0,     8,  -123,  -123,  -122,    35,   -58,  -123,  -123,    38,
      39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    85,    86,
      26,    89,    90,   174,    70,    28,    29,    30,    31,    65,
      32,   185,    33,    34,    35,   214,   215,   216,   230,   231,
      36,    37,    80,   125,   164,   196,    38,    84,   119,   175,
      57,    58,   129,    59,    60,    61,    41,    42,   120,   121,
     122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    69,   -84,    73,    77,    27,    43,    63,    40,   110,
      64,    39,    66,    44,    39,   176,    39,   203,    81,    40,
      48,    39,    40,   131,    40,   132,    78,     4,   134,    40,
     132,   205,   206,   207,   208,    45,     5,   171,   172,   212,
     213,    47,   233,    87,    87,    91,   -84,   145,   146,   176,
     176,   176,    77,   135,   204,   136,    77,    82,   205,   206,
     207,   208,    83,   100,   101,   102,   -84,   162,   163,    39,
     159,    75,   160,    39,   113,   222,    56,    40,   113,    67,
     173,    40,   176,   176,   176,   176,   176,    97,    46,    98,
      99,   100,   101,   102,   166,   103,   167,   159,   137,   219,
     148,   212,   213,    71,    39,   200,   201,   202,    74,   147,
     105,   106,    40,    98,    99,   100,   101,   102,    93,    94,
      95,    96,   207,   208,    79,    92,    83,   107,   108,   109,
     133,   156,    87,   138,   111,   158,    91,   114,   224,   225,
     226,   227,   228,   123,   161,   102,   126,   180,    63,   128,
     130,   181,    39,   229,   186,    51,   191,   192,   217,   223,
      40,   238,    88,   139,   140,   141,   142,   143,   144,   170,
     235,   149,   150,   151,   168,   153,   209,   182,   154,   210,
      39,    97,   234,    98,    99,   100,   101,   102,    40,   103,
     243,   187,     0,     0,     0,     0,   189,     0,   190,   169,
      48,    49,    50,    51,   105,     4,     0,     0,     0,     0,
       0,   178,   179,     0,     5,     0,     0,    52,    53,     0,
       0,   107,   241,   188,    77,     0,     0,     0,     0,     0,
     197,     0,   198,     0,     0,    39,     0,     0,     0,     0,
      54,    39,     0,    40,     0,     0,   113,     1,     2,    40,
       3,   211,     0,   116,   117,     0,     4,     0,     0,     0,
      55,   118,     0,     0,     0,     5,     0,    97,     0,    98,
      99,   100,   101,   102,     0,   103,     0,     6,     7,   232,
       8,     0,     0,     9,   236,     0,    10,     0,     0,   237,
     105,   106,    11,    12,     0,    13,    14,    68,    15,     0,
       0,    16,     0,    17,   232,   244,   245,   107,    18,     1,
       2,     0,     3,   152,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,    97,     5,    98,    99,
     100,   101,   102,     0,   103,     0,     0,     0,     0,     6,
       7,     0,     8,     1,     2,     9,     3,     0,    10,   105,
     106,     0,     4,     0,    11,    12,     0,    13,    14,     0,
      15,     5,     0,    16,    72,    17,   107,     0,     0,     0,
      18,     0,   155,     6,     7,     0,     8,     1,     2,     9,
       3,     0,    10,     0,     0,     0,     4,     0,    11,    12,
       0,    13,    14,   112,    15,     5,     0,    16,     0,    17,
       0,     0,     0,     0,    76,     0,     0,     6,     7,     0,
       8,     1,     2,     9,     3,     0,    10,     0,     0,     0,
       4,     0,    11,    12,     0,    13,    14,     0,    15,     5,
       0,    16,   115,    17,     0,     0,     0,     0,    76,     0,
       0,     6,     7,     0,     8,     1,     2,     9,     3,     0,
      10,     0,     0,     0,     4,     0,    11,    12,     0,    13,
      14,     0,    15,     5,     0,    16,     0,    17,    48,    49,
      50,    51,    18,     4,     0,     6,     7,     0,     8,     0,
       0,     9,     5,     0,    10,    52,    53,     0,     0,     0,
      11,    12,     0,    13,    14,     0,    15,     0,     0,    16,
       0,    17,     0,     0,     0,     0,    76,     0,    54,    48,
      49,    50,    51,   193,   194,     0,     0,     0,   195,    48,
      49,    50,    51,     5,     4,     0,    52,    53,    55,   127,
       0,   124,     0,     5,     0,     0,    52,    53,    48,    49,
      50,    51,     0,     4,     4,     0,     0,     0,     0,    54,
       0,     0,     5,     5,     0,    52,    53,     0,     0,    54,
       0,     0,     0,     0,     0,     6,     7,     0,     8,    55,
       0,     9,     0,     4,    10,     0,     0,     0,    54,    55,
      11,    12,     5,    13,    14,     0,    15,     0,     0,    16,
       0,    17,     0,     0,     6,     7,     0,     8,    55,    62,
       9,     0,     0,    10,     0,     0,     0,     0,     0,    11,
      12,     0,    13,    14,     0,    15,     0,     0,    16,    97,
      17,    98,    99,   100,   101,   102,    97,   103,    98,    99,
     100,   101,   102,    97,   103,    98,    99,   100,   101,   102,
       0,   103,   105,   106,     0,     0,     0,   220,   221,   105,
     106,     0,    97,     0,    98,    99,   100,   101,   102,   107,
     103,     0,     0,     0,     0,   199,   107,     0,     0,     0,
       0,     0,   242,   107,     0,   105,   106,    97,     0,    98,
      99,   100,   101,   102,     0,   103,     0,     0,     0,     0,
       0,    97,   107,    98,    99,   100,   101,   102,     0,   103,
     105,   106,     0,     0,    97,     0,    98,    99,   100,   101,
     102,     0,   103,     0,   105,   106,     0,   107,     0,   183,
     157,     0,     0,     0,     0,     0,     0,   105,   106,     0,
       0,   107,   184,    97,   218,    98,    99,   100,   101,   102,
       0,   103,     0,     0,   107,     0,     0,    97,   239,    98,
      99,   100,   101,   102,     0,   103,   105,   106,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,   104,     0,
     105,   106,    97,   107,    98,    99,   100,   101,   102,     0,
     103,     0,     0,     0,     0,     0,    97,   107,    98,    99,
     100,   101,   102,     0,   103,   105,   106,    97,     0,    98,
      99,   100,   101,   102,   165,   103,     0,    16,     0,   105,
     106,    97,   107,    98,    99,   100,   101,   102,   177,   103,
     105,   106,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,   105,   106,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107
};

static const yytype_int16 yycheck[] =
{
       0,    14,     0,    16,    21,     0,    65,    11,     0,    67,
      11,    11,    12,    65,    14,   137,    16,    29,    23,    11,
       7,    21,    14,    64,    16,    66,    21,    12,    64,    21,
      66,    24,    25,    26,    27,    65,    21,    24,    25,    55,
      56,    35,    58,    43,    44,    45,    44,    31,    32,   171,
     172,   173,    69,    64,    66,    66,    73,    62,    24,    25,
      26,    27,    67,    26,    27,    28,    64,    13,    14,    69,
      66,     0,    68,    73,    69,    68,    10,    69,    73,    13,
      67,    73,   204,   205,   206,   207,   208,    22,    37,    24,
      25,    26,    27,    28,    66,    30,    68,    66,    28,    68,
     104,    55,    56,    67,   104,   171,   172,   173,    67,   104,
      45,    46,   104,    24,    25,    26,    27,    28,    52,    53,
      54,    55,    26,    27,    64,    38,    67,    62,    62,    62,
      67,    67,   132,    68,    68,    66,   136,    71,   204,   205,
     206,   207,   208,    64,    40,    28,    80,    44,   152,    83,
      84,   152,   152,   211,    57,    10,    15,    15,    68,    67,
     152,    66,    44,    97,    98,    99,   100,   101,   102,   136,
      65,   105,   106,   107,   132,   109,   180,   152,   112,   180,
     180,    22,   214,    24,    25,    26,    27,    28,   180,    30,
     238,   156,    -1,    -1,    -1,    -1,   158,    -1,   159,   133,
       7,     8,     9,    10,    45,    12,    -1,    -1,    -1,    -1,
      -1,   145,   146,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    62,   235,   157,   241,    -1,    -1,    -1,    -1,    -1,
     164,    -1,   166,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      47,   241,    -1,   235,    -1,    -1,   241,     3,     4,   241,
       6,   185,    -1,    60,    61,    -1,    12,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    21,    -1,    22,    -1,    24,
      25,    26,    27,    28,    -1,    30,    -1,    33,    34,   213,
      36,    -1,    -1,    39,   218,    -1,    42,    -1,    -1,   223,
      45,    46,    48,    49,    -1,    51,    52,    53,    54,    -1,
      -1,    57,    -1,    59,   238,   239,   240,    62,    64,     3,
       4,    -1,     6,    68,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    21,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,     3,     4,    39,     6,    -1,    42,    45,
      46,    -1,    12,    -1,    48,    49,    -1,    51,    52,    -1,
      54,    21,    -1,    57,    58,    59,    62,    -1,    -1,    -1,
      64,    -1,    68,    33,    34,    -1,    36,     3,     4,    39,
       6,    -1,    42,    -1,    -1,    -1,    12,    -1,    48,    49,
      -1,    51,    52,    53,    54,    21,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    33,    34,    -1,
      36,     3,     4,    39,     6,    -1,    42,    -1,    -1,    -1,
      12,    -1,    48,    49,    -1,    51,    52,    -1,    54,    21,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    33,    34,    -1,    36,     3,     4,    39,     6,    -1,
      42,    -1,    -1,    -1,    12,    -1,    48,    49,    -1,    51,
      52,    -1,    54,    21,    -1,    57,    -1,    59,     7,     8,
       9,    10,    64,    12,    -1,    33,    34,    -1,    36,    -1,
      -1,    39,    21,    -1,    42,    24,    25,    -1,    -1,    -1,
      48,    49,    -1,    51,    52,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    47,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,     7,
       8,     9,    10,    21,    12,    -1,    24,    25,    67,    68,
      -1,    19,    -1,    21,    -1,    -1,    24,    25,     7,     8,
       9,    10,    -1,    12,    12,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    21,    21,    -1,    24,    25,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    67,
      -1,    39,    -1,    12,    42,    -1,    -1,    -1,    47,    67,
      48,    49,    21,    51,    52,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,    33,    34,    -1,    36,    67,    67,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    52,    -1,    54,    -1,    -1,    57,    22,
      59,    24,    25,    26,    27,    28,    22,    30,    24,    25,
      26,    27,    28,    22,    30,    24,    25,    26,    27,    28,
      -1,    30,    45,    46,    -1,    -1,    -1,    17,    18,    45,
      46,    -1,    22,    -1,    24,    25,    26,    27,    28,    62,
      30,    -1,    -1,    -1,    -1,    68,    62,    -1,    -1,    -1,
      -1,    -1,    68,    62,    -1,    45,    46,    22,    -1,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    22,    62,    24,    25,    26,    27,    28,    -1,    30,
      45,    46,    -1,    -1,    22,    -1,    24,    25,    26,    27,
      28,    -1,    30,    -1,    45,    46,    -1,    62,    -1,    37,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    62,    50,    22,    65,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    62,    -1,    -1,    22,    37,    24,
      25,    26,    27,    28,    -1,    30,    45,    46,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    22,    62,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    22,    62,    24,    25,
      26,    27,    28,    -1,    30,    45,    46,    22,    -1,    24,
      25,    26,    27,    28,    40,    30,    -1,    57,    -1,    45,
      46,    22,    62,    24,    25,    26,    27,    28,    29,    30,
      45,    46,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    12,    21,    33,    34,    36,    39,
      42,    48,    49,    51,    52,    54,    57,    59,    64,    70,
      71,    72,    73,    74,    75,    76,    79,    83,    84,    85,
      86,    87,    89,    91,    92,    93,    99,   100,   105,   109,
     110,   115,   116,    65,    65,    65,    37,    35,     7,     8,
       9,    10,    24,    25,    47,    67,   107,   109,   110,   112,
     113,   114,    67,    84,    85,    88,   109,   107,    53,    72,
      83,    67,    58,    72,    67,     0,    64,    74,    83,    64,
     101,    23,    62,    67,   106,    77,    78,   109,    77,    80,
      81,   109,    38,   107,   107,   107,   107,    22,    24,    25,
      26,    27,    28,    30,    43,    45,    46,    62,   107,    62,
     115,   107,    53,    83,   107,    58,    60,    61,    68,   107,
     117,   118,   119,    64,    19,   102,   107,    68,   107,   111,
     107,    64,    66,    67,    64,    64,    66,    28,    68,   107,
     107,   107,   107,   107,   107,    31,    32,    83,    84,   107,
     107,   107,    68,   107,   107,    68,    67,    65,    66,    66,
      68,    40,    13,    14,   103,    40,    66,    68,    78,   107,
      81,    24,    25,    67,    82,   108,   113,    29,   107,   107,
      44,    85,    88,    37,    50,    90,    57,   114,   107,   118,
     119,    15,    15,    11,    12,    16,   104,   107,   107,    68,
     108,   108,   108,    29,    66,    24,    25,    26,    27,    84,
      85,   107,    55,    56,    94,    95,    96,    68,    65,    68,
      17,    18,    68,    67,   108,   108,   108,   108,   108,   115,
      97,    98,   107,    58,    95,    65,   107,   107,    66,    37,
      50,    72,    68,    98,   107,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    76,    77,    77,
      78,    79,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    90,    90,    91,    92,    92,    93,    94,    94,    95,
      96,    96,    97,    97,    98,    98,    98,    99,   100,   100,
     100,   100,   100,   100,   101,   102,   102,   102,   103,   103,
     104,   104,   104,   104,   104,   104,   105,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   113,   114,   115,   115,   116,
     116,   116,   116,   117,   117,   118,   118,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     2,     1,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     3,
       4,     4,     1,     3,     7,     1,     3,     1,     1,     1,
       6,     1,     4,     6,     2,     5,     2,     5,     0,     1,
       7,     1,     1,     3,     4,     3,     7,     1,     2,     3,
       1,     2,     1,     3,     1,     3,     3,     5,     1,     1,
       3,     1,     2,     1,     0,     0,     2,     2,     2,     2,
       1,     1,     2,     2,     1,     0,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     4,     4,
       2,     2,     3,     4,     1,     1,     3,     3,     3,     3,
       2,     2,     3,     1,     1,     1,     1,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     4,     6,     1,     4,     1,     3,     1,     3,     5
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

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


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 47 "el.y" /* yacc.c:1646  */
    { root = (yyvsp[0].fn); }
#line 1791 "el.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 49 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.create(); }
#line 1797 "el.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 51 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.createI((yyvsp[0].fn)); }
#line 1803 "el.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 52 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.putI((yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 1809 "el.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.createI((yyvsp[-1].fn)); }
#line 1815 "el.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.create();    }
#line 1821 "el.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 57 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.createI((yyvsp[0].fn)); }
#line 1827 "el.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 59 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.putI((yyvsp[-2].fn), (yyvsp[-1].fn)); }
#line 1833 "el.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 60 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = stmtsV.putI((yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 1839 "el.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 71 "el.y" /* yacc.c:1646  */
    {
         func_stmt fs;
         fs.func = (yyvsp[0].fn);
         (yyval.fn) = stmtV.put(fs);
     }
#line 1849 "el.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 1855 "el.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 85 "el.y" /* yacc.c:1646  */
    { putInput((yyvsp[-1].fn)); }
#line 1861 "el.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 87 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_var(0, (yyvsp[-1].fn)); }
#line 1867 "el.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 1873 "el.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 90 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1879 "el.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::VARDEC, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 1885 "el.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 97 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_var(1, (yyvsp[-1].fn)); }
#line 1891 "el.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 1897 "el.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1903 "el.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 104 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::ARRDEC, (yyvsp[-6].fn), (yyvsp[-1].fn), (yyvsp[-4].fn)); }
#line 1909 "el.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 108 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 1915 "el.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 109 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1921 "el.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_if((yyvsp[-4].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1927 "el.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_if((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1933 "el.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 122 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_if((yyvsp[-4].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1939 "el.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 125 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once(-1, (yyvsp[0].fn)); }
#line 1945 "el.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 126 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1951 "el.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 129 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once(-1, (yyvsp[0].fn)); }
#line 1957 "el.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 130 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_once((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 1963 "el.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 1969 "el.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "el.y" /* yacc.c:1646  */
    {
        for_stmt fs;
        fs.var = (yyvsp[-5].fn);
        fs.type = (yyvsp[-2].fn);
        fs.from = (yyvsp[-3].fn);
        fs.to = (yyvsp[-1].fn);
        fs.block = (yyvsp[0].fn);
        (yyval.fn) = stmtV.put(fs);
    }
#line 1983 "el.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 1989 "el.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 150 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 1; }
#line 1995 "el.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 153 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_while(0, (yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 2001 "el.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 155 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_while(1, (yyvsp[0].fn), (yyvsp[-2].fn)); }
#line 2007 "el.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 156 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_while(1, (yyvsp[0].fn), -1); }
#line 2013 "el.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 160 "el.y" /* yacc.c:1646  */
    {
        switch_stmt ss;
        ss.con = (yyvsp[-4].fn);
        ss.sections = (yyvsp[-1].fn);
        (yyval.fn) = stmtV.put(ss);
    }
#line 2024 "el.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2030 "el.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-1].fn), (yyvsp[0].fn)); }
#line 2036 "el.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::SECTION, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2042 "el.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2048 "el.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 175 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[0].fn); }
#line 2054 "el.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 178 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2060 "el.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 179 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2066 "el.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 182 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcase((yyvsp[0].fn), -1, 0); }
#line 2072 "el.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 183 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcase((yyvsp[-2].fn), (yyvsp[0].fn), 1); }
#line 2078 "el.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 184 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcase((yyvsp[-2].fn), (yyvsp[0].fn), 2); }
#line 2084 "el.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 188 "el.y" /* yacc.c:1646  */
    {
      auto &oa = boost::get<order_stmt>(stmtV[(yyval.fn) = (yyvsp[0].fn)]);
      oa.op = (yyvsp[-4].fn);
      oa.name = (yyvsp[-3].fn);
      oa.num = (yyvsp[-2].fn);
      oa.time = (yyvsp[-1].fn);
    }
#line 2096 "el.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 197 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2102 "el.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 198 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 1; }
#line 2108 "el.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 199 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 2; }
#line 2114 "el.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 200 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 2; }
#line 2120 "el.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 201 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 3; }
#line 2126 "el.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 202 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 3; }
#line 2132 "el.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 205 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2138 "el.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 209 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2144 "el.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 211 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -2; }
#line 2150 "el.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 214 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2156 "el.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 215 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 1; }
#line 2162 "el.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 218 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(0, -1); }
#line 2168 "el.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 219 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(0, -1); }
#line 2174 "el.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 220 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(1, (yyvsp[-1].fn)); }
#line 2180 "el.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 221 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(2, (yyvsp[-1].fn)); }
#line 2186 "el.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 222 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(3, -1); }
#line 2192 "el.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 223 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_order(3, -1); }
#line 2198 "el.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 227 "el.y" /* yacc.c:1646  */
    {
      asm_stmt as;
      as.var = (yyvsp[-2].fn);
      as.type = (yyvsp[-1].fn);
      as.exp = (yyvsp[0].fn);
      (yyval.fn) = stmtV.put(as);
    }
#line 2210 "el.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 236 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = 0; }
#line 2216 "el.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 240 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::MUL, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2222 "el.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 241 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::DIV, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2228 "el.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 242 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::ADD, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2234 "el.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 243 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::SUB, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2240 "el.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 244 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::AND, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2246 "el.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 245 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::OR,  (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2252 "el.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 246 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::NOT, (yyvsp[0].fn), -1); }
#line 2258 "el.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 247 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp(0,  (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2264 "el.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 248 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp((yyvsp[-1].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2270 "el.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 249 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp(6, (yyvsp[-3].fn), (yyvsp[0].fn)); }
#line 2276 "el.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 250 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newcmp(7, (yyvsp[-3].fn), (yyvsp[0].fn)); }
#line 2282 "el.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 251 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::UMINUS, (yyvsp[0].fn), -1); }
#line 2288 "el.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 252 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[0].fn); }
#line 2294 "el.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 253 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[-1].fn); }
#line 2300 "el.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 254 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::BAR, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2306 "el.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 259 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::MUL, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2312 "el.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 260 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::DIV, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2318 "el.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 261 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::ADD, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2324 "el.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 262 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::SUB, (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2330 "el.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 263 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::UMINUS, (yyvsp[0].fn), -1); }
#line 2336 "el.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 264 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[0].fn); }
#line 2342 "el.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 265 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[-1].fn); }
#line 2348 "el.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 269 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newname((yyvsp[0].fn)); }
#line 2354 "el.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 270 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newname(0); }
#line 2360 "el.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 273 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::FUNC, (yyvsp[0].fn), -2); }
#line 2366 "el.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 274 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::FUNC, (yyvsp[-2].fn), -1); }
#line 2372 "el.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 275 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newast(NodeType::FUNC, (yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2378 "el.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 278 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2384 "el.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 279 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2390 "el.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 283 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newtf(true); }
#line 2396 "el.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 284 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newtf(false); }
#line 2402 "el.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 288 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newdouble((yyvsp[0].fn)); }
#line 2408 "el.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 290 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newtext((yyvsp[0].fn)); }
#line 2414 "el.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 293 "el.y" /* yacc.c:1646  */
    {
         block_stmt bs;
         bs.stmts = (yyvsp[-1].fn);
         (yyval.fn) = stmtV.put(bs);
     }
#line 2424 "el.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 298 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2430 "el.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 301 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print(-1, -1); }
#line 2436 "el.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 302 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print(-1, -1); }
#line 2442 "el.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 303 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print(-1, (yyvsp[-1].fn)); }
#line 2448 "el.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 304 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = new_print((yyvsp[-3].fn), (yyvsp[-1].fn)); }
#line 2454 "el.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 307 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = -1; }
#line 2460 "el.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 308 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = (yyvsp[-1].fn); }
#line 2466 "el.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 311 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.createI((yyvsp[0].fn)); }
#line 2472 "el.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 312 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = astsV.putI((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2478 "el.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 315 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newprint((yyvsp[0].fn)); }
#line 2484 "el.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 316 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newprint((yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2490 "el.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 317 "el.y" /* yacc.c:1646  */
    { (yyval.fn) = newprint((yyvsp[-4].fn), (yyvsp[-2].fn), (yyvsp[0].fn)); }
#line 2496 "el.tab.c" /* yacc.c:1646  */
    break;


#line 2500 "el.tab.c" /* yacc.c:1646  */
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 319 "el.y" /* yacc.c:1906  */

