/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1805060.y"

#include<bits/stdc++.h>
#include "SymbolTable.cpp"

using namespace std;



extern FILE *yyin;

SymbolTable s_table(7);
FILE *inp_file;
ofstream log_file;
ofstream error_file;

int line_count = 1;
int num_of_error = 0;

string type;

int yyparse(void);
int yylex(void);

void add_log(int lc, string rule)
{
	log_file<<"Line "<<lc<<": "<<rule<<endl<<endl;
}

void add_error(int lc, string msg, string name)
{
	error_file<<"Error at line "<<lc<<": "<<msg<<" "<<name<<endl<<endl;
	log_file<<"Error at line "<<lc<<": "<<msg<<" "<<name<<endl<<endl;
}

void yyerror(char *s)
{
	//write your code
	add_error(line_count, s, "");
	num_of_error++;
}


#line 114 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    DO = 261,                      /* DO  */
    WHILE = 262,                   /* WHILE  */
    CONTINUE = 263,                /* CONTINUE  */
    DEFAULT = 264,                 /* DEFAULT  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    LPAREN = 267,                  /* LPAREN  */
    RPAREN = 268,                  /* RPAREN  */
    LCURL = 269,                   /* LCURL  */
    RCURL = 270,                   /* RCURL  */
    LTHIRD = 271,                  /* LTHIRD  */
    RTHIRD = 272,                  /* RTHIRD  */
    INCOP = 273,                   /* INCOP  */
    DECOP = 274,                   /* DECOP  */
    ASSIGNOP = 275,                /* ASSIGNOP  */
    NOT = 276,                     /* NOT  */
    PRINTLN = 277,                 /* PRINTLN  */
    COMMA = 278,                   /* COMMA  */
    SEMICOLON = 279,               /* SEMICOLON  */
    ID = 280,                      /* ID  */
    CONST_INT = 281,               /* CONST_INT  */
    CONST_FLOAT = 282,             /* CONST_FLOAT  */
    CONST_CHAR = 283,              /* CONST_CHAR  */
    INT = 284,                     /* INT  */
    FLOAT = 285,                   /* FLOAT  */
    DOUBLE = 286,                  /* DOUBLE  */
    CHAR = 287,                    /* CHAR  */
    ADDOP = 288,                   /* ADDOP  */
    MULOP = 289,                   /* MULOP  */
    RELOP = 290,                   /* RELOP  */
    LOGICOP = 291,                 /* LOGICOP  */
    LOWER_THAN_ELSE = 292          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define DO 261
#define WHILE 262
#define CONTINUE 263
#define DEFAULT 264
#define RETURN 265
#define VOID 266
#define LPAREN 267
#define RPAREN 268
#define LCURL 269
#define RCURL 270
#define LTHIRD 271
#define RTHIRD 272
#define INCOP 273
#define DECOP 274
#define ASSIGNOP 275
#define NOT 276
#define PRINTLN 277
#define COMMA 278
#define SEMICOLON 279
#define ID 280
#define CONST_INT 281
#define CONST_FLOAT 282
#define CONST_CHAR 283
#define INT 284
#define FLOAT 285
#define DOUBLE 286
#define CHAR 287
#define ADDOP 288
#define MULOP 289
#define RELOP 290
#define LOGICOP 291
#define LOWER_THAN_ELSE 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "1805060.y"

	SymbolInfo *s_info;
	vector<SymbolInfo*>* siList;

