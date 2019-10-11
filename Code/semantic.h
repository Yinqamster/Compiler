#ifndef SEMANTIC_H
#define SEMANTIC_H
#include "domtree.h"

enum type{myfloat,myint,myarray,mystruct};

union varp {
	struct Structure *sp;
	struct array *ap;
};
struct array{
	enum type arrayType;
	int size;
	struct array *next;
};

struct structField{
	char name[32];
	int  basicOrArray;	
	enum type sFtype;
	struct array *sFa;
	
};

struct Structure{
	char name[32];
//	struct array *S_array;
//	struct structField *f;
	struct Structure *next;
	int depth;
	struct argList *sMember;
	int inStruct;
//	int 
};

struct argList{
	char name[32];
	struct array *a;
	char structName[32];
	enum type argType;
	struct argList *next;
};

struct msgFun{
	int num;
	enum type FunType;
	struct argList *msg;
};

struct msgVar{
	enum type VarType;
	int ArrayOrStructOrBasic;
//	char name[32];
	struct Structure *Vstruct;
	struct array *Varray;
	int var_no;
};

union msgSymbol{
	struct msgVar *Vmsg;
	struct msgFun *Fmsg;
};

struct NodeSymbol{
	int FunOrVar;//fun 0 var 1
	struct NodeSymbol *next;
	char structName[32];
	int line;
	int depth;
	union msgSymbol Smsg;
};

struct symbol{
	struct NodeSymbol *node;
	char name[32];
	int ifUse;//0 not use 1 use
};

extern void init();
extern int getIDFromTable(struct treeNode* node);
extern struct msgFun *getFunMsg(struct treeNode *node);
extern int getVarIDByName(char *name);
extern void startSemantic();
extern void createFun(enum type funType, struct treeNode *node, int varNum, struct argList *myList);
extern void isProgram(struct treeNode *node);
extern void isExtDefList(struct treeNode *node);
extern void isExtDef(struct treeNode *node);
extern void isExtDecList(struct treeNode *node,struct Structure *s, enum type MyType);

extern void isSpecifier(struct treeNode *node,enum type *MyType, struct Structure *s);
extern void isStructSpecifier(struct treeNode *node,enum type *MyType, struct Structure *s);
extern void isOptTag(struct treeNode *node, struct Structure *s);
extern void isTag(struct treeNode *node,struct Structure *s);

extern void isVarDec(struct treeNode *node,enum type MyType, struct array *a, struct Structure *s);
extern void isFunDec(struct treeNode *node,enum type makMyType);
extern void isVarList(struct treeNode *node, struct argList *list);
extern void isParamDec(struct treeNode *node, struct argList *list);

extern void isCompSt(struct treeNode *node,enum type MyType);
extern void isStmtList(struct treeNode *node,enum type MyType);
extern void isStmt(struct treeNode *node,enum type MyType);

extern void isDefList(struct treeNode *node, struct Structure *s);
extern void isDef(struct treeNode *node, struct Structure *s);
extern void isDecList(struct treeNode *node, enum type MyType, struct Structure *s);
extern void isDec(struct treeNode *node, enum type MyType, struct Structure *s);

extern void isExp(struct treeNode *node,enum type *newType, struct Structure *structure);
extern struct argList* isArgs(struct treeNode *node, enum type MyType);

extern void printTable();
#endif
