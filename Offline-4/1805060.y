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
		if(first_line.find("PUSH BX")!=string::npos){
			getline(reader,second_line);
			
			if(second_line.find("POP BX")!=string::npos)
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

%type<s_info> start program unit var_declaration func_declaration func_definition
%type<s_info> parameter_list compound_statement statements declaration_list statement if_statement
%type<s_info> expression_statement expression logic_expression variable rel_expression
%type<s_info> simple_expression term unary_expression factor argument_list arguments

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

start : program
	{
		//write your code in this block in all the similar blocks below
		add_log(line_count, "start : program");
		
		s_table.print_all(log_file);
	}
	;

program : program unit 
		{
			add_log(line_count, "program : program unit");
			
		}

	| unit
		{
			add_log(line_count, "program : unit");
			
		}
	;

unit : var_declaration
		{
			add_log(line_count, "unit : var_declaration");
			
		}

     | func_declaration
	 	{
			add_log(line_count, "unit : func_declaration");
			
		}

     | func_definition
	 	{
			add_log(line_count, "unit : func_definition");
			
		}			
     ;
    
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
			{
				add_log(line_count, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
				

				$2->setSize(-1);
				s_table.insert($2);
			}

		| type_specifier ID LPAREN RPAREN SEMICOLON
			{
				add_log(line_count, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
				

				$2->setSize(-1);
				s_table.insert($2);
			}
		;
	 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{
					add_log(line_count, "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");

					$2->setSize(-1);
					s_table.insert($2);
				}

		| type_specifier ID LPAREN RPAREN
				{
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN compound_statement");

					$2->setSize(-1);
					s_table.insert($2);

					asm_code+= "\n"+$2->getName()+" PROC\t;func_definition";
					if($2->getName()=="main")
					{
						asm_code+= "\nMOV AX,@DATA \nMOV DS,AX\t;initializing data segment\n";
					}
					
				}
			compound_statement
				{
					if($2->getName()=="main")
					{
						asm_code+= "\n\nMOV AH, 4CH \nINT 21H\t\t;return 0";
					}

					asm_code+= "\n"+$2->getName()+" ENDP";
				}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
			{
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier ID");
				
			}

		| parameter_list COMMA type_specifier
			{
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");
				
			}

 		| type_specifier ID
			{
				add_log(line_count, "parameter_list : type_specifier ID");
				
			}

		| type_specifier
			{
				add_log(line_count, "parameter_list : type_specifier");
				
			}
 		;

 		
compound_statement : LCURL
				{
					add_log(line_count, "compound_statement : LCURL statements RCURL");
					s_table.enter_scope();
				}
				statements
				{

				}
				RCURL
				{
					s_table.exit_scope();
				}

 		    | LCURL 
				{
					add_log(line_count, "compound_statement : LCURL RCURL");
					s_table.enter_scope();
				}
				RCURL
				{
					s_table.exit_scope();
				}
 		    ;

var_declaration : type_specifier declaration_list SEMICOLON
			{
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");	
				s_table.print_all(log_file);
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
				
				string tmp_name = newTemp();
				$3->set_asm_var(tmp_name);
				s_table.insert($3);

				data_segment+= tmp_name+" DW ?\n";
				asm_code+= "\nMOV "+tmp_name+", 0\t;initializing variable with 0";
			}

 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		  	{
				add_log(line_count, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
				
			}

 		  | ID
		  {
			add_log(line_count, "declaration_list : ID");

			string tmp_name = newTemp();
			$1->set_asm_var(tmp_name);
			s_table.insert($1);

			data_segment+= tmp_name+" DW ?\n";
			asm_code+= "\nMOV "+tmp_name+", 0\t;initializing variable with 0";
		  }

 		  | ID LTHIRD CONST_INT RTHIRD
		  		{
					add_log(line_count, "declaration_list : ID LTHIRD CONST_INT RTHIRD");

				}
 		  ;

statements : statement
			{
				add_log(line_count, "statements : statement");
				
			}

	   | statements statement
	   		{
				add_log(line_count, "statements : statements statement");
				
			}
	   ;

if_statement : IF LPAREN expression RPAREN statement
			{
				add_log(line_count, "if_statement : IF LPAREN expression RPAREN statement");
				
			}
	   
statement : var_declaration
			{
				add_log(line_count, "statement : var_declaration");
				
			}

	  | expression_statement
	  		{
				add_log(line_count, "statement : expression_statement");
				
			}

	  | compound_statement
	  		{
				add_log(line_count, "statement : compound_statement");
				
			}

	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  		{
				add_log(line_count, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
			}

	  | if_statement %prec LOWER_THAN_ELSE
	  		{
				add_log(line_count, "statement : if_statement");
				
			}

	  | if_statement ELSE statement
	  		{
				add_log(line_count, "statement : if_statement ELSE statement");
				
			}

	  | WHILE LPAREN expression RPAREN statement
	  		{
				add_log(line_count, "statement : WHILE LPAREN expression RPAREN statement");
				
			}

	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  		{
				add_log(line_count, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

				asm_code+= "\n\nMOV AX, "+ s_table.look_up($3->getName())->get_asm_var();
				asm_code+= "\nCALL PRINT\t;PRINTLN LPAREN ID RPAREN SEMICOLON";
			}

	  | RETURN expression SEMICOLON
	  		{
				add_log(line_count, "statement : RETURN expression SEMICOLON");
			}
	  ;
	  
expression_statement : SEMICOLON	
				{
					add_log(line_count, "expression_statement : SEMICOLON");
				}

			| expression SEMICOLON 
				{
					add_log(line_count, "expression_statement : expression SEMICOLON");
					
				}
			;
	  
variable : ID 	
		{
			add_log(line_count, "variable : ID");

			string var_name = s_table.look_up($1->getName())->get_asm_var();
			$$->set_asm_var(var_name);

			asm_code+= "\nPUSH "+ var_name;
		}	

	 | ID LTHIRD expression RTHIRD 
	 	{
			add_log(line_count, "variable : ID LTHIRD expression RTHIRD");

		}
	 ;
	 
expression : logic_expression	
			{
				add_log(line_count, "expression : logic_expression");
				
			}

	   | variable ASSIGNOP logic_expression 
	   		{
				add_log(line_count, "expression : variable ASSIGNOP logic_expression");
				
				asm_code+= "\nPOP BX\t;variable ASSIGNOP logic_expression";
				asm_code+= "\nPOP AX";
				string var_name = s_table.look_up($1->getName())->get_asm_var();
				asm_code+= "\nMOV "+var_name+", BX";
			}	
	   ;
			
logic_expression : rel_expression 
			{
				add_log(line_count, "logic_expression : rel_expression");
				
			}	

		 | rel_expression LOGICOP rel_expression 	
		 	{
				add_log(line_count, "logic_expression : rel_expression LOGICOP rel_expression");
				
				asm_code+= "\nPOP BX\t;rel_expression LOGICOP rel_expression";
				asm_code+= "\nPOP AX";

				string L1 = newLabel();
				string L0 = newLabel();
				string L = newLabel();

				if($2->getName()=="&&")
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
		 ;
			
rel_expression	: simple_expression 
			{
				add_log(line_count, "rel_expression	: simple_expression");
				
			}

		| simple_expression RELOP simple_expression	
			{
				add_log(line_count, "rel_expression : simple_expression RELOP simple_expression");
				

				asm_code+= "\nPOP BX\t;simple_expression RELOP simple_expression";
				asm_code+= "\nPOP AX";

				string L1 = newLabel();
				string L0 = newLabel();
				string L = newLabel();

				if($2->getName()=="<")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJGE "+L0;
				}
				else if($2->getName()=="<=")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJG "+L0;
				}
				else if($2->getName()==">")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJLE "+L0;
				}
				else if($2->getName()==">=")
				{
					asm_code+= "\nCMP AX, BX";
					asm_code+= "\nJL "+L0;
				}
				else if($2->getName()=="==")
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
		;
				
simple_expression : term 
			{
				add_log(line_count, "simple_expression : term");
				
			}

		  | simple_expression ADDOP term 
		  	{
				add_log(line_count, "simple_expression : simple_expression ADDOP term");
				
				asm_code+= "\nPOP BX\t;simple_expression ADDOP term";
				asm_code+= "\nPOP AX";
				if($2->getName()=="+") asm_code+= "\nADD BX, AX";
				else asm_code+= "\nSUB BX, AX";
				asm_code+= "\nPUSH BX";
			}
		  ;
					
term :	unary_expression
		{
			add_log(line_count, "term : unary_expression");
			
		}

     |  term MULOP unary_expression
	 	{
				add_log(line_count, "term : term MULOP unary_expression");
				
				asm_code+= "\nPOP BX\t;term MULOP unary_expression";
				asm_code+= "\nPOP AX";
				if($2->getName()=="*")
				{
					asm_code+= "\nMUL BX";
					asm_code+= "\nMOV BX, AX";
				}else
				{
					asm_code+= "\nXOR DX, DX";
					asm_code+= "\nDIV BX";
					if($2->getName()=="/") asm_code+= "\nMOV BX, AX";
					else asm_code+= "\nMOV BX, DX";
				}
				asm_code+= "\nPUSH BX";
		}
     ;

unary_expression : ADDOP unary_expression  
			{
				add_log(line_count, "unary_expression : ADDOP unary_expression");
				
				if($1->getName()=="-")
				{
					asm_code+= "\nPOP BX\t;ADDOP unary_expression";
					asm_code+= "\nNEG BX\nPUSH BX";
				}
			}

		 | NOT unary_expression 
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

		 | factor 
		 	{
				add_log(line_count, "unary_expression	: factor");
				
			}
		 ;
	
factor	: variable
		{
			add_log(line_count, "factor	: variable");
			
		}

	| ID LPAREN argument_list RPAREN
			{
				add_log(line_count, "factor : ID LPAREN argument_list RPAREN");
				
			}

	| LPAREN expression RPAREN
			{
				add_log(line_count, "factor : LPAREN expression RPAREN");
				
			}

	| CONST_INT 
		{
			add_log(line_count, "factor	: CONST_INT");

			asm_code+= "\nPUSH "+$1->getName();
		}

	| CONST_FLOAT
		{
			add_log(line_count, "factor	: CONST_FLOAT");
		}

	| variable INCOP 
		{
			add_log(line_count, "factor	: variable INCOP");

			string var_name = s_table.look_up($1->getName())->get_asm_var();
			asm_code+= "\nINC "+var_name+"\t;variable INCOP";
			asm_code+= "\nPUSH "+var_name;
		}

	| variable DECOP
		{
			add_log(line_count, "factor	: variable DECOP");
			
			string var_name = s_table.look_up($1->getName())->get_asm_var();
			asm_code+= "\nDEC "+var_name+"\t;variable DECOP";
			asm_code+= "\nPUSH "+var_name;
		}
	;
	
argument_list : arguments
		{
			add_log(line_count, "argument_list : arguments");
			
		}
		;
	
arguments : arguments COMMA logic_expression
		{
			add_log(line_count, "argument_list : arguments COMMA logic_expression");
			
		}

	      | logic_expression
		{
			add_log(line_count, "argument_list : logic_expression");
			
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

