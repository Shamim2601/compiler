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
int total_offset = 0;

string asm_code = "";
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
stack<string> levels;

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

ifstream reader;
ofstream optimized_file;

void optimize_1(string fName)
{
	reader.open(fName);
	optimized_file.open("optimized_file.asm");
	string first_line;
	string second_line;

	while(getline(reader,first_line)){
		if(first_line.find("PUSH")!=string::npos){
			vector<string> tokens;
			stringstream check1(first_line);
			string token ;
			while(getline(check1, token, ' '))
			{
				tokens.push_back(token);
			}
			getline(reader,second_line);
			
			if((second_line.find("POP")!=string::npos)&&(second_line.find(tokens[1])!=string::npos))
			{
				optimized_file <<";"<< first_line << "\n";
				optimized_file <<";"<< second_line << "\n";
			}
			else
			{
				optimized_file << first_line << "\n";
				optimized_file << second_line << "\n";
			}
		}
		else if(first_line.find("MOV")!=string::npos)
		{
			vector<string> tokens;
			stringstream check1(first_line);
			string token ;
			while(getline(check1, token, ' '))
			{
				tokens.push_back(token);
			}

			vector<string> tokens1;
			stringstream check2(tokens[1]);
			string token1 ;
			while(getline(check2, token1, ','))
			{
				tokens1.push_back(token1);
			}
			
			getline(reader,second_line);
			
			if((second_line.find("MOV")!=string::npos)&&(second_line.find(tokens1[0])!=string::npos)&&(second_line.find(tokens1[1])!=string::npos))
			{
				optimized_file <<";"<< first_line << "\n";
				optimized_file <<";"<< second_line << "\n";
			}
			else
			{
				optimized_file << first_line << "\n";
				optimized_file << second_line << "\n";
			}
		}
		else
		{
			optimized_file << first_line << "\n";
		}	
	}
	optimized_file.close();
}


#line 209 "y.tab.c"

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
#line 139 "1805060.y"

	SymbolInfo *s_info;
	vector<SymbolInfo*>* siList;

