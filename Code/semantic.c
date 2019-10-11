#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "semantic.h"

extern struct treeNode *treeRoot;

struct symbol *varSymbol[1000];
struct symbol *funSymbol[1000];
struct Structure *TStruct;
//struct Structure TStruct[1000];
int depth;

void init(){
	TStruct = NULL;
//	TStruct = (struct Structure *)malloc(struct Structure);
	memset(varSymbol, 0, sizeof(struct symbol*)*1000);
	memset(funSymbol, 0, sizeof(struct symbol*)*1000);
	depth = 0;
}

void read_write() {
	struct treeNode *node = (struct treeNode *)malloc (sizeof(struct treeNode));
	strcpy(node->text,"read");
	node->line = 0;
//	node->depth=0;
	strcpy(node->type,"ID");
	for(int i = 0; i < 7; i++) {
		node->child[i] = NULL;
	}
	enum type varType;
	varType = myint;
	createFun(varType,node,0,NULL);
	strcpy(node->text,"write");
//	node->depth=0;
	struct argList *p = (struct argList*)malloc(sizeof(struct argList));
	p->next = NULL;
	p->argType = myint;
	createFun(varType,node,1,p);
//	printTable();
}

void startSemantic(){
	init();
	read_write();
	isProgram(treeRoot);
//	printf("start\n");
}


unsigned int getHash(char *name){
	unsigned int val = 0,i;
	for(;*name;++name){
		val = (val<<2)+*name;
		if(i = val & ~0x3fff)
			val = (val ^ (i >> 12)) & 0x3fff;
	}
	return val%1000;
}

void createVar(enum type varType, struct treeNode *node, struct Structure *varStruct, struct array *varArray){
	struct Structure *varStructTemp=varStruct;
//	printf("create VarType:%d\n", varType);
//	while(varStructTemp!=NULL) {
	//	printf("create VarStruct->name:%s\n", varStructTemp->name);
//		varStructTemp=varStructTemp->next;
//	}
	varStructTemp=varStruct;
//	printf("inStruct? %d\n", varStruct->inStruct);
//	printf("create Var node->text:%s\n", node->text);
	unsigned int val = getHash(node->text);
//	printf("val=%d\n",val);
	struct symbol *temp = varSymbol[val];
//	printf(";;;%d\n",val);
	int ifFind = 0;
//	printf("temp is null?%d\n",temp == NULL ? 1 : 0);
	if(temp != NULL){
//		printf("confict:%d\n",varSymbol[105]->node->depth);
//		unsigned int i = val;
		while(temp!=NULL){
//			val++;
//			if(val==1000)	val=0;
//			temp = varSymbol[val];
//			printf("%s\n",node->text);
//			printf("%s\n",temp->name);
	//		printf("find!!:%d\n",temp->node->depth);
			if(strcmp(temp->name,node->text)==0 && depth == temp->node->depth){
				if(varStruct->inStruct == 0){
					printf("Error type 3 at Line %d : Redefined variable '%s'\n",node->line,node->text);
					return;
				}
				else{
					printf("Error type 15 at Line %d : Redefined variable '%s'\n",node->line,node->text);
					return;
				}
			}
			else if(strcmp(temp->name,node->text)==0)
				ifFind = 1;
			val++;
			if(val == 1000)
				val=0;
			temp = varSymbol[val];
		}
	}
//	printStructTable();
	struct Structure *structTemp = TStruct;
	while(structTemp != NULL) {
//		printf("111\n");
		if(strcmp(structTemp->name,node->text)==0){
			ifFind=1;
			if(varStruct->inStruct == 0){
				printf("Error type 3 at Line %d : Redefined variable '%s'\n",node->line,node->text);
				return;
			}
			else{
				printf("Error type 15 at Line %d : Redefined variable '%s'\n",node->line,node->text);
				return;
			}
		}
//		else if(strcmp(structTemp->name,node->text)==0)
//			ifFind = 1;
		structTemp = structTemp->next;
	}
//	printf("Here ok!\n");
	struct NodeSymbol *NewNode = (struct NodeSymbol *)malloc(sizeof(struct NodeSymbol));
	varSymbol[val] = (struct symbol*)malloc(sizeof(struct symbol));
	if(varArray != NULL) {
		varType = 2;
	}
//	if(varArray!=NULL){
//		if(varArray->next != NULL){
//			varType = 2;
//		printf("array::%d\n",varArray->arrayType);
//		}
//		if(varArray->next == NULL && varStruct != NULL)
//			varType = 3;
/*		else if(varStruct != NULL)
			varType = 3;*/
//	}
//	if(varArray)
//	printf("varArray->:%d\n",varArray->arrayType);
//	printf("varType=%d\n",varType);
	if(varType == 0 || varType == 1 || varType == 2){
		if(varStruct->inStruct==1) {
			strcpy(NewNode->structName,varStruct->name); 
		}
		NewNode->FunOrVar = 1;
		NewNode->line = node->line;
		NewNode->next=NULL;
		NewNode->Smsg.Vmsg = (struct msgVar *)malloc(sizeof(struct msgVar));
		NewNode->Smsg.Vmsg->VarType = varType;
		NewNode->depth = depth;
		if(varType != 2){
			NewNode->Smsg.Vmsg->ArrayOrStructOrBasic = 2;
			NewNode->Smsg.Vmsg->Varray = NULL;
		}
		else {
			NewNode->Smsg.Vmsg->ArrayOrStructOrBasic = 0;
			NewNode->Smsg.Vmsg->Varray = (struct array *)malloc(sizeof(struct array));
			NewNode->Smsg.Vmsg->Varray = varArray;
		}
//		MySymbol[val]->node = NewNode;
//		strcpy(MySymbol.name, node->text);
	}
	else if(varType == 3){
/*		for(int i = 0; i < 1000; i++){
			if(strcpy(TStruct[i].name, varStruct.name)==0){
				
			}
		}*/
//		printf("here!");
		struct Structure *Stemp = TStruct;
//		if(varStruct->inStruct==1){
			while(varStruct->next!=NULL) {
//				printf("varStruct->name:%s\n",varStruct->name);
				varStruct=varStruct->next;
//			}
		}
//		printf("varStruct->name:%s\n",varStruct->name);
		while(Stemp!=NULL){
			if(strcmp(Stemp->name,varStruct->name)==0)
				break;
			Stemp = Stemp->next;
		}
		if(Stemp == NULL){
			if(strcmp(varStruct->name,"noName")!=0) {
				printf("Error type 17 at Line %d:undefined structure \"%s\"\n", node->line, varStruct->name);
			}
		}
		NewNode->FunOrVar = 1;
		NewNode->line = node->line;
		NewNode->next = NULL;
		strcpy(NewNode->structName,varStruct->name);
//		NewNode->Smsg = (union msg)malloc(sizeof(union msgSymbol));
		NewNode->Smsg.Vmsg = (struct msgVar *)malloc(sizeof(struct msgVar));
		NewNode->Smsg.Vmsg->VarType = varType;
		NewNode->Smsg.Vmsg->Vstruct = (struct Structure *)malloc(sizeof(struct Structure));
		NewNode->Smsg.Vmsg->ArrayOrStructOrBasic = 1;
		NewNode->Smsg.Vmsg->Vstruct = varStruct;
		NewNode->depth = depth;
	}


//	printf("ifFind=%d\n",ifFind);
	if(ifFind == 0){
//		printf("notfind\n");
		varSymbol[val]->node = NewNode;
//		printf("f:%d\n",varSymbol[val]->node->depth);
	}
	else{
		NewNode->next = varSymbol[val]->node;
		varSymbol[val]->node = NewNode;
	}
	varSymbol[val]->ifUse = 1;
	strcpy(varSymbol[val]->name, node->text);


	if(varStruct->inStruct==1) {
//		printf("add to argList!\n");
		struct argList *temp = (struct argList*)malloc(sizeof(struct argList));
		temp->argType=varType;
//		strcpy(temp->structName,NewNode->structName);
		if(varType==2){
			temp->a=varArray;
		}
		strcpy(temp->name,node->text);
		temp->next=NULL;
//		printf("temp1 name %s\n",temp->name);
		varStruct=varStructTemp;
		if(varStruct->sMember == NULL) {
//			printf("temp2 name %s\n",temp->name);
			varStruct->sMember=(struct argList *)malloc(sizeof(struct argList));
			varStruct->sMember=temp;
//			return;
		}
		else {
		struct argList *p = varStruct->sMember;
		while(p->next != NULL){
			p=p->next;
		}
		p->next=temp;
//		printf("temp3 name %s\n",temp->name);
		}

/*		if(varType==3){
			struct Structure *t=varStructTemp;
			while(varStructTemp->next!=NULL){
				varStructTemp=varStructTemp->next;
			}
			if(varStructTemp!=t) {
				while(t->next!=varStructTemp){
					t=t->next;
				}
				t->next=NULL;
//				varStruct=t;
			}*/
/*			else if(varStructTemp==t) {
				strcpy(varStruct->name,"");
			//	t=NULL;
			}*/
//		}

//		strcpy(varStruct->name,"");
	//	varStruct->inStruct=0;
	}
		if(varType==3){
			struct Structure *t=varStructTemp;
////			varStruct=varStructTemp;
			while(varStructTemp->next!=NULL){
//				printf("3333\n");
				varStructTemp=varStructTemp->next;
			}
			if(varStructTemp!=t) {
//				printf("aaaaaaa\n");
				while(t->next!=varStructTemp){
					t=t->next;
				}
				t->next=NULL;
				free(varStructTemp);
//				varStruct=t;
			}
	/*		else if(varStructTemp==t) {
				printf("t == varStruct?%d\n",t==varStruct?1:0);
			//	varStruct=NULL;
				strcpy(varStruct->name,"");
			}*/
		}
//		printf("vava%s\n",varStruct->name);
//	printf("type:%d",varType);
//	printf("type:%d\n", varSymbol[val]->node->Smsg.Vmsg->VarType);
//	printf("f:%d\n",varSymbol[105]->node->depth);
//	printf("120%s\n",varSymbol[120]->name);
}

