/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 12 "tinyC.y"

  #include <stdio.h>
  #include <string.h>
  #include "SymbolTable.h"
  void yyerror (char *string);
  extern int yylineno;
  int controlIf=TRUE;


/* Line 268 of yacc.c  */
#line 81 "tinyC.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT = 259,
     ID = 260,
     VOID = 261,
     STRING = 262,
     PRINTF = 263,
     IF = 264,
     THEN = 265,
     ELSE = 266,
     WHILE = 267,
     DO = 268,
     READ = 269,
     WRITE = 270,
     NUMBER = 271,
     SEMI = 272,
     LPAREN = 273,
     RPAREN = 274,
     LBRACE = 275,
     RBRACE = 276,
     LBRACKET = 277,
     RBRACKET = 278,
     LT = 279,
     MT = 280,
     LOE = 281,
     MOE = 282,
     ASSIGN = 283,
     EQUALITY = 284,
     ITSNOT = 285,
     PLUS1 = 286,
     MINUS1 = 287,
     EQUALSM1 = 288,
     EQUALSP1 = 289,
     MOD = 290,
     EQ = 291,
     FLOAT_NUM = 292,
     INT_NUM = 293,
     PLUS = 294,
     MINUS = 295,
     TIMES = 296,
     DIV = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 20 "tinyC.y"

  int type;
  int ivalue;
  float value;
  string name;
  SymbolTable * st;



/* Line 293 of yacc.c  */
#line 169 "tinyC.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 181 "tinyC.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   90

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNRULES -- Number of states.  */
#define YYNSTATES  95

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    14,    16,    18,    19,
      20,    24,    25,    31,    41,    48,    53,    58,    63,    67,
      71,    75,    79,    85,    91,    97,    99,   103,   107,   111,
     115,   119,   123,   125,   129,   133,   135,   139,   143,   145,
     149,   151,   153,   155
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    50,    -1,    45,    46,    -1,    -1,
      47,     5,    17,    -1,     3,    -1,     4,    -1,    -1,    -1,
      50,    48,    51,    -1,    -1,     9,    53,    10,    48,    51,
      -1,     9,    53,    10,    48,    51,    49,    11,    48,    51,
      -1,    12,    48,    53,    13,    48,    51,    -1,    57,    28,
      53,    17,    -1,    57,    33,    53,    17,    -1,    57,    34,
      53,    17,    -1,    31,    57,    17,    -1,    57,    31,    17,
      -1,    32,    57,    17,    -1,    57,    32,    17,    -1,    14,
      18,    57,    19,    17,    -1,    15,    18,    53,    19,    17,
      -1,     8,    18,     7,    19,    17,    -1,    52,    -1,    20,
      50,    21,    -1,    54,    24,    54,    -1,    54,    36,    54,
      -1,    54,    25,    54,    -1,    54,    26,    54,    -1,    54,
      30,    54,    -1,    54,    -1,    54,    39,    55,    -1,    54,
      40,    55,    -1,    55,    -1,    55,    41,    56,    -1,    55,
      42,    56,    -1,    56,    -1,    18,    53,    19,    -1,    38,
      -1,    37,    -1,    57,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    89,    90,    93,   104,   105,   108,   113,
     128,   137,   142,   159,   181,   210,   243,   244,   246,   255,
     264,   273,   281,   282,   283,   284,   287,   292,   302,   311,
     320,   329,   338,   341,   373,   404,   409,   438,   483,   486,
     489,   506,   523,   545
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "ID", "VOID",
  "STRING", "PRINTF", "IF", "THEN", "ELSE", "WHILE", "DO", "READ", "WRITE",
  "NUMBER", "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "LT", "MT", "LOE", "MOE", "ASSIGN", "EQUALITY", "ITSNOT",
  "PLUS1", "MINUS1", "EQUALSM1", "EQUALSP1", "MOD", "EQ", "FLOAT_NUM",
  "INT_NUM", "PLUS", "MINUS", "TIMES", "DIV", "$accept", "program",
  "var_dec", "single_dec", "type", "m", "n", "stmt_seq", "stmt", "block",
  "exp", "simple_exp", "term", "factor", "variable", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    49,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    55,    55,    55,    56,
      56,    56,    56,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     1,     1,     0,     0,
       3,     0,     5,     9,     6,     4,     4,     4,     3,     3,
       3,     3,     5,     5,     5,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    11,     1,     6,     7,     3,     0,     8,     0,
       0,     5,    43,     0,     0,     8,     0,     0,    11,     0,
       0,    10,    25,     0,     0,     0,    41,    40,     0,    32,
      35,    38,    42,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      18,    20,     0,    19,    21,     0,     0,     0,    39,     0,
      27,    29,    30,    31,    28,    33,    34,    36,    37,     8,
       0,     0,    15,    16,    17,    24,    12,     0,    22,    23,
       0,    14,     8,     0,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    10,    90,     8,    21,    22,
      28,    29,    30,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int8 yypact[] =
{
     -67,    12,     2,   -67,   -67,   -67,   -67,    13,    20,    16,
      -1,   -67,   -67,    11,    -3,   -67,    19,    23,   -67,    39,
      39,   -67,   -67,    38,    36,    -3,   -67,   -67,    41,    24,
     -25,   -67,   -67,    -3,    39,    -3,    26,    35,    40,    -3,
      44,    45,    -3,    -3,    34,    48,   -67,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    42,    49,    54,   -67,
     -67,   -67,    57,   -67,   -67,    58,    59,    62,   -67,    -1,
     -17,   -17,   -17,   -17,   -17,   -25,   -25,   -67,   -67,   -67,
      63,    64,   -67,   -67,   -67,   -67,    47,    -1,   -67,   -67,
      71,   -67,   -67,    -1,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -14,   -67,    72,   -66,   -67,
       3,    37,   -27,   -15,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -10
static const yytype_int8 yytable[] =
{
      23,    33,    12,    86,    12,     4,     5,    13,    14,    37,
      38,    15,     3,    16,    17,    25,    54,    55,     9,    18,
      -2,    91,    52,    53,    57,    75,    76,    94,    45,    24,
      19,    20,    69,    11,    26,    27,    56,    34,    58,    77,
      78,    35,    62,    44,    12,    65,    66,    59,    47,    48,
      49,    46,    60,    67,    50,    79,     0,    61,    -9,    23,
      51,    63,    64,    52,    53,    87,    39,    68,    80,    40,
      41,    42,    43,    81,    82,    83,    84,    23,    93,    85,
      88,    89,    92,    23,    70,    71,    72,    73,    74,     0,
      36
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-67))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      10,    15,     5,    69,     5,     3,     4,     8,     9,    19,
      20,    12,     0,    14,    15,    18,    41,    42,     5,    20,
       0,    87,    39,    40,    34,    52,    53,    93,    25,    18,
      31,    32,    46,    17,    37,    38,    33,    18,    35,    54,
      55,    18,    39,     7,     5,    42,    43,    21,    24,    25,
      26,    10,    17,    19,    30,    13,    -1,    17,    11,    69,
      36,    17,    17,    39,    40,    79,    28,    19,    19,    31,
      32,    33,    34,    19,    17,    17,    17,    87,    92,    17,
      17,    17,    11,    93,    47,    48,    49,    50,    51,    -1,
      18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     3,     4,    46,    47,    50,     5,
      48,    17,     5,     8,     9,    12,    14,    15,    20,    31,
      32,    51,    52,    57,    18,    18,    37,    38,    53,    54,
      55,    56,    57,    48,    18,    18,    50,    57,    57,    28,
      31,    32,    33,    34,     7,    53,    10,    24,    25,    26,
      30,    36,    39,    40,    41,    42,    53,    57,    53,    21,
      17,    17,    53,    17,    17,    53,    53,    19,    19,    48,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    13,
      19,    19,    17,    17,    17,    17,    51,    48,    17,    17,
      49,    51,    11,    48,    51
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  *++yyvsp = yylval;

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
        case 5:

