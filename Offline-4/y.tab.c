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
ofstream code_file;

int line_count = 1;
int num_of_error = 0;

string code = "";
string data_segment = "";

int yyparse(void);
int yylex(void);

void add_log(int lc, string rule)
{
	log_file<<"Line "<<lc<<": "<<rule<<endl<<endl;
}

void add_error(int lc, string msg, string name)
{
	cout<<"Error at line "<<lc-1<<": "<<msg<<" "<<name<<endl<<endl;
	error_file<<"Error at line "<<lc-1<<": "<<msg<<" "<<name<<endl<<endl;
	log_file<<"Error at line "<<lc-1<<": "<<msg<<" "<<name<<endl<<endl;
	num_of_error++;
}

void yyerror(char *s)
{
	//write your code
	add_error(line_count, s, "");
}

int labelCount = 0;
int tempCount = 0;


string newLabel()
{
	string lb = "";
	labelCount++;
	lb+="L"+to_string(labelCount);
	return lb;
}

string newTemp()
{
	string t= "";
	tempCount++;
	t+="t"+to_string(tempCount);
	return t;
}


#line 137 "y.tab.c"

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
#line 67 "1805060.y"

	SymbolInfo *s_info;
	vector<SymbolInfo*>* siList;

#line 269 "y.tab.c"

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
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_parameter_list = 45,            /* parameter_list  */
  YYSYMBOL_compound_statement = 46,        /* compound_statement  */
  YYSYMBOL_var_declaration = 47,           /* var_declaration  */
  YYSYMBOL_type_specifier = 48,            /* type_specifier  */
  YYSYMBOL_declaration_list = 49,          /* declaration_list  */
  YYSYMBOL_statements = 50,                /* statements  */
  YYSYMBOL_if_statement = 51,              /* if_statement  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_expression_statement = 53,      /* expression_statement  */
  YYSYMBOL_variable = 54,                  /* variable  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_logic_expression = 56,          /* logic_expression  */
  YYSYMBOL_rel_expression = 57,            /* rel_expression  */
  YYSYMBOL_simple_expression = 58,         /* simple_expression  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_unary_expression = 60,          /* unary_expression  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_argument_list = 62,             /* argument_list  */
  YYSYMBOL_arguments = 63                  /* arguments  */
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
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

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
       0,    91,    91,   100,   106,   113,   119,   125,   132,   141,
     151,   160,   159,   185,   191,   197,   203,   211,   217,   224,
     232,   237,   242,   249,   261,   267,   279,   286,   292,   299,
     305,   311,   317,   323,   329,   335,   341,   347,   355,   362,
     367,   374,   386,   393,   399,   410,   416,   423,   429,   436,
     442,   449,   455,   462,   468,   474,   481,   487,   493,   499,
     506,   511,   517,   524,   531,   537
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
  "program", "unit", "func_declaration", "func_definition", "$@1",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "if_statement",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -72,   -72,   -72,    17,    19,   -72,   -72,   -72,   -72,
       3,   -72,   -72,     7,    30,    -3,    11,    31,   -72,    18,
      -1,    36,    48,    59,   -72,    66,     1,    19,   -72,   -72,
      57,    52,   -72,   -72,   -72,    62,    77,    85,    86,    87,
     132,   132,   -72,   132,    88,   -72,    23,   -72,   -72,   132,
     -72,   -72,    76,    81,   100,   -72,   -72,    32,    92,   -72,
      73,   -15,    78,   -72,   -72,   -72,   -72,   132,   121,   132,
      94,   106,    53,   -72,    98,   132,   132,   -72,   109,   -72,
     -72,   110,   -72,   -72,   132,   -72,   132,   132,   132,   132,
     113,   121,   114,   -72,   -72,   115,   -72,   116,   107,   124,
     -72,   -72,   -72,    78,   105,   -72,   110,   132,   110,   125,
     -72,   132,   -72,   -72,   137,   -72,   -72,   -72,   110,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    22,    20,    21,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    25,     0,     0,     0,     0,    19,    11,
       0,    16,     0,    23,     9,     0,     0,     0,    15,    26,
       0,     0,    12,     8,    10,    14,     0,     0,     0,     0,
       0,     0,    18,     0,     0,    39,    41,    59,    60,     0,
      32,    30,     0,     0,    34,    27,    31,    56,     0,    43,
      45,    47,    49,    51,    55,    13,    24,     0,     0,     0,
       0,     0,    56,    54,     0,     0,     0,    53,    25,    17,
      28,     0,    61,    62,     0,    40,     0,     0,     0,     0,
       0,     0,     0,    38,    58,     0,    65,     0,    63,     0,
      35,    44,    46,    50,    48,    52,     0,     0,     0,     0,
      57,     0,    42,    29,     0,    36,    37,    64,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   146,   -72,   -72,   -72,   -72,    64,    16,
       9,   -72,   -72,   -72,   -48,   -57,   -43,   -38,   -71,    69,
      68,    65,   -42,   -72,   -72,   -72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    25,    20,    50,    51,
      52,    14,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    73,    70,    71,    96,    80,    72,    77,     1,    10,
      19,    91,    26,   101,    10,    31,     9,    11,    87,    15,
      88,     9,    27,    16,    21,    33,     2,     3,    13,    90,
       1,    92,    72,   100,   107,    75,    35,    22,    99,    76,
     117,    72,    24,    72,    72,    72,    72,   105,     2,     3,
      82,    83,    84,    17,    18,    37,    23,    38,   113,    39,
     115,    28,    40,     1,    41,    29,    31,    42,    72,   114,
     119,    82,    83,    43,    44,    30,    45,    46,    47,    48,
      31,     2,     3,    36,    37,    49,    38,    65,    39,    32,
      34,    40,     1,    41,    66,    31,    79,    67,    68,    69,
      74,    78,    43,    44,    81,    45,    46,    47,    48,    86,
       2,     3,    89,    37,    49,    38,    85,    39,    93,    94,
      40,     1,    41,    95,    31,    16,   106,   108,   109,   110,
     111,    43,    44,    41,    45,    46,    47,    48,    87,     2,
       3,   112,    43,    49,    41,    45,    46,    47,    48,   116,
     118,    12,   103,    43,    49,   102,   104,    46,    47,    48,
       0,     0,     0,     0,     0,    49
};

