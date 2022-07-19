%{
#include<bits/stdc++.h>
#include "SymbolTable.cpp"

using namespace std;



extern FILE *yyin;

SymbolTable s_table(30);
FILE *inp_file;
ofstream log_file;
ofstream error_file;

int line_count = 1;
int num_of_error = 0;

string type;

int yyparse(void);
int yylex(void);

void yyerror(char *s)
{
	//write your code
	//fprintf(error_file, "Syntax error detected by parser at line: %d : \"%s\"\n", line_count, s);
	//fprintf(log_file, "Syntax error detected by parser at line: %d : \"%s\"\n", line_count, s);
	num_of_error++;
}

void add_log(int lc, string rule)
{
	log_file<<"Line no "<<lc<<": "<<rule<<endl<<endl;
}

void add_error(int lc, string msg)
{
	error_file<<"Error at line "<<lc<<": "<<msg<<endl<<endl;
	log_file<<"Error at line "<<lc<<": "<<msg<<endl<<endl;
}

%}

%union {
	SymbolInfo *s_info;
	vector<SymbolInfo*>* siList;
}

%token IF ELSE FOR DO WHILE CONTINUE DEFAULT RETURN VOID  
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD  INCOP DECOP ASSIGNOP NOT  
%token PRINTLN COMMA SEMICOLON

%token<s_info> ID CONST_INT CONST_FLOAT CONST_CHAR INT FLOAT DOUBLE CHAR
%token<s_info> ADDOP MULOP RELOP LOGICOP
%type<s_info> type_specifier 

%type<siList> start program unit var_declaration func_declaration func_definition
%type<siList> parameter_list compound_statement statements declaration_list statement
%type<siList> expression_statement expression logic_expression variable rel_expression
%type<siList> simple_expression term unary_expression factor argument_list arguments

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

/*
start : program
	{
		//write your code in this block in all the similar blocks below
		fprintf(log_file, "Line: %d    :start : program\n\n",line_count);
	}
	;

program : program unit 
		{
			fprintf(log_file, "Line: %d    :program : program unit\n\n",line_count);
			
		}
	| unit
		{

		}
	;
	
unit : var_declaration
     | func_declaration
     | func_definition
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		| type_specifier ID LPAREN RPAREN SEMICOLON
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
		| type_specifier ID LPAREN RPAREN compound_statement
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
		| parameter_list COMMA type_specifier
 		| type_specifier ID
		| type_specifier
 		;

 		
compound_statement : LCURL statements RCURL
 		    | LCURL RCURL
 		    ;

*/
var_declaration : type_specifier declaration_list SEMICOLON
			{
				$$ = new vector<SymbolInfo*>();
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");

				string tpsp = $1->getName().c_str();
				if(tpsp== "void")
				{
					add_error(line_count, "Variable type cannot be void");
					num_of_error++;
				}

				log_file<<tpsp<<" ";
		  	    for(int i = 0; i < $2->size(); i++){
		  			$$->push_back($2->at(i));
		  			log_file << $2->at(i)->getName().c_str();
					if(i<$2->size()-1){log_file<<",";}
		  		}
				log_file<<";\n\n";
			}
 		 ;

type_specifier	: INT
		{
			add_log(line_count, "type_specifier : INT");
			log_file<<"int\n\n";
			type = "INT";
		}
 		| FLOAT
		{
			add_log(line_count, "type_specifier : FLOAT");
			log_file<<"float\n\n";
			type = "FLOAT";
		}
 		| VOID
		{
			add_log(line_count, "type_specifier : VOID");
			log_file<<"void\n\n";
			type = "VOID";
		}
 		;
	
declaration_list : declaration_list COMMA ID
			{
				add_log(line_count, "declaration_list : declaration_list COMMA ID");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if(i<$1->size()-1){log_file<<",";}
				}

				log_file<<","<<$3->getName().c_str()<<endl<<endl;
				$$->push_back($3);
			}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
 		  | ID
		  {
			add_log(line_count, "declaration_list : ID");
			log_file<<$1->getName().c_str()<<"\n\n";
			$$ = new vector<SymbolInfo*>();
			$$->push_back($1);
		  }
 		  | ID LTHIRD CONST_INT RTHIRD
 		  ;
/*	

statements : statement
	   | statements statement
	   ;
	   
statement : var_declaration
	  | expression_statement
	  | compound_statement
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  | IF LPAREN expression RPAREN statement
	  | IF LPAREN expression RPAREN statement ELSE statement
	  | WHILE LPAREN expression RPAREN statement
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  | RETURN expression SEMICOLON
	  ;
	  
expression_statement 	: SEMICOLON			
			| expression SEMICOLON 
			;
	  
variable : ID 		
	 | ID LTHIRD expression RTHIRD 
	 ;
	 
 expression : logic_expression	
	   | variable ASSIGNOP logic_expression 	
	   ;
			
logic_expression : rel_expression 	
		 | rel_expression LOGICOP rel_expression 	
		 ;
			
rel_expression	: simple_expression 
		| simple_expression RELOP simple_expression	
		;
				
simple_expression : term 
		  | simple_expression ADDOP term 
		  ;
					
term :	unary_expression
     |  term MULOP unary_expression
     ;

unary_expression : ADDOP unary_expression  
		 | NOT unary_expression 
		 | factor 
		 ;
	
factor	: variable 
	| ID LPAREN argument_list RPAREN
	| LPAREN expression RPAREN
	| CONST_INT 
	| CONST_FLOAT
	| variable INCOP 
	| variable DECOP
	;
	
argument_list : arguments
			  |
			  ;
	
arguments : arguments COMMA logic_expression
	      | logic_expression
	      ;
*/

%%
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

