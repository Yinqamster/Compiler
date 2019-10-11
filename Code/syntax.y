%{
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	#include <stdlib.h>
	#include <math.h>
	#include "lex.yy.c"
	int IFerror;	
	struct treeNode *treeRoot;
	struct treeNode *create(char *type, int count, ...);
%}

%union {struct treeNode *node;}
%token <node>INT FLOAT SEMI COMMA ID TYPE OCT HEX WRONGHEX WRONGOCT
%right <node>ASSIGNOP
%left  <node>OR
%left  <node>AND
%left  <node>RELOP
%left  <node>MINUS PLUS
%left  <node>STAR DIV
%right <node>NOT
%left  <node>LP RP LB RB DOT LC RC 

%nonassoc <node>LOWER_THAN_ELSE
%nonassoc <node>IF ELSE WHILE STRUCT RETURN

%type <node>Program  ExtDefList ExtDef ExtDecList 
%type <node>Specifier StructSpecifier OptTag Tag
%type <node>VarDec FunDec VarList ParamDec
%type <node>CompSt StmtList Stmt
%type <node>DefList Def DecList Dec
%type <node>Exp Args


%%
Program		: ExtDefList{$$=create("Program",1,$1);treeRoot=$$;}
			;
ExtDefList 	: ExtDef ExtDefList {$$=create("ExtDefList",2,$1,$2);}
			| {$$=NULL;}
			;
ExtDef		: Specifier ExtDecList SEMI {$$=create("ExtDef",3,$1,$2,$3);}
			| Specifier FunDec CompSt {$$=create("ExtDef",3,$1,$2,$3);}
			| Specifier SEMI {$$=create("ExtDef",2,$1,$2);}
			;
ExtDecList	: VarDec {$$=create("ExtDecList",1,$1);}
			| VarDec COMMA ExtDecList {$$=create("ExtDecList",3,$1,$2,$3);}
			;
Specifier	: TYPE {$$=create("Specifier",1,$1);}
			| StructSpecifier {$$=create("Specifier",1,$1);}
			;
StructSpecifier	: STRUCT OptTag LC DefList RC {$$=create("StructSpecifier",5,$1,$2,$3,$4,$5);}
			| STRUCT Tag {$$=create("StructSpecifier",2,$1,$2);}
			;
OptTag		: ID {$$=create("OptTag",1,$1);}
			| {$$=NULL;}
			;
Tag			: ID {$$=create("Tag",1,$1);}
			;
VarDec		: ID {$$=create("VarDec",1,$1);}
			| VarDec LB INT RB {$$=create("VarDec",4,$1,$2,$3,$4);}
			;
FunDec		: ID LP VarList RP {$$=create("FunDec",4,$1,$2,$3,$4);}
			| ID LP RP {$$=create("FunDec",3,$1,$2,$3);}
			| error RP {IFerror=1;}
			;
VarList		: ParamDec COMMA VarList {$$=create("VarList",3,$1,$2,$3);}
			| ParamDec {$$=create("VarList",1,$1);}
			;
ParamDec	: Specifier VarDec{$$=create("ParamDec",2,$1,$2);}
			| error COMMA{IFerror=1;}
			| error RB{IFerror=1;}
			;
CompSt		: LC DefList StmtList RC {$$=create("CompSt",4,$1,$2,$3,$4);}
			| error RC {IFerror=1;}
			;
StmtList	: Stmt StmtList {$$=create("StmtList",2,$1,$2);}
			| {$$=NULL;}
			;
Stmt		: Exp SEMI {$$=create("Stmt",2,$1,$2);}
			| CompSt {$$=create("Stmt",1,$1);}
			| RETURN Exp SEMI {$$=create("Stmt",3,$1,$2,$3);}
			| IF LP Exp RP Stmt  %prec LOWER_THAN_ELSE{$$=create("Stmt",5,$1,$2,$3,$4,$5);}
			| IF LP Exp RP Stmt ELSE Stmt {$$=create("Stmt",7,$1,$2,$3,$4,$5,$6,$7);}
			| WHILE LP Exp RP Stmt {$$=create("Stmt",5,$1,$2,$3,$4,$5);}
			| error SEMI {IFerror=1;}
			| error WHILE LP Exp RP {IFerror=1;}
			| error IF LP Exp RP {IFerror=1;}
			| error ELSE {IFerror=1;}
			|ELSE LP Exp RP error{IFerror=1;}
			| Exp error{IFerror=1;}
			;
DefList 	: Def DefList{$$=create("DefList",2,$1,$2);}
			| {$$=NULL;}
			;
Def			: Specifier DecList SEMI {$$=create("Def",3,$1,$2,$3);}
			| Specifier DecList error {IFerror=1;}
			;
DecList		: Dec {$$=create("DecList",1,$1);}
			| Dec COMMA DecList {$$=create("DecList",3,$1,$2,$3);}
			;
Dec			: VarDec {$$=create("Dec",1,$1);}
			| VarDec ASSIGNOP Exp {$$=create("Dec",3,$1,$2,$3);}
			;