static const yytype_int8 yycheck[] =
{
      43,    43,    40,    41,    75,    53,    49,    49,    11,     0,
      13,    68,    13,    84,     5,    14,     0,     0,    33,    12,
      35,     5,    23,    16,    15,    24,    29,    30,    25,    67,
      11,    69,    75,    81,    91,    12,    27,    26,    76,    16,
     111,    84,    24,    86,    87,    88,    89,    89,    29,    30,
      18,    19,    20,    23,    24,     3,    25,     5,   106,     7,
     108,    25,    10,    11,    12,    17,    14,    15,   111,   107,
     118,    18,    19,    21,    22,    16,    24,    25,    26,    27,
      14,    29,    30,    26,     3,    33,     5,    25,     7,    25,
      26,    10,    11,    12,    17,    14,    15,    12,    12,    12,
      12,    25,    21,    22,     4,    24,    25,    26,    27,    36,
      29,    30,    34,     3,    33,     5,    24,     7,    24,    13,
      10,    11,    12,    25,    14,    16,    13,    13,    13,    13,
      23,    21,    22,    12,    24,    25,    26,    27,    33,    29,
      30,    17,    21,    33,    12,    24,    25,    26,    27,    24,
      13,     5,    87,    21,    33,    86,    88,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    29,    30,    39,    40,    41,    42,    43,    47,
      48,     0,    41,    25,    49,    12,    16,    23,    24,    13,
      45,    48,    26,    25,    24,    44,    13,    23,    25,    17,
      16,    14,    46,    24,    46,    48,    26,     3,     5,     7,
      10,    12,    15,    21,    22,    24,    25,    26,    27,    33,
      46,    47,    48,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    25,    17,    12,    12,    12,
      55,    55,    54,    60,    12,    12,    16,    60,    25,    15,
      52,     4,    18,    19,    20,    24,    36,    33,    35,    34,
      55,    53,    55,    24,    13,    25,    56,    62,    63,    55,
      52,    56,    57,    59,    58,    60,    13,    53,    13,    13,
      13,    23,    17,    52,    55,    52,    24,    56,    13,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    44,    43,    45,    45,    45,    45,    46,    46,    47,
      48,    48,    48,    49,    49,    49,    49,    50,    50,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     0,     6,     4,     3,     2,     1,     3,     2,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     5,
       1,     1,     1,     7,     1,     3,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     3,     1
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
#line 92 "1805060.y"
        {
		//write your code in this block in all the similar blocks below
		add_log(line_count, "start : program");
		
		s_table.print_all(log_file);
	}
#line 1403 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 101 "1805060.y"
                {
			add_log(line_count, "program : program unit");
			
		}
#line 1412 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 107 "1805060.y"
                {
			add_log(line_count, "program : unit");
			
		}
#line 1421 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 114 "1805060.y"
                {
			add_log(line_count, "unit : var_declaration");
			
		}
#line 1430 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 120 "1805060.y"
                {
			add_log(line_count, "unit : func_declaration");
			
		}
#line 1439 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 126 "1805060.y"
                {
			add_log(line_count, "unit : func_definition");
			
		}
#line 1448 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 133 "1805060.y"
                        {
				add_log(line_count, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
				

				(yyvsp[-4].s_info)->setSize(-1);
				s_table.insert((yyvsp[-4].s_info));
			}
#line 1460 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 142 "1805060.y"
                        {
				add_log(line_count, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
				

				(yyvsp[-3].s_info)->setSize(-1);
				s_table.insert((yyvsp[-3].s_info));
			}
#line 1472 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 152 "1805060.y"
                                {
					add_log(line_count, "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");

					(yyvsp[-4].s_info)->setSize(-1);
					s_table.insert((yyvsp[-4].s_info));
				}
#line 1483 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 160 "1805060.y"
                                {
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN compound_statement");

					(yyvsp[-2].s_info)->setSize(-1);
					s_table.insert((yyvsp[-2].s_info));

					code+= "\n"+(yyvsp[-2].s_info)->getName()+" PROC";
					if((yyvsp[-2].s_info)->getName()=="main")
					{
						code+= "\nMOV AX,@DATA \nMOV DS,AX\n";
					}
					
				}
#line 1501 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN RPAREN $@1 compound_statement  */
#line 174 "1805060.y"
                                {
					if((yyvsp[-4].s_info)->getName()=="main")
					{
						code+= "\n\nMOV AH, 4CH \nINT 21H";
					}

					code+= "\n"+(yyvsp[-4].s_info)->getName()+" ENDP";
				}
#line 1514 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 186 "1805060.y"
                        {
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier ID");
				
			}
#line 1523 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier  */
#line 192 "1805060.y"
                        {
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");
				
			}
#line 1532 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier ID  */
#line 198 "1805060.y"
                        {
				add_log(line_count, "parameter_list : type_specifier ID");
				
			}
#line 1541 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier  */
#line 204 "1805060.y"
                        {
				add_log(line_count, "parameter_list : type_specifier");
				
			}
#line 1550 "y.tab.c"
    break;

  case 17: /* compound_statement: LCURL statements RCURL  */
#line 212 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL statements RCURL");
					
				}
#line 1559 "y.tab.c"
    break;

  case 18: /* compound_statement: LCURL RCURL  */
#line 218 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL RCURL");
					
				}
#line 1568 "y.tab.c"
    break;

  case 19: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 225 "1805060.y"
                        {
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");
				

			}
#line 1578 "y.tab.c"
    break;

  case 20: /* type_specifier: INT  */
#line 233 "1805060.y"
                {
			add_log(line_count, "type_specifier : INT");
		}
#line 1586 "y.tab.c"
    break;

  case 21: /* type_specifier: FLOAT  */
#line 238 "1805060.y"
                {
			add_log(line_count, "type_specifier : FLOAT");
		}
#line 1594 "y.tab.c"
    break;

  case 22: /* type_specifier: VOID  */
#line 243 "1805060.y"
                {
			add_log(line_count, "type_specifier : VOID");
		}
#line 1602 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID  */
#line 250 "1805060.y"
                        {
				add_log(line_count, "declaration_list : declaration_list COMMA ID");
				
				string tmp_name = newTemp();
				(yyvsp[0].s_info)->set_asm_var(tmp_name);
				s_table.insert((yyvsp[0].s_info));

				data_segment+= tmp_name+" DW ?\n";
				code+= "\nMOV "+tmp_name+", 0";
			}
#line 1617 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 262 "1805060.y"
                        {
				add_log(line_count, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
				
			}
#line 1626 "y.tab.c"
    break;

  case 25: /* declaration_list: ID  */
#line 268 "1805060.y"
                  {
			add_log(line_count, "declaration_list : ID");

			string tmp_name = newTemp();
			(yyvsp[0].s_info)->set_asm_var(tmp_name);
			s_table.insert((yyvsp[0].s_info));

			data_segment+= tmp_name+" DW ?\n";
			code+= "\nMOV "+tmp_name+", 0";
		  }
#line 1641 "y.tab.c"
    break;

  case 26: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 280 "1805060.y"
                                {
					add_log(line_count, "declaration_list : ID LTHIRD CONST_INT RTHIRD");

				}
#line 1650 "y.tab.c"
    break;

  case 27: /* statements: statement  */
#line 287 "1805060.y"
                        {
				add_log(line_count, "statements : statement");
				
			}
#line 1659 "y.tab.c"
    break;

  case 28: /* statements: statements statement  */
#line 293 "1805060.y"
                        {
				add_log(line_count, "statements : statements statement");
				
			}
#line 1668 "y.tab.c"
    break;

  case 29: /* if_statement: IF LPAREN expression RPAREN statement  */
#line 300 "1805060.y"
                        {
				add_log(line_count, "if_statement : IF LPAREN expression RPAREN statement");
				
			}
#line 1677 "y.tab.c"
    break;

  case 30: /* statement: var_declaration  */
#line 306 "1805060.y"
                        {
				add_log(line_count, "statement : var_declaration");
				
			}
#line 1686 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 312 "1805060.y"
                        {
				add_log(line_count, "statement : expression_statement");
				
			}
#line 1695 "y.tab.c"
    break;

  case 32: /* statement: compound_statement  */
#line 318 "1805060.y"
                        {
				add_log(line_count, "statement : compound_statement");
				
			}
#line 1704 "y.tab.c"
    break;

  case 33: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 324 "1805060.y"
                        {
				add_log(line_count, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
				
			}
#line 1713 "y.tab.c"
    break;

  case 34: /* statement: if_statement  */
#line 330 "1805060.y"
                        {
				add_log(line_count, "statement : if_statement");
				
			}
#line 1722 "y.tab.c"
    break;

  case 35: /* statement: if_statement ELSE statement  */
#line 336 "1805060.y"
                        {
				add_log(line_count, "statement : if_statement ELSE statement");
				
			}
#line 1731 "y.tab.c"
    break;

  case 36: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 342 "1805060.y"
                        {
				add_log(line_count, "statement : WHILE LPAREN expression RPAREN statement");
				
			}
#line 1740 "y.tab.c"
    break;

  case 37: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 348 "1805060.y"
                        {
				add_log(line_count, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

				code+= "\n\nMOV AX, "+ s_table.look_up((yyvsp[-2].s_info)->getName())->get_asm_var();
				code+= "\nCALL PRINT";
			}
#line 1751 "y.tab.c"
    break;

  case 38: /* statement: RETURN expression SEMICOLON  */
#line 356 "1805060.y"
                        {
				add_log(line_count, "statement : RETURN expression SEMICOLON");
				
			}
#line 1760 "y.tab.c"
    break;

  case 39: /* expression_statement: SEMICOLON  */
#line 363 "1805060.y"
                                {
					add_log(line_count, "expression_statement : SEMICOLON");
				}
#line 1768 "y.tab.c"
    break;

  case 40: /* expression_statement: expression SEMICOLON  */
#line 368 "1805060.y"
                                {
					add_log(line_count, "expression_statement : expression SEMICOLON");
					
				}
#line 1777 "y.tab.c"
    break;

  case 41: /* variable: ID  */
#line 375 "1805060.y"
                {
			add_log(line_count, "variable : ID");

			string var_name = s_table.look_up((yyvsp[0].s_info)->getName())->get_asm_var();
			(yyval.s_info)->set_asm_var(var_name);

			code+= "\nMOV BX, "+ var_name;
			code+= "\nPUSH BX";

		}
#line 1792 "y.tab.c"
    break;

  case 42: /* variable: ID LTHIRD expression RTHIRD  */
#line 387 "1805060.y"
                {
			add_log(line_count, "variable : ID LTHIRD expression RTHIRD");

		}
#line 1801 "y.tab.c"
    break;

  case 43: /* expression: logic_expression  */
#line 394 "1805060.y"
                        {
				add_log(line_count, "expression : logic_expression");
				
			}
#line 1810 "y.tab.c"
    break;

  case 44: /* expression: variable ASSIGNOP logic_expression  */
#line 400 "1805060.y"
                        {
				add_log(line_count, "expression : variable ASSIGNOP logic_expression");
				
				code+= "\nPOP BX";
				code+= "\nPOP AX";
				string var_name = s_table.look_up((yyvsp[-2].s_info)->getName())->get_asm_var();
				code+= "\nMOV "+var_name+", BX";
			}
#line 1823 "y.tab.c"
    break;

  case 45: /* logic_expression: rel_expression  */
#line 411 "1805060.y"
                        {
				add_log(line_count, "logic_expression : rel_expression");
				
			}
#line 1832 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 417 "1805060.y"
                        {
				add_log(line_count, "logic_expression : rel_expression LOGICOP rel_expression");
				
			}
#line 1841 "y.tab.c"
    break;

  case 47: /* rel_expression: simple_expression  */
#line 424 "1805060.y"
                        {
				add_log(line_count, "rel_expression	: simple_expression");
				
			}
#line 1850 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression RELOP simple_expression  */
#line 430 "1805060.y"
                        {
				add_log(line_count, "rel_expression : simple_expression RELOP simple_expression");
				
			}
#line 1859 "y.tab.c"
    break;

  case 49: /* simple_expression: term  */
#line 437 "1805060.y"
                        {
				add_log(line_count, "simple_expression : term");
				
			}
#line 1868 "y.tab.c"
    break;

  case 50: /* simple_expression: simple_expression ADDOP term  */
#line 443 "1805060.y"
                        {
				add_log(line_count, "simple_expression : simple_expression ADDOP term");
				
			}
#line 1877 "y.tab.c"
    break;

  case 51: /* term: unary_expression  */
#line 450 "1805060.y"
                {
			add_log(line_count, "term : unary_expression");
			
		}
#line 1886 "y.tab.c"
    break;

  case 52: /* term: term MULOP unary_expression  */
#line 456 "1805060.y"
                {
				add_log(line_count, "term : term MULOP unary_expression");
				
		}
#line 1895 "y.tab.c"
    break;

  case 53: /* unary_expression: ADDOP unary_expression  */
#line 463 "1805060.y"
                        {
				add_log(line_count, "unary_expression : ADDOP unary_expression");
				
			}
#line 1904 "y.tab.c"
    break;

  case 54: /* unary_expression: NOT unary_expression  */
#line 469 "1805060.y"
                        {
				add_log(line_count, "unary_expression : NOT unary_expression");
				
			}
#line 1913 "y.tab.c"
    break;

  case 55: /* unary_expression: factor  */
#line 475 "1805060.y"
                        {
				add_log(line_count, "unary_expression	: factor");
				
			}
#line 1922 "y.tab.c"
    break;

  case 56: /* factor: variable  */
#line 482 "1805060.y"
                {
			add_log(line_count, "factor	: variable");
			
		}
#line 1931 "y.tab.c"
    break;

  case 57: /* factor: ID LPAREN argument_list RPAREN  */
#line 488 "1805060.y"
                        {
				add_log(line_count, "factor : ID LPAREN argument_list RPAREN");
				
			}
#line 1940 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 494 "1805060.y"
                        {
				add_log(line_count, "factor : LPAREN expression RPAREN");
				
			}
#line 1949 "y.tab.c"
    break;

  case 59: /* factor: CONST_INT  */
#line 500 "1805060.y"
                {
			add_log(line_count, "factor	: CONST_INT");

			code+= "\nPUSH "+(yyvsp[0].s_info)->getName();
		}
#line 1959 "y.tab.c"
    break;

  case 60: /* factor: CONST_FLOAT  */
#line 507 "1805060.y"
                {
			add_log(line_count, "factor	: CONST_FLOAT");
		}
#line 1967 "y.tab.c"
    break;

  case 61: /* factor: variable INCOP  */
#line 512 "1805060.y"
                {
			add_log(line_count, "factor	: variable INCOP");
			
		}
#line 1976 "y.tab.c"
    break;

  case 62: /* factor: variable DECOP  */
#line 518 "1805060.y"
                {
			add_log(line_count, "factor	: variable DECOP");
			
		}
#line 1985 "y.tab.c"
    break;

  case 63: /* argument_list: arguments  */
#line 525 "1805060.y"
                {
			add_log(line_count, "argument_list : arguments");
			
		}
#line 1994 "y.tab.c"
    break;

  case 64: /* arguments: arguments COMMA logic_expression  */
#line 532 "1805060.y"
                {
			add_log(line_count, "argument_list : arguments COMMA logic_expression");
			
		}
#line 2003 "y.tab.c"
    break;

  case 65: /* arguments: logic_expression  */
#line 538 "1805060.y"
                {
			add_log(line_count, "argument_list : logic_expression");
			
		}
#line 2012 "y.tab.c"
    break;


#line 2016 "y.tab.c"

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

#line 545 "1805060.y"

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
	code_file.open("code_file.asm");

	yyin= fin;
	yyparse();

	if(num_of_error==0)
	{
		code_file<<".MODEL SMALL"<<endl<<".STACK 400H"<<endl<<".DATA\nNUMBER_STRING DB '00000$'"<<endl;
		code_file<<data_segment;
		code_file<<"\n.CODE";
		code_file<<code;

		code_file<<"\n\nPRINT PROC";
    	code_file<<"\nLEA SI, NUMBER_STRING";
    	code_file<<"\nADD SI, 5";
    	code_file<<"\nPRINT_LOOP:\nDEC SI\nMOV DX, 0\nMOV CX, 10\nDIV CX";
    	code_file<<"\nADD DL, '0'\nMOV [SI], DL\nCMP AX, 0\nJNE PRINT_LOOP";
    	code_file<<"\nMOV DX, SI\nMOV AH, 9\nINT 21H";
		code_file<<"\nMOV AH, 2\t;printing newline\nMOV DL, 0DH\nINT 21H\nMOV DL, 0AH\nINT 21H";
		code_file<<"\nRET\nPRINT ENDP";
		code_file<<"\n\nEND MAIN";
	}

	log_file<<"Total lines: "<<line_count<<"\nTotal errors: "<<num_of_error<<"\n";
	fclose(yyin);
	log_file.close();
	error_file.close();
	code_file.close();

	return 0;
}