#line 246 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_LPAREN = 12,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 13,                    /* RPAREN  */
  YYSYMBOL_LCURL = 14,                     /* LCURL  */
  YYSYMBOL_RCURL = 15,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 16,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 17,                    /* RTHIRD  */
  YYSYMBOL_INCOP = 18,                     /* INCOP  */
  YYSYMBOL_DECOP = 19,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 20,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_PRINTLN = 22,                   /* PRINTLN  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_CONST_INT = 26,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 27,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 28,                /* CONST_CHAR  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 31,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 32,                      /* CHAR  */
  YYSYMBOL_ADDOP = 33,                     /* ADDOP  */
  YYSYMBOL_MULOP = 34,                     /* MULOP  */
  YYSYMBOL_RELOP = 35,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 36,                   /* LOGICOP  */
  YYSYMBOL_LOWER_THAN_ELSE = 37,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_start = 39,                     /* start  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_unit = 41,                      /* unit  */
  YYSYMBOL_func_declaration = 42,          /* func_declaration  */
  YYSYMBOL_func_definition = 43,           /* func_definition  */
  YYSYMBOL_parameter_list = 44,            /* parameter_list  */
  YYSYMBOL_compound_statement = 45,        /* compound_statement  */
  YYSYMBOL_var_declaration = 46,           /* var_declaration  */
  YYSYMBOL_type_specifier = 47,            /* type_specifier  */
  YYSYMBOL_declaration_list = 48,          /* declaration_list  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_expression_statement = 51,      /* expression_statement  */
  YYSYMBOL_variable = 52,                  /* variable  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_logic_expression = 54,          /* logic_expression  */
  YYSYMBOL_rel_expression = 55,            /* rel_expression  */
  YYSYMBOL_simple_expression = 56,         /* simple_expression  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_unary_expression = 58,          /* unary_expression  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_arguments = 61                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    76,   106,   125,   140,   155,   174,   213,
     237,   282,   317,   335,   352,   362,   373,   399,   412,   435,
     441,   447,   455,   479,   506,   522,   543,   560,   588,   606,
     624,   642,   698,   733,   782,   817,   830,   851,   860,   880,
     889,   913,   930,   960,   977,  1006,  1023,  1052,  1065,  1090,
    1103,  1132,  1151,  1170,  1184,  1197,  1219,  1240,  1250,  1260,
    1276,  1293,  1307,  1331
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "DO", "WHILE", "CONTINUE", "DEFAULT", "RETURN", "VOID", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "INCOP", "DECOP",
  "ASSIGNOP", "NOT", "PRINTLN", "COMMA", "SEMICOLON", "ID", "CONST_INT",
  "CONST_FLOAT", "CONST_CHAR", "INT", "FLOAT", "DOUBLE", "CHAR", "ADDOP",
  "MULOP", "RELOP", "LOGICOP", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -61,   -61,   -61,    31,    -3,   -61,   -61,   -61,   -61,
      -9,   -61,   -61,     9,    36,    23,    11,    39,   -61,    -1,
       1,    46,    57,    24,    51,   -61,   -61,     4,    -3,   -61,
     -61,    22,    67,    74,    81,   131,   131,   -61,   131,    87,
     -61,    26,   -61,   -61,   131,   -61,   -61,    75,    80,   -61,
     -61,    78,    58,   -61,    72,    16,    69,   -61,   -61,   -61,
     -61,    86,    98,   131,   120,   131,    93,   105,    70,   -61,
      97,   131,   131,   -61,   108,   -61,   -61,   -61,   -61,   131,
     -61,   131,   131,   131,   131,   -61,   -61,   112,   120,   113,
     -61,   -61,   114,   -61,   115,   106,   123,   -61,   -61,    69,
     104,   -61,   109,   131,   109,   124,   -61,   131,   -61,   145,
     137,   -61,   -61,   -61,   109,   109,   -61,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    19,    20,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    24,     0,     0,     0,     0,    18,     0,
       0,    15,     0,    22,     0,     9,    11,     0,     0,    14,
      25,     0,     0,     0,     0,     0,     0,    17,     0,     0,
      37,    39,    57,    58,     0,    30,    28,     0,     0,    26,
      29,    54,     0,    41,    43,    45,    47,    49,    53,     8,
      10,    13,     0,     0,     0,     0,     0,     0,    54,    52,
       0,     0,     0,    51,    24,    16,    27,    59,    60,     0,
      38,     0,     0,     0,     0,    12,    23,     0,     0,     0,
      36,    56,     0,    63,     0,    61,     0,    42,    44,    48,
      46,    50,     0,     0,     0,     0,    55,     0,    40,    32,
       0,    34,    35,    62,     0,     0,    33,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   146,   -61,   -61,   -61,   -10,    15,     7,
     -61,   -61,   -47,   -59,   -38,   -33,   -60,    73,    76,    79,
     -34,   -61,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    45,    46,    47,
      14,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    94,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    76,    66,    67,    69,    88,    68,    10,     1,    26,
      73,    93,    10,    24,    27,     9,    13,    60,    24,    97,
       9,    15,    21,    25,    28,    16,     2,     3,    59,   103,
      87,    11,    89,    68,     1,    61,    19,    22,    71,    96,
      31,    68,    72,    68,    68,    68,    68,   113,    62,    82,
     101,    83,     2,     3,    32,   109,    33,   111,    34,    17,
      18,    35,     1,    36,    23,    24,    37,   116,   117,    68,
     110,    29,    38,    39,    30,    40,    41,    42,    43,    63,
       2,     3,    80,    32,    44,    33,    64,    34,    77,    78,
      35,     1,    36,    65,    24,    75,    77,    78,    79,    70,
      74,    38,    39,    84,    40,    41,    42,    43,    81,     2,
       3,    85,    32,    44,    33,    86,    34,    90,    91,    35,
       1,    36,    92,    24,    16,   102,   104,   105,   106,   107,
      38,    39,    36,    40,    41,    42,    43,    82,     2,     3,
     108,    38,    44,    36,    40,    41,    42,    43,   112,   114,
     115,    12,    38,    44,    98,     0,    41,    42,    43,   100,
       0,    99,     0,     0,    44
};

static const yytype_int8 yycheck[] =
{
      38,    48,    35,    36,    38,    64,    44,     0,    11,    19,
      44,    71,     5,    14,    13,     0,    25,    27,    14,    79,
       5,    12,    15,    24,    23,    16,    29,    30,    24,    88,
      63,     0,    65,    71,    11,    28,    13,    26,    12,    72,
      16,    79,    16,    81,    82,    83,    84,   107,    26,    33,
      84,    35,    29,    30,     3,   102,     5,   104,     7,    23,
      24,    10,    11,    12,    25,    14,    15,   114,   115,   107,
     103,    25,    21,    22,    17,    24,    25,    26,    27,    12,
      29,    30,    24,     3,    33,     5,    12,     7,    18,    19,
      10,    11,    12,    12,    14,    15,    18,    19,    20,    12,
      25,    21,    22,    34,    24,    25,    26,    27,    36,    29,
      30,    25,     3,    33,     5,    17,     7,    24,    13,    10,
      11,    12,    25,    14,    16,    13,    13,    13,    13,    23,
      21,    22,    12,    24,    25,    26,    27,    33,    29,    30,
      17,    21,    33,    12,    24,    25,    26,    27,    24,     4,
      13,     5,    21,    33,    81,    -1,    25,    26,    27,    83,
      -1,    82,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    29,    30,    39,    40,    41,    42,    43,    46,
      47,     0,    41,    25,    48,    12,    16,    23,    24,    13,
      44,    47,    26,    25,    14,    24,    45,    13,    23,    25,
      17,    16,     3,     5,     7,    10,    12,    15,    21,    22,
      24,    25,    26,    27,    33,    45,    46,    47,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    24,
      45,    47,    26,    12,    12,    12,    53,    53,    52,    58,
      12,    12,    16,    58,    25,    15,    50,    18,    19,    20,
      24,    36,    33,    35,    34,    25,    17,    53,    51,    53,
      24,    13,    25,    54,    60,    61,    53,    54,    55,    57,
      56,    58,    13,    51,    13,    13,    13,    23,    17,    50,
      53,    50,    24,    54,     4,    13,    50,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    43,    44,    44,    44,    44,    45,    45,    46,    47,
      47,    47,    48,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     1,
       1,     7,     5,     7,     5,     5,     3,     1,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  switch (yyn)
    {
  case 2: /* start: program  */
