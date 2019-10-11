%option yylineno

%{
	#include <stdio.h>
	#include <string.h>
	#include "syntax.tab.h"
	#include "domtree.h"	
	extern int IFerror;
	void found(char *type, char *text);
%}

LETTER [A-Za-z_]
INT [1-9][0-9]*|[0]
FLOAT ([0]|[1-9][0-9]*)+\.[0-9]+
KEYWORD auto|break|case|char|const|continue|defaultdo|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|vpid|volatile|while
ID ({LETTER})({LETTER}|[0-9])*
SEMI ;
COMMA ,
ASSIGNOP =
RELOP >|<|>=|<=|==|!=
PLUS \+
MINUS \-
STAR \*
DIV \/
AND &&
OR \|\|
DOT \.
NOT !
TYPE (int)|(float)
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
STRUCT struct
RETURN return
IF if
ELSE else
WHILE while
SPACE [ \t\n\r]+
OCT [0][0-7]+
WRONGOCT [0][0-7]*[89]+
HEX [0][xX][0-9a-fA-F]+
WRONGHEX [0][xX][0-9a-fA-F]*[g-zG-Z]+

%%
{SPACE}		
{TYPE}		{found("TYPE",yytext);return TYPE;}
{INT}		{found("INT",yytext);return INT;}
{FLOAT}		{found("FLOAT",yytext);return FLOAT;}
{SEMI}		{found("SEMI",yytext);return SEMI;}
{COMMA}		{found("COMMA",yytext);return COMMA;}
{ASSIGNOP}	{found("ASSIGNOP",yytext);return ASSIGNOP;}
{RELOP}		{found("RELOP",yytext);return RELOP;}
{PLUS}		{found("PLUS",yytext);return PLUS;}
{MINUS}		{found("MINUS",yytext);return MINUS;}
{STAR}		{found("STAR",yytext);return STAR;}
{DIV}		{found("DIV",yytext);return DIV;}
{AND}		{found("AND",yytext);return AND;}
{OR}		{found("OR",yytext);return OR;}
{DOT}		{found("DOT",yytext);return DOT;}
{NOT}		{found("NOT",yytext);return NOT;}
{LP}		{found("LP",yytext);return LP;}
{RP}		{found("RP",yytext);return RP;}
{LB}		{found("LB",yytext);return LB;}
{RB}		{found("RB",yytext);return RB;}
{LC}		{found("LC",yytext);return LC;}
{RC}		{found("RC",yytext);return RC;}
{OCT}		{found("OCT",yytext);return OCT;}
{HEX}		{found("HEX",yytext);return HEX;}
{WRONGOCT}	{IFerror = 1;printf("Error type A at Line %d: Illegal octal number \'%s\'\n", yylineno, yytext);found("WRONGOCT",yytext);return WRONGOCT;}
{WRONGHEX}	{IFerror = 1;printf("Error type A at Line %d: Illegal hexadecimal number \'%s\'\n", yylineno, yytext);found("WRONGHEX",yytext);return WRONGHEX;}
{WHILE}		{found("WHILE",yytext);return WHILE;}
{STRUCT}    {found("STRUCT",yytext);return STRUCT;}
{IF}		{found("IF",yytext);return IF;}
{ELSE}		{found("ELSE",yytext);return ELSE;}
{RETURN}    {found("RETURN",yytext);return RETURN;}
{ID}        {found("ID",yytext);return ID;}
. {IFerror = 1;printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext);}


%%

void found(char *type, char *text){
	yylval.node = (struct treeNode*)malloc(sizeof(struct treeNode));
	yylval.node->line = yylineno;
	yylval.node->flag = 1;
	strcpy(yylval.node->type,type);
	strcpy(yylval.node->text,text);
}
