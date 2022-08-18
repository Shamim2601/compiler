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
extern ofstream log_file;
extern ofstream error_file;

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
			log_file<<"Line no "<<line_count<<" : Comment found."<<endl<<endl;
			for(int i = 0; i< strlen(yytext); i++)
			{
				if(yytext[i]=='\n')
				{
					line_count++;
				}
			} 
		}

"if"	{
			SymbolInfo* si = new SymbolInfo(yytext, "IF");
			yylval.s_info = si;
			return IF;
		}
		
"else"	{
			SymbolInfo* si = new SymbolInfo(yytext, "ELSE");
			yylval.s_info = si;
			return ELSE;
		}

"for"	{
			SymbolInfo* si = new SymbolInfo(yytext, "FOR");
			yylval.s_info = si;
			return FOR;
		}

"while"	{
			SymbolInfo* si = new SymbolInfo(yytext, "WHILE");
			yylval.s_info = si;
			return WHILE;
		}

"do"	{
			SymbolInfo* si = new SymbolInfo(yytext, "DO");
			yylval.s_info = si;
			return DO;
		}

"int"	{
			SymbolInfo* si = new SymbolInfo(yytext, "INT");
			yylval.s_info = si;
			return INT;
		}

"char"	{
			SymbolInfo* si = new SymbolInfo(yytext, "CHAR");
			yylval.s_info = si;
			return CHAR;
		}

"float"	{
			SymbolInfo* si = new SymbolInfo(yytext, "FLOAT");
			yylval.s_info = si;
			return FLOAT;
		}

"double"	{
			SymbolInfo* si = new SymbolInfo(yytext, "DOUBLE");
			yylval.s_info = si;
			return DOUBLE;
		}

"void"	{
			SymbolInfo* si = new SymbolInfo(yytext, "VOID");
			yylval.s_info = si;
			return VOID;
		}

"return"	{
			SymbolInfo* si = new SymbolInfo(yytext, "RETURN");
			yylval.s_info = si;
			return RETURN;
		}

"default"	{
			SymbolInfo* si = new SymbolInfo(yytext, "DEFAULT");
			yylval.s_info = si;
			return DEFAULT;
		}

"continue"	{
			SymbolInfo* si = new SymbolInfo(yytext, "CONTINUE");
			yylval.s_info = si;
			return  CONTINUE;
		}

"println"	{
			SymbolInfo* si = new SymbolInfo(yytext, "PRINTLN");
			yylval.s_info = si;
			return PRINTLN;
		}


{ADDOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "ADDOP");
			yylval.s_info = si;
			return ADDOP;
		}

{MULOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "MULOP");
			yylval.s_info = si;
			return MULOP;
		}

{INCOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "INCOP");
			yylval.s_info = si;
			return INCOP;
		}

{DECOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "DECOP");
			yylval.s_info = si;
			return DECOP;
		}

{RELOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "RELOP");
			yylval.s_info = si;
			return RELOP;
		}

{ASSIGNOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "ASSIGNOP");
			yylval.s_info = si;
			return ASSIGNOP;
		}

{LOGICOP}		{
			SymbolInfo* si = new SymbolInfo(yytext, "LOGICOP");
			yylval.s_info = si;
			return LOGICOP;
		}

{NOT}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return NOT;
		}

{LPAREN}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return LPAREN;
		}

{RPAREN}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return RPAREN;
		}
		
{LCURL}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return LCURL;
		}

{RCURL}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return RCURL;
		}

{LTHIRD}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return LTHIRD;
		}

{RTHIRD}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return RTHIRD;
		}

{COMMA}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
			return COMMA;
		}

{SEMICOLON}		{
			SymbolInfo* si = new SymbolInfo(yytext);
			yylval.s_info = si;
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
			SymbolInfo* si = new SymbolInfo(yytext, "CONST_INT");
			yylval.s_info = si;
			return CONST_INT;
			
		}	

{CONST_FLOAT}	{
			SymbolInfo* si = new SymbolInfo(yytext, "CONST_FLOAT");
			yylval.s_info = si;
			return CONST_FLOAT;
		}	

{CONST_CHAR}	{
			SymbolInfo* si = new SymbolInfo(yytext, "CONST_CHAR");
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
		/*
			error_file<<"Error at line "<<line_count<<" : Unrecognized token found."<<endl<<endl;
			num_of_error++;
		*/
		}

%%