#line 69 "1805060.y"
        {
		//write your code in this block in all the similar blocks below
		add_log(line_count, "start : program");
		s_table.print_all(log_file);
	}
#line 1377 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 77 "1805060.y"
                {
			add_log(line_count, "program : program unit");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i = 0; i< (yyvsp[-1].siList)->size(); i++)
			{
				log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));

				if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
					{log_file << " ";}
				if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
					{log_file << endl;}
			}

			for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
			{
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
				if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
			}

			log_file<<endl<<endl;
		}
#line 1410 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 107 "1805060.y"
                {
			add_log(line_count, "program : unit");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
			{
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
				if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
			}
			log_file<<endl<<endl;
		}
#line 1431 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 126 "1805060.y"
                {
			add_log(line_count, "unit : var_declaration");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
			{
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" )
				{log_file << " ";}
			}
			log_file<<endl<<endl;
		}
#line 1449 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 141 "1805060.y"
                {
			add_log(line_count, "unit : func_declaration");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
			{
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" )
				{log_file << " ";}
			}
			log_file<<endl<<endl;
		}
#line 1467 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 156 "1805060.y"
                {
			add_log(line_count, "unit : func_definition");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
			{
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
				{log_file << " ";}
				if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
				{log_file << endl;}
			}
			log_file<<endl<<endl;
		}
#line 1488 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 175 "1805060.y"
                        {
				add_log(line_count, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");

				(yyval.siList) = new vector<SymbolInfo*>();
				string fName = (yyvsp[-4].s_info)->getName().c_str();
				if(s_table.look_up(fName)!=NULL)
				{
					add_error(line_count, "Multiple declaration of",fName);
					num_of_error++;
				}

				log_file << (yyvsp[-5].s_info)->getName().c_str() << " " << (yyvsp[-4].s_info)->getName().c_str() << (yyvsp[-3].s_info)->getName().c_str();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					log_file<<(yyvsp[-2].siList)->at(i)->getName();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float")
					{log_file << " ";}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str()<< (yyvsp[0].s_info)->getName().c_str() << "\n\n";

				(yyval.siList)->push_back((yyvsp[-5].s_info));
				(yyval.siList)->push_back((yyvsp[-4].s_info));
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
				}
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));

				vector<string>* par_list = new vector<string>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					par_list->push_back((yyvsp[-2].siList)->at(i)->getName());
				}
				s_table.insert((yyvsp[-4].s_info)->getName().c_str(), (yyvsp[-4].s_info)->getType().c_str(), par_list);
			}
#line 1530 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 214 "1805060.y"
                        {
				add_log(line_count, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");

				(yyval.siList) = new vector<SymbolInfo*>();
				string fName = (yyvsp[-3].s_info)->getName().c_str();
				if(s_table.look_up(fName)!=NULL)
				{
					add_error(line_count, "Multiple declaration of", fName);
					num_of_error++;
				}

				log_file << (yyvsp[-4].s_info)->getName().c_str() << " " << (yyvsp[-3].s_info)->getName().c_str() << (yyvsp[-2].s_info)->getName().c_str()<<(yyvsp[-1].s_info)->getName().c_str()<< (yyvsp[0].s_info)->getName().c_str() << "\n\n";

				(yyval.siList)->push_back((yyvsp[-4].s_info));
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));

				s_table.insert((yyvsp[-3].s_info)->getName().c_str(), (yyvsp[-3].s_info)->getType().c_str());
			}
