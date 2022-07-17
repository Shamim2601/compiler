/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    INT = 264,                     /* INT  */
    FLOAT = 265,                   /* FLOAT  */
    DOUBLE = 266,                  /* DOUBLE  */
    CHAR = 267,                    /* CHAR  */
    DEFAULT = 268,                 /* DEFAULT  */
    RETURN = 269,                  /* RETURN  */
    VOID = 270,                    /* VOID  */
    LPAREN = 271,                  /* LPAREN  */
    RPAREN = 272,                  /* RPAREN  */
    LCURL = 273,                   /* LCURL  */
    RCURL = 274,                   /* RCURL  */
    LTHIRD = 275,                  /* LTHIRD  */
    RTHIRD = 276,                  /* RTHIRD  */
    INCOP = 277,                   /* INCOP  */
    DECOP = 278,                   /* DECOP  */
    ASSIGNOP = 279,                /* ASSIGNOP  */
    NOT = 280,                     /* NOT  */
    PRINTLN = 281,                 /* PRINTLN  */
    COMMA = 282,                   /* COMMA  */
    SEMICOLON = 283,               /* SEMICOLON  */
    ID = 284,                      /* ID  */
    CONST_INT = 285,               /* CONST_INT  */
    CONST_FLOAT = 286,             /* CONST_FLOAT  */
    CONST_CHAR = 287,              /* CONST_CHAR  */
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
#define INT 264
#define FLOAT 265
#define DOUBLE 266
#define CHAR 267
#define DEFAULT 268
#define RETURN 269
#define VOID 270
#define LPAREN 271
#define RPAREN 272
#define LCURL 273
#define RCURL 274
#define LTHIRD 275
#define RTHIRD 276
#define INCOP 277
#define DECOP 278
#define ASSIGNOP 279
#define NOT 280
#define PRINTLN 281
#define COMMA 282
#define SEMICOLON 283
#define ID 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define CONST_CHAR 287
#define ADDOP 288
#define MULOP 289
#define RELOP 290
#define LOGICOP 291
#define LOWER_THAN_ELSE 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "1805060.y"

	SymbolInfo* s_info;
	vector<SymbolInfo*>* siList;

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