#line 341 "y.tab.c"

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
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_var_declaration = 50,           /* var_declaration  */
  YYSYMBOL_type_specifier = 51,            /* type_specifier  */
  YYSYMBOL_declaration_list = 52,          /* declaration_list  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_if_statement = 54,              /* if_statement  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_expression_statement = 59,      /* expression_statement  */
  YYSYMBOL_variable = 60,                  /* variable  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_logic_expression = 62,          /* logic_expression  */
  YYSYMBOL_rel_expression = 63,            /* rel_expression  */
  YYSYMBOL_simple_expression = 64,         /* simple_expression  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_unary_expression = 66,          /* unary_expression  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_argument_list = 68,             /* argument_list  */
  YYSYMBOL_arguments = 69                  /* arguments  */
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
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

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
       0,   163,   163,   172,   178,   185,   191,   197,   204,   213,
     223,   232,   231,   257,   263,   269,   275,   284,   289,   283,
     301,   300,   313,   320,   325,   330,   337,   348,   354,   365,
     372,   378,   386,   385,   410,   416,   422,   428,   433,   444,
     443,   459,   458,   485,   493,   501,   506,   513,   523,   530,
     536,   547,   553,   589,   595,   647,   653,   665,   671,   692,
     703,   719,   726,   732,   738,   744,   751,   756,   765,   775,
     782,   788
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
  "parameter_list", "compound_statement", "$@2", "$@3", "$@4",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "if_statement", "$@5", "statement", "$@6", "$@7", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -77,   -77,   -77,    33,    -7,   -77,   -77,   -77,   -77,
      22,   -77,   -77,     9,    -5,     0,    41,    34,   -77,    60,
       1,    61,    68,    72,   -77,    75,     2,    -7,   -77,   -77,
      71,    83,   -77,   -77,   -77,    77,    84,    50,    85,   -77,
     -77,    91,    92,    93,    25,    25,    25,    94,   -77,    54,
     -77,   -77,    25,   -77,   -77,    82,    50,   104,   -77,   -77,
      76,    86,   -77,    73,    21,    78,   -77,   -77,   -77,    25,
      66,    25,    87,   100,    17,   -77,    89,    25,    25,   -77,
      99,   101,   -77,   -77,   -77,   -77,    25,   -77,    25,    25,
      25,    25,   105,    66,   106,   -77,   -77,   107,   -77,   108,
     102,   109,   -77,    50,   -77,   -77,    78,    90,   -77,   -77,
      25,   -77,    98,   -77,    25,   -77,   -77,    50,   111,    50,
     -77,   -77,   -77,    50,   -77,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    11,
       0,    16,     0,    26,     9,     0,     0,     0,    15,    29,
       0,    17,    12,     8,    10,    14,     0,     0,     0,    13,
      27,     0,     0,     0,     0,     0,     0,     0,    45,    47,
      65,    66,     0,    36,    34,     0,    18,    38,    30,    35,
      62,     0,    49,    51,    53,    55,    57,    61,    21,     0,
       0,     0,     0,     0,    62,    60,     0,     0,     0,    59,
      28,     0,    31,    39,    67,    68,     0,    46,     0,     0,
       0,     0,     0,     0,     0,    44,    64,     0,    71,     0,
      69,     0,    19,     0,    50,    52,    56,    54,    58,    32,
       0,    41,     0,    63,     0,    48,    40,     0,     0,     0,
      43,    70,    33,     0,    42,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   112,   -77,   -77,   -77,   -77,    56,   -77,
     -77,   -77,    15,    12,   -77,   -77,   -77,   -77,   -54,   -77,
     -77,   -65,   -46,   -37,   -76,    39,    38,    40,   -43,   -77,
     -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    25,    20,    53,    37,
      81,    38,    54,    55,    14,    56,    57,   117,    58,   103,
     119,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      74,    98,    82,    75,     1,    93,    74,    72,    73,    79,
     104,     1,    10,    19,    26,     9,    31,    10,    17,    18,
       9,    15,     2,     3,    27,    16,    33,    21,   110,     2,
       3,    74,    92,    11,    94,    84,    85,    45,   121,    35,
      74,   101,    74,    74,    74,    74,    46,    13,   108,   116,
      49,    50,    51,    41,    89,    42,    90,    43,    52,    23,
      44,     1,    45,   122,    31,   124,    77,    22,    74,   125,
      78,    46,    47,   118,    48,    49,    50,    51,    45,     2,
       3,    32,    34,    52,    24,    29,    28,    46,    30,    31,
      48,    49,    50,    51,    84,    85,    86,    36,   -20,    52,
      68,    40,    39,    69,    70,    71,    76,    80,    83,    88,
      87,    95,    91,    96,    97,    16,   102,    12,   109,   111,
     112,   113,   120,    89,   123,   114,   115,   105,   107,   106
};