#line 1556 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 238 "1805060.y"
                                {
					add_log(line_count, "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");

					(yyval.siList) = new vector<SymbolInfo*>();
					string fName = (yyvsp[-4].s_info)->getName().c_str();
					if(s_table.look_up(fName)!=NULL)
					{
						add_error(line_count, "Multiple declaration of", fName);
						num_of_error++;
					}

					log_file<<(yyvsp[-5].s_info)->getName().c_str()<<" "<<(yyvsp[-4].s_info)->getName().c_str()<<(yyvsp[-3].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-5].s_info));
					(yyval.siList)->push_back((yyvsp[-4].s_info));
					(yyval.siList)->push_back((yyvsp[-3].s_info));
					for(int i = 0; i< (yyvsp[-2].siList)->size(); i++)
					{
						log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
						(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
						if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float")
						{log_file << " ";}
					}
					log_file<<(yyvsp[-1].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-1].s_info));
					for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
					{
						log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
						(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

						if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
						{log_file << " ";}
						if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<endl<<endl;

					vector<string>* par_list = new vector<string>();
					for(int i=0; i<(yyvsp[-2].siList)->size();i++)
					{
						par_list->push_back((yyvsp[-2].siList)->at(i)->getName());
					}
					s_table.insert((yyvsp[-4].s_info)->getName().c_str(), (yyvsp[-4].s_info)->getType().c_str(), par_list);
				}
#line 1604 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN RPAREN compound_statement  */
#line 283 "1805060.y"
                                {
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN compound_statement");

					(yyval.siList) = new vector<SymbolInfo*>();

					string fName = (yyvsp[-3].s_info)->getName().c_str();
					if(s_table.look_up(fName)!=NULL)
					{
						add_error(line_count, "Multiple declaration of", fName);
						num_of_error++;
					}

					log_file<<(yyvsp[-4].s_info)->getName().c_str()<<" "<<(yyvsp[-3].s_info)->getName().c_str()<<(yyvsp[-2].s_info)->getName().c_str()<<(yyvsp[-1].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-4].s_info));
					(yyval.siList)->push_back((yyvsp[-3].s_info));
					(yyval.siList)->push_back((yyvsp[-2].s_info));
					(yyval.siList)->push_back((yyvsp[-1].s_info));
					for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
					{
						log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
						(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

						if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
						{log_file << " ";}
						if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<endl<<endl;

					s_table.insert((yyvsp[-3].s_info)->getName().c_str(), (yyvsp[-3].s_info)->getType().c_str());
				}
#line 1640 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 318 "1805060.y"
                        {
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier ID");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-3].siList)->size();i++)
				{
					log_file<<(yyvsp[-3].siList)->at(i)->getName();
					if((yyvsp[-3].siList)->at(i)->getName() == "int" || (yyvsp[-3].siList)->at(i)->getName() == "float")
					{log_file << " ";}
					(yyval.siList)->push_back((yyvsp[-3].siList)->at(i));
				}
				log_file<<(yyvsp[-2].s_info)->getName().c_str()<<(yyvsp[-1].s_info)->getName().c_str()<<" "<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1661 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier  */
#line 336 "1805060.y"
                        {
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					log_file<<(yyvsp[-2].siList)->at(i)->getName();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float")
					{log_file << " ";}
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str()<<" "<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1681 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier ID  */
#line 353 "1805060.y"
                        {
				add_log(line_count, "parameter_list : type_specifier ID");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-1].s_info)->getName().c_str()<<" "<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1694 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier  */
#line 363 "1805060.y"
                        {
				add_log(line_count, "parameter_list : type_specifier");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1706 "y.tab.c"
    break;

  case 16: /* compound_statement: LCURL statements RCURL  */
#line 374 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL statements RCURL");

					(yyval.siList) = new vector<SymbolInfo*>();
					log_file<<(yyvsp[-2].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-2].s_info));
					s_table.enter_scope();

					for(int i = 0; i< (yyvsp[-1].siList)->size(); i++)
					{
						log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
						(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));

						if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
						{log_file << " ";}
						if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
					(yyval.siList)->push_back((yyvsp[0].s_info));

					s_table.print_all(log_file);
					s_table.exit_scope();
				}
#line 1735 "y.tab.c"
    break;

  case 17: /* compound_statement: LCURL RCURL  */
#line 400 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL RCURL");

					(yyval.siList) = new vector<SymbolInfo*>();
					log_file<<(yyvsp[-1].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-1].s_info));
					log_file<<(yyvsp[0].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].s_info));
					log_file<<endl<<endl;
				}