void createFun(enum type funType, struct treeNode *node, int varNum, struct argList *myList){
//	printf("create function:%s\n", node->text);
//	printf("varNum:%d\n",varNum);
	unsigned int val = getHash(node->text);
//	printf("%d\n", val);
	struct symbol *temp = funSymbol[val];
	if(temp != NULL){
//		printf("1111\n");
		while(temp!=NULL){
//			val++;
//			if(val == 1000) val = 0;
//			temp = funSymbol[val];
			if(strcmp(funSymbol[val]->name,node->text)==0){
				printf("Error type 4 at line %d: Redefined function \"%s\"\n", node->line, node->text);
				return;
			}
			val++;
			if(val == 1000)
				val=0;
			temp = funSymbol[val];
		}
	}
//	printf("find a propriate position\n");
	struct NodeSymbol *funNode = (struct NodeSymbol *)malloc(sizeof(struct NodeSymbol));
	funNode->FunOrVar = 0;
	funNode->next = NULL;
	funNode->line = node->line;
	funNode->Smsg.Fmsg = (struct msgFun *)malloc(sizeof(struct msgFun));
	funNode->Smsg.Fmsg->num = varNum;
	funNode->Smsg.Fmsg->FunType = funType;
	funNode->Smsg.Fmsg->msg = (struct argList *)malloc(sizeof(struct argList));
	funNode->Smsg.Fmsg->msg = myList;
//	printf("111\n");
	funSymbol[val] = (struct symbol *)malloc(sizeof(struct symbol));
	funSymbol[val]->node = funNode;
	strcpy(funSymbol[val]->name, node->text);
//	funSymbol[val]->ifUse = 1;
//	printf("create function successfully\n");
}

void createStruct(struct treeNode *node, struct Structure *newStruct){
//	printf("Create Struct:%s\n",newStruct->name);
	struct Structure *temp = (struct Structure*)malloc(sizeof(struct Structure));
	while(newStruct->next != NULL) {
		newStruct=newStruct->next;
	}
	strcpy(temp->name,newStruct->name);
	temp->inStruct=newStruct->inStruct;
	temp->sMember=newStruct->sMember;
	temp->next = TStruct;
	TStruct=temp;
/*	newStruct->next=TStruct;
	TStruct=newStruct;*/
//	printStructTable();
}

enum type getVarType(struct treeNode *node){ 
/*	for(int i = 0; i<1000; i++){
		if(varSymbol[i]!=NULL){
			printf("%s\n", varSymbol[i]->name);
			printf("%d\n", varSymbol[i]->node->Smsg.Vmsg->VarType);
		}
	}*/
	unsigned int var = getHash(node->text);
//	printf("%d\n",var);
	while(strcmp(varSymbol[var]->name, node->text) != 0){
		var++;
		if(var == 1000)
			var = 0;
	}
//	printf("%d\n",var);
	enum type t = varSymbol[var]->node->Smsg.Vmsg->VarType;
//	printf("%d\n", t);
	return t;
}

enum type getFunType(struct treeNode *node){
	unsigned int var = getHash(node->text);
	while(strcmp(funSymbol[var]->name, node->text) != 0){
		var++;
		if(var == 1000)
			var = 0;
	}
	return funSymbol[var]->node->Smsg.Fmsg->FunType;
}

char *changeType(enum type t){
	if(t == 0)
		return "float";
	else if(t == 1)
		return "int";
	else if(t == 2)
		return "array";
	else if(t == 3)
		return "struct";
}


void isProgram(struct treeNode *node) {
//	printf("do Program\n");
	if(node == NULL) {
//		printf("Program node is null\n");
		return;
	}
	if(strcmp(node->type,"Program")!=0) {
		printf("Node is not Program\n");
		return;
	}
/*	for(int i = 0; i < 7; i++) {
		if(node->child[i] == NULL){
			printf("Program child %d is null",i);
			return;
		}
		else {
			isExtDefList(node->child[i]);
		}
	}*/
	if(node->child[0]==NULL) {
//		printf("Program child 0 is null\n");
		return;
	}
	else {
		isExtDefList(node->child[0]);
	}
}