Exp			: Exp ASSIGNOP Exp {$$=create("Exp",3,$1,$2,$3);}
			| Exp AND Exp {$$=create("Exp",3,$1,$2,$3);}
			| Exp OR Exp {$$=create("Exp",3,$1,$2,$3);}
			| Exp RELOP Exp {$$=create("Exp",3,$1,$2,$3);}
			| Exp PLUS Exp {$$=create("Exp",3,$1,$2,$3);}
			| Exp MINUS Exp {$$=create("Exp",3,$1,$2,$3);} 
			| Exp STAR Exp {$$=create("Exp",3,$1,$2,$3);} 
			| Exp DIV Exp {$$=create("Exp",3,$1,$2,$3);} 
			| LP Exp RP {$$=create("Exp",3,$1,$2,$3);} 
			| MINUS Exp {$$=create("Exp",2,$1,$2);}
			| NOT Exp {$$=create("Exp",2,$1,$2);}
			| ID LP Args RP {$$=create("Exp",4,$1,$2,$3,$4);}
			| ID LP RP {$$=create("Exp",3,$1,$2,$3);}
			| Exp LB Exp RB {$$=create("Exp",4,$1,$2,$3,$4);}
			| Exp DOT ID {$$=create("Exp",3,$1,$2,$3);}
			| ID {$$=create("Exp",1,$1);}
			| INT {$$=create("Exp",1,$1);}
			| FLOAT {$$=create("Exp",1,$1);}
			| HEX {$$=create("Exp",1,$1);}
			| OCT {$$=create("Exp",1,$1);}
			| WRONGHEX{IFerror = 1;}
			| WRONGOCT{IFerror = 1;}
			;
Args		: Exp COMMA Args {$$=create("Args",3,$1,$2,$3);}
			| Exp {$$=create("Args",1,$1);}
			;

%%
yyerror(char *msg){
	fprintf(stderr,"Error type B at line %d: unexpected \'%s\'\n",yylineno, yytext);
//	fprintf(stderr,"Error type B at line %d:%s\n",yylineno,yytext);
}

struct treeNode *create(char *type, int count, ...){
	struct treeNode *root = (struct treeNode *)malloc(sizeof(struct treeNode));
	root->flag=0;
	va_list n;
	va_start (n, count);

	strcpy(root->type, type);
	int i;
	for(i = 0; i < count; i++){
//		root->child[i] = (struct treeNode *)malloc(sizeof(struct treeNode));
		root->child[i] = va_arg(n,struct treeNode *);
		root->line = root->child[0]->line;
//		root->child[i]->parent = root;
//		printf("%s\n",root->type);
//		printf("NULLLLL?%d\t%d\n",i,root->child[i]->parent==NULL?1:0);
		if(root->child[i]!=NULL) {
			root->child[i]->parent=root;
		}
	}
	va_end(n);
	return root;
}

void print(struct treeNode *root, int depth){
//	printf("%s\n","print");
	if(root == NULL){
//		printf("%s\n","null");
		return;
	}
//	printf("%s\n",root->type);
	int i;
	for(i=0;i<depth;i++)
		printf("  ");
	if(root->flag){
		if(strcmp(root->type,"INT")==0|strcmp(root->type,"TYPE")==0|strcmp(root->type,"ID")==0|strcmp(root->type,"FLOAT")==0)
			printf("%s: %s\n",root->type,root->text);
		else if(strcmp(root->type,"HEX")==0){
			int len = strlen(root->text);
			int j;
			int temp=0;
			for(j=len-1;j>=2;j--){
				int k=0;
				int temp_=1;
				for(k=0;k<len-j-1;k++)
					temp_*=16;
				switch(root->text[j]){
				case 'A':
				case 'a':if(temp_==0) temp+=10;temp+=10*temp_;break;
				case 'B':
				case 'b':if(temp_==0) temp+=11;temp+=11*temp_;break;
				case 'C':
				case 'c':if(temp_==0) temp+=12;temp+=12*temp_;break;
				case 'D':
				case 'd':if(temp_==0) temp+=13;temp+=13*temp_;break;
				case 'E':
				case 'e':if(temp_==0) temp+=14;temp+=14*temp_;break;
				case 'F':
				case 'f':if(temp_==0) temp+=15;temp+=15*temp_;break;
				default:temp+=(root->text[j]-'0')*temp_;
				}
			}
			printf("%s: %d\n","INT",temp);
		}
		else if(strcmp(root->type,"OCT")==0){
			int len = strlen(root->text);
			int j;
			int temp=0;
			for(j=len-1;j>=1;j--){
				int k=0;
				int temp_=1;
				for(k=0;k<len-j-1;k++)
					temp_*=8;
//				printf("%d\n",temp_);
				if(temp_==0)
					temp+=(root->text[j]-'0');
				temp+=(root->text[j]-'0')*temp_;
//				printf("%d\n",temp);
			}
			printf("%s: %d\n","INT",temp);
		}
		else printf("%s\n",root->type);
	}
	else {
		printf("%s (%d)\n",root->type, root->line);
	}
	for(i=0;i<7;i++){
		if(root->child[i]!=NULL)
			print(root->child[i],depth+1);
	}
}