#line 1750 "y.tab.c"
    break;

  case 18: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 413 "1805060.y"
                        {
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");

				string tpsp = (yyvsp[-2].s_info)->getName().c_str();
				if(tpsp== "void")
				{
					add_error(line_count, "Variable type cannot be void", "");
					num_of_error++;
				}

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-2].s_info)->getName().c_str()<<" ";
				(yyval.siList)->push_back((yyvsp[-2].s_info));
		  	    for(int i = 0; i < (yyvsp[-1].siList)->size(); i++){
		  			log_file << (yyvsp[-1].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
		  		}
				log_file<<(yyvsp[0].s_info)->getName().c_str()<<"\n\n";
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1775 "y.tab.c"
    break;

  case 19: /* type_specifier: INT  */
#line 436 "1805060.y"
                {
			add_log(line_count, "type_specifier : INT");
			log_file<<"int\n\n";
		}
#line 1784 "y.tab.c"
    break;

  case 20: /* type_specifier: FLOAT  */
#line 442 "1805060.y"
                {
			add_log(line_count, "type_specifier : FLOAT");
			log_file<<"float\n\n";
		}
#line 1793 "y.tab.c"
    break;

  case 21: /* type_specifier: VOID  */
#line 448 "1805060.y"
                {
			add_log(line_count, "type_specifier : VOID");
			log_file<<"void\n\n";
		}
#line 1802 "y.tab.c"
    break;

  case 22: /* declaration_list: declaration_list COMMA ID  */
#line 456 "1805060.y"
                        {
				add_log(line_count, "declaration_list : declaration_list COMMA ID");

				(yyval.siList) = new vector<SymbolInfo*>();

				bool is_inserted = s_table.insert((yyvsp[0].s_info)->getName().c_str(), (yyvsp[0].s_info)->getType().c_str());
				if(!is_inserted)
				{
					add_error(line_count, "Multiple declaration of", (yyvsp[0].s_info)->getName().c_str());
					num_of_error++;
				}

				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
				}

				log_file<<(yyvsp[-1].s_info)->getName().c_str()<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1829 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 480 "1805060.y"
                        {
				add_log(line_count, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");

				(yyval.siList) = new vector<SymbolInfo*>();

				bool is_inserted = s_table.insert((yyvsp[-3].s_info)->getName().c_str(), (yyvsp[-3].s_info)->getType().c_str());
				if(!is_inserted)
				{
					add_error(line_count, "Multiple declaration of", (yyvsp[-3].s_info)->getName().c_str());
					num_of_error++;
				}

				for(int i=0; i<(yyvsp[-5].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-5].siList)->at(i));
					log_file<<(yyvsp[-5].siList)->at(i)->getName().c_str();
				}

				log_file<<(yyvsp[-4].s_info)->getName().c_str()<<(yyvsp[-3].s_info)->getName().c_str()<<(yyvsp[-2].s_info)->getName().c_str()<<(yyvsp[-1].s_info)->getName().c_str()<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[-4].s_info));
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 1859 "y.tab.c"
    break;

  case 24: /* declaration_list: ID  */
#line 507 "1805060.y"
                  {
			add_log(line_count, "declaration_list : ID");
			log_file<<(yyvsp[0].s_info)->getName().c_str()<<"\n\n";

			bool is_inserted = s_table.insert((yyvsp[0].s_info)->getName().c_str(), (yyvsp[0].s_info)->getType().c_str());
			if(!is_inserted)
			{
				add_error(line_count, "Multiple declaration of", (yyvsp[0].s_info)->getName().c_str());
				num_of_error++;
			}

			(yyval.siList) = new vector<SymbolInfo*>();
			(yyval.siList)->push_back((yyvsp[0].s_info));
		  }
#line 1878 "y.tab.c"
    break;

  case 25: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 523 "1805060.y"
                                {
					add_log(line_count, "declaration_list : ID LTHIRD CONST_INT RTHIRD");

					(yyval.siList) = new vector<SymbolInfo*>();

					bool is_inserted = s_table.insert((yyvsp[-3].s_info)->getName().c_str(), (yyvsp[-3].s_info)->getType().c_str());
				if(!is_inserted)
				{
					add_error(line_count, "Multiple declaration of", (yyvsp[-3].s_info)->getName().c_str());
					num_of_error++;
				}
				
					log_file<<(yyvsp[-3].s_info)->getName().c_str()<<(yyvsp[-2].s_info)->getName().c_str()<<(yyvsp[-1].s_info)->getName().c_str()<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
					(yyval.siList)->push_back((yyvsp[-3].s_info));
					(yyval.siList)->push_back((yyvsp[-2].s_info));
					(yyval.siList)->push_back((yyvsp[-1].s_info));
					(yyval.siList)->push_back((yyvsp[0].s_info));
				}
#line 1901 "y.tab.c"
    break;

  case 26: /* statements: statement  */
