%{
    #include <iostream>
    using namespace std;

    extern "C" {int yylex(void);}
    void yyerror(char *s);
%}

%union {
    int u_int;
    float u_float;
    char *u_string;
}

%start program

%token <u_string> ID
%token <u_int> INTEGER
%token <u_float> DOUBLE

%token FUNC CNUF IF FI ELSE ELSEIF FOR ROF LOOP POOL

%token TRUE FALSE

%token DIV MUL MINUS PLUS

%token CEQ CNEQ CL CLE CG CGE

%token AND OR

%token LBRACKET RBRACKET ARROW COLON

%token EQ

%left '-' '+'
%left '*' '/'

%%



program : statements
        ;


statements : statement
           | statements statement
           ;


statement : function
          | var_decl
          ;




var_decl : ID ID ';'
         | ID assignement
//         | tab_id ID; /* TODO gerer l'assignement des tableaux lors de la declaration */
/* TODO : Gerer les declarations multiples */
         ;



function : FUNC fct_decl fct_def CNUF
         ;

fct_decl : ID ID LBRACKET params RBRACKET
         ;

fct_def : instructions
        ;

fct_call : ID LBRACKET args RBRACKET ';'
         ;

fct_call_in_exp : ID LBRACKET args RBRACKET 
         ;

return_statement : ID ';' /* ID = 'RETURN' dans ce cas */
                 | ID expression ';'
                 ;



instructions : /* empty */
             | instruction /* Pas necessaire. TODO : Supprimer? */
             | instructions instruction
             ;


instruction : if_statement | for_statement | loop_statement | var_decl
            | assignement | fct_call | return_statement
            ;



if_statement : IF LBRACKET condition RBRACKET instructions FI
             | IF LBRACKET condition RBRACKET instructions else_statement FI
             | IF LBRACKET condition RBRACKET instructions elseif_statements FI
             | IF LBRACKET condition RBRACKET instructions elseif_statements else_statement FI
             ;

else_statement : ELSE instructions
               ;

elseif_statements : elseif_statement
                  | elseif_statements elseif_statement
                  ;

elseif_statement : ELSEIF LBRACKET condition RBRACKET instructions



for_statement : FOR ID ARROW ladder instructions ROF

ladder : expression COLON expression
       | expression COLON expression COLON expression
       ;



loop_statement : LOOP LBRACKET condition RBRACKET instructions POOL
               ;



condition : boolean
          | LBRACKET condition RBRACKET
          | condition operator_bool condition
          | expression comparator expression
          ;



expression : LBRACKET expression RBRACKET
           | fct_call_in_exp
           | operand
           | expression operator_arith expression
           ;



/* Liste de parametre avec type d'une fonction (dans fct_def par exemple) */
params : /* empty */
           | param 
           | params ',' param
           ;

param : ID ID
          ;

/* Liste des arguments d'appel a une fonction */
args : /* empty */
            | expression
            | args ',' expression
            ;





assignement : ID EQ expression ';'
//            | tab_id '=' 


operand : ID | numeric
//TABBLEAU ..
        ;

boolean : TRUE
        | FALSE
        ;

operator_bool : OR | AND
              ;

operator_arith : PLUS | MINUS | MUL | DIV


comparator : CEQ | CNEQ | CL | CLE | CG | CGE

numeric : INTEGER | DOUBLE

//tab_id : ID ':' expression
//       | ID ':' INTEGER
//       ;





%%



main(int argc, char *argv[]) {
    extern FILE *yyin;
    ++argv; --argc;
    yyin = fopen(argv[0], "r");
    yyparse();
}

void yyerror(char *s)
{
    cout << "coucou " << s << endl;
}

