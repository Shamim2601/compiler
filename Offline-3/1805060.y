%{
#include<bits/stdc++.h>
#include "SymbolTable.cpp"

using namespace std;



extern FILE *yyin;

SymbolTable s_table(7);
FILE *inp_file;
ofstream log_file;
ofstream error_file;

int line_count = 1;
int num_of_error = 0;

string type;

int yyparse(void);
int yylex(void);

void add_log(int lc, string rule)
{
	log_file<<"Line "<<lc<<": "<<rule<<endl<<endl;
}

void add_error(int lc, string msg)
{
	error_file<<"Error at line "<<lc<<": "<<msg<<endl<<endl;
	log_file<<"Error at line "<<lc<<": "<<msg<<endl<<endl;
}

void yyerror(char *s)
{
	//write your code
	add_error(line_count, s);
	num_of_error++;
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
	}
	;

program : program unit 
		{
			add_log(line_count, "program : program unit");

			$$ = new vector<SymbolInfo*>();
			for(int i = 0; i< $1->size(); i++)
			{
				log_file<<$1->at(i)->getName().c_str();
				$$->push_back($1->at(i));

				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
				if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
			}

			for(int i = 0; i< $2->size(); i++)
			{
				log_file<<$2->at(i)->getName().c_str();
				$$->push_back($2->at(i));

				if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
					{log_file << " ";}
				if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
					{log_file << endl;}
			}

			log_file<<endl<<endl;
		}

	| unit
		{
			add_log(line_count, "program : unit");

			$$ = new vector<SymbolInfo*>();
			for(int i = 0; i< $1->size(); i++)
			{
				log_file<<$1->at(i)->getName().c_str();
				$$->push_back($1->at(i));

				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
				if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
			}
			log_file<<endl<<endl;
		}
	;

unit : var_declaration
		{
			add_log(line_count, "unit : var_declaration");

			$$ = new vector<SymbolInfo*>();
			for(int i = 0; i< $1->size(); i++)
			{
				log_file<<$1->at(i)->getName().c_str();
				$$->push_back($1->at(i));
				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" )
					{log_file << " ";}
			}
			log_file<<endl<<endl;
		}

     | func_declaration
	 	{
			add_log(line_count, "unit : func_declaration");

			$$ = new vector<SymbolInfo*>();
			for(int i = 0; i< $1->size(); i++)
			{
				log_file<<$1->at(i)->getName().c_str();
				$$->push_back($1->at(i));
				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" )
					{log_file << " ";}
			}
			log_file<<endl<<endl;
		}

     | func_definition
	 	{
			add_log(line_count, "unit : func_definition");

			$$ = new vector<SymbolInfo*>();
			for(int i = 0; i< $1->size(); i++)
			{
				log_file<<$1->at(i)->getName().c_str();
				$$->push_back($1->at(i));

				if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
				if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
			}
			log_file<<endl<<endl;
		}
     ;
    
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
			{
				add_log(line_count, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");

				$$ = new vector<SymbolInfo*>();
				string fName = $2->getName().c_str();
				if(s_table.look_up(fName)!=NULL)
				{
					add_log(line_count, "Multiple declaration of "+fName);
					add_error(line_count, "Multiple declaration of "+fName);
					num_of_error++;
				}

				log_file << $1->getName().c_str() << " " << $2->getName().c_str() << $3->getName().c_str();
				for(int i=0; i<$4->size();i++)
				{
					log_file<<$4->at(i)->getName();
					if($4->at(i)->getName() == "int" || $4->at(i)->getName() == "float")
					{log_file << " ";}
				}
				log_file<<$5->getName().c_str()<< $6->getName().c_str() << "\n\n";

				$$->push_back($1);
				$$->push_back($2);
				$$->push_back($3);
				for(int i=0; i<$4->size();i++)
				{
					$$->push_back($4->at(i));
				}
				$$->push_back($5);
				$$->push_back($6);
			}

		| type_specifier ID LPAREN RPAREN SEMICOLON
			{
				add_log(line_count, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");

				$$ = new vector<SymbolInfo*>();
				string fName = $2->getName().c_str();
				if(s_table.look_up(fName)!=NULL)
				{
					add_log(line_count, "Multiple declaration of "+fName);
					add_error(line_count, "Multiple declaration of "+fName);
					num_of_error++;
				}

				log_file << $1->getName().c_str() << " " << $2->getName().c_str() << $3->getName().c_str()<<$4->getName().c_str()<< $5->getName().c_str() << "\n\n";

				$$->push_back($1);
				$$->push_back($2);
				$$->push_back($3);
				$$->push_back($4);
				$$->push_back($5);
			}
		;
	 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{
					add_log(line_count, "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");

					$$ = new vector<SymbolInfo*>();
					log_file<<$1->getName().c_str()<<" "<<$2->getName().c_str()<<$3->getName().c_str();
					$$->push_back($1);
					$$->push_back($2);
					$$->push_back($3);
					for(int i = 0; i< $4->size(); i++)
					{
						log_file<<$4->at(i)->getName().c_str();
						$$->push_back($4->at(i));
						if($4->at(i)->getName() == "int" || $4->at(i)->getName() == "float")
						{log_file << " ";}
					}
					log_file<<$5->getName().c_str();
					$$->push_back($5);
					for(int i = 0; i< $6->size(); i++)
					{
						log_file<<$6->at(i)->getName().c_str();
						$$->push_back($6->at(i));

						if($6->at(i)->getName() == "int" || $6->at(i)->getName() == "float" || $6->at(i)->getName() == "void" || $6->at(i)->getName() == "return")
						{log_file << " ";}
						if($6->at(i)->getName() == ";" || $6->at(i)->getName() == "{" || $6->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<endl<<endl;
				}

		| type_specifier ID LPAREN RPAREN compound_statement
				{
					add_log(line_count, "func_definition : type_specifier ID LPAREN RPAREN compound_statement");

					$$ = new vector<SymbolInfo*>();
					log_file<<$1->getName().c_str()<<" "<<$2->getName().c_str()<<$3->getName().c_str()<<$4->getName().c_str();
					$$->push_back($1);
					$$->push_back($2);
					$$->push_back($3);
					$$->push_back($4);
					for(int i = 0; i< $5->size(); i++)
					{
						log_file<<$5->at(i)->getName().c_str();
						$$->push_back($5->at(i));

						if($5->at(i)->getName() == "int" || $5->at(i)->getName() == "float" || $5->at(i)->getName() == "void" || $5->at(i)->getName() == "return")
						{log_file << " ";}
						if($5->at(i)->getName() == ";" || $5->at(i)->getName() == "{" || $5->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<endl<<endl;
				}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
			{
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					log_file<<$1->at(i)->getName();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float")
					{log_file << " ";}
					$$->push_back($1->at(i));
				}
				log_file<<$2->getName().c_str()<<$3->getName().c_str()<<" "<<$4->getName().c_str()<<endl<<endl;
				$$->push_back($2);
				$$->push_back($3);
				$$->push_back($4);
			}

		| parameter_list COMMA type_specifier
			{
				add_log(line_count, "parameter_list : parameter_list COMMA type_specifier");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					log_file<<$1->at(i)->getName();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float")
					{log_file << " ";}
					$$->push_back($1->at(i));
				}
				log_file<<$2->getName().c_str()<<" "<<$3->getName().c_str()<<endl<<endl;
				$$->push_back($2);
				$$->push_back($3);
			}

 		| type_specifier ID
			{
				add_log(line_count, "parameter_list : type_specifier ID");

				$$ = new vector<SymbolInfo*>();
				log_file<<$1->getName().c_str()<<" "<<$2->getName().c_str()<<endl<<endl;
				$$->push_back($1);
				$$->push_back($2);
			}

		| type_specifier
			{
				add_log(line_count, "parameter_list : type_specifier");

				$$ = new vector<SymbolInfo*>();
				log_file<<$1->getName().c_str()<<endl<<endl;
				$$->push_back($1);
			}
 		;

 		
compound_statement : LCURL statements RCURL
				{
					add_log(line_count, "compound_statement : LCURL statements RCURL");

					$$ = new vector<SymbolInfo*>();
					log_file<<$1->getName().c_str();
					$$->push_back($1);
					for(int i = 0; i< $2->size(); i++)
					{
						log_file<<$2->at(i)->getName().c_str();
						$$->push_back($2->at(i));

						if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
						{log_file << " ";}
						if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
						{log_file << endl;}
					}
					log_file<<$3->getName().c_str()<<endl<<endl;
					$$->push_back($3);
				}

 		    | LCURL RCURL
				{
					add_log(line_count, "compound_statement : LCURL RCURL");

					$$ = new vector<SymbolInfo*>();
					log_file<<$1->getName().c_str();
					$$->push_back($1);
					log_file<<$2->getName().c_str();
					$$->push_back($2);
					log_file<<endl<<endl;
				}
 		    ;

var_declaration : type_specifier declaration_list SEMICOLON
			{
				add_log(line_count, "var_declaration : type_specifier declaration_list SEMICOLON");

				string tpsp = $1->getName().c_str();
				if(tpsp== "void")
				{
					add_error(line_count, "Variable type cannot be void");
					num_of_error++;
				}

				$$ = new vector<SymbolInfo*>();
				log_file<<$1->getName().c_str()<<" ";
				$$->push_back($1);
		  	    for(int i = 0; i < $2->size(); i++){
		  			log_file << $2->at(i)->getName().c_str();
					$$->push_back($2->at(i));
		  		}
				log_file<<$3->getName().c_str()<<"\n\n";
				$$->push_back($3);
			}
 		 ;

type_specifier	: INT
		{
			add_log(line_count, "type_specifier : INT");
			log_file<<"int\n\n";
		}

 		| FLOAT
		{
			add_log(line_count, "type_specifier : FLOAT");
			log_file<<"float\n\n";
		}

 		| VOID
		{
			add_log(line_count, "type_specifier : VOID");
			log_file<<"void\n\n";
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
				}

				log_file<<$2->getName().c_str()<<$3->getName().c_str()<<endl<<endl;
				$$->push_back($2);
				$$->push_back($3);
			}

 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		  	{
				add_log(line_count, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
				}

				log_file<<$2->getName().c_str()<<$3->getName().c_str()<<$4->getName().c_str()<<$5->getName().c_str()<<$6->getName().c_str()<<endl<<endl;
				$$->push_back($2);
				$$->push_back($3);
				$$->push_back($4);
				$$->push_back($5);
				$$->push_back($6);
			}

 		  | ID
		  {
			add_log(line_count, "declaration_list : ID");
			log_file<<$1->getName().c_str()<<"\n\n";

			$$ = new vector<SymbolInfo*>();
			$$->push_back($1);
		  }

 		  | ID LTHIRD CONST_INT RTHIRD
		  		{
					add_log(line_count, "declaration_list : ID LTHIRD CONST_INT RTHIRD");

					$$ = new vector<SymbolInfo*>();
				
					log_file<<$1->getName().c_str()<<$2->getName().c_str()<<$3->getName().c_str()<<$4->getName().c_str()<<endl<<endl;
					$$->push_back($1);
					$$->push_back($2);
					$$->push_back($3);
					$$->push_back($4);
				}
 		  ;

statements : statement
			{
				add_log(line_count, "statements : statement");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
					if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}

	   | statements statement
	   		{
				add_log(line_count, "statements : statement");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
					if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
				}

				for(int i=0; i<$2->size();i++)
				{
					$$->push_back($2->at(i));
					log_file<<$2->at(i)->getName().c_str();
					if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
					{log_file << " ";}
					if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}
	   ;
	   
statement : var_declaration

	  | expression_statement

	  | compound_statement

	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement

	  | IF LPAREN expression RPAREN statement

	  | IF LPAREN expression RPAREN statement ELSE statement

	  | WHILE LPAREN expression RPAREN statement

	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  		{
				add_log(line_count, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

				$$ = new vector<SymbolInfo*>();
				log_file<<$1->getName().c_str()<<$2->getName().c_str()<<$3->getName().c_str()<<$4->getName().c_str()<<$5->getName().c_str()<<endl<<endl;
				$$->push_back($1);
				$$->push_back($2);
				$$->push_back($3);
				$$->push_back($4);
				$$->push_back($5);
			}

	  | RETURN expression SEMICOLON
	  		{
				add_log(line_count, "statement : RETURN expression SEMICOLON");

				$$ = new vector<SymbolInfo*>();
				log_file<<$1->getName().c_str()<<" ";
				$$->push_back($1);
				for(int i=0; i<$2->size();i++)
				{
					$$->push_back($2->at(i));
					log_file<<$2->at(i)->getName().c_str();
					if($2->at(i)->getName() == "int" || $2->at(i)->getName() == "float" || $2->at(i)->getName() == "void" || $2->at(i)->getName() == "return")
					{log_file << " ";}
					if($2->at(i)->getName() == ";" || $2->at(i)->getName() == "{" || $2->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<$3->getName().c_str()<<endl<<endl;
				$$->push_back($3);
			}
	  ;
	  
expression_statement 	: SEMICOLON	

			| expression SEMICOLON 
			;
	  
variable : ID 	
		{
			add_log(line_count, "variable : ID");

			$$ = new vector<SymbolInfo*>();
			log_file<<$1->getName().c_str()<<endl<<endl;
			$$->push_back($1);
		}	

	 | ID LTHIRD expression RTHIRD 
	 ;
	 
 expression : logic_expression	
			{
				add_log(line_count, "expression : logic_expression");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
					if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}

	   | variable ASSIGNOP logic_expression 	
	   ;
			
logic_expression : rel_expression 
			{
				add_log(line_count, "logic_expression : rel_expression");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
					if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}	

		 | rel_expression LOGICOP rel_expression 	
		 ;
			
rel_expression	: simple_expression 
			{
				add_log(line_count, "rel_expression	: simple_expression");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
					if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<endl<<endl;
			}

		| simple_expression RELOP simple_expression	
		;
				
simple_expression : term 
			{
				add_log(line_count, "simple_expression : term");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
				}
				log_file<<endl<<endl;
			}

		  | simple_expression ADDOP term 
		  	{
				add_log(line_count, "simple_expression : simple_expression ADDOP term");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
					if($1->at(i)->getName() == "int" || $1->at(i)->getName() == "float" || $1->at(i)->getName() == "void" || $1->at(i)->getName() == "return")
					{log_file << " ";}
					if($1->at(i)->getName() == ";" || $1->at(i)->getName() == "{" || $1->at(i)->getName() == "}")
					{log_file << endl;}
				}
				log_file<<$2->getName().c_str();
				$$->push_back($2);
				for(int i=0; i<$3->size();i++)
				{
					$$->push_back($3->at(i));
					log_file<<$3->at(i)->getName().c_str();
				}
				log_file<<endl<<endl;
			}
		  ;
					
term :	unary_expression
		{
			add_log(line_count, "term : unary_expression");

			$$ = new vector<SymbolInfo*>();
			for(int i=0; i<$1->size();i++)
			{
				$$->push_back($1->at(i));
				log_file<<$1->at(i)->getName().c_str();
			}
			log_file<<endl<<endl;
		}

     |  term MULOP unary_expression
     ;

unary_expression : ADDOP unary_expression  

		 | NOT unary_expression 

		 | factor 
		 	{
				add_log(line_count, "unary_expression	: factor");

				$$ = new vector<SymbolInfo*>();
				for(int i=0; i<$1->size();i++)
				{
					$$->push_back($1->at(i));
					log_file<<$1->at(i)->getName().c_str();
				}
				log_file<<endl<<endl;
			}
		 ;
	
factor	: variable
		{
			add_log(line_count, "factor	: variable");

			$$ = new vector<SymbolInfo*>();
			for(int i=0; i<$1->size();i++)
			{
				$$->push_back($1->at(i));
				log_file<<$1->at(i)->getName().c_str();
			}
			log_file<<endl<<endl;
		}

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

