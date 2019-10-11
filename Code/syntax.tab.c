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
#line 1 "./syntax.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	#include <stdlib.h>
	#include <math.h>
	#include "lex.yy.c"
	int IFerror;	
	struct treeNode *treeRoot;
	struct treeNode *create(char *type, int count, ...);


/* Line 268 of yacc.c  */
#line 84 "./syntax.tab.c"

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
     INT = 258,
     FLOAT = 259,
     SEMI = 260,
     COMMA = 261,
     ID = 262,
     TYPE = 263,
     OCT = 264,
     HEX = 265,
     WRONGHEX = 266,
     WRONGOCT = 267,
     ASSIGNOP = 268,
     OR = 269,
     AND = 270,
     RELOP = 271,
     PLUS = 272,
     MINUS = 273,
     DIV = 274,
     STAR = 275,
     NOT = 276,
     RC = 277,
     LC = 278,
     DOT = 279,
     RB = 280,
     LB = 281,
     RP = 282,
     LP = 283,
     LOWER_THAN_ELSE = 284,
     RETURN = 285,
     STRUCT = 286,
     WHILE = 287,
     ELSE = 288,
     IF = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 13 "./syntax.y"
struct treeNode *node;


/* Line 293 of yacc.c  */
#line 158 "./syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 170 "./syntax.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   352

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    17,    20,    22,
      26,    28,    30,    36,    39,    41,    42,    44,    46,    51,
      56,    60,    63,    67,    69,    72,    75,    78,    83,    86,
      89,    90,    93,    95,    99,   105,   113,   119,   122,   128,
     134,   137,   143,   146,   149,   150,   154,   158,   160,   164,
     166,   170,   174,   178,   182,   186,   190,   194,   198,   202,
     206,   209,   212,   217,   221,   226,   230,   232,   234,   236,
     238,   240,   242,   244,   248
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    37,    -1,    -1,    40,
      39,     5,    -1,    40,    45,    48,    -1,    40,     5,    -1,
      44,    -1,    44,     6,    39,    -1,     8,    -1,    41,    -1,
      31,    42,    23,    51,    22,    -1,    31,    43,    -1,     7,
      -1,    -1,     7,    -1,     7,    -1,    44,    26,     3,    25,
      -1,     7,    28,    46,    27,    -1,     7,    28,    27,    -1,
       1,    27,    -1,    47,     6,    46,    -1,    47,    -1,    40,
      44,    -1,     1,     6,    -1,     1,    25,    -1,    23,    51,
      49,    22,    -1,     1,    22,    -1,    50,    49,    -1,    -1,
      55,     5,    -1,    48,    -1,    30,    55,     5,    -1,    34,
      28,    55,    27,    50,    -1,    34,    28,    55,    27,    50,
      33,    50,    -1,    32,    28,    55,    27,    50,    -1,     1,
       5,    -1,     1,    32,    28,    55,    27,    -1,     1,    34,
      28,    55,    27,    -1,     1,    33,    -1,    33,    28,    55,
      27,     1,    -1,    55,     1,    -1,    52,    51,    -1,    -1,
      40,    53,     5,    -1,    40,    53,     1,    -1,    54,    -1,
      54,     6,    53,    -1,    44,    -1,    44,    13,    55,    -1,
      55,    13,    55,    -1,    55,    15,    55,    -1,    55,    14,
      55,    -1,    55,    16,    55,    -1,    55,    17,    55,    -1,
      55,    18,    55,    -1,    55,    20,    55,    -1,    55,    19,
      55,    -1,    28,    55,    27,    -1,    18,    55,    -1,    21,
      55,    -1,     7,    28,    56,    27,    -1,     7,    28,    27,
      -1,    55,    26,    55,    25,    -1,    55,    24,     7,    -1,
       7,    -1,     3,    -1,     4,    -1,    10,    -1,     9,    -1,
      11,    -1,    12,    -1,    55,     6,    56,    -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    38,    39,    41,    42,    43,    45,    46,
      48,    49,    51,    52,    54,    55,    57,    59,    60,    62,
      63,    64,    66,    67,    69,    70,    71,    73,    74,    76,
      77,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    92,    93,    95,    96,    98,    99,   101,
     102,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   127,   128
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "SEMI", "COMMA", "ID",
  "TYPE", "OCT", "HEX", "WRONGHEX", "WRONGOCT", "ASSIGNOP", "OR", "AND",
  "RELOP", "PLUS", "MINUS", "DIV", "STAR", "NOT", "RC", "LC", "DOT", "RB",
  "LB", "RP", "LP", "LOWER_THAN_ELSE", "RETURN", "STRUCT", "WHILE", "ELSE",
  "IF", "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList",
  "Specifier", "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Dec", "Exp", "Args", 0
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
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      40,    40,    41,    41,    42,    42,    43,    44,    44,    45,
      45,    45,    46,    46,    47,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     1,     3,
       1,     1,     5,     2,     1,     0,     1,     1,     4,     4,
       3,     2,     3,     1,     2,     2,     2,     4,     2,     2,
       0,     2,     1,     3,     5,     7,     5,     2,     5,     5,
       2,     5,     2,     2,     0,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    15,     0,     2,     4,     0,    11,    16,     0,
      13,     1,     3,     0,     7,    17,     0,     8,     0,    44,
      21,     0,     5,     0,     0,     0,    44,     6,     0,     0,
      44,     0,    20,     0,     0,    23,    17,     9,     0,    28,
       0,    49,     0,    47,    12,    43,    25,    26,    24,    19,
       0,    18,     0,    67,    68,    66,    70,    69,    71,    72,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,    46,    45,     0,    22,    37,     0,    40,     0,
       0,    60,    61,     0,     0,     0,     0,     0,    27,    29,
      42,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    48,     0,     0,    63,    74,     0,    59,
      33,     0,     0,     0,    51,    53,    52,    54,    55,    56,
      58,    57,    65,     0,     0,     0,     0,    62,     0,     0,
       0,    64,    38,    39,    73,    36,    41,    34,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    28,     7,     9,    10,    17,
      18,    34,    35,    67,    68,    69,    29,    30,    42,    43,
      70,   108
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int16 yypact[] =
{
      -2,   -61,     1,    22,   -61,    -2,    63,   -61,   -10,    30,
     -61,   -61,   -61,     3,   -61,    28,    66,    25,    20,    -2,
     -61,    15,   -61,    52,    75,    60,    -2,   -61,    52,    65,
      -2,    -1,   -61,    52,    71,    84,   -61,   -61,    74,   -61,
      51,    54,    13,    94,   -61,   -61,   -61,   -61,    76,   -61,
       9,   -61,    43,   -61,   -61,    77,   -61,   -61,   -61,   -61,
     140,   140,   140,   140,    79,    81,    83,   -61,    82,    51,
     109,   140,   -61,   -61,    52,   -61,   -61,    88,   -61,    92,
     127,   326,    23,   186,   157,   140,   140,   140,   -61,   -61,
     -61,   -61,   140,   140,   140,   140,   140,   140,   140,   140,
     105,   140,   290,   -61,   140,   140,   -61,   172,   113,   -61,
     -61,   201,   216,   231,   290,   302,   313,   323,   326,   326,
      23,    23,   -61,   276,   246,   261,   140,   -61,    85,   120,
      85,   -61,   -61,   -61,   -61,   -61,   -61,    99,    85,   -61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   136,   -61,   119,     7,   -61,   -61,   -61,   -24,
     -61,    96,   -61,   135,    87,   -37,   -11,   -61,    86,   -61,
     -60,    31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      81,    82,    83,    84,    41,    46,     1,     6,     8,    48,
      31,   102,     6,   -14,    72,    40,    31,     1,    73,    45,
     107,    25,    11,     1,    47,   111,   112,   113,    33,     2,
      20,    23,   114,   115,   116,   117,   118,   119,   120,   121,
       2,   123,    32,    26,   124,   125,     2,   100,    76,   101,
      41,    24,    52,    19,    53,    54,    21,    33,    55,    36,
      56,    57,    58,    59,    13,    39,   107,    71,    14,    60,
      15,    22,    61,   -30,    26,    77,    78,    79,    38,    62,
      24,    63,    39,    64,    65,    66,    52,    44,    53,    54,
      50,   135,    55,   137,    56,    57,    58,    59,    49,    51,
      74,   139,    24,    60,    88,    80,    61,    85,    26,    86,
      90,    87,   122,    62,    91,    63,   104,    64,    65,    66,
     105,   136,    92,    93,    94,    95,    96,    97,    98,    99,
      53,    54,   138,   100,    55,   101,    56,    57,    58,    59,
     127,    12,    37,    53,    54,    60,    75,    55,    61,    56,
      57,    58,    59,    27,   106,    62,    89,   134,    60,     0,
     103,    61,   110,     0,     0,     0,     0,     0,    62,     0,
      92,    93,    94,    95,    96,    97,    98,    99,   126,     0,
       0,   100,     0,   101,     0,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,   100,     0,   101,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,     0,   101,   109,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,   100,     0,   101,   128,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,     0,   101,   129,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,   100,     0,   101,   130,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,     0,   101,   132,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,   100,     0,   101,   133,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,   131,   101,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,   100,     0,   101,    94,    95,    96,
      97,    98,    99,     0,     0,     0,   100,     0,   101,    95,
      96,    97,    98,    99,     0,     0,     0,   100,     0,   101,
      96,    97,    98,    99,     0,    98,    99,   100,     0,   101,
     100,     0,   101
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-61))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      60,    61,    62,    63,    28,     6,     8,     0,     7,    33,
       1,    71,     5,    23,     1,    26,     1,     8,     5,    30,
      80,     1,     0,     8,    25,    85,    86,    87,    21,    31,
      27,     6,    92,    93,    94,    95,    96,    97,    98,    99,
      31,   101,    27,    23,   104,   105,    31,    24,     5,    26,
      74,    26,     1,    23,     3,     4,    28,    50,     7,     7,
       9,    10,    11,    12,     1,    22,   126,    13,     5,    18,
       7,     5,    21,    22,    23,    32,    33,    34,     3,    28,
      26,    30,    22,    32,    33,    34,     1,    22,     3,     4,
       6,   128,     7,   130,     9,    10,    11,    12,    27,    25,
       6,   138,    26,    18,    22,    28,    21,    28,    23,    28,
       1,    28,     7,    28,     5,    30,    28,    32,    33,    34,
      28,     1,    13,    14,    15,    16,    17,    18,    19,    20,
       3,     4,    33,    24,     7,    26,     9,    10,    11,    12,
      27,     5,    23,     3,     4,    18,    50,     7,    21,     9,
      10,    11,    12,    18,    27,    28,    69,   126,    18,    -1,
      74,    21,     5,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,     6,    -1,
      -1,    24,    -1,    26,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    -1,    26,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    27,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    -1,    26,    27,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    27,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    -1,    26,    27,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    27,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    -1,    26,    27,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    26,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    -1,    26,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    24,    -1,    26,
      17,    18,    19,    20,    -1,    19,    20,    24,    -1,    26,
      24,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    31,    36,    37,    38,    40,    41,     7,    42,
      43,     0,    37,     1,     5,     7,    39,    44,    45,    23,
      27,    28,     5,     6,    26,     1,    23,    48,    40,    51,
      52,     1,    27,    40,    46,    47,     7,    39,     3,    22,
      51,    44,    53,    54,    22,    51,     6,    25,    44,    27,
       6,    25,     1,     3,     4,     7,     9,    10,    11,    12,
      18,    21,    28,    30,    32,    33,    34,    48,    49,    50,
      55,    13,     1,     5,     6,    46,     5,    32,    33,    34,
      28,    55,    55,    55,    55,    28,    28,    28,    22,    49,
       1,     5,    13,    14,    15,    16,    17,    18,    19,    20,
      24,    26,    55,    53,    28,    28,    27,    55,    56,    27,
       5,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,     7,    55,    55,    55,     6,    27,    27,    27,
      27,    25,    27,    27,    56,    50,     1,    50,    33,    50
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
        case 2:

