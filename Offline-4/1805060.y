%{
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

int yyparse(void);
int yylex(void);

void add_log(int lc, string rule)
{
	log_file<<"Line "<<lc<<": "<<rule<<endl<<endl;
}

void add_error(int lc, string msg, string name)
{
	cout<<"Error at line "<<lc<<": "<<msg<<" "<<name<<endl<<endl;
	error_file<<"Error at line "<<lc<<": "<<msg<<" "<<name<<endl<<endl;
	log_file<<"Error at line "<<lc<<": "<<msg<<" "<<name<<endl<<endl;
	num_of_error++;
}

void yyerror(char *s)
{
	//write your code
	add_error(line_count, s, "");
}

int labelCount = 0;
int tempCount = 0;
string data = "";

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

%}

%union {
	SymbolInfo *s_info;
	vector<SymbolInfo*>* siList;
}

%token<s_info> IF ELSE FOR DO WHILE CONTINUE DEFAULT RETURN VOID  
%token<s_info> LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD  INCOP DECOP ASSIGNOP NOT  
%token<s_info> PRINTLN COMMA SEMICOLON

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

start : program
	{
		//write your code in this block in all the similar blocks below
		add_log(line_count, "start : program");
		$$ = new vector<SymbolInfo*>();

		s_table.print_all(log_file);
	}
	;

program : program unit 
		{
			add_log(line_count, "program : program unit");
			$$ = new vector<SymbolInfo*>();
		}

	| unit
		{
			add_log(line_count, "program : unit");
			$$ = new vector<SymbolInfo*>();
		}
	;