void isExtDefList(struct treeNode *node) {
//	printf("do ExtDefList\n");
	if(node == NULL) {
//		printf("ExtDefList node is null\n");
		return;
	}
	if(strcmp(node->type,"ExtDefList")!=0) {
		printf("Node is not ExtDefList\n");
		return;
	}
/*	for(int i = 0; i < 7; i++) {
		if(node->child[i] == NULL) {
			printf("ExtDefList child %d is null\n",i);
			return;
		}
		else {
			struct treeNode *child = node->child[i];
			isExtDef(child);
		}
	}*/
	if(node->child[0] == NULL) {//ok
//		printf("ExtDefList child 0 is null\n");
		return;
	}
	else {
		struct treeNode *child0 = node->child[0];
		isExtDef(child0);
		if(node->child[1] == NULL) {
//			printf("ExtDefList child 1 is null\n");
			return;
		}
		else {
			struct treeNode *child1 = node->child[1];
			isExtDefList(child1);
		}
	}
}

void isExtDef(struct treeNode *node) {
//	printf("do ExtDef\n");
	if(node == NULL) {
		printf("Node ExtDef is null\n");
		return;
	}
	if(strcmp(node->type, "ExtDef") != 0) {
		printf("Node is not ExtDef\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	//Todo:
	//child0 = specifier not finish
	//
	enum type newType;
	struct Structure *newStruct = (struct Structure *)malloc(sizeof(struct Structure));
	newStruct->inStruct = 0;
	newStruct->next=NULL;
/*		struct Structure *a=newStruct;
		while(a!=NULL) {
			printf("aname:%s\n",a->name);
			a=a->next;
		}*/
	isSpecifier(child0, &newType, newStruct);
/*		struct Structure *a=newStruct;
		while(a!=NULL) {
			printf("aname:%s\n",a->name);
			a=a->next;
		}*/
//	printf("def:%d\n", newType);
	struct treeNode *child1 = node->child[1];
	if(strcmp(child1->type,"ExtDecList")==0) {
		isExtDecList(child1, newStruct, newType);
	}
	else if(strcmp(child1->type,"SEMI")==0){
//		printf("AATYPE:%d\n",newType);
	}
	else if(strcmp(child1->type,"FunDec")==0) {
//		printf("fun\n");
		isFunDec(child1, newType);
		struct treeNode *child2 = node->child[2];
		isCompSt(child2, newType);
	}
}

void isExtDecList(struct treeNode* node, struct Structure *s, enum type MyType){
//	printf("do ExtDecList\n");
	if(node == NULL) {
//		printf("ExtDecList is null\n");
		return;
	}
	if(strcmp(node->type,"ExtDecList") != 0) {
		printf("Node is not ExtDecList\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	//Todo:array
	//child0 = varDec is not finished
	//
	struct array *myArray = (struct array *)malloc(sizeof(struct array));
	myArray = NULL;
//	printf("sssName %s\n",s->name);
	isVarDec(child0,MyType, myArray, s);//Todo
	if(node->child[1] != NULL) {
		struct treeNode *child2 = node->child[2];
		isExtDecList(child2,s, MyType);
	}
}

void isSpecifier(struct treeNode* node, enum type *MyType, struct Structure *s) {
//	printf("do Specifier\n");
	if(node == NULL) {
//		printf("Specifier is null\n");
		return;
	}
	if(strcmp(node->type,"Specifier") != 0) {
		printf("Node is not Specifier\n");
		return;
	}

	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type, "TYPE")==0) {
		//Todo:
//		printf("%s\n",child0->text);
//		*MyType = 1;
		if(strcmp(child0->text,"int")==0)
			*MyType = 1;
		else if(strcmp(child0->text,"float")==0)
			*MyType = 0;
//		s = NULL;
	}
	else if(strcmp(child0->type, "StructSpecifier")==0) {
		//Todo:
//		enum type st;
		struct Structure *a=s;
		isStructSpecifier(child0, MyType, s);
/*		while(a!=NULL) {
			printf("aname:%s~%d\n",a->name,a->inStruct);
			a=a->next;
		}*/
//		*MyType = st;
		
	}
	else {
		printf("syntax wrong\n");
	}
}

void isStructSpecifier(struct treeNode *node, enum type *MyType, struct Structure *s){
//	printf("do StructSpecifier\n");
	if(node == NULL) {
//		printf("StructSpecifier is null\n");
		return;
	}
	if(strcmp(node->type,"StructSpecifier") != 0) {
		printf("Node is not StructSpecifier\n");
		return;
	}
	//node->child[0] is STRUCT, do nothing.
	struct treeNode* child0 = node->child[0];
	struct treeNode* child1 = node->child[1];
	s->inStruct = 1;
//	printf("child1 is null?%d\n",child1==NULL?1:0);
//	printf("%s\n",node->child[2]->type);
	if(child1==NULL) {
//		printf("%s\n",node->child[2]->type);
//		printf("%s\n",node->child[3]->type);
		strcpy(s->name,"noName");
//		printf("snameBefore:%s\n",s->name);
		child1 = node->child[3];
//		isOptTag(node->child[1],s);
		isDefList(child1,s);
		isOptTag(node->child[1],s);
		s->inStruct = 0;

	}
	else if(strcmp(child1->type,"OptTag")==0) {
		//Todo:define a struct structure
		strcpy(s->name,child1->child[0]->text);
//		printf("child1->text:%s\n",s->name);
		child1 = node->child[3];
//		isOptTag(node->child[1],s);
/*		struct Structure *a=s;
		while(a!=NULL) {
			printf("aname:%s\n",a->name);
			a=a->next;
		}*/
		isDefList(child1,s);
/*		struct Structure *a=s;
		while(a!=NULL) {
			printf("aname:%s\n",a->name);
			a=a->next;
		}*/
		isOptTag(node->child[1],s);
/*		struct Structure *a=s;
		while(a!=NULL) {
			printf("aname:%s\n",a->name);
			a=a->next;
		}*/
		s->inStruct = 0;
	}
	else if(strcmp(child1->type,"Tag")==0) {
		//Todo:define a struct var
//		isOptTag(node->chlid[1],s);
//		printf("child1 %s\n",child1->child[0]->text);
		s->inStruct=1;
		isTag(child1,s);
	/*	while(s->next!=NULL){
			s=s->next;
			printf("sName is %s!\n",s->name);
		}*/
		s->inStruct = 0;
//		strcpy(s->name,"");
	}
	else {
		printf("syntax wrong\n");
	}
	*MyType = 3;
//	printf("struct::%s\n",s->name);
}
void isOptTag(struct treeNode *node, struct Structure *s){
//	printf("do OptTag\n");
	if(node == NULL) {
//		printf("OptTag is null\n");
//		printf("sname:%s\n",s->name);
		createStruct(NULL,s);
//		printStructTable();
//		return;
	}
	else {
		if(strcmp(node->type,"OptTag") != 0) {
			printf("Node is not OptTag\n");
			return;
		}
		if(node->child[0]==NULL){
//			printf("dddd\n");
			strcpy(s->name,"");
			return;
		}
		else{
//			printf("now sName %s\n",s->name);
			strcpy(s->name, node->child[0]->text);
		}
		struct treeNode *child0 = node->child[0];
//		strcpy(s->name, node->text);
		struct Structure *temp = TStruct;
//		printTable();
		while(temp != NULL) {
			if(strcmp(temp->name, s->name)==0) {
				printf("Error type 16 at line %d : Duplicated name '%s'\n",child0->line,child0->text);
			}
			temp = temp->next;
		}
		struct Structure *a=s;
		while(a!=NULL) {
//			printf("aname:%s\n",a->name);
			a=a->next;
		}
		createStruct(node, s);
//		printStructTable();
	}
	//Todo:
	
}
void isTag(struct treeNode *node,struct Structure *s){
//	printf("do Tag\n");
	struct treeNode *child0 = node->child[0];
//	printf("s->name is %s\n",s->name);
	//Todo:copy name
	if(strcmp(s->name,"")==0) {
		strcpy(s->name, child0->text);
	}
	else {
//		printf("s->name is not \"\"\n");
		struct Structure *sNext = (struct Structure *)malloc(sizeof(struct Structure));
		sNext->next=NULL;
		sNext->inStruct=1;
		strcpy(sNext->name,child0->text);
//		printf("sNextName %s\n",sNext->name);
		struct Structure *t = s;
		if(t==NULL){
			t=sNext;
		}
		else {
			while(t->next!=NULL) {
				t=t->next;
			}
			t->next=sNext;
		}

/*		t=s;
		while(t!=NULL){
			printf("tName%s~%d~\n",t->name,t->inStruct);
			t=t->next;
		}*/

	}
//	printf("test  %s\n",s->name);
}

void isVarDec(struct treeNode *node,enum type MyType, struct array *a, struct Structure *s){
//	printf("do VarDec\n");
	if(node == NULL) {
//		printf("VarDec is null\n");
		return;
	}
	if(strcmp(node->type,"VarDec") != 0) {
		printf("Node is not VarDec\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"ID")==0) {
		//Todo:
//		enum type t;
//		t = MyType;
//		printf("%d:create\n",MyType);
/*		struct array *temp = a;
		int num = 0;
		while(temp!=NULL){
			printf("111\n");
			num++;
			temp=temp->next;
		}
//		if(a )
//		if(a == NULL)
		printf("num:%d\n",num);*/
//		if(a!=NULL)
//			if(a->next!=NULL)
//				MyType = 2;
//		printf("num:%d\n",a->arrayType);

//		printf(">>>%d\n",a==NULL);
		createVar(MyType, child0, s, a);
//		printf("%s~~~\n",s->name);
	}
	else if(strcmp(child0->type,"VarDec")==0) {
		//Todo:
//		printf("11111111\n");
		struct array *temp = (struct array *)malloc(sizeof(struct array));
		temp->size = atoi(node->child[2]->text);
		temp->arrayType = 2;
		if(a == NULL){
//			printf("22222222\n");

			temp->next = NULL;
			a = temp;
		}
		else{
//			printf("3333333\n");
			temp->next = a;
			a = temp;
		}
//		printf("mmm11%d\n",MyType);
		isVarDec(child0, MyType, a, s);
//		printf("mmm%d\n",MyType);
//		printf("%d??\n",a==NULL);
		MyType = 2;
	}

}
void isFunDec(struct treeNode *node,enum type MyType){
//	printf("do FunDec\n");
	if(node == NULL) {
//		printf("FunDec is null\n");
		return;
	}
	if(strcmp(node->type,"FunDec") != 0) {
		printf("Node is not FunDec\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"ID")==0) {
		//Todo:
		struct argList *list;
		list = (struct argList*)malloc(sizeof(struct argList));
		list->next=NULL;
		list->argType=-1;
		strcpy(list->name,"");
		int num = 0;
		if(node->child[3]!=NULL){
			isVarList(node->child[2], list);
			struct argList *temp = list;
//			printf("list:%s\n", list->name);
//			printf("temp is null?%d\n",temp==NULL?1:0);
			while(temp!=NULL){
				num++;
				temp = temp->next;
			}
//			printf("num=%d\n",num);
		}
		else
			list = NULL;
		createFun(MyType, child0, num, list);
	}
}
void isVarList(struct treeNode *node, struct argList *list){
//	printf("do VarList\n");
	if(node == NULL) {
//		printf("VarList is null\n");
		return;
	}
	if(strcmp(node->type,"VarList") != 0) {
		printf("Node is not VarList\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	//Todo:
	struct argList *temp = (struct argList *)malloc(sizeof(struct argList));
//	struct argList *temp;
//	struct argList *p = (struct argList *)malloc(sizeof(struct argList));
//	p->next=NULL;
	isParamDec(child0, temp);

//	printf("name:%s type:%d\n",temp->name,temp->argType);
//	list = aL;
//	strcpy(p->name,temp->name);
//	p->argType=temp->argType;
/*	if(list == NULL) {
		printf("111111111");
		list = aL;
	}
	else {
		printf("222222222");
		aL->next=list;
		list=aL;
	}*/
//	printf("hu:%s %d\n", list->name,list->argType);
	if(list->argType == -1) {
		list->argType=temp->argType;
		strcpy(list->name,temp->name);
	}
	else {
		while(list->next != NULL) {
			list=list->next;
		}
		list->next=temp;
	}
//	temp->next=list;
//	list = temp;
	if(node->child[2]!=NULL){
//		printf("grgr\n");
		isVarList(node->child[2],list);
//		t->next = list;
//		list = t;
	}

//	list=p;
/*
	while(list!=NULL) {
		printf("%d~",list->argType);
		list = list->next;
	}
	printf("\n");*/
//	printf("hu:%s\n", list->name);
//	else{
//		list = aL;
//	}
}
void isParamDec(struct treeNode *node, struct argList *list){
//	printf("do ParamDec\n");
	if(node == NULL) {
//		printf("ParamDec is null\n");
		return;
	}
	if(strcmp(node->type,"ParamDec") != 0) {
		printf("Node is not ParamDec\n");
		return;
	}
	struct treeNode *child0 = node->child[0];//Specifier
	struct treeNode *child1 = node->child[1];//VarDec
	//Todo:
	struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
//	s = NULL;
	enum type t;
	s->inStruct = 0;
	isSpecifier(node->child[0], &t, s);
//	printf("paraDec:%d\n", t);
	struct array *a;
	a = NULL;
	isVarDec(node->child[1], t, a, s);
	
	strcpy(list->name, node->child[1]->child[0]->text);
//	printf("listName:%s\n",list->name);
	list->argType = t;
//	printf("listType:%d\n",list->argType);
}

void isCompSt(struct treeNode *node,enum type MyType){
//	printf("do CompSt\n");
	if(node == NULL) {
//		printf("CompSt is null\n");
		return;
	}
	if(strcmp(node->type,"CompSt") != 0) {
		printf("Node is not CompSt\n");
		return;
	}
	
	depth++;
	
	struct treeNode *child0 = node->child[0];//LC
	struct treeNode *child1 = node->child[1];//DefList
	struct treeNode *child2 = node->child[2];//StmtList
	struct treeNode *child3 = node->child[3];//RC
	struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
	if(strcmp(child0->type,"LC")!=0 || strcmp(child3->type,"RC")!=0) {
		printf("syntax error\n");
	}
	//Todo:
	isDefList(child1, s);
	isStmtList(child2, MyType);
//	printf("ok2\n");
/*	int i;
	
	for(i=0;i<1000;i++){
		if(varSymbol[i]!=NULL){
			if(varSymbol[i]->node->depth == depth){
				varSymbol[i]->node = varSymbol[i]->node->next;
				if(varSymbol[i]->node == NULL)
					varSymbol[i] = NULL;
			}
		}
	}
	depth--;*/
}
void isStmtList(struct treeNode *node, enum type MyType){
//	printf("do StmtList\n");
	if(node == NULL) {
//		printf("StmtList is null\n");
		return;
	}
	if(strcmp(node->type,"StmtList") != 0) {
		printf("Node is not StmtList\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	if(child0!=NULL) {
//		printf("%s\n",node->child[0]->text);
//		printf("11%s\n",child0->type);
		isStmt(child0, MyType);
		struct treeNode *child1 = node->child[1];
		isStmtList(child1, MyType);
//		printf("ok\n");
	}
}
void isStmt(struct treeNode *node, enum type MyType){
//	printf("do Stmt:%s %d\n",node->type, node->line);
	if(node == NULL) {
//		printf("Stmt is null\n");
		return;
	}
	if(strcmp(node->type,"Stmt") != 0) {
		printf("Node is not Stmt\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
//	printf("%s %s",child0->type, child0->text);
	if(strcmp(child0->type,"Exp")==0) {
		//Todo:
		struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
//		enum type *t;
	//	printf("%s\n", node->child[0]->child[0]->type);
		isExp(child0, &MyType, s);
	}
	else if(strcmp(child0->type,"CompSt")==0) {
		//Todo:
		isCompSt(node->child[0], MyType);
	}
	else if(strcmp(child0->type,"RETURN")==0) {
		//Todo:
		enum type t;
//		t = 0;
		struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
		isExp(node->child[1], &t, s);
//		printf("%d::%d\n", MyType, t);
		if(MyType!=t){
			printf("Error type 8 at line %d: Type mismatched for return\n", node->line);
			return;
		}
		
		
	}
	else if(strcmp(child0->type,"IF")==0) {
		//Todo:
		struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
		enum type t;
//		printf("t type is:%d\n",t);
/*		printf("child type is:%s\n",node->child[0]->type);
		printf("child type is:%s\n",node->child[1]->type);
		printf("child type is:%s\n",node->child[2]->type);
		printf("child type is:%s\n",node->child[3]->type);
		printf("child type is:%s\n",node->child[4]->type);
		printf("child type is:%s\n",node->child[5]->type);
		printf("child type is:%s\n",node->child[6]->type);*/
		isExp(node->child[2], &t, s);
//		printf("t type is:%d\n",t);
		if(t!=1 && t!=2){
			printf("Error type 7 at line %d: Type mismatched for operand\n", node->child[2]->line);
			return;
		}
		isStmt(node->child[4], MyType);
		if(node->child[6]!=NULL){
			isStmt(node->child[6], MyType);
		}
	}
	else if(strcmp(child0->type,"WHILE")==0) {
		//Todo:
		enum type t;
		struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
		isExp(node->child[2], &t, s);
		if(t!=1){
			printf("Error type 7 at line %d: Type mismatched for operand\n", node->child[2]->line);
			return;
		}
		isStmt(node->child[4], MyType);
	}
}

void isDefList(struct treeNode *node, struct Structure *s){
//	printf("do DefList\n");
	if(node == NULL) {
//		printf("DefList is null\n");
		return;
	}
	if(strcmp(node->type,"DefList") != 0) {
		printf("Node is not DefList\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	if(child0 == NULL){//ok, do nothing
		return;
	}
	else if(strcmp(child0->type,"Def")==0) {
		int state = s->inStruct;
//		printf("state:%d\n",state);
		isDef(child0, s);
		s->inStruct=state;
//		printf("name5 %s %d\n",s->name,s->inStruct);
		struct treeNode *child1 = node->child[1];
		isDefList(child1, s);
		s->inStruct=state;
//		printf("name6 %s %d\n",s->name,s->inStruct);
	}
//	printf("name5 %s\n",s->name);
}
void isDef(struct treeNode *node, struct Structure *s){
//	printf("do Def\n");
//	printf("%s\n", node->child[0]->type);
	if(node == NULL) {
//		printf("Def is null\n");
		return;
	}
	if(strcmp(node->type,"Def") != 0) {
		printf("Node is not Def\n");
		return;
	}
	struct treeNode *child0 = node->child[0];//Specifier
	struct treeNode *child1 = node->child[1];//DecList
	//Todo:
	enum type MyType;
	isSpecifier(child0, &MyType, s);
/*	while(s->next!=NULL) {
		s=s->next;
	}*/
	isDecList(child1, MyType, s);
//	strcpy(s->name,"");
//	s->inStruct=0;
}
void isDecList(struct treeNode *node, enum type MyType, struct Structure *s){
//	printf("do DecList\n");
	if(node == NULL) {
//		printf("DecList is null\n");
		return;
	}
	if(strcmp(node->type,"DecList") != 0) {
		printf("Node is not DecList\n");
		return;
	}
	struct treeNode *child0 = node->child[0];//Dec
	if(strcmp(child0->type,"Dec")==0) {
//		printf("name4 %s %d\n",s->name,s->inStruct);
		isDec(child0, MyType, s);
//		printf("name4 %s\n",s->name);
		struct treeNode *child1 = node->child[1];//COMMA
		if(child1 != NULL) {
			struct treeNode *child2 = node->child[2];//Declist
			isDecList(child2,MyType,s);
		}
	}
}
void isDec(struct treeNode *node, enum type MyType, struct Structure *s){
//	printf("do Dec\n");
	if(node == NULL) {
//		printf("Dec is null\n");
		return;
	}
	if(strcmp(node->type,"Dec") != 0) {
		printf("Node is not Dec\n");
		return;
	}
	struct treeNode *child0 = node->child[0];//VarDec
	//Todo:
	struct array *a = NULL;
//	printf("name3 %s %d\n",s->name,s->inStruct);
	isVarDec(child0, MyType, a, s);
//	printf("??%d\n",a==NULL);
	if(a != NULL) {
	//	printf("qweqwe");
		MyType = 2;
	}
	if(node->child[2] != NULL){
		if(s->inStruct == 1)
			printf("Error type 15 at Line %d: Initialized struct field '%s'\n",node->line, child0->child[0]->text);
		enum type t;
		isExp(node->child[2], &t, s);
		if(t!=MyType){
			printf("Error type 5 at line %d: Type mismatched for assignment\n", node->child[2]->line);
			return;
		}
	}
}
/*
void isExp(struct treeNode *node){
//	printf("do Exp\n");
	if(node == NULL) {
//		printf("Exp is null\n");
		return;
	}
	if(strcmp(node->type,"Exp") != 0) {
		printf("Node is not Exp\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	//Todo:
}*/

void isExp(struct treeNode *node, enum type *newType, struct Structure *structure){
//	printf("do Exp:%s\n",node->child[0]->type);
	if(node == NULL) {
		printf("Exp is null\n");
		return;
	}
	if(strcmp(node->type,"Exp") != 0) {
		printf("Node is not Exp\n");
		return;
	}
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"Exp")==0) {
	//	printf("exp exp\n");
		struct treeNode *child1 = node->child[1];
		if(strcmp(child1->type,"ASSIGNOP")==0) {
//			printf("assignop\n");
			struct treeNode *child2 = node->child[2];//Exp
			int typeIsOk = 0;
			struct treeNode *c0NextC0 = child0->child[0];//child[0] then child[0];
//			printf("%s\n", c0NextC0->type);
			if(strcmp(c0NextC0->type,"ID")==0) {//ID NULL
				struct treeNode *c0NextC1 = child0->child[1];
				if(c0NextC1 == NULL) {
					typeIsOk=1;      //left exp is ID
				}
			}
			if(strcmp(c0NextC0->type,"Exp")==0) {//Exp LB Exp RB   or   Exp Dot ID
				struct treeNode *c0NextC1 = child0->child[1];
//				printf("11%s\n",c0NextC1->type);
				if(strcmp(c0NextC1->type,"LB")==0) {
					if(strcmp(child0->child[2]->type,"Exp")==0 && strcmp(child0->child[3]->type,"RB")==0) {
						typeIsOk=1;
					}
				}
				else if(strcmp(c0NextC1->type,"DOT")==0) {
//					printf("22%s\n",child0->child[2]->type);
					if(strcmp(child0->child[2]->type,"ID")==0) {
						typeIsOk=1;
					}
				}
			}
			if(typeIsOk==0) {
				printf("Error type 6 at Line %d: Expression at the left side of the assignment has only rvalue.\n",child0->line);
				return;
			}

			enum type leftType;
			enum type rightType;
			char leftName[40];
			char rightName[40];
//			leftType = rightType;
//			printf("befo%s\n")
//			printf("%s %s\n",child0->type, child2->type);
			isExp(child0,&leftType, structure);
//			printf("name1 %s\n",structure->name);
			if(leftType == 3) {
				strcpy(leftName,structure->name);
			}
			//Todo:
			isExp(child2,&rightType, structure);
//			printf("name2 %s\n",structure->name);
			if(leftType == 3) {
				strcpy(rightName,structure->name);
			}
//			printf("r:%d\n",rightType);
			//Todo:
//			printf("hhh:%d:%d\n",leftType,rightType);
			if(leftType != rightType) {
//				printf("1\n");
				printf("Error type 5 at Line %d: Types at the both side of the assignment are different.\n",child0->line);
				return;
			}
			//Todo:if it is struct???
//			printf("%s  %s\n",leftName, rightName);
			if(leftType == 3){
				unsigned int hashL = getHash(leftName);
				unsigned int hashR = getHash(rightName);
//				printf("%d  %d  ~\n",hashL, hashR);
				struct symbol *tempL=varSymbol[hashL];
				struct symbol *tempR=varSymbol[hashR];
				int findL=0,findR=0;

				for(int i = 0; i < 1000; i++) {
					if(findL==0 && tempL != NULL) {
						if(strcmp(tempL->name, leftName)==0) {
							findL=1;
						}
						else {
							hashL++;
							if(hashL==1000) {
								hashL = 0;
							}
							tempL=varSymbol[hashL];
						}
					}
					if(findR==0 && tempR != NULL){
						if(strcmp(tempR->name, rightName)==0) {
							findR=1;
						}
						else {
							hashR++;
							if(hashR==1000){
								hashR=0;
							}
							tempR=varSymbol[hashR];
						}
					}
					if(findL==1 && findR ==1) break;
				}

//				printf("%d  %d  ~~~\n",findL, findR);
				
				if(tempL!=NULL && tempR !=NULL){
					if(strcmp(tempL->name,tempR->name)!=0) {
						printf("Error type 5 at Line %d: Type mismatched for assignment\n",child0->line);
					}
				}
			}
		}
		else if(strcmp(child1->type,"AND")==0||strcmp(child1->type,"OR")==0||strcmp(child1->type,"RELOP")==0||strcmp(child1->type,"PLUS")==0||strcmp(child1->type,"MINUS")==0||strcmp(child1->type,"STAR")==0||strcmp(child1->type,"DIV")==0){
//			printf("op:%s\n",child1->type);
			struct treeNode *child2 = node->child[2];
			enum type leftType;
			enum type rightType;
			isExp(child0,&leftType,structure);
			isExp(child2,&rightType,structure);
			if(leftType != rightType) {
				printf("Error Type 7 at line %d: Type mismatched for operands.\n",child0->line);
				return;
			}
			*newType=leftType;
//			printf("type~~%d\n",*newType);
		}
		else if(strcmp(child1->type,"LB")==0) {//Exp LB Exp RB
			//Todo:
			enum type t;
			isExp(child0,&t,structure);
//			printf("child0:%d\n",t);
//			printf("hwhd:%d\n",t);
			if(t != 2 && t != 1) {
				printf("Error type 10 at Line %d: '%s' is not an array, illegal use of \"[]\"\n", child0->line, child0->child[0]->text);
				return;
			}
			*newType = 2;
			struct treeNode *child2 = node->child[2];
			isExp(child2, &t, structure);
			*newType = t;
		}
		else if(strcmp(child1->type,"DOT")==0) {//Exp DOT ID
			//Todo:
//			printf("Here~");
			enum type t;
			isExp(node->child[0], &t, structure);
//			printf("t=%d\n",t);
			*newType=t;
			char sName[32];
//			printf("11%s\n",structure->name);
//			printTable();
			for(int i = 0; i < 1000; i++) {
				if(varSymbol[i]!=NULL) {
					if(strcmp(varSymbol[i]->name,structure->name)==0) {
						strcpy(sName,varSymbol[i]->node->structName);
						break;
					}
				}
			}
//			printf("sName:%s\t%s\n",node->child[2]->text,sName);
			if(t != 3){
				printf("Error type 13 at line %d:Illegal use of .\n", node->line);
				return;
			}
			struct Structure *temp = TStruct;
			while(strcmp(temp->name, sName)!=0) {
				temp=temp->next;
			}
//			while(strcmp(temp->name, structure->name) == 0){
//				temp = temp->next;
//			}
//			struct structField *tempF = temp->sMember;
			struct argList *tempF = temp->sMember;
//			printf("tempF is NULL?%d\n",tempF==NULL?1:0);
			while(tempF!=NULL){
				if(strcmp(tempF->name, node->child[2]->text) == 0){
					break;
				}
				tempF = tempF->next;
			}
			if(tempF==NULL){
				printf("Error type 14 at line %d: Non-existed field \"%s\"\n", node->line, node->child[2]->text);
				return;
			}
			struct treeNode *child2 = node->child[2];
//			printf("type%d",getVarType(child2));
			*newType=getVarType(child2);
			strcpy(structure->name,node->child[2]->text);
		}
	}
	else if(strcmp(child0->type,"LP")==0) {//??? 
	}
	else if(strcmp(child0->type,"MINUS")==0) {
		struct treeNode *child1 = node->child[1];
		isExp(child1,newType,structure);
	}
	else if(strcmp(child0->type,"NOT")==0) {//???
		struct treeNode *child1 = node->child[1];
		isExp(child1,newType,structure);
	}
	else if(strcmp(child0->type,"ID")==0) {
//		printf("do ID\n");
		strcpy(structure->name,child0->text);
		if(node->child[1] == NULL) { //ID is var
//			printf("haha:%s\n",child0->text);
			unsigned int hashVal = getHash(child0->text);
//			printf("%d\n",hashVal);
			struct symbol *temp = varSymbol[hashVal];
			int find = 0;
			int val=0;
			if(temp==NULL){
				printf("Error type 1 at Line %d: Undefined variable '%s'\n",child0->line, child0->text);
				return;
			}
			if(strcmp(child0->text,temp->name)==0) {
				find = 1;
			}
			else {
				while(strcmp(child0->text,temp->name)!=0) {
					hashVal++;
					if(hashVal == 1000) {
						hashVal=0;
					}
					temp=varSymbol[hashVal];
					if(strcmp(child0->text,temp->name)==0) {
						find = 1;
						break;
					}
					if(val == 999&&find==0){//not found
						break;
					}
					val++;
				}
			}
//			printf("child0->text:%s\n",child0->text);
			*newType = getVarType(child0);
//			printf("var:%d\n", *newType);
			if(find == 0){
				printf("Error type 1 at Line %d: Undefined variable '%s'\n",child0->line, child0->text);
				return;
			}
		}
		else {//ID is function
//			printf("ID is function\n");
			unsigned int hashFun = getHash(child0->text);
			struct symbol *temp = funSymbol[hashFun];
			int find = 0;
			int val=0;
/*			if(temp==NULL){
				printf("Error type 11 at Line %d: '%s' is not a function\n",child0->line,child0->text);
				return 0;
			}*/
//			printf("fun:%s,%d\n",temp->name,hashFun);
			if(temp!=NULL){
				if(strcmp(child0->text,funSymbol[hashFun]->name)==0) {
					find=1;
				}
				else {
					while(strcmp(child0->text,temp->name)!=0) {
						hashFun++;
						if(hashFun==1000) {
							hashFun=0;
						}
						temp=varSymbol[hashFun];
						if(strcmp(child0->text,temp->name)==0) {
							find = 1;
							break;
						}
						if(val == 999&&find==0){//not found
							break;
						}
						val++;
					}
				}
			}
//			printf("find is %d\n",find);
			if(find == 1){
				*newType = funSymbol[hashFun]->node->Smsg.Fmsg->FunType;
			}
//			printf("find:%d,%d\n",find,hashFun);
			if(find == 0||temp == NULL) {
	//			printf("111\n");
				hashFun = getHash(child0->text);
				temp = varSymbol[hashFun];
				if(temp==NULL){
					printf("Error type 2 at Line %d: Undefined function '%s'\n",child0->line,child0->text);
					return;
				}
				if(strcmp(child0->text,varSymbol[hashFun]->name)==0) {
					find=1;
					printf("Error type 11 at Line %d: '%s' is not a function\n",child0->line,child0->text);
					return;
				}
				else {
					while(strcmp(child0->text,temp->name)!=0) {
						hashFun++;
						if(hashFun==1000) {
							hashFun=0;
						}
						temp=varSymbol[hashFun];
						if(strcmp(child0->text,temp->name)==0) {
							find = 1;
							printf("Error type 11 at Line %d: '%s' is not a function\n",child0->line,child0->text);
							return;
							break;
						}
						if(val == 999&&find==0){//not found
							break;
						}
						val++;
					}
				}

				if(find==0) {
					printf("Error type 2 at Line %d: Undefined function '%s'\n",child0->line,child0->text);
					return;
				}
			}
			
			
			struct treeNode *child1 = node->child[1];
			if(strcmp(child1->type, "LP")==0) {
				struct treeNode *child2 = node->child[2];
				struct argList *funL=NULL;
				if(strcmp(child2->type,"Args")==0) {
					//Todo:
//					struct argList *funL;
					funL = isArgs(child2,*newType);

					//only for test
/*					struct argList *t = funL;
					while(t != NULL) {
						printf("%d  ",t->argType);
						t=t->next;
					}*/

//					printf("Args %d\n",funL->argType);
				}
				else if(strcmp(child2->type,"RP")==0) {
					//Todo:
					funL = NULL;
				}
				struct argList *listTemp = funL;
				struct argList *flistTemp = funSymbol[hashFun]->node->Smsg.Fmsg->msg;
		//		char listName[32];
		//		strcpy(listName,funSymbol[hashFun]->node->Smsg.Fmsg->msg->name);
		//		printf("listName:%s\n",listName);
//				printf("aaaaaaaaaa%d\n",listTemp==NULL?1:0);
				while(listTemp!=NULL){
					if(flistTemp==NULL){
						char n[32];
						enum type t;
						t = funSymbol[hashFun]->node->Smsg.Fmsg->msg->argType;
//						if(t==0)
//						n = changeType(t);
						strcpy(n,changeType(t));
						printf("Error type 9 at Line %d: \"%s(%s)\" is not applicable for arguments(",child2->line, funSymbol[hashFun]->name, n);
						struct argList *ftemp = funL;
						while(ftemp!=NULL){
							t = ftemp->argType;
//							n = changeType(t);
							strcpy(n,changeType(t));
							printf("%s,",n);
							ftemp=ftemp->next;
						}
						printf(").\n");
						break;
					}
					else if(flistTemp != NULL) {
						//Todo: judge if type of args is the same
						enum type t;
						char n[32];
						char n2[32];
						char structNameN[32];
						char structNameN2[32];
						strcpy(n,"");
						strcpy(n2,"");
						strcpy(structNameN,"");
						strcpy(structNameN2,"");
			//			strcpy(n,funSymbol[hashFun]->node->Smsg.Fmsg->msg->name);
						strcpy(n,listTemp->name);
						strcpy(n2,flistTemp->name);
				//		t = funSymbol[hashFun]->node->Smsg.Fmsg->msg->argType;
				//		strcpy(n,funSymbol[hashFun]->node->Smsg.Fmsg->msg->structName);
				//		strcpy(n2,changeType(flistTemp->argType));
						int find=0;
						for(int i = 0; i < 1000; i++) {
							if(varSymbol[i] != NULL) {
							if(strcmp(n,varSymbol[i]->name)==0) {
								strcpy(structNameN,varSymbol[i]->node->structName);
								find++;
							}
							if(strcmp(n2,varSymbol[i]->name)==0) {
								strcpy(structNameN2,varSymbol[i]->node->structName);
								find++;
							}
							}
							if(find==2) break;
						}
						if(strcmp(structNameN,structNameN2)!=0){
							printf("Error type 9 at Line %d: \"%s\" is not applicable for arguments\n",child2->line, funSymbol[hashFun]->name);
						}
//						printf("1.%s\n",structNameN);
//						printf("2.%s\n",structNameN2);
//						printf("1.%s\n",n);
//						printf("2.%s\n",n2);
					}
					flistTemp=flistTemp->next;
					listTemp=listTemp->next;
				}
				if(flistTemp!=NULL){
					char n[32];
					enum type t;
					t = funSymbol[hashFun]->node->Smsg.Fmsg->FunType;
//					if(t==0)
//					n = changeType(t);
					strcpy(n,changeType(t));
					printf("Error Type 9 at Line %d: \"%s(%s)\" is not applicable for arguments(",child2->line, funSymbol[hashFun]->name, n);
					struct argList *ftemp = funL;
					while(ftemp!=NULL){
						t = ftemp->argType;
//						n = changeType(t);
						strcpy(n,changeType(t));
						printf("%s,",n);
						ftemp=ftemp->next;
					}
					printf(").\n");
				}
			}
		}
	}
	else if(strcmp(child0->type,"INT")==0) {
	//	strcpy(structure->name,"INT");
//		printf("type is Array ?%d\n",*newType);
		if(*newType != 2) {//myint
			*newType =1;
		}
	}
	else if(strcmp(child0->type,"FLOAT")==0) {
	//	printf("%d\n",*newType);
		if(*newType == 2) {
			printf("Error type 12 at Line %d: %s is not an integer,expected an ingeter!\n",child0->line,child0->text);
			return;
		}
		else {//myfloat
			*newType = 0;
		}
	}
}


struct argList* isArgs(struct treeNode *node, enum type MyType){
//	printf("do Args\n");
	
	if(node == NULL) {
//		printf("Args is null\n");
		return NULL;
	}
	if(strcmp(node->type,"Args") != 0) {
		printf("Node is not Args\n");
		return NULL;
	}
	//Todo:
	struct treeNode *child0 = node->child[0];
	struct argList * a = (struct argList *)malloc(sizeof(struct argList));
	struct Structure *s = (struct Structure *)malloc(sizeof(struct Structure));
	strcpy(a->structName,"");
//	strcpy(s->structName,"");
//	printf("child0->child0:%s\n",child0->child[0]->text);
	isExp(child0,&MyType, s);
	a->argType = MyType;
	strcpy(a->name,child0->child[0]->text);
	a->next = NULL;
//	printf("ltype:%d\n",MyType);
	if(node->child[2]!=NULL){
//		list = a;
//		list = (struct argList *)malloc(sizeof(struct argList));
//		list = isArgs(node->child[2], MyType, &list);
		a->next = isArgs(node->child[2],MyType);
//		printf("hh:%d\n",list->argType);
//		list = a;
	}
//	printf("atype:%d\n",list->argType);
//	list = a;
	return a;
//	printf("atype:%d\n",list->argType);
}

void printVarTable() {
	printf("varTable:\n");
	printf("name  funOrVar structName  type  depth\n");
	for(int i = 0; i < 1000; i++) {
//		printf("%d*",i);
		struct symbol *temp = varSymbol[i];
		if(temp != NULL) {
//			printf("%s\t",temp->name);
//			printf("%d\t",temp->node->FunOrVar);
			printf("%s\t%d\t%s\t", temp->name,temp->node->FunOrVar,temp->node->structName);
			if(temp->node->FunOrVar==0){
				printf("%d\t",temp->node->Smsg.Fmsg->FunType);
			}
			else if(temp->node->FunOrVar==1){
				printf("%d\t",temp->node->Smsg.Vmsg->VarType);
			}
			printf("%d\n",temp->node->depth);

		}
	}
}
void printFunTable() {
	printf("FunTable:\n");
	printf("name  funOrVar  type  depth  args\n");
	for(int i = 0; i < 1000; i++) {
		struct symbol *temp = funSymbol[i];
		if(temp != NULL) {
			printf("%s\t%d\t", temp->name,temp->node->FunOrVar);
			if(temp->node->FunOrVar==0){
				printf("%d\t",temp->node->Smsg.Fmsg->FunType);
			}
			else if(temp->node->FunOrVar==1){
				printf("%d\t",temp->node->Smsg.Vmsg->VarType);
			}
			printf("%d\t",temp->node->depth);

			struct argList *args = temp->node->Smsg.Fmsg->msg;
			while(args!=NULL) {
				printf("%d,",args->argType);
				args=args->next;
			}
			printf("\n");
		}
	}
}
void printStructTable() {
	printf("StructTable:\n");
	struct Structure *Stemp = TStruct;
	printf("name\targList\n");
	while(Stemp!=NULL){
		printf("%s  ",Stemp->name);
		struct argList *member = Stemp->sMember;
		if(member == NULL) {
			printf("Member is NULL");
		}
		while(member != NULL) {
			printf("%s  ",member->name);
			member = member->next;
		}
		Stemp = Stemp->next;
		printf("\n");
	}

}
void printTable() {
	printVarTable();
	printFunTable();
	printStructTable();
}

int getIDFromTable(struct treeNode* node){
	
//	printf("node->text:%s\n",node->text);
	int val = getHash(node->text);
	struct symbol* temp = varSymbol[val]; 
	while(temp!=NULL){
		if(strcmp(temp->name, node->text)==0){
			return temp->node->Smsg.Vmsg->var_no;
		}
	}
	return 0;
}


struct msgFun *getFunMsg(struct treeNode *node){
	for(int i = 0; i < 1000; i++) {
		if(funSymbol[i]!=NULL) {
			if(strcmp(funSymbol[i]->name,node->text)==0) {
				return funSymbol[i]->node->Smsg.Fmsg;
			}
		}
	}
	return NULL;
}

int getVarIDByName(char *name) {
	for(int i = 0; i < 1000; i++) {
		if(varSymbol[i]!=NULL) {
			if(strcmp(varSymbol[i]->name,name)==0) {
				return varSymbol[i]->node->Smsg.Vmsg->var_no;
			}
		}
	}
	return 0;
}