#line 544 "1805060.y"
                        {
				add_log(line_count, "statements : statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 1921 "y.tab.c"
    break;

  case 27: /* statements: statements statement  */
#line 561 "1805060.y"
                        {
				add_log(line_count, "statements : statements statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-1].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
					log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
					if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 1951 "y.tab.c"
    break;

  case 28: /* statement: var_declaration  */
#line 589 "1805060.y"
                        {
				add_log(line_count, "statement : var_declaration");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 1972 "y.tab.c"
    break;

  case 29: /* statement: expression_statement  */
#line 607 "1805060.y"
                        {
				add_log(line_count, "statement : expression_statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 1993 "y.tab.c"
    break;

  case 30: /* statement: compound_statement  */
#line 625 "1805060.y"
                        {
				add_log(line_count, "statement : compound_statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2014 "y.tab.c"
    break;

  case 31: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 643 "1805060.y"
                        {
				add_log(line_count, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-6].s_info)->getName().c_str()<<(yyvsp[-5].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-6].s_info));
				(yyval.siList)->push_back((yyvsp[-5].s_info));
				for(int i = 0; i< (yyvsp[-4].siList)->size(); i++)
				{
					log_file<<(yyvsp[-4].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-4].siList)->at(i));

					if((yyvsp[-4].siList)->at(i)->getName() == "int" || (yyvsp[-4].siList)->at(i)->getName() == "float" || (yyvsp[-4].siList)->at(i)->getName() == "void" || (yyvsp[-4].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-4].siList)->at(i)->getName() == ";" || (yyvsp[-4].siList)->at(i)->getName() == "{" || (yyvsp[-4].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				for(int i = 0; i< (yyvsp[-3].siList)->size(); i++)
				{
					log_file<<(yyvsp[-3].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-4].siList)->at(i));

					if((yyvsp[-3].siList)->at(i)->getName() == "int" || (yyvsp[-3].siList)->at(i)->getName() == "float" || (yyvsp[-3].siList)->at(i)->getName() == "void" || (yyvsp[-3].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-3].siList)->at(i)->getName() == ";" || (yyvsp[-3].siList)->at(i)->getName() == "{" || (yyvsp[-3].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				for(int i = 0; i< (yyvsp[-2].siList)->size(); i++)
				{
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));

					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));

				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<endl<<endl;
			}
#line 2073 "y.tab.c"
    break;

  case 32: /* statement: IF LPAREN expression RPAREN statement  */
#line 699 "1805060.y"
                        {
				add_log(line_count, "statement : IF LPAREN expression RPAREN statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-4].s_info)->getName().c_str()<<(yyvsp[-3].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-4].s_info));
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				for(int i = 0; i< (yyvsp[-2].siList)->size(); i++)
				{
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));

					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));

				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<endl<<endl;
			}
#line 2111 "y.tab.c"
    break;

  case 33: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 734 "1805060.y"
                        {
				add_log(line_count, "statement : IF LPAREN expression RPAREN statement ELSE statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-6].s_info)->getName().c_str()<<(yyvsp[-5].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-6].s_info));
				(yyval.siList)->push_back((yyvsp[-5].s_info));
				for(int i = 0; i< (yyvsp[-4].siList)->size(); i++)
				{
					log_file<<(yyvsp[-4].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-4].siList)->at(i));

					if((yyvsp[-4].siList)->at(i)->getName() == "int" || (yyvsp[-4].siList)->at(i)->getName() == "float" || (yyvsp[-4].siList)->at(i)->getName() == "void" || (yyvsp[-4].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-4].siList)->at(i)->getName() == ";" || (yyvsp[-4].siList)->at(i)->getName() == "{" || (yyvsp[-4].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-3].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-3].s_info));

				for(int i = 0; i< (yyvsp[-2].siList)->size(); i++)
				{
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));

					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));

				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<endl<<endl;
			}
#line 2163 "y.tab.c"
    break;

  case 34: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 783 "1805060.y"
                        {
				add_log(line_count, "statement : WHILE LPAREN expression RPAREN statement");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-4].s_info)->getName().c_str()<<(yyvsp[-3].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-4].s_info));
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				for(int i = 0; i< (yyvsp[-2].siList)->size(); i++)
				{
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));

					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));

				for(int i = 0; i< (yyvsp[0].siList)->size(); i++)
				{
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));

					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<endl<<endl;
			}
#line 2201 "y.tab.c"
    break;

  case 35: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 818 "1805060.y"
                        {
				add_log(line_count, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-4].s_info)->getName().c_str()<<(yyvsp[-3].s_info)->getName().c_str()<<(yyvsp[-2].s_info)->getName().c_str()<<(yyvsp[-1].s_info)->getName().c_str()<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[-4].s_info));
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 2217 "y.tab.c"
    break;

  case 36: /* statement: RETURN expression SEMICOLON  */
#line 831 "1805060.y"
                        {
				add_log(line_count, "statement : RETURN expression SEMICOLON");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-2].s_info)->getName().c_str()<<" ";
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				for(int i=0; i<(yyvsp[-1].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
					log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
					if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
				(yyval.siList)->push_back((yyvsp[0].s_info));
			}
#line 2240 "y.tab.c"
    break;

  case 37: /* expression_statement: SEMICOLON  */
#line 852 "1805060.y"
                                {
					add_log(line_count, "expression_statement : SEMICOLON");

					(yyval.siList) = new vector<SymbolInfo*>();
					log_file<<(yyvsp[0].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].s_info));
				}
#line 2252 "y.tab.c"
    break;

  case 38: /* expression_statement: expression SEMICOLON  */
#line 861 "1805060.y"
                                {
					add_log(line_count, "expression_statement : expression SEMICOLON");

					(yyval.siList) = new vector<SymbolInfo*>();
					for(int i=0; i<(yyvsp[-1].siList)->size();i++)
					{
						(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
						log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
						if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
						{log_file << " ";}
						if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<(yyvsp[0].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].s_info));
					log_file<<endl<<endl;
				}
#line 2274 "y.tab.c"
    break;

  case 39: /* variable: ID  */
#line 881 "1805060.y"
                {
			add_log(line_count, "variable : ID");

			(yyval.siList) = new vector<SymbolInfo*>();
			log_file<<(yyvsp[0].s_info)->getName().c_str()<<endl<<endl;
			(yyval.siList)->push_back((yyvsp[0].s_info));
		}
