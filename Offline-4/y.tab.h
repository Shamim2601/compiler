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
#line 73 "1805060.y"

	SymbolInfo *s_info;
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