static const yytype_int8 yycheck[] =
{
      46,    77,    56,    46,    11,    70,    52,    44,    45,    52,
      86,    11,     0,    13,    13,     0,    14,     5,    23,    24,
       5,    12,    29,    30,    23,    16,    24,    15,    93,    29,
      30,    77,    69,     0,    71,    18,    19,    12,   114,    27,
      86,    78,    88,    89,    90,    91,    21,    25,    91,   103,
      25,    26,    27,     3,    33,     5,    35,     7,    33,    25,
      10,    11,    12,   117,    14,   119,    12,    26,   114,   123,
      16,    21,    22,   110,    24,    25,    26,    27,    12,    29,
      30,    25,    26,    33,    24,    17,    25,    21,    16,    14,
      24,    25,    26,    27,    18,    19,    20,    26,    15,    33,
      15,    17,    25,    12,    12,    12,    12,    25,     4,    36,
      24,    24,    34,    13,    25,    16,    15,     5,    13,    13,
      13,    13,    24,    33,    13,    23,    17,    88,    90,    89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    29,    30,    39,    40,    41,    42,    43,    50,
      51,     0,    41,    25,    52,    12,    16,    23,    24,    13,
      45,    51,    26,    25,    24,    44,    13,    23,    25,    17,
      16,    14,    46,    24,    46,    51,    26,    47,    49,    25,
      17,     3,     5,     7,    10,    12,    21,    22,    24,    25,
      26,    27,    33,    46,    50,    51,    53,    54,    56,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    15,    12,
      12,    12,    61,    61,    60,    66,    12,    12,    16,    66,
      25,    48,    56,     4,    18,    19,    20,    24,    36,    33,
      35,    34,    61,    59,    61,    24,    13,    25,    62,    68,
      69,    61,    15,    57,    62,    63,    65,    64,    66,    13,
      59,    13,    13,    13,    23,    17,    56,    55,    61,    58,
      24,    62,    56,    13,    56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    44,    43,    45,    45,    45,    45,    47,    48,    46,
      49,    46,    50,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    55,    54,    56,    56,    56,    56,    56,    57,
      56,    58,    56,    56,    56,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    68,
      69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     0,     6,     4,     3,     2,     1,     0,     0,     5,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     0,     6,     1,     1,     1,     7,     1,     0,
       4,     0,     6,     5,     3,     1,     2,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       2,     1,     1,     4,     3,     1,     1,     2,     2,     1,
       3,     1
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
#line 164 "1805060.y"
        {
		//write your code in this block in all the similar blocks below
		add_log(line_count, "start : program");
		
		s_table.print_all(log_file);
	}
#line 1482 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 173 "1805060.y"
                {
			add_log(line_count, "program : program unit");
			
		}
#line 1491 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 179 "1805060.y"
                {
			add_log(line_count, "program : unit");
			
		}
#line 1500 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 186 "1805060.y"
                {
			add_log(line_count, "unit : var_declaration");
			
		}
#line 1509 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 192 "1805060.y"
                {
			add_log(line_count, "unit : func_declaration");
			
		}
#line 1518 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 198 "1805060.y"
                {
			add_log(line_count, "unit : func_definition");
			
		}
#line 1527 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 205 "1805060.y"
                        {
				add_log(line_count, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
				

				(yyvsp[-4].s_info)->setSize(-1);
				s_table.insert((yyvsp[-4].s_info));
			}
#line 1539 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 214 "1805060.y"
                        {
				add_log(line_count, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
				

				(yyvsp[-3].s_info)->setSize(-1);
				s_table.insert((yyvsp[-3].s_info));
			}
#line 1551 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 224 "1805060.y"
                                {
					add_log(line_count, "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");

					(yyvsp[-4].s_info)->setSize(-1);
					s_table.insert((yyvsp[-4].s_info));
				}
#line 1562 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 232 "1805060.y"
                                {	
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN");
					(yyvsp[-2].s_info)->setSize(-1);
					s_table.insert((yyvsp[-2].s_info));

					asm_code+= "\n"+(yyvsp[-2].s_info)->getName()+" PROC\t;func_definition";
					if((yyvsp[-2].s_info)->getName()=="main")
					{
						asm_code+= "\nMOV AX,@DATA \nMOV DS,AX\t;initializing data segment\n";
					}
					
				}
#line 1579 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN RPAREN $@1 compound_statement  */
#line 245 "1805060.y"
                                {
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN compound_statement");
					if((yyvsp[-4].s_info)->getName()=="main")
					{
						asm_code+= "\n\nMOV AH, 4CH \nINT 21H\t\t;return 0";
					}

					asm_code+= "\n"+(yyvsp[-4].s_info)->getName()+" ENDP";
				}
#line 1593 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 258 "1805060.y"
                        {
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier ID");
				
			}
#line 1602 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier  */
#line 264 "1805060.y"
                        {
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");
				
			}
#line 1611 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier ID  */
#line 270 "1805060.y"
                        {
				add_log(line_count, "parameter_list : type_specifier ID");
				
			}
#line 1620 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier  */
#line 276 "1805060.y"
                        {
				add_log(line_count, "parameter_list : type_specifier");
				
			}
#line 1629 "y.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 284 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL");
					s_table.enter_scope();
				}
#line 1638 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 289 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL statements");
				}
#line 1646 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@2 statements $@3 RCURL  */
#line 293 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL statements RCURL");
										
					s_table.exit_scope();

				}
#line 1657 "y.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 301 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL");
					s_table.enter_scope();
				}
#line 1666 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL $@4 RCURL  */
#line 306 "1805060.y"
                                {
					add_log(line_count, "compound_statement : LCURL RCURL");

					s_table.exit_scope();
				}
#line 1676 "y.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 314 "1805060.y"
                        {
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");	
				s_table.print_all(log_file);
			}
#line 1685 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 321 "1805060.y"
                {
			add_log(line_count, "type_specifier : INT");
		}
