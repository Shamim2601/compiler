%option noyywrap

%{
#include<bits/stdc++.h>
#include "SymbolTable.cpp"
#include "y.tab.h"

using namespace std;

void yyerror(char* s);

extern YYSTYPE yylval;
extern int line_count;
extern int num_of_error;
extern SymbolTable s_table;
extern FILE* log_file;

char convert_char(char* ch)
{
	if(ch[1]!= '\\'){return ch[1];}
	else{
		switch(ch[2]){
			case 'n': return  10; break;
			case 'f': return  12; break;
			case 'v': return  11; break;
            case 't': return  9; break;
			case 'r': return  13; break;
			default: return  0; break;
		}
	}
}

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NUMBER {DIGIT}+
NEWLINE \r?\n

ADDOP [+-]
MULOP [*/%]
INCOP "++"
DECOP "--"
RELOP "<"|"<="|">"|">="|"=="|"!="
ASSIGNOP [=]
LOGICOP "&&"|"||"
NOT [!]
LPAREN "("
RPAREN ")"
LCURL "{"
RCURL "}"
LTHIRD "["
RTHIRD "]"
COMMA [,]
SEMICOLON [;]

ID [A-Za-z_][a-zA-Z0-9_]*
CONST_INT {NUMBER}
CONST_FLOAT {NUMBER}?(\.{NUMBER})?([Ee][+-]?{NUMBER})?

EMPTY \'\'
SP_CHAR [ntf\\'rabv0]
CONST_CHAR (\'[^\\]\')|(\'\\{SP_CHAR}\')

SL_COMMENT \/\/.*(\\(\r)?\n.*)*
ML_COMMENT ("/*")([^*]|\*[^\/])*("*/")
COMMENT {SL_COMMENT}|{ML_COMMENT}

DPOINT_ERROR {NUMBER}\.{NUMBER}(\.{NUMBER}?)+
ILL_FORM_NUM {DIGIT}*(\.{DIGIT}*)*[Ee][+-]?{DIGIT}*(\.{DIGIT}*)+
INVALID {NUMBER}({LETTER}+{NUMBER}?)+
MULTICHAR (\'[^\\].+\')|(\'\\{SP_CHAR}.+\')
UNFINISHED_CHAR (\'[^\\])|(\'\\{SP_CHAR})
UNFINISHED_COMMENT ("/*")([^*]|\*[^\/])*
UNRECOGNIZED .

%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

{COMMENT}	{
			/*fprintf(logout,"Line no %d: comment found\n\n",line_count);
			for(int i = 0; i<strlen(yytext); i++)
			{
				if(yytext[i]=='\n')
				{
					line_count++;
				}
			} */
		}

{UNFINISHED_COMMENT}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Unfinished Comment.\n\n",line_count);
			num_of_error++;
			for(int i = 0; i<strlen(yytext); i++)
			{
				if(yytext[i]=='\n')
				{
					line_count++;
				}
			}*/
		}

"if"	{
			return IF;
		}
		
"else"	{
			return ELSE;
		}

"for"	{
			return FOR;
		}

"while"	{
			return WHILE;
		}

"do"	{
			return DO;
		}

"int"	{
			return INT;
		}

"char"	{
			return CHAR;
		}

"float"	{
			return FLOAT;
		}

"double"	{
			return DOUBLE;
		}

"void"	{
			return VOID;
		}

"return"	{
			return RETURN;
		}

"default"	{
			return DEFAULT;
		}

"continue"	{
			return  CONTINUE;
		}

"printf"	{
			return PRINTLN;
		}


{ADDOP}		{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("ADDOP");
			yylval.s_info = si;
			return ADDOP;
		}

{MULOP}		{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("MULOP");
			yylval.s_info = si;
			return MULOP;
		}

{INCOP}		{
			return INCOP;
		}

{DECOP}		{
			return DECOP;
		}

{RELOP}		{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("RELOP");
			yylval.s_info = si;
			return RELOP;
		}

{ASSIGNOP}		{
			return ASSIGNOP;
		}

{LOGICOP}		{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("LOGICOP");
			yylval.s_info = si;
			return LOGICOP;
		}

{NOT}		{
			return NOT;
		}

{LPAREN}		{
			return LPAREN;
		}

{RPAREN}		{
			return RPAREN;
		}
		
{LCURL}		{
			return LCURL;
		}

{RCURL}		{
			return RCURL;
		}

{LTHIRD}		{
			return LTHIRD;
		}

{RTHIRD}		{
			return RTHIRD;
		}

{COMMA}		{
			return COMMA;
		}

{SEMICOLON}		{
			return SEMICOLON;
		}


{EMPTY}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Empty character.\n\n",line_count);
			num_of_error++;*/
		}

{ID}	{
			SymbolInfo* si = new SymbolInfo(yytext, "ID");
			yylval.s_info = si;
			return ID;
		}

{CONST_INT}	{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("CONST_INT");
			yylval.s_info = si;
			return CONST_INT;
			
		}	

{CONST_FLOAT}	{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("CONST_FLOAT");
			yylval.s_info = si;
			return CONST_FLOAT;
		}	

{CONST_CHAR}	{
			SymbolInfo* si = new SymbolInfo();
			si->setName(yytext);
			si->setType("CONST_CHAR");
			yylval.s_info = si;
			return CONST_CHAR;
		}

{INVALID}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Invalid prefix of identifier or invalid suffix of number %s.\n\n",line_count, yytext);
			num_of_error++;*/
		}

{MULTICHAR}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Multiple character constant %s.\n\n",line_count, yytext);
			num_of_error++;*/
		}

{UNFINISHED_CHAR}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Unfinished character constant %s.\n\n",line_count, yytext);
			num_of_error++;*/
		}

{DPOINT_ERROR}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Multiple decimal points in %s.\n\n",line_count, yytext);
			num_of_error++;*/
		}

{ILL_FORM_NUM}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Ill formed number  %s.\n\n",line_count, yytext);
			num_of_error++;*/
		}

{UNRECOGNIZED}	{
			/*fprintf(logout,"Error! Line no: %d ; Type: Unrecognized character %s.\n\n",line_count, yytext);
			num_of_error++;*/
		}

%%