/* Line 1806 of yacc.c  */
#line 36 "./syntax.y"
    {(yyval.node)=create("Program",1,(yyvsp[(1) - (1)].node));treeRoot=(yyval.node);}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 38 "./syntax.y"
    {(yyval.node)=create("ExtDefList",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 39 "./syntax.y"
    {(yyval.node)=NULL;}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 41 "./syntax.y"
    {(yyval.node)=create("ExtDef",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 42 "./syntax.y"
    {(yyval.node)=create("ExtDef",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 43 "./syntax.y"
    {(yyval.node)=create("ExtDef",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 45 "./syntax.y"
    {(yyval.node)=create("ExtDecList",1,(yyvsp[(1) - (1)].node));}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 46 "./syntax.y"
    {(yyval.node)=create("ExtDecList",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 48 "./syntax.y"
    {(yyval.node)=create("Specifier",1,(yyvsp[(1) - (1)].node));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 49 "./syntax.y"
    {(yyval.node)=create("Specifier",1,(yyvsp[(1) - (1)].node));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 51 "./syntax.y"
    {(yyval.node)=create("StructSpecifier",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 52 "./syntax.y"
    {(yyval.node)=create("StructSpecifier",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 54 "./syntax.y"
    {(yyval.node)=create("OptTag",1,(yyvsp[(1) - (1)].node));}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 55 "./syntax.y"
    {(yyval.node)=NULL;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 57 "./syntax.y"
    {(yyval.node)=create("Tag",1,(yyvsp[(1) - (1)].node));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 59 "./syntax.y"
    {(yyval.node)=create("VarDec",1,(yyvsp[(1) - (1)].node));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 60 "./syntax.y"
    {(yyval.node)=create("VarDec",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 62 "./syntax.y"
    {(yyval.node)=create("FunDec",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 63 "./syntax.y"
    {(yyval.node)=create("FunDec",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 64 "./syntax.y"
    {IFerror=1;}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 66 "./syntax.y"
    {(yyval.node)=create("VarList",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 67 "./syntax.y"
    {(yyval.node)=create("VarList",1,(yyvsp[(1) - (1)].node));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 69 "./syntax.y"
    {(yyval.node)=create("ParamDec",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 70 "./syntax.y"
    {IFerror=1;}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 71 "./syntax.y"
    {IFerror=1;}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 73 "./syntax.y"
    {(yyval.node)=create("CompSt",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 74 "./syntax.y"
    {IFerror=1;}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 76 "./syntax.y"
    {(yyval.node)=create("StmtList",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 77 "./syntax.y"
    {(yyval.node)=NULL;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 79 "./syntax.y"
    {(yyval.node)=create("Stmt",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 80 "./syntax.y"
    {(yyval.node)=create("Stmt",1,(yyvsp[(1) - (1)].node));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 81 "./syntax.y"
    {(yyval.node)=create("Stmt",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 82 "./syntax.y"
    {(yyval.node)=create("Stmt",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 83 "./syntax.y"
    {(yyval.node)=create("Stmt",7,(yyvsp[(1) - (7)].node),(yyvsp[(2) - (7)].node),(yyvsp[(3) - (7)].node),(yyvsp[(4) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(6) - (7)].node),(yyvsp[(7) - (7)].node));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 84 "./syntax.y"
    {(yyval.node)=create("Stmt",5,(yyvsp[(1) - (5)].node),(yyvsp[(2) - (5)].node),(yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node),(yyvsp[(5) - (5)].node));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 85 "./syntax.y"
    {IFerror=1;}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 86 "./syntax.y"
    {IFerror=1;}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 87 "./syntax.y"
    {IFerror=1;}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 88 "./syntax.y"
    {IFerror=1;}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 89 "./syntax.y"
    {IFerror=1;}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 90 "./syntax.y"
    {IFerror=1;}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 92 "./syntax.y"
    {(yyval.node)=create("DefList",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 93 "./syntax.y"
    {(yyval.node)=NULL;}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 95 "./syntax.y"
    {(yyval.node)=create("Def",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 96 "./syntax.y"
    {IFerror=1;}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 98 "./syntax.y"
    {(yyval.node)=create("DecList",1,(yyvsp[(1) - (1)].node));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 99 "./syntax.y"
    {(yyval.node)=create("DecList",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 101 "./syntax.y"
    {(yyval.node)=create("Dec",1,(yyvsp[(1) - (1)].node));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 102 "./syntax.y"
    {(yyval.node)=create("Dec",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 104 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 105 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 106 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 107 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 108 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 109 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 110 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 111 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 112 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 113 "./syntax.y"
    {(yyval.node)=create("Exp",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 114 "./syntax.y"
    {(yyval.node)=create("Exp",2,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 115 "./syntax.y"
    {(yyval.node)=create("Exp",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 116 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 117 "./syntax.y"
    {(yyval.node)=create("Exp",4,(yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node),(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 118 "./syntax.y"
    {(yyval.node)=create("Exp",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 119 "./syntax.y"
    {(yyval.node)=create("Exp",1,(yyvsp[(1) - (1)].node));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 120 "./syntax.y"
    {(yyval.node)=create("Exp",1,(yyvsp[(1) - (1)].node));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 121 "./syntax.y"
    {(yyval.node)=create("Exp",1,(yyvsp[(1) - (1)].node));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 122 "./syntax.y"
    {(yyval.node)=create("Exp",1,(yyvsp[(1) - (1)].node));}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 123 "./syntax.y"
    {(yyval.node)=create("Exp",1,(yyvsp[(1) - (1)].node));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 124 "./syntax.y"
    {IFerror = 1;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 125 "./syntax.y"
    {IFerror = 1;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 127 "./syntax.y"
    {(yyval.node)=create("Args",3,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 128 "./syntax.y"
    {(yyval.node)=create("Args",1,(yyvsp[(1) - (1)].node));}
    break;



/* Line 1806 of yacc.c  */
#line 2067 "./syntax.tab.c"
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
#line 131 "./syntax.y"

yyerror(char *msg){
	fprintf(stderr,"Error type B at line %d: unexpected \'%s\'\n",yylineno, yytext);
//	fprintf(stderr,"Error type B at line %d:%s\n",yylineno,yytext);
}

struct treeNode *create(char *type, int count, ...){
	struct treeNode *root = (struct treeNode *)malloc(sizeof(struct treeNode));
	root->flag=0;
	va_list n;
	va_start (n, count);

	strcpy(root->type, type);
	int i;
	for(i = 0; i < count; i++){
//		root->child[i] = (struct treeNode *)malloc(sizeof(struct treeNode));
		root->child[i] = va_arg(n,struct treeNode *);
		root->line = root->child[0]->line;
//		root->child[i]->parent = root;
//		printf("%s\n",root->type);
//		printf("NULLLLL?%d\t%d\n",i,root->child[i]->parent==NULL?1:0);
		if(root->child[i]!=NULL) {
			root->child[i]->parent=root;
		}
	}
	va_end(n);
	return root;
}

void print(struct treeNode *root, int depth){
//	printf("%s\n","print");
	if(root == NULL){
//		printf("%s\n","null");
		return;
	}
//	printf("%s\n",root->type);
	int i;
	for(i=0;i<depth;i++)
		printf("  ");
	if(root->flag){
		if(strcmp(root->type,"INT")==0|strcmp(root->type,"TYPE")==0|strcmp(root->type,"ID")==0|strcmp(root->type,"FLOAT")==0)
			printf("%s: %s\n",root->type,root->text);
		else if(strcmp(root->type,"HEX")==0){
			int len = strlen(root->text);
			int j;
			int temp=0;
			for(j=len-1;j>=2;j--){
				int k=0;
				int temp_=1;
				for(k=0;k<len-j-1;k++)
					temp_*=16;
				switch(root->text[j]){
				case 'A':
				case 'a':if(temp_==0) temp+=10;temp+=10*temp_;break;
				case 'B':
				case 'b':if(temp_==0) temp+=11;temp+=11*temp_;break;
				case 'C':
				case 'c':if(temp_==0) temp+=12;temp+=12*temp_;break;
				case 'D':
				case 'd':if(temp_==0) temp+=13;temp+=13*temp_;break;
				case 'E':
				case 'e':if(temp_==0) temp+=14;temp+=14*temp_;break;
				case 'F':
				case 'f':if(temp_==0) temp+=15;temp+=15*temp_;break;
				default:temp+=(root->text[j]-'0')*temp_;
				}
			}
			printf("%s: %d\n","INT",temp);
		}
		else if(strcmp(root->type,"OCT")==0){
			int len = strlen(root->text);
			int j;
			int temp=0;
			for(j=len-1;j>=1;j--){
				int k=0;
				int temp_=1;
				for(k=0;k<len-j-1;k++)
					temp_*=8;
//				printf("%d\n",temp_);
				if(temp_==0)
					temp+=(root->text[j]-'0');
				temp+=(root->text[j]-'0')*temp_;
//				printf("%d\n",temp);
			}
			printf("%s: %d\n","INT",temp);
		}
		else printf("%s\n",root->type);
	}
	else {
		printf("%s (%d)\n",root->type, root->line);
	}
	for(i=0;i<7;i++){
		if(root->child[i]!=NULL)
			print(root->child[i],depth+1);
	}
}