#line 1693 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 326 "1805060.y"
                {
			add_log(line_count, "type_specifier : FLOAT");
		}
#line 1701 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 331 "1805060.y"
                {
			add_log(line_count, "type_specifier : VOID");
		}
#line 1709 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 338 "1805060.y"
                        {
				add_log(line_count, "declaration_list : declaration_list COMMA ID");
				
				string tmp_name = newTemp();
				(yyvsp[0].s_info)->set_asm_var(tmp_name);
				s_table.insert((yyvsp[0].s_info));

				data_segment+= tmp_name+" DW ?\n";
			}
#line 1723 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 349 "1805060.y"
                        {
				add_log(line_count, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
				
			}
#line 1732 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 355 "1805060.y"
                  {
			add_log(line_count, "declaration_list : ID");

			string tmp_name = newTemp();
			(yyvsp[0].s_info)->set_asm_var(tmp_name);
			s_table.insert((yyvsp[0].s_info));

			data_segment+= tmp_name+" DW ?\n";
		  }
#line 1746 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 366 "1805060.y"
                                {
					add_log(line_count, "declaration_list : ID LTHIRD CONST_INT RTHIRD");

				}
#line 1755 "y.tab.c"
    break;

  case 30: /* statements: statement  */
#line 373 "1805060.y"
                        {
				add_log(line_count, "statements : statement");
				
			}
#line 1764 "y.tab.c"
    break;

  case 31: /* statements: statements statement  */
#line 379 "1805060.y"
                        {
				add_log(line_count, "statements : statements statement");
				
			}
#line 1773 "y.tab.c"
    break;

  case 32: /* $@5: %empty  */
#line 386 "1805060.y"
                        {
				add_log(line_count, "if_statement : IF LPAREN expression RPAREN");

				string if_next_level = newLabel();
				levels.push(if_next_level);

				asm_code+= "\nPOP BX\t;if_statement : IF LPAREN expression RPAREN";
				asm_code+= "\nCMP BX, 0";
				asm_code+= "\nJE "+ if_next_level;
				
			}
#line 1789 "y.tab.c"
    break;

  case 33: /* if_statement: IF LPAREN expression RPAREN $@5 statement  */
#line 398 "1805060.y"
                        {
				add_log(line_count, "if_statement : IF LPAREN expression RPAREN statement");

				string if_next_level = levels.top();
				levels.pop();
				string else_next_level = newLabel();
				levels.push(else_next_level);

				asm_code+= "\nJMP "+else_next_level;
				asm_code+= "\n"+if_next_level+":";
			}
#line 1805 "y.tab.c"
    break;

  case 34: /* statement: var_declaration  */
#line 411 "1805060.y"
                        {
				add_log(line_count, "statement : var_declaration");
				
			}
#line 1814 "y.tab.c"
    break;

  case 35: /* statement: expression_statement  */
#line 417 "1805060.y"
                        {
				add_log(line_count, "statement : expression_statement");
				
			}
#line 1823 "y.tab.c"
    break;

  case 36: /* statement: compound_statement  */
#line 423 "1805060.y"
                        {
				add_log(line_count, "statement : compound_statement");
				
			}
#line 1832 "y.tab.c"
    break;

  case 37: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 429 "1805060.y"
                        {
				add_log(line_count, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
			}
#line 1840 "y.tab.c"
    break;

  case 38: /* statement: if_statement  */
#line 434 "1805060.y"
                        {
				add_log(line_count, "statement : if_statement");
				
				string just_if_next = levels.top();
				levels.pop();

				asm_code+= "\n"+just_if_next+":";
			}
#line 1853 "y.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 444 "1805060.y"
                        {
				add_log(line_count, "statement : if_statement ELSE");
				
			}
#line 1862 "y.tab.c"
    break;

  case 40: /* statement: if_statement ELSE $@6 statement  */
#line 449 "1805060.y"
                        {
				add_log(line_count, "statement : if_statement ELSE statement");

				string else_next_level = levels.top();
				levels.pop();

				asm_code+= "\n"+else_next_level+":";
			}
#line 1875 "y.tab.c"
    break;

  case 41: /* $@7: %empty  */
#line 459 "1805060.y"
                        {
				add_log(line_count, "statement : WHILE LPAREN expression RPAREN statement");
				
				string while_begin_level = newLabel();
				levels.push(while_begin_level);
				string while_next_level = newLabel();
				levels.push(while_next_level);

				asm_code+= "\n"+while_begin_level+":";
				asm_code+= "\nPOP BX\t;statement : WHILE LPAREN expression RPAREN";
				asm_code+= "\nCMP BX, 0";
				asm_code+= "\nJE "+ while_next_level;
			}
#line 1893 "y.tab.c"
    break;

  case 42: /* statement: WHILE LPAREN expression RPAREN $@7 statement  */
#line 473 "1805060.y"
                        {
				add_log(line_count, "statement : WHILE LPAREN expression RPAREN statement");

				string while_next_level = levels.top();
				levels.pop();
				string while_begin_level = levels.top();
				levels.pop();

				asm_code+= "\nJMP "+while_begin_level;
				asm_code+= "\n"+while_next_level+":";
			}
#line 1909 "y.tab.c"
    break;

  case 43: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 486 "1805060.y"
                        {
				add_log(line_count, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

				asm_code+= "\nMOV AX, "+ s_table.look_up((yyvsp[-2].s_info)->getName())->get_asm_var();
				asm_code+= "\nCALL PRINT\t;PRINTLN LPAREN ID RPAREN SEMICOLON";
			}
#line 1920 "y.tab.c"
    break;

  case 44: /* statement: RETURN expression SEMICOLON  */
#line 494 "1805060.y"
                        {
				add_log(line_count, "statement : RETURN expression SEMICOLON");

				asm_code+= "\t;statement : RETURN expression SEMICOLON";
			}
#line 1930 "y.tab.c"
    break;

  case 45: /* expression_statement: SEMICOLON  */
#line 502 "1805060.y"
                                {
					add_log(line_count, "expression_statement : SEMICOLON");
				}
#line 1938 "y.tab.c"
    break;

  case 46: /* expression_statement: expression SEMICOLON  */
#line 507 "1805060.y"
                                {
					add_log(line_count, "expression_statement : expression SEMICOLON");
					
				}
#line 1947 "y.tab.c"
    break;

  case 47: /* variable: ID  */
#line 514 "1805060.y"
                {
			add_log(line_count, "variable : ID");

			string var_name = s_table.look_up((yyvsp[0].s_info)->getName())->get_asm_var();
			(yyval.s_info)->set_asm_var(var_name);

			asm_code+= "\nPUSH "+ var_name;
		}
#line 1960 "y.tab.c"
    break;

  case 48: /* variable: ID LTHIRD expression RTHIRD  */
#line 524 "1805060.y"
                {
			add_log(line_count, "variable : ID LTHIRD expression RTHIRD");

		}
#line 1969 "y.tab.c"
    break;

  case 49: /* expression: logic_expression  */
#line 531 "1805060.y"
                        {
				add_log(line_count, "expression : logic_expression");
				
			}
#line 1978 "y.tab.c"
    break;

  case 50: /* expression: variable ASSIGNOP logic_expression  */
#line 537 "1805060.y"
                        {
				add_log(line_count, "expression : variable ASSIGNOP logic_expression");
				
				asm_code+= "\nPOP BX\t;variable ASSIGNOP logic_expression";
				asm_code+= "\nPOP AX";
				string var_name = s_table.look_up((yyvsp[-2].s_info)->getName())->get_asm_var();
				asm_code+= "\nMOV "+var_name+", BX";
			}
#line 1991 "y.tab.c"
    break;

  case 51: /* logic_expression: rel_expression  */
#line 548 "1805060.y"
                        {
				add_log(line_count, "logic_expression : rel_expression");
				
			}
#line 2000 "y.tab.c"
    break;

  case 52: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 554 "1805060.y"
                        {
				add_log(line_count, "logic_expression : rel_expression LOGICOP rel_expression");
				
				asm_code+= "\nPOP BX\t;rel_expression LOGICOP rel_expression";
				asm_code+= "\nPOP AX";

				string L1 = newLabel();
				string L0 = newLabel();
				string L = newLabel();

				if((yyvsp[-1].s_info)->getName()=="&&")
				{
					asm_code+= "\nCMP AX, 0";
					asm_code+= "\nJE "+L0;
					asm_code+= "\nCMP BX, 0";
					asm_code+= "\nJE "+L0;
				}
				else
				{
					asm_code+= "\nCMP AX, 1";
					asm_code+= "\nJE "+L1;
					asm_code+= "\nCMP BX, 1";
					asm_code+= "\nJE "+L1;
					asm_code+= "\nJMP "+L;
				}

				asm_code+= "\n"+L1;
				asm_code+= ":\nMOV BX, 1";
				asm_code+= "\nJMP "+L;
				asm_code+= "\n"+L0;
				asm_code+= ":\nMOV BX, 0";
				asm_code+= "\n"+L+":\nPUSH BX";
			}
#line 2038 "y.tab.c"
    break;

  case 53: /* rel_expression: simple_expression  */
#line 590 "1805060.y"
                        {
				add_log(line_count, "rel_expression	: simple_expression");
				
			}
#line 2047 "y.tab.c"
    break;

  case 54: /* rel_expression: simple_expression RELOP simple_expression  */
#line 596 "1805060.y"
                        {
				add_log(line_count, "rel_expression : simple_expression RELOP simple_expression");
				

				asm_code+= "\nPOP BX\t;simple_expression RELOP simple_expression";
				asm_code+= "\nPOP AX";

				string L1 = newLabel();
				string L0 = newLabel();
				string L = newLabel();

				if((yyvsp[-1].s_info)->getName()=="<")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJGE "+L0;
				}
				else if((yyvsp[-1].s_info)->getName()=="<=")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJG "+L0;
				}
				else if((yyvsp[-1].s_info)->getName()==">")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJLE "+L0;
				}
				else if((yyvsp[-1].s_info)->getName()==">=")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJL "+L0;
				}
				else if((yyvsp[-1].s_info)->getName()=="==")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJNE "+L0;
				}
				else
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJE "+L0;
				}

				asm_code+= "\n"+L1;
				asm_code+= ":\nMOV BX, 1";
				asm_code+= "\nJMP "+L;
				asm_code+= "\n"+L0;
				asm_code+= ":\nMOV BX, 0";
				asm_code+= "\n"+L+":\nPUSH BX";
			}
