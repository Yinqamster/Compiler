#include <stdio.h>
extern FILE* yyin;
extern int yylineno;
extern int IFerror;
extern struct treeNode* treeRoot;
#define YYDEBUG 1
int main(int argc, char** argv) {
/*	if (argc>1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return 1;
		}
		yylineno = 1;
	}
	while(yylex() != 0);*/
	if (argc <= 1) return 1;
	FILE* f = fopen(argv[1],"r");
	if (!f){
		perror(argv[1]);
		return 1;
	}
//	printf("%d\n",errorFlag);
//	if(treeRoot!=NULL&&errorFlag==0)
//		print(treeRoot,0);
	yylineno = 1;
	yyrestart(f);
//	yydebug=1;
	yyparse();
	FILE *f1=fopen(argv[2],"w");
//	if(treeRoot!=NULL&&IFerror==0)
//		print(treeRoot,0);
	startSemantic();
//	printf("ok\n");
	printCode(argv[2]);
//	printTable();
	fclose(f);
	fclose(f1);
	return 0;
}
