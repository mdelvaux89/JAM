%{
	#include <iostream>
	using namespace std;

	#include "JAM.tab.h" /* The tokens */ 
	#define YY_DECL extern "C" int yylex()
%}

%option yylineno

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*


%%


func					{cout << " " << yytext << " " << endl; return(FUNC);}
"-"+cnuf				{cout << " " << yytext << " " << endl; return(CNUF);}
if						{cout << " " << yytext << " " << endl; return(IF);}
"-"+fi					{cout << " " << yytext << " " << endl; return(FI);}
else					{cout << " " << yytext << " " << endl; return(ELSE);}
elseif					{cout << " " << yytext << " " << endl; return(ELSEIF);}
for						{cout << " " << yytext << " " << endl; return(FOR);}
"-"+rof					{cout << " " << yytext << " " << endl; return(ROF);}
loop					{cout << " " << yytext << " " << endl; return(LOOP);}
"-"+pool				{cout << " " << yytext << " " << endl; return(POOL);}

true					{cout << " " << yytext << " " << endl; return(TRUE);}
false					{cout << " " << yytext << " " << endl; return(FALSE);}

"="						{cout << " " << yytext << " " << endl; return(EQ);}

"+"						{cout << " " << yytext << " " << endl; return(PLUS);}
"-"						{cout << " " << yytext << " " << endl; return(MINUS);}
"*"						{cout << " " << yytext << " " << endl; return(MUL);}
"/"						{cout << " " << yytext << " " << endl; return(DIV);}

"=="					{cout << " " << yytext << " " << endl; return(CEQ);}
"!="					{cout << " " << yytext << " " << endl; return(CNEQ);}
"<"						{cout << " " << yytext << " " << endl; return(CL);}
"<="					{cout << " " << yytext << " " << endl; return(CLE);}
">"						{cout << " " << yytext << " " << endl; return(CG);}
">="					{cout << " " << yytext << " " << endl; return(CGE);}

"("						{cout << " " << yytext << " " << endl; return(LBRACKET);}
")"						{cout << " " << yytext << " " << endl; return(RBRACKET);}

"<-"					{cout << " " << yytext << " " << endl; return(ARROW);}

":"						{cout << " " << yytext << " " << endl; return(COLON);}

or						{cout << " " << yytext << " " << endl; return(OR);}
and						{cout << " " << yytext << " " << endl; return(AND);}

{ID}					{cout << " " << yytext << " " << endl; yylval.u_string = yytext; return(ID);}

{DIGIT}+				{cout << " " << yytext << " " << endl; yylval.u_int = atoi(yytext); return(INTEGER);}
{DIGIT}*"'"{DIGIT}+		{cout << " " << yytext << " " << endl; yylval.u_float = atof(yytext); return(DOUBLE);}

"<<".*"\n"				/* empty */	
[ \t\n]+ 				/* blank, tab, new line: eat up whitespace */
. 						{cout << "ERREUR" << yylineno << " ->" << yytext << "<-" << endl; return(yytext[0]);}

%%