#line 2101 "y.tab.c"
    break;

  case 55: /* simple_expression: term  */
#line 648 "1805060.y"
                        {
				add_log(line_count, "simple_expression : term");
				
			}
#line 2110 "y.tab.c"
    break;

  case 56: /* simple_expression: simple_expression ADDOP term  */
#line 654 "1805060.y"
                        {
				add_log(line_count, "simple_expression : simple_expression ADDOP term");
				
				asm_code+= "\nPOP BX\t;simple_expression ADDOP term";
				asm_code+= "\nPOP AX";
				if((yyvsp[-1].s_info)->getName()=="+") asm_code+= "\nADD BX, AX";
				else asm_code+= "\nSUB BX, AX";
				asm_code+= "\nPUSH BX";
			}
#line 2124 "y.tab.c"
    break;

  case 57: /* term: unary_expression  */
#line 666 "1805060.y"
                {
			add_log(line_count, "term : unary_expression");
			
		}
#line 2133 "y.tab.c"
    break;

  case 58: /* term: term MULOP unary_expression  */
#line 672 "1805060.y"
                {
				add_log(line_count, "term : term MULOP unary_expression");
				
				asm_code+= "\nPOP BX\t;term MULOP unary_expression";
				asm_code+= "\nPOP AX";
				if((yyvsp[-1].s_info)->getName()=="*")
				{
					asm_code+= "\nMUL BX";
					asm_code+= "\nMOV BX, AX";
				}else
				{
					asm_code+= "\nXOR DX, DX";
					asm_code+= "\nDIV BX";
					if((yyvsp[-1].s_info)->getName()=="/") asm_code+= "\nMOV BX, AX";
					else asm_code+= "\nMOV BX, DX";
				}
				asm_code+= "\nPUSH BX";
		}
