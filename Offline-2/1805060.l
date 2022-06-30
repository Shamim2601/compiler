%option noyywrap

%{
#include<iostream>
#include<bits/stdc++.h>
#include "SymbolTable.cpp"

int line_count=1;
int num_of_error = 0;
string ml_str="";
SymbolTable st(7);

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

FILE *logout;
FILE *tokenout;

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NUMBER {DIGIT}+
NEWLINE \r?\n

ADDOP [+-]
MULOP [*/%]
INCOP "++"|"--"
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

IDENTIFIERS [A-Za-z_][a-zA-Z0-9_]*
INTEGER_LITERALS {NUMBER}
FLOATING_POINT_LITERALS {NUMBER}?(\.{NUMBER})?([Ee][+-]?{NUMBER})?

EMPTY \'\'
SP_CHAR [ntf\\'rabv0]
CHARACTER_LITERAL (\'[^\\]\')|(\'\\{SP_CHAR}\')

STRING \"([^\"\n]|(\\[\n])|(\"))*\"
SL_COMMENT \/\/.*(\\(\r)?\n.*)*
ML_COMMENT ("/*")([^*]|\*[^\/])*("*/")
COMMENT {SL_COMMENT}|{ML_COMMENT}

DPOINT_ERROR {NUMBER}\.{NUMBER}(\.{NUMBER}?)+
ILL_FORM_NUM {DIGIT}*(\.{DIGIT}*)*[Ee][+-]?{DIGIT}*(\.{DIGIT}*)+
INVALID {NUMBER}({LETTER}+{NUMBER}?)+
MULTICHAR (\'[^\\].+\')|(\'\\{SP_CHAR}.+\')
UNFINISHED_CHAR (\'[^\\])|(\'\\{SP_CHAR})
UNFINISHED_STRING \"([^\"\n]|(\\[\n]))*
UNFINISHED_COMMENT ("/*")([^*]|\*[^\/])*
UNRECOGNIZED .

%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

{COMMENT}	{
			fprintf(logout,"Line no %d: comment found\n\n",line_count);
			for(int i = 0; i<strlen(yytext); i++)
			{
				if(yytext[i]=='\n')
				{
					line_count++;
				}
			}
		}

{UNFINISHED_COMMENT}	{
			fprintf(logout,"Error! Line no: %d ; Type: Unfinished Comment.\n\n",line_count);
			num_of_error++;
			for(int i = 0; i<strlen(yytext); i++)
			{
				if(yytext[i]=='\n')
				{
					line_count++;
				}
			}
		}

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
		}

"for"	{
			fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
		}

"while"	{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
		}

"do"	{
			fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
		}

"break"	{
			fprintf(tokenout,"<BREAK>");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);
		}

"int"	{
			fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
		}

"char"	{
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
		}

"float"	{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);
		}

"double"	{
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);
		}

"void"	{
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
		}

"return"	{
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
		}

"switch"	{
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
		}

"case"	{
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
		}

"default"	{
			fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
		}

"continue"	{
			fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
		}

{ADDOP}		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
		}

{MULOP}		{
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
		}

{INCOP}		{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
		}

{RELOP}		{
			fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
		}

{ASSIGNOP}		{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n\n",line_count,yytext);
		}

{LOGICOP}		{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
		}

{NOT}		{
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
		}

{LPAREN}		{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
		}

{RPAREN}		{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
		}
		
{LCURL}		{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			st.enter_scope();
		}

{RCURL}		{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			st.exit_scope();
		}

{LTHIRD}		{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
		}

{RTHIRD}		{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
		}

{COMMA}		{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
		}

{SEMICOLON}		{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
		}


{EMPTY}	{
			fprintf(logout,"Error! Line no: %d ; Type: Empty character.\n\n",line_count);
			num_of_error++;
		}

{IDENTIFIERS}	{
			fprintf(tokenout,"<ID,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
			st.insert(yytext, "ID", logout);
		}

{INTEGER_LITERALS}	{
			fprintf(tokenout,"<CONST_INT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
			st.insert(yytext, "CONST_INT", logout);
		}	

{FLOATING_POINT_LITERALS}	{
			fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
			st.insert(yytext, "CONST_FLOAT", logout);
		}	

{CHARACTER_LITERAL}	{
			fprintf(tokenout,"<CONST_CHAR,%c>", convert_char(yytext));
			fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %c found\n\n",line_count, convert_char(yytext));
			st.insert(yytext, "CONST_CHAR", logout);
		}

{STRING}	{
			for(int i = 0; i<strlen(yytext); i++)
			{
				char ch = yytext[i];
				if(yytext[i]=='"'){}
				else if(yytext[i]=='\n')
				{
					line_count++;
					ml_str.push_back(yytext[i]);
				}
				else if(ch=='\t'|| ch=='\r'||ch=='\f'||ch=='\v')
				{
					ml_str.push_back(ch);
				}
				else{
					ml_str.push_back(yytext[i]);
				}
			}
			fprintf(tokenout,"<STRING, %s >", ml_str.c_str());
			fprintf(logout,"Line no %d: String: \"%s\" found\n\n",line_count, ml_str.c_str());
		}

{INVALID}	{
			fprintf(logout,"Error! Line no: %d ; Type: Invalid prefix of identifier or invalid suffix of number %s.\n\n",line_count, yytext);
			num_of_error++;
		}

{MULTICHAR}	{
			fprintf(logout,"Error! Line no: %d ; Type: Multiple character constant %s.\n\n",line_count, yytext);
			num_of_error++;
		}

{UNFINISHED_CHAR}	{
			fprintf(logout,"Error! Line no: %d ; Type: Unfinished character constant %s.\n\n",line_count, yytext);
			num_of_error++;
		}

{UNFINISHED_STRING}	{
			fprintf(logout,"Error! Line no: %d ; Type: Unfinished String %s\n\n",line_count, yytext);
			num_of_error++;
		}


{DPOINT_ERROR}	{
			fprintf(logout,"Error! Line no: %d ; Type: Multiple decimal points in %s.\n\n",line_count, yytext);
			num_of_error++;
		}

{ILL_FORM_NUM}	{
			fprintf(logout,"Error! Line no: %d ; Type: Ill formed number  %s.\n\n",line_count, yytext);
			num_of_error++;
		}

{UNRECOGNIZED}	{
			fprintf(logout,"Error! Line no: %d ; Type: Unrecognized character %s.\n\n",line_count, yytext);
			num_of_error++;
		}

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout = fopen("1805060_log.txt", "w");
	tokenout= fopen("1805060_token.txt","w");

	yyin= fin;
	yylex();
	st.print_all(logout);
	fprintf(logout,"Total lines: %d\nTotal errors: %d\n",line_count,num_of_error);
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