/* Line 1806 of yacc.c  */
#line 93 "tinyC.y"
    {
                              if(findValue(st, (yyvsp[(2) - (3)].name)) == FALSE){
                                putValue((yyvsp[(2) - (3)].name), (yyvsp[(1) - (3)].type), st);
                              }else{
                                printf("Variable '%s' declared before\n", (yyvsp[(2) - (3)].name));
                                yyerror("Error");
                                return FALSE;
                              }
                            }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 104 "tinyC.y"
    {(yyval.type) = T_INTEGER;}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 105 "tinyC.y"
    {(yyval.type) = T_FLOAT;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 108 "tinyC.y"
    {
                              (yyval.st)->p_line.quad = quad;
                            }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 113 "tinyC.y"
    {
                              char t[BUFFER_SIZE];
                              sprintf(t, "%d", quad);
                              char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
                              strcpy(s,t);
                              (yyval.st)->p_line.next_list = s;
                              lines[quad].quad = quad;
                              lines[quad].operation = "-";
                              lines[quad].arg1 = "-";
                              lines[quad].arg2 = "-";
                              lines[quad].destination = "S.next";
                              quad++;
                            }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 128 "tinyC.y"
    {
                              // AQUI ESTÁ EL PROBLEMA
                              // PUEDEN CHECAR LA 2A DIAPOSITIVA DE LA PAGINA 25
                              // DEL TOPIC 3. NO VEO FORMA DE ACOPLAR LAS ÚLTIMAS 4 PRODUCCIONES.
                              // S -> begin L end
                              // S -> A
                              // S -> L1; M S
                              // L -> S
                            }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 137 "tinyC.y"
    {
                              
                            }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 142 "tinyC.y"
    {

                                            (yyval.st) = (yyvsp[(2) - (5)].st);
                                            if((yyvsp[(2) - (5)].st)->p_line.false_list){
                                              mergeWithNextList((yyvsp[(2) - (5)].st),FALSE_LIST, (yyvsp[(5) - (5)].st),(yyval.st));
                                            }
                                            generateCodeCond((yyvsp[(2) - (5)].st),(yyvsp[(2) - (5)].st)->p_line.destination,(yyval.st));
                                            backpatch_list((yyvsp[(2) - (5)].st),TRUE_LIST,(yyvsp[(4) - (5)].st)->p_line.quad);

                                            int index = (yyvsp[(2) - (5)].st)->p_line.quad+1;
                                            lines[index].quad = index;
                                            lines[index].operation = "-";
                                            lines[index].arg1 = "-";
                                            lines[index].arg2 = "-";
                                            lines[index].destination = "S.next";

                                          }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 159 "tinyC.y"
    {
                                              (yyval.st) = (yyvsp[(2) - (9)].st);

                                              if((yyvsp[(6) - (9)].st)->p_line.next_list){
                                                mergeWithNextList((yyvsp[(6) - (9)].st),NEXT_LIST,(yyvsp[(9) - (9)].st),(yyval.st));
                                              }

                                              if((yyvsp[(5) - (9)].st)->p_line.next_list){
                                                mergeWithNextList((yyvsp[(5) - (9)].st),NEXT_LIST,(yyval.st),(yyval.st));
                                              }

                                              generateCodeCond((yyvsp[(2) - (9)].st),(yyvsp[(2) - (9)].st)->p_line.destination,(yyval.st));
                                              backpatch_list((yyvsp[(2) - (9)].st),TRUE_LIST,(yyvsp[(4) - (9)].st)->p_line.quad);
                                              backpatch_list((yyvsp[(2) - (9)].st),FALSE_LIST,(yyvsp[(8) - (9)].st)->p_line.quad);

                                              int index = (yyvsp[(2) - (9)].st)->p_line.quad+1;
                                              lines[index].quad = index;
                                              lines[index].operation = "-";
                                              lines[index].arg1 = "-";
                                              lines[index].arg2 = "-";

                                          }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 181 "tinyC.y"
    {

                                              (yyval.st) = (yyvsp[(3) - (6)].st);
                                              mergeWithNextList((yyvsp[(3) - (6)].st),FALSE_LIST,(yyval.st),(yyval.st));
                                          
                                              generateCodeCond((yyvsp[(3) - (6)].st),(yyvsp[(3) - (6)].st)->p_line.destination,(yyval.st));
                                          
                                              backpatch_list((yyvsp[(3) - (6)].st),TRUE_LIST,(yyvsp[(5) - (6)].st)->p_line.quad);

                                              int index = (yyvsp[(3) - (6)].st)->p_line.quad+1;
                                              lines[index].quad = index;
                                              lines[index].operation = "-";
                                              lines[index].arg1 = "-";
                                              lines[index].arg2 = "-";
                                              lines[index].destination = "S.next";

                                              index = getQuadWhile();
                                              lines[index].quad = index;
                                              lines[index].operation = "-";
                                              lines[index].arg1 = "-";
                                              lines[index].arg2 = "-";
                                              char ts[BUFFER_SIZE];
                                              sprintf(ts, "%d",(yyvsp[(2) - (6)].st)->p_line.quad);
                                              char* s = (char*)malloc(sizeof(char)*strlen(ts) + 1);
                                              strcpy(s,ts);
                                              lines[index].destination = s;

                                              quad = index+1;
                                          }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 210 "tinyC.y"
    { //the variable and expression is the same
                                            
                                            SymbolTable * t = getValue(st, (yyvsp[(1) - (4)].st)->name);

                                            ///// Conversión de Tipos
                                            if((yyvsp[(1) - (4)].st) -> type == (yyvsp[(3) - (4)].st) -> type){
                                              if((yyvsp[(1) - (4)].st) -> type == T_FLOAT){
                                                t -> val.fvalue  = (yyvsp[(3) - (4)].st) -> val.fvalue;
                                              }else if((yyvsp[(1) - (4)].st) -> type == T_INTEGER){
                                                t -> val.ivalue  = (yyvsp[(3) - (4)].st) -> val.ivalue;
                                              }
                                            //the variable and expression not the same  
                                            }else{
                                              yyerror("#Warning 4, implicit casting between int and float ");
                                              //check if term is int and factor is float
                                              if((yyvsp[(1) - (4)].st) -> type == T_INTEGER && (yyvsp[(3) - (4)].st) -> type == T_FLOAT){
                                                t -> val.ivalue  = (int)(yyvsp[(3) - (4)].st) -> val.fvalue;
                                                //check if term is float and factor is int
                                              }else if((yyvsp[(1) - (4)].st) -> type == T_FLOAT && (yyvsp[(3) - (4)].st) -> type == T_INTEGER){
                                                t -> val.fvalue  = (float)(yyvsp[(3) - (4)].st) -> val.ivalue;
                                              }
                                            }              
                              
                                            // Generación de Código
                                            generateCode("=",t,(yyvsp[(3) - (4)].st),"-",(yyval.st));

                                            //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);

                                            //Reutilizar variables temporales
                                            if((yyvsp[(3) - (4)].st)->name != NULL && (yyvsp[(3) - (4)].st)->name[0] == 't'){
                                              tempIndex = 0;
                                            }                                  
                                          }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 243 "tinyC.y"
    {}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 244 "tinyC.y"
    {}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 246 "tinyC.y"
    {
                                                  SymbolTable * t = getValue(st, (yyvsp[(2) - (3)].st)->name);
                                                  if((yyvsp[(2) - (3)].st) -> type == T_FLOAT){
                                                      t -> val.fvalue  += 1.0;
                                                  }else{
                                                      t -> val.ivalue  += 1;
                                                  }     
                                                }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 255 "tinyC.y"
    {
                                                  SymbolTable * t = getValue(st, (yyvsp[(1) - (3)].st)->name);
                                                  if((yyvsp[(1) - (3)].st) -> type == T_FLOAT){
                                                      t -> val.fvalue  += 1.0;
                                                  }else{
                                                      t -> val.ivalue  += 1;
                                                  }      
                                                }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 264 "tinyC.y"
    {
                                                  SymbolTable * t = getValue(st, (yyvsp[(2) - (3)].st)->name);
                                                  if((yyvsp[(2) - (3)].st) -> type == T_FLOAT){
                                                      t -> val.fvalue  -= 1.0;
                                                  }else{
                                                      t -> val.ivalue  -= 1;
                                                  }  
                                                }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 273 "tinyC.y"
    {
                                                 SymbolTable * t = getValue(st, (yyvsp[(1) - (3)].st)->name);
                                                  if((yyvsp[(1) - (3)].st) -> type == T_FLOAT){
                                                      t -> val.fvalue  -= 1.0;
                                                  }else{
                                                      t -> val.ivalue  -= 1;
                                                  }  
                                                }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 281 "tinyC.y"
    {}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 282 "tinyC.y"
    {}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 283 "tinyC.y"
    {}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 284 "tinyC.y"
    {  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 287 "tinyC.y"
    {
                                              (yyval.st) = (yyvsp[(2) - (3)].st);
                                            }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 292 "tinyC.y"
    {
                                              // Code Generation
                                              putNextQuad((yyval.st),TRUE_LIST,0);
                                              putNextQuad((yyval.st),FALSE_LIST,1);

                                              generateCode("<",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),"goto",(yyval.st));
                                              strcat((yyval.st)->p_line.code,"\ngoto");
                                              quad++;

                                            }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 302 "tinyC.y"
    {
                                              // Code Generation
                                              putNextQuad((yyval.st),TRUE_LIST,0);
                                              putNextQuad((yyval.st),FALSE_LIST,1);

                                              generateCode("==",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),"goto",(yyval.st));
                                              strcat((yyval.st)->p_line.code,"\ngoto");
                                              quad++;
                                            }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 311 "tinyC.y"
    {
                                              // Code Generation
                                              putNextQuad((yyval.st),TRUE_LIST,0);
                                              putNextQuad((yyval.st),FALSE_LIST,1);

                                              generateCode(">",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),"goto",(yyval.st));
                                              strcat((yyval.st)->p_line.code,"\ngoto");
                                              quad++;
                                            }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 320 "tinyC.y"
    {
                                              // Code Generation
                                              putNextQuad((yyval.st),TRUE_LIST,0);
                                              putNextQuad((yyval.st),FALSE_LIST,1);

                                              generateCode("<=",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),"goto",(yyval.st));
                                              strcat((yyval.st)->p_line.code,"\ngoto");
                                              quad++;
                                            }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 329 "tinyC.y"
    {
                                              // Code Generation
                                              putNextQuad((yyval.st),TRUE_LIST,0);
                                              putNextQuad((yyval.st),FALSE_LIST,1);

                                              generateCode(">=",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),"goto",(yyval.st));
                                              strcat((yyval.st)->p_line.code,"\ngoto");
                                              quad++;
                                            }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 338 "tinyC.y"
    {(yyval.st) = (yyvsp[(1) - (1)].st);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 341 "tinyC.y"
    {
                                        // same type
                                        if((yyvsp[(1) - (3)].st) -> type == (yyvsp[(3) - (3)].st) -> type){
                                          if((yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                            // the types are floating
                                            //$$ -> val.fvalue = ($1 -> val.fvalue + $3 -> val.fvalue);
                                            (yyval.st) -> type = T_FLOAT;
                                          }else{
                                            // the types are integer
                                            //$$ -> val.ivalue = ($1 -> val.ivalue + $3 -> val.ivalue);
                                            (yyval.st) -> type = T_INTEGER;
                                          }
                                        }else{
                                          //the types are not the same
                                          yyerror("Warning, implicit casting between int and float ");
                                          //check if term is int and factor is float
                                          if((yyvsp[(1) - (3)].st) -> type == T_INTEGER && (yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                            //$$ -> val.fvalue = ((float)($1 -> val.ivalue) + $3 -> val.fvalue);
                                            (yyval.st) -> type = T_FLOAT;
                                            //check if term is float and factor is int
                                          }else if((yyvsp[(1) - (3)].st) -> type == T_FLOAT && (yyvsp[(3) - (3)].st) -> type == T_INTEGER){
                                            //$$ -> val.fvalue = ($1 -> val.fvalue + (float)($3 -> val.ivalue));
                                            (yyval.st) -> type = T_FLOAT;
                                          }
                                        }

                                        //Code Generation
                                        newTemp("+",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),(yyval.st));
                                        //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                      }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 373 "tinyC.y"
    {
                                        // same type
                                        if((yyvsp[(1) - (3)].st) -> type == (yyvsp[(3) - (3)].st) -> type){
                                          if((yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                            // the types are floating
                                            //$$ -> val.fvalue = ($1 -> val.fvalue - $3 -> val.fvalue);
                                            (yyval.st) -> type = T_FLOAT;
                                          }else{
                                            // the types are integer
                                            //$$ -> val.ivalue = ($1 -> val.ivalue - $3 -> val.ivalue);
                                            (yyval.st) -> type = T_INTEGER;
                                          }
                                        }else{
                                          //the types are not the same
                                          yyerror("Warning, implicit casting between int and float ");
                                          //check if term is int and factor is float
                                          if((yyvsp[(1) - (3)].st) -> type == T_INTEGER && (yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                            //$$ -> val.fvalue = ((float)($1 -> val.ivalue) - $3 -> val.fvalue);
                                            (yyval.st) -> type = T_FLOAT;
                                            //check if term is float and factor is int
                                          }else if((yyvsp[(1) - (3)].st) -> type == T_FLOAT && (yyvsp[(3) - (3)].st) -> type == T_INTEGER){
                                            //$$ -> val.fvalue = ($1 -> val.fvalue - (float)($3 -> val.ivalue));
                                            (yyval.st) -> type = T_FLOAT;
                                          }
                                        }

                                        //Generación Código
                                        newTemp("-",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),(yyval.st));
                                        //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                      }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 404 "tinyC.y"
    {
                                        (yyval.st) = (yyvsp[(1) - (1)].st);
                                      }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 409 "tinyC.y"
    { //equal types
                                    if((yyvsp[(1) - (3)].st) -> type == (yyvsp[(3) - (3)].st) -> type){
                                      if((yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                        // the types are floating
                                        //$$ -> val.fvalue = ($1 -> val.fvalue * $3 -> val.fvalue);
                                        (yyval.st) -> type = T_FLOAT;
                                      }else{
                                        // the types are integer
                                        //$$ -> val.ivalue = ($1 -> val.ivalue * $3 -> val.ivalue);
                                        (yyval.st) -> type = T_INTEGER;
                                      }
                                    }else{
                                      //the types are not the same
                                      yyerror("Warning, implicit casting between int and float ");
                                      //check if term is int and factor is float
                                      if((yyvsp[(1) - (3)].st) -> type == T_INTEGER && (yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                        //$$ -> val.fvalue = ($1 -> val.ivalue * $3 -> val.fvalue);
                                        (yyval.st) -> type = T_FLOAT;
                                        //check if term is float and factor is int
                                      }else if((yyvsp[(1) - (3)].st) -> type == T_FLOAT && (yyvsp[(3) - (3)].st) -> type == T_INTEGER){
                                        //$$ -> val.fvalue = ($1 -> val.fvalue * $3 -> val.ivalue);
                                        (yyval.st) -> type = T_FLOAT;
                                      }
                                    }

                                    //Generación Código
                                        newTemp("*",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),(yyval.st));
                                        //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                  }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 438 "tinyC.y"
    {
                                    if((yyvsp[(1) - (3)].st) -> type == (yyvsp[(3) - (3)].st) -> type){
                                      //equal types
                                      if((yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                        // the types are floating
                                        if((yyvsp[(3) - (3)].st) -> val.fvalue == 0.0){
                                          yyerror("#Error, division by 0,");
                                          return 1;
                                        }else{
                                          //$$ -> value      = ($1 -> value / $3 -> value);
                                          //$$ -> val.fvalue = ($1 -> val.fvalue / $3 -> val.fvalue);
                                        }
                                        // both are integers
                                      }else{
                                        if((yyvsp[(3) - (3)].st) -> val.ivalue == 0){
                                          yyerror("#Error, division by 0,");
                                          return 1;
                                        }else{
                                          yyerror("Division between two ints, implicit casting to float");
                                          //$$ -> value      = ($1 -> value / $3 -> value);
                                          //$$ -> val.fvalue = ((float)$1 -> val.ivalue / (float)$3 -> val.ivalue);
                                          (yyval.st) -> type = T_FLOAT;  
                                        }
                                        
                                      }
                                    }else{
                                      //the types are not the same
                                      yyerror("#term 1, Warning, implicit casting between int and float ");
                                      //check if term is int and factor is float
                                      if((yyvsp[(1) - (3)].st) -> type == T_INTEGER && (yyvsp[(3) - (3)].st) -> type == T_FLOAT){
                                        //$$ -> value      = ($1 -> value / $3 -> value);
                                        //$$ -> val.fvalue = ((float)$1 -> val.ivalue / $3 -> val.fvalue);
                                        (yyval.st) -> type = T_FLOAT;
                                        //check if term is float and factor is int
                                      }else if((yyvsp[(1) - (3)].st) -> type == T_FLOAT && (yyvsp[(3) - (3)].st) -> type == T_INTEGER){
                                        //$$ -> value      = ($1 -> value / $3 -> value);
                                        //$$ -> val.fvalue = ($1 -> val.fvalue / (float)$3 -> val.ivalue);
                                        (yyval.st) -> type = T_FLOAT;
                                      }
                                    }

                                    //Generación Código
                                    newTemp("/",(yyvsp[(1) - (3)].st),(yyvsp[(3) - (3)].st),(yyval.st));
                                    //printf("%d %s %s %s %s\n", $$->p_line.quad, $$->p_line.operation, $$->p_line.arg1, $$->p_line.arg2, $$->p_line.destination);
                                  }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 483 "tinyC.y"
    {(yyval.st) = (yyvsp[(1) - (1)].st);}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 486 "tinyC.y"
    {
                                    (yyval.st) = (yyvsp[(2) - (3)].st);
                                  }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 489 "tinyC.y"
    {
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));
                                    t -> value = (yyvsp[(1) - (1)].ivalue);
                                    t -> val.ivalue = (yyvsp[(1) - (1)].ivalue);
                                    t -> type  = T_INTEGER;

                                    //Code Generation
                                    //t->name = NULL
                                    char ts[BUFFER_SIZE];
                                    sprintf(ts, "%d",t->val.ivalue);
                                    char* s = (char*)malloc(sizeof(char)*strlen(ts) + 1);
                                    strcpy(s,ts);
                                    t->name = s;
                                    
                                    (yyval.st) = t;
                                    
                                  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 506 "tinyC.y"
    {
                                    
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));
                                    t -> val.fvalue = (yyvsp[(1) - (1)].value);
                                    t -> value = (yyvsp[(1) - (1)].value);
                                    t -> type  = T_FLOAT;

                                    //Code Generation
                                    //t-> name = NULL;
                                    char ts[BUFFER_SIZE];
                                    sprintf(ts, "%f",t->val.fvalue);
                                    char* s = (char*)malloc(sizeof(char)*strlen(ts) + 1);
                                    strcpy(s,ts);
                                    t->name = s;

                                    (yyval.st) = t;
                                  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 523 "tinyC.y"
    {//se regresa el valor de la variable
                                    SymbolTable *t = (SymbolTable*)malloc(sizeof(SymbolTable));

                                    t -> type  = (yyvsp[(1) - (1)].st) -> type;
                                    t -> value = (yyvsp[(1) - (1)].st) -> value;

                                    if((yyvsp[(1) - (1)].st) -> type == T_FLOAT){
                                      t -> val.fvalue = (yyvsp[(1) - (1)].st) -> val.fvalue;
                                    }else if((yyvsp[(1) - (1)].st) -> type == T_INTEGER){
                                      t -> val.ivalue = (yyvsp[(1) - (1)].st) -> val.ivalue;
                                    }

                                    #ifdef DEBUG
                                    printf("%s\n", (yyvsp[(1) - (1)].st)->name);
                                    #endif

                                    t->name = (yyvsp[(1) - (1)].st)->name;

                                    (yyval.st) = t;
                                  }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 545 "tinyC.y"
    {//variable contiene el nombre de la variable
                                    if(findValue(st, (yyvsp[(1) - (1)].name)) == TRUE){
                                      SymbolTable *t = getValue(st, (yyvsp[(1) - (1)].name));
                                      (yyval.st) = t;
                                    }else{
                                      printf("#variable, No variable '%s' declared before\n", (yyvsp[(1) - (1)].name));
                                      yyerror("Error");
                                      return FALSE;
                                    }
                                  }
    break;



/* Line 1806 of yacc.c  */
#line 2149 "tinyC.tab.c"
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 556 "tinyC.y"


#include "lex.yy.c"


void yyerror (char *string){
  printf ("%s at line %d \n",string, yylineno);
}

SymbolTable* initSymbolTable(){
    SymbolTable* newTable = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    //tabla = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    return newTable;
}
void checkTableSize(SymbolTable* table){
    if(emptyItems == 1){
        #ifdef DEBUG
        printf("Full table\n");
        #endif
        resizeSymbolTable(table);
    }else{
      #ifdef DEBUG
      printf("Table still has space: %d\n", emptyItems);
      #endif
    }
}
void controlarColision(char* symbol, int type, SymbolTable * table, int index){
  //checkTableSize(table);
  #ifdef DEBUG
  printf("I'm going to look a new position for value %s type: %d \n", symbol, type);
  #endif
    while(table[index].name != NULL || index < size - 1){
      if(table[index].name == symbol){
            printf("Element found. No adding the symbol\n");
            return;
      }
        index++;      
        if(index >= size -1){
          index = 0;
        }
        #ifdef DEBUG
        printf("Search at index: %d from %d\n", index, size-1);
        #endif
        if(table[index].name == NULL){
            #ifdef DEBUG
            printf("At index %d there is an empty space \n", index);
            #endif
            table[index].name = symbol;
            table[index].type = type;
            emptyItems--;
            #ifdef DEBUG
            printf("Symbol inserted \n");
            #endif
            return;
        }else{
          #ifdef DEBUG
          printf("Cell full \n");
          #endif
        }
    }
}
SymbolTable* putValue(char* symbol, int type, SymbolTable*table){
    int hash = 0;
    int index;
    char * temp = symbol;

    #ifdef DEBUG
    printf("Table size: %d\n", size);
    printf("Symbol to insert: %s type: %d \n", symbol, type);
    #endif
    while(*temp){
        hash += (int)*(temp);
        temp++;
    }
    index = hash % size;
    
    if(table[index].name == NULL){
        char* newSymbol = (char*)malloc(sizeof(char)* strlen(symbol) + 1);
        strcpy(newSymbol, symbol);
        table[index].name = newSymbol;
        table[index].type = type;
        table[index].value = 0.0;
        #ifdef DEBUG
        printf("Inserted value: %s type: %d i: %d\n", newSymbol, type, index);
        #endif
        emptyItems--;
        checkTableSize(table);
        return table;
    }else{
        if(strcmp (table[index].name, symbol) == 0){
          #ifdef DEBUG
          printf("That symbol already exists!!!! \n");
          #endif
            return table;
        }else{
            //colision
            #ifdef DEBUG
            printf("\n\n***Colission at index %d\n", index);
            #endif
            controlarColision(symbol, type,  table, index);
            checkTableSize(table);
            return table;
        }
    }
    
    return NULL;
}
void resizeSymbolTable(SymbolTable * table){
    int oldsize = size;
    int i;
    string value;
    int type;
    size *= 2;
    emptyItems = size;
    SymbolTable * newST = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    #ifdef DEBUG
    printf("Double the size of the table\n");
    #endif
    for(i=0; i< oldsize; i++){
        type = table[i].type;
        value = table[i].name;
        if(value != NULL){
            putValue(value, type, newST);
        }
    }
    free(st);
    st = (SymbolTable*)malloc(sizeof(SymbolTable)* size);
    emptyItems = size;
    for(i=0; i< size; i++){
        value = newST[i].name;
        type = newST[i].type;
        if(value != NULL){
            putValue(value, type, st);
        }
    }
    free(newST);
}
char* getType(int value){
  switch(value){
    case 1:
    return "int";
    break;
    case 2:
    return "float";
  }

  return NULL;
}
int findValue(SymbolTable*table, string symbol){
  int i;
  for(i=0; i< size; i++){
    if(table[i].name != NULL){
      if(strcmp(table[i].name, symbol) == 0){
        return 0;
      }
    }
  }
  return 1;
}
SymbolTable * getValue(SymbolTable*table, string symbol){
  int i;
  for(i=0; i< size; i++){
    if(table[i].name != NULL){
      if(strcmp(table[i].name, symbol) == TRUE){
        return &table[i];
      }
    }
  }
  return NULL;
}
void showTable(SymbolTable*tabla){
    int i;
#ifdef DEBUG
    printf("\nSymbol Table\n");
#endif
    for(i=0; i< size; i++){
      //if(tabla[i].name != NULL){
        if(tabla[i].type == T_INTEGER){
          printf("Index: %3d   name: %3s   type: int value: %d\n", i, tabla[i].name,tabla[i].val.ivalue);  
        }else if(tabla[i].type == T_FLOAT){
          printf("Index: %3d   name: %3s   type: float value: %f\n", i, tabla[i].name, tabla[i].val.fvalue);
        }else{
          printf("Index: %3d   name: %3s   type: NULL \n", i, tabla[i].name);
        }
        
      //}
    }
}

// Code Generation

void putNextQuad(SymbolTable* arg, int list , int increment){
  char tempBuffer[BUFFER_SIZE];
  sprintf(tempBuffer,"%d ", quad + increment);
  char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
  strcpy(tempString,tempBuffer);

  if(list == TRUE_LIST){
    arg->p_line.true_list = tempString;
  } else if(list == FALSE_LIST) {
    arg->p_line.false_list = tempString;
  } else if(list == NEXT_LIST) {
    arg->p_line.next_list = tempString;
  }
}

void generateCode(char* op, SymbolTable* arg1,SymbolTable* arg2, char* dest, SymbolTable* top) {
   top->p_line.quad = quad;

   lines[quad].quad = quad;
   lines[quad].operation = op;
   lines[quad].arg1 = arg1->name;
   lines[quad].arg2 = arg2->name;
   lines[quad].destination = dest;
   quad++;

   top->p_line.operation = op;
   top->p_line.arg1 = arg1->name;
   top->p_line.arg2 = arg2->name;
   top->p_line.destination = dest;

   char tempBuffer[BUFFER_SIZE];
   sprintf(tempBuffer,"%s %s %s %s", op, arg1->name, arg2->name, dest);
   char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
   strcpy(tempString,tempBuffer);
   top->p_line.code = tempString;

   top->p_line.next_list = NULL;   
}

void generateCodeCond(SymbolTable* arg, char* dest, SymbolTable* top){
  int index = arg->p_line.quad;
  lines[index].quad = index;
  lines[index].operation = arg->p_line.operation;
  lines[index].arg1 = arg->p_line.arg1;
  lines[index].arg2 = arg->p_line.arg2;
  lines[index].destination = arg->p_line.destination;

  top->p_line.quad = index;
  top->p_line.operation = arg->p_line.operation;
  top->p_line.arg1 = arg->p_line.arg1;
  top->p_line.arg2 = arg->p_line.arg2;
  top->p_line.destination = arg->p_line.destination;

  char tempBuffer[BUFFER_SIZE];
  sprintf(tempBuffer,"%s %s %s %s", arg->p_line.operation, arg->p_line.arg1, arg->p_line.arg2, dest);
  char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
  strcpy(tempString,tempBuffer);
  top->p_line.code = tempString;

  top->p_line.next_list = NULL;  

  quad++;
}

void newTemp(char* op, SymbolTable* arg1, SymbolTable* arg2, SymbolTable* top) {
  
  
  lines[quad].quad = quad;
  lines[quad].operation = op;
  lines[quad].arg1 = arg1->name;
  lines[quad].arg2 = arg2->name;

  top->p_line.quad = quad;
  char tempBuffer[BUFFER_SIZE];
  sprintf(tempBuffer,"%s %s %s t%d", op, arg1->name, arg2->name,tempIndex);
  char* tempString = (char*)malloc(sizeof(char)*strlen(tempBuffer) + 1);
  strcpy(tempString,tempBuffer);
  char t[BUFFER_SIZE];
  tempIndex++;
  sprintf(t, "t%d", tempIndex-1);
  char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
  strcpy(s,t);
  top->name = s;
  top->p_line.operation = op;
  top->p_line.arg1 = arg1->name;
  top->p_line.arg2 = arg2->name;
  top->p_line.code = tempString;
  top->p_line.destination = s;
  
  lines[quad].destination = s;

  quad++;
}

void backpatch_list(SymbolTable* e, int list, int nQuad){
  char *strToken = "";
  char t[BUFFER_SIZE];
  sprintf(t, "%d", nQuad);
  char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
  strcpy(s,t);
  
  if(list == FALSE_LIST){
    strToken = strtok(e->p_line.false_list," ");
  } else if(list == TRUE_LIST){
    strToken = strtok(e->p_line.true_list," ");
  } else if(list == NEXT_LIST){
    strToken = strtok(e->p_line.next_list," ");
  }

  while(strToken != NULL){
      int i = atoi(strToken);
      lines[i].destination = s;   
      strToken = strtok(NULL," ");
    }
}

void mergeWithNextList(SymbolTable* arg1, int l1, SymbolTable* arg2, SymbolTable* top) {
  char t[BUFFER_SIZE];

  if(arg2->p_line.next_list == NULL){
    if(l1 == FALSE_LIST)
      sprintf(t, "%s", arg1->p_line.false_list);
    else if(l1 == TRUE_LIST)
      sprintf(t, "%s", arg1->p_line.true_list);
    else if(l1 == NEXT_LIST)
      sprintf(t, "%s", arg1->p_line.next_list);
  } else if(l1 == FALSE_LIST) {
    sprintf(t, "%s %s", arg1->p_line.false_list,arg2->p_line.next_list);
  } else if(l1 == TRUE_LIST) {
    sprintf(t, "%s %s", arg1->p_line.true_list,arg2->p_line.next_list);
  } else if(l1 == NEXT_LIST) {
    sprintf(t, "%s %s", arg1->p_line.next_list,arg2->p_line.next_list);
  }
  char* s = (char*)malloc(sizeof(char)*strlen(t) + 1);
  strcpy(s,t);
  top->p_line.next_list = s;
}

void printLines(){
  int i;

  i = 1;
  while(lines[i].quad){
    printf("%d %s %s %s %s\n",lines[i].quad, lines[i].operation, lines[i].arg1, lines[i].arg2, lines[i].destination);    
    i++;
  }

}

int getQuadWhile(){
  int i = 1;
  while(lines[i].quad){
   i++;
  }
  return i;
}

int main (){
  st = initSymbolTable();

  if(yyparse() == 0){
    printf("No errors\n");
    //showTable(st);
    printLines();
  }
  
  return 0;
}