#line 2156 "y.tab.c"
    break;

  case 59: /* unary_expression: ADDOP unary_expression  */
#line 693 "1805060.y"
                        {
				add_log(line_count, "unary_expression : ADDOP unary_expression");
				
				if((yyvsp[-1].s_info)->getName()=="-")
				{
					asm_code+= "\nPOP BX\t;ADDOP unary_expression";
					asm_code+= "\nNEG BX\nPUSH BX";
				}
			}
#line 2170 "y.tab.c"
    break;

  case 60: /* unary_expression: NOT unary_expression  */
#line 704 "1805060.y"
                        {
				add_log(line_count, "unary_expression : NOT unary_expression");
				
				string L1 = newLabel();
				string L0 = newLabel();
				string L = newLabel();
				asm_code+= "\nPOP BX\t;NOT unary_expression";
				asm_code+= "\nCMP BX, 0";
				asm_code+= "\nJNE "+L0;
				asm_code+= "\n"+L1+":\nMOV BX, 1";
				asm_code+= "\nJMP "+L;
				asm_code+= "\n"+L0+":\nMOV BX, 0";
				asm_code+= "\n"+L+":\nPUSH BX";
			}
#line 2189 "y.tab.c"
    break;

  case 61: /* unary_expression: factor  */
#line 720 "1805060.y"
                        {
				add_log(line_count, "unary_expression	: factor");
				
			}