unit : var_declaration
		{
			add_log(line_count, "unit : var_declaration");
			$$ = new vector<SymbolInfo*>();
		}

     | func_declaration
	 	{
			add_log(line_count, "unit : func_declaration");
			$$ = new vector<SymbolInfo*>();
		}

     | func_definition
	 	{
			add_log(line_count, "unit : func_definition");
			$$ = new vector<SymbolInfo*>();
		

			if($1->at(0)->getName()=="main")
			{
				code+= "\nMOV AH, 4CH \nINT 21H";
			}

			code+= "\n"+$1->at(0)->getName()+" ENDP";

		}			
     ;
    
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
			{
				add_log(line_count, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
				$$ = new vector<SymbolInfo*>();

				$2->setSize(-1);
				s_table.insert($2);
			}

		| type_specifier ID LPAREN RPAREN SEMICOLON
			{
				add_log(line_count, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
				$$ = new vector<SymbolInfo*>();

				$2->setSize(-1);
				s_table.insert($2);
			}
		;
	 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{
					add_log(line_count, "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
					$$ = new vector<SymbolInfo*>();
					$$->push_back($2);

					$2->setSize(-1);
					s_table.insert($2);
				}

		| type_specifier ID LPAREN RPAREN compound_statement
				{
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN compound_statement");
					$$ = new vector<SymbolInfo*>();
					$$->push_back($2);

					$2->setSize(-1);
					s_table.insert($2);

					code+= "\n"+$2->getName()+" PROC";
					if($2->getName()=="main")
					{
						code+= "\nMOV AX,@DATA \nMOV DS,AX";
					}
					
				}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
			{
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier ID");
				$$ = new vector<SymbolInfo*>();
			}

		| parameter_list COMMA type_specifier
			{
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");
				$$ = new vector<SymbolInfo*>();
			}

 		| type_specifier ID
			{
				add_log(line_count, "parameter_list : type_specifier ID");
				$$ = new vector<SymbolInfo*>();
			}

		| type_specifier
			{
				add_log(line_count, "parameter_list : type_specifier");
				$$ = new vector<SymbolInfo*>();
			}
 		;

 		
compound_statement : LCURL statements RCURL
				{
					add_log(line_count, "compound_statement : LCURL statements RCURL");
					$$ = new vector<SymbolInfo*>();
				}

 		    | LCURL RCURL
				{
					add_log(line_count, "compound_statement : LCURL RCURL");
					$$ = new vector<SymbolInfo*>();
				}
 		    ;

var_declaration : type_specifier declaration_list SEMICOLON
			{
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");
				$$ = new vector<SymbolInfo*>();

			}
 		 ;

type_specifier	: INT
		{
			add_log(line_count, "type_specifier : INT");
		}

 		| FLOAT
		{
			add_log(line_count, "type_specifier : FLOAT");
		}

 		| VOID
		{
			add_log(line_count, "type_specifier : VOID");
		}
 		;


declaration_list : declaration_list COMMA ID
			{
				add_log(line_count, "declaration_list : declaration_list COMMA ID");
				$$ = new vector<SymbolInfo*>();

			}

 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		  	{
				add_log(line_count, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
				$$ = new vector<SymbolInfo*>();

			}

 		  | ID
		  {
			add_log(line_count, "declaration_list : ID");
		  }

 		  | ID LTHIRD CONST_INT RTHIRD
		  		{
					add_log(line_count, "declaration_list : ID LTHIRD CONST_INT RTHIRD");
					$$ = new vector<SymbolInfo*>();

				}
 		  ;

statements : statement
			{
				add_log(line_count, "statements : statement");
				$$ = new vector<SymbolInfo*>();
			}

	   | statements statement
	   		{
				add_log(line_count, "statements : statements statement");
				$$ = new vector<SymbolInfo*>();
			}
	   ;
	   
statement : var_declaration
			{
				add_log(line_count, "statement : var_declaration");
				$$ = new vector<SymbolInfo*>();
			}

	  | expression_statement
	  		{
				add_log(line_count, "statement : expression_statement");
				$$ = new vector<SymbolInfo*>();
			}

	  | compound_statement
	  		{
				add_log(line_count, "statement : compound_statement");
				$$ = new vector<SymbolInfo*>();
			}

	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  		{
				add_log(line_count, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
				$$ = new vector<SymbolInfo*>();
			}

	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
	  		{
				add_log(line_count, "statement : IF LPAREN expression RPAREN statement");
				$$ = new vector<SymbolInfo*>();
			}

	  | IF LPAREN expression RPAREN statement ELSE statement
	  		{
				add_log(line_count, "statement : IF LPAREN expression RPAREN statement ELSE statement");
				$$ = new vector<SymbolInfo*>();
			}

	  | WHILE LPAREN expression RPAREN statement
	  		{
				add_log(line_count, "statement : WHILE LPAREN expression RPAREN statement");
				$$ = new vector<SymbolInfo*>();
			}

	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  		{
				add_log(line_count, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
				$$ = new vector<SymbolInfo*>();
			}

	  | RETURN expression SEMICOLON
	  		{
				add_log(line_count, "statement : RETURN expression SEMICOLON");
				$$ = new vector<SymbolInfo*>();
			}
	  ;
	  
expression_statement : SEMICOLON	
				{
					add_log(line_count, "expression_statement : SEMICOLON");
				}

			| expression SEMICOLON 
				{
					add_log(line_count, "expression_statement : expression SEMICOLON");
					$$ = new vector<SymbolInfo*>();
				}
			;
	  
variable : ID 	
		{
			add_log(line_count, "variable : ID");

			s_table.insert($1);
		}	

	 | ID LTHIRD expression RTHIRD 
	 	{
			add_log(line_count, "variable : ID LTHIRD expression RTHIRD");

					s_table.insert($1);
		}
	 ;
	 
expression : logic_expression	
			{
				add_log(line_count, "expression : logic_expression");
				$$ = new vector<SymbolInfo*>();
			}

	   | variable ASSIGNOP logic_expression 
	   		{
				add_log(line_count, "expression : variable ASSIGNOP logic_expression");
				$$ = new vector<SymbolInfo*>();
			}	
	   ;
			
logic_expression : rel_expression 
			{
				add_log(line_count, "logic_expression : rel_expression");
				$$ = new vector<SymbolInfo*>();
			}	

		 | rel_expression LOGICOP rel_expression 	
		 	{
				add_log(line_count, "logic_expression : rel_expression LOGICOP rel_expression");
				$$ = new vector<SymbolInfo*>();
			}
		 ;
			
rel_expression	: simple_expression 
			{
				add_log(line_count, "rel_expression	: simple_expression");
				$$ = new vector<SymbolInfo*>();
			}

		| simple_expression RELOP simple_expression	
			{
				add_log(line_count, "rel_expression : simple_expression RELOP simple_expression");
				$$ = new vector<SymbolInfo*>();
			}
		;
				
simple_expression : term 
			{
				add_log(line_count, "simple_expression : term");
				$$ = new vector<SymbolInfo*>();
			}

		  | simple_expression ADDOP term 
		  	{
				add_log(line_count, "simple_expression : simple_expression ADDOP term");
				$$ = new vector<SymbolInfo*>();
			}
		  ;
					
term :	unary_expression
		{
			add_log(line_count, "term : unary_expression");
			$$ = new vector<SymbolInfo*>();
		}

     |  term MULOP unary_expression
	 	{
				add_log(line_count, "term : term MULOP unary_expression");
				$$ = new vector<SymbolInfo*>();
		}
     ;

unary_expression : ADDOP unary_expression  
			{
				add_log(line_count, "unary_expression : ADDOP unary_expression");
				$$ = new vector<SymbolInfo*>();
			}

		 | NOT unary_expression 
		 	{
				add_log(line_count, "unary_expression : NOT unary_expression");
				$$ = new vector<SymbolInfo*>();
			}

		 | factor 
		 	{
				add_log(line_count, "unary_expression	: factor");
				$$ = new vector<SymbolInfo*>();
			}
		 ;
	
factor	: variable
		{
			add_log(line_count, "factor	: variable");
			$$ = new vector<SymbolInfo*>();
		}

	| ID LPAREN argument_list RPAREN
			{
				add_log(line_count, "factor : ID LPAREN argument_list RPAREN");
				$$ = new vector<SymbolInfo*>();
			}

	| LPAREN expression RPAREN
			{
				add_log(line_count, "factor : LPAREN expression RPAREN");
				$$ = new vector<SymbolInfo*>();
			}

	| CONST_INT 
		{
			add_log(line_count, "factor	: CONST_INT");
		}

	| CONST_FLOAT
		{
			add_log(line_count, "factor	: CONST_FLOAT");
		}

	| variable INCOP 
		{
			add_log(line_count, "factor	: variable INCOP");
			$$ = new vector<SymbolInfo*>();
		}

	| variable DECOP
		{
			add_log(line_count, "factor	: variable DECOP");
			$$ = new vector<SymbolInfo*>();
		}
	;
	
argument_list : arguments
		{
			add_log(line_count, "argument_list : arguments");
			$$ = new vector<SymbolInfo*>();
		}
		;
	
arguments : arguments COMMA logic_expression
		{
			add_log(line_count, "argument_list : arguments COMMA logic_expression");
			$$ = new vector<SymbolInfo*>();
		}

	      | logic_expression
		{
			add_log(line_count, "argument_list : logic_expression");
			$$ = new vector<SymbolInfo*>();
		}
	    ;


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
	code_file.open("code_file.asm");


	code_file<<".MODEL SMALL"<<endl<<".STACK 400H"<<endl<<".DATA"<<endl;

	yyin= fin;
	yyparse();

	code_file<<code;
	code_file<<"\n\nEND MAIN";

	log_file<<"Total lines: "<<line_count<<"\nTotal errors: "<<num_of_error<<"\n";
	fclose(yyin);
	log_file.close();
	error_file.close();
	code_file.close();

	return 0;
}