#line 2286 "y.tab.c"
    break;

  case 40: /* variable: ID LTHIRD expression RTHIRD  */
#line 890 "1805060.y"
                {
			add_log(line_count, "variable : ID LTHIRD expression RTHIRD");

			(yyval.siList) = new vector<SymbolInfo*>();
			log_file<<(yyvsp[-3].s_info)->getName().c_str()<<(yyvsp[-2].s_info)->getName().c_str();
			(yyval.siList)->push_back((yyvsp[-3].s_info));
			(yyval.siList)->push_back((yyvsp[-2].s_info));

			for(int i=0; i<(yyvsp[-1].siList)->size();i++)
					{
						(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
						log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
						if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
						{log_file << " ";}
						if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<(yyvsp[0].s_info)->getName().c_str();
					(yyval.siList)->push_back((yyvsp[0].s_info));
					log_file<<endl<<endl;
		}
#line 2312 "y.tab.c"
    break;

  case 41: /* expression: logic_expression  */
#line 914 "1805060.y"
                        {
				add_log(line_count, "expression : logic_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2332 "y.tab.c"
    break;

  case 42: /* expression: variable ASSIGNOP logic_expression  */
#line 931 "1805060.y"
                        {
				add_log(line_count, "expression : variable ASSIGNOP logic_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}

				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2364 "y.tab.c"
    break;

  case 43: /* logic_expression: rel_expression  */
#line 961 "1805060.y"
                        {
				add_log(line_count, "logic_expression : rel_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2384 "y.tab.c"
    break;

  case 44: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 978 "1805060.y"
                        {
				add_log(line_count, "logic_expression : rel_expression LOGICOP rel_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2415 "y.tab.c"
    break;

  case 45: /* rel_expression: simple_expression  */
#line 1007 "1805060.y"
                        {
				add_log(line_count, "rel_expression	: simple_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2435 "y.tab.c"
    break;

  case 46: /* rel_expression: simple_expression RELOP simple_expression  */
#line 1024 "1805060.y"
                        {
				add_log(line_count, "rel_expression : simple_expression RELOP simple_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2466 "y.tab.c"
    break;

  case 47: /* simple_expression: term  */
#line 1053 "1805060.y"
                        {
				add_log(line_count, "simple_expression : term");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				}
				log_file<<endl<<endl;
			}
#line 2482 "y.tab.c"
    break;

  case 48: /* simple_expression: simple_expression ADDOP term  */
#line 1066 "1805060.y"
                        {
				add_log(line_count, "simple_expression : simple_expression ADDOP term");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				}
				log_file<<endl<<endl;
			}
#line 2509 "y.tab.c"
    break;

  case 49: /* term: unary_expression  */
#line 1091 "1805060.y"
                {
			add_log(line_count, "term : unary_expression");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[0].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
			}
			log_file<<endl<<endl;
		}
#line 2525 "y.tab.c"
    break;

  case 50: /* term: term MULOP unary_expression  */
#line 1104 "1805060.y"
                {
				add_log(line_count, "term : term MULOP unary_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[-2].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
					log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
					if((yyvsp[-2].siList)->at(i)->getName() == "int" || (yyvsp[-2].siList)->at(i)->getName() == "float" || (yyvsp[-2].siList)->at(i)->getName() == "void" || (yyvsp[-2].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-2].siList)->at(i)->getName() == ";" || (yyvsp[-2].siList)->at(i)->getName() == "{" || (yyvsp[-2].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2556 "y.tab.c"
    break;

  case 51: /* unary_expression: ADDOP unary_expression  */
#line 1133 "1805060.y"
                        {
				add_log(line_count, "unary_expression : ADDOP unary_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2578 "y.tab.c"
    break;

  case 52: /* unary_expression: NOT unary_expression  */
#line 1152 "1805060.y"
                        {
				add_log(line_count, "unary_expression : NOT unary_expression");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-1].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-1].s_info));
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
					if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
#line 2600 "y.tab.c"
    break;

  case 53: /* unary_expression: factor  */
#line 1171 "1805060.y"
                        {
				add_log(line_count, "unary_expression	: factor");

				(yyval.siList) = new vector<SymbolInfo*>();
				for(int i=0; i<(yyvsp[0].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
					log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				}
				log_file<<endl<<endl;
			}
#line 2616 "y.tab.c"
    break;

  case 54: /* factor: variable  */
#line 1185 "1805060.y"
                {
			add_log(line_count, "factor	: variable");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[0].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
			}
			log_file<<endl<<endl;
		}
#line 2632 "y.tab.c"
    break;

  case 55: /* factor: ID LPAREN argument_list RPAREN  */
#line 1198 "1805060.y"
                        {
				add_log(line_count, "factor : ID LPAREN argument_list RPAREN");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-3].s_info)->getName().c_str()<<(yyvsp[-2].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-3].s_info));
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				for(int i=0; i<(yyvsp[-1].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
					log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
					if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[0].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].s_info));
				log_file<<endl<<endl;
			}
#line 2657 "y.tab.c"
    break;

  case 56: /* factor: LPAREN expression RPAREN  */
#line 1220 "1805060.y"
                        {
				add_log(line_count, "factor : LPAREN expression RPAREN");

				(yyval.siList) = new vector<SymbolInfo*>();
				log_file<<(yyvsp[-2].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[-2].s_info));
				for(int i=0; i<(yyvsp[-1].siList)->size();i++)
				{
					(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
					log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
					if((yyvsp[-1].siList)->at(i)->getName() == "int" || (yyvsp[-1].siList)->at(i)->getName() == "float" || (yyvsp[-1].siList)->at(i)->getName() == "void" || (yyvsp[-1].siList)->at(i)->getName() == "return")
					{log_file << " ";}
					if((yyvsp[-1].siList)->at(i)->getName() == ";" || (yyvsp[-1].siList)->at(i)->getName() == "{" || (yyvsp[-1].siList)->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<(yyvsp[0].s_info)->getName().c_str();
				(yyval.siList)->push_back((yyvsp[0].s_info));
				log_file<<endl<<endl;
			}
#line 2681 "y.tab.c"
    break;

  case 57: /* factor: CONST_INT  */
#line 1241 "1805060.y"
                {
			add_log(line_count, "factor	: CONST_INT");

			(yyval.siList) = new vector<SymbolInfo*>();
			log_file<<(yyvsp[0].s_info)->getName().c_str();
			(yyval.siList)->push_back((yyvsp[0].s_info));
			log_file<<endl<<endl;
		}
#line 2694 "y.tab.c"
    break;

  case 58: /* factor: CONST_FLOAT  */
#line 1251 "1805060.y"
                {
			add_log(line_count, "factor	: CONST_FLOAT");

			(yyval.siList) = new vector<SymbolInfo*>();
			log_file<<(yyvsp[0].s_info)->getName().c_str();
			(yyval.siList)->push_back((yyvsp[0].s_info));
			log_file<<endl<<endl;
		}
#line 2707 "y.tab.c"
    break;

  case 59: /* factor: variable INCOP  */
#line 1261 "1805060.y"
                {
			add_log(line_count, "factor	: variable INCOP");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[-1].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
				log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
			}

			log_file<<(yyvsp[0].s_info)->getName().c_str();
			(yyval.siList)->push_back((yyvsp[0].s_info));
			log_file<<endl<<endl;
		}
#line 2726 "y.tab.c"
    break;

  case 60: /* factor: variable DECOP  */
#line 1277 "1805060.y"
                {
			add_log(line_count, "factor	: variable DECOP");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[-1].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[-1].siList)->at(i));
				log_file<<(yyvsp[-1].siList)->at(i)->getName().c_str();
			}

			log_file<<(yyvsp[0].s_info)->getName().c_str();
			(yyval.siList)->push_back((yyvsp[0].s_info));
			log_file<<endl<<endl;
		}
#line 2745 "y.tab.c"
    break;

  case 61: /* argument_list: arguments  */
#line 1294 "1805060.y"
                {
			add_log(line_count, "argument_list : arguments");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[0].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
			}
			log_file<<endl<<endl;
		}
#line 2761 "y.tab.c"
    break;

  case 62: /* arguments: arguments COMMA logic_expression  */
#line 1308 "1805060.y"
                {
			add_log(line_count, "argument_list : arguments COMMA logic_expression");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[-2].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[-2].siList)->at(i));
				log_file<<(yyvsp[-2].siList)->at(i)->getName().c_str();
			}
			log_file<<(yyvsp[-1].s_info)->getName().c_str();
			(yyval.siList)->push_back((yyvsp[-1].s_info));
			for(int i=0; i<(yyvsp[0].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
				{log_file << " ";}
				if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
				{log_file << endl;}
			}
			log_file<<endl<<endl;
		}
#line 2788 "y.tab.c"
    break;

  case 63: /* arguments: logic_expression  */
#line 1332 "1805060.y"
                {
			add_log(line_count, "argument_list : logic_expression");

			(yyval.siList) = new vector<SymbolInfo*>();
			for(int i=0; i<(yyvsp[0].siList)->size();i++)
			{
				(yyval.siList)->push_back((yyvsp[0].siList)->at(i));
				log_file<<(yyvsp[0].siList)->at(i)->getName().c_str();
				if((yyvsp[0].siList)->at(i)->getName() == "int" || (yyvsp[0].siList)->at(i)->getName() == "float" || (yyvsp[0].siList)->at(i)->getName() == "void" || (yyvsp[0].siList)->at(i)->getName() == "return")
				{log_file << " ";}
				if((yyvsp[0].siList)->at(i)->getName() == ";" || (yyvsp[0].siList)->at(i)->getName() == "{" || (yyvsp[0].siList)->at(i)->getName() == "}")
				{log_file << endl;}
			}
			log_file<<endl<<endl;
		}
#line 2808 "y.tab.c"
    break;


#line 2812 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1350 "1805060.y"

int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	log_file.open("log_file.txt");
	error_file.open("error_file.txt");

	yyin= fin;
	yyparse();

	log_file<<"Total lines: "<<line_count<<"\nTotal errors: "<<num_of_error<<"\n";
	fclose(yyin);
	log_file.close();
	error_file.close();
	return 0;
}