#line 2198 "y.tab.c"
    break;

  case 62: /* factor: variable  */
#line 727 "1805060.y"
                {
			add_log(line_count, "factor	: variable");
			
		}
#line 2207 "y.tab.c"
    break;

  case 63: /* factor: ID LPAREN argument_list RPAREN  */
#line 733 "1805060.y"
                        {
				add_log(line_count, "factor : ID LPAREN argument_list RPAREN");
				
			}
#line 2216 "y.tab.c"
    break;

  case 64: /* factor: LPAREN expression RPAREN  */
#line 739 "1805060.y"
                        {
				add_log(line_count, "factor : LPAREN expression RPAREN");
				
			}
#line 2225 "y.tab.c"
    break;

  case 65: /* factor: CONST_INT  */
#line 745 "1805060.y"
                {
			add_log(line_count, "factor	: CONST_INT");

			asm_code+= "\nPUSH "+(yyvsp[0].s_info)->getName();
		}
#line 2235 "y.tab.c"
    break;

  case 66: /* factor: CONST_FLOAT  */
#line 752 "1805060.y"
                {
			add_log(line_count, "factor	: CONST_FLOAT");
		}
#line 2243 "y.tab.c"
    break;

  case 67: /* factor: variable INCOP  */
#line 757 "1805060.y"
                {
			add_log(line_count, "factor	: variable INCOP");

			string var_name = s_table.look_up((yyvsp[-1].s_info)->getName())->get_asm_var();
			asm_code+= "\nINC "+var_name+"\t;variable INCOP";
			asm_code+= "\nPUSH "+var_name;
		}
#line 2255 "y.tab.c"
    break;

  case 68: /* factor: variable DECOP  */
#line 766 "1805060.y"
                {
			add_log(line_count, "factor	: variable DECOP");
			
			string var_name = s_table.look_up((yyvsp[-1].s_info)->getName())->get_asm_var();
			asm_code+= "\nDEC "+var_name+"\t;variable DECOP";
			asm_code+= "\nPUSH "+var_name;
		}
#line 2267 "y.tab.c"
    break;

  case 69: /* argument_list: arguments  */
#line 776 "1805060.y"
                {
			add_log(line_count, "argument_list : arguments");
			
		}
#line 2276 "y.tab.c"
    break;

  case 70: /* arguments: arguments COMMA logic_expression  */
#line 783 "1805060.y"
                {
			add_log(line_count, "argument_list : arguments COMMA logic_expression");
			
		}
#line 2285 "y.tab.c"
    break;

  case 71: /* arguments: logic_expression  */
#line 789 "1805060.y"
                {
			add_log(line_count, "argument_list : logic_expression");
			
		}
#line 2294 "y.tab.c"
    break;


#line 2298 "y.tab.c"

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

#line 796 "1805060.y"

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
		code_file<<asm_code;

		code_file<<"\n\nPRINT PROC";
		code_file<<"\nCMP AX, 0\nJNL NORMAL \nPUSH AX\nMOV DL, 45\nMOV AH, 2\nINT 21H \nPOP AX\nNEG AX\nNORMAL:";
    	code_file<<"\nLEA SI, NUMBER_STRING";
    	code_file<<"\nADD SI, 5";
    	code_file<<"\nPRINT_LOOP:\nDEC SI\nXOR DX, DX\nMOV CX, 10\nDIV CX";
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

	optimize_1("code_file.asm");

	return 0;
}

