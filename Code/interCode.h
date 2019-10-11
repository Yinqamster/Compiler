#ifndef INTERCODE_H
#define INTERCODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domtree.h"
#include "semantic.h"

//typedef struct Operand_ *Operand;
//typedef struct InterCode_ *InterCode;
//typedef struct InterCodes_ *InterCodes;
typedef enum {EQ,NE,GT,LT,GE,LE} relop_type;

struct Operand{
	enum {VARIABLE_op, CONSTANT_op, ADDRESS_op, TEMPVAR_op, REFERENCE_op, LABEL_op, PARAM_op, FUNCTION_op} kind;
	union {
		int var_no;
		int value;
		int label_no;
		int temp_no;
		int addr_no;
		char *func_name;
		char *param_name;
	}u;
};

struct InterCode{
	enum {ASSIGN, PLUS, MINUS, MUL, DIV, RETURN, LABEL, GOTO, IFGOTO, DEC, ARG, CALL, PARAM, WRITE, READ, FUNCTION} kind;
	union {
		//return lable goto read write arg function param
		struct {struct Operand* op;} single;
		//call dec assign
		struct {struct Operand* right, *left;} assign;
		//plus minus mul div
		struct {struct Operand* result, *op1, *op2;} binop;
		//if...goto...
		struct {struct Operand* left, *right, *label;
			    relop_type relopType;
		} triop;
	}u;
};

struct InterCodes{
	struct InterCode *code;
    struct InterCodes *prev, *next;
};

extern struct InterCodes *CodeHead,*CodeTail;
extern int temp_num,label_num;

//extern void init();
//extern void intermediate();
extern void visitTree(struct treeNode *node, int i);
extern void insertCode(struct InterCodes *code);
extern relop_type get_relop(struct treeNode *node);
//extern void delete_code(intercodes code);
extern void printCode(char *fileName);
extern void printf_operand(struct Operand *op, FILE *fp);
extern void printf_type(struct InterCode* inter, FILE *fp);
extern struct Operand* new_temp();
//extern operand new_tmp_id(int id);
extern struct Operand* myVar(int id);
extern struct Operand* myConst(int value);
extern struct Operand* new_reference(int id);
extern struct Operand* new_label();
extern struct Operand* new_function(char *func_name);
extern struct Operand* new_param(char *param_name);
extern struct InterCodes* add_assign(struct Operand* left, struct Operand* right);
extern struct InterCodes* add_call(struct Operand* left, struct Operand* right);
extern struct InterCodes* add_dec(struct Operand* left, struct Operand* right);
extern struct InterCodes* add_triop(relop_type type,struct Operand* c1, struct Operand* c2, struct Operand* label);
extern struct InterCodes* add_return(struct Operand* op);
extern struct InterCodes* add_label(struct Operand* op);
extern struct InterCodes* add_goto(struct Operand* op);
extern struct InterCodes* add_read(struct Operand* op);
extern struct InterCodes* add_write(struct Operand* op);
extern struct InterCodes* add_arg(struct Operand* op);
extern struct InterCodes* add_function(struct Operand* op);
extern struct InterCodes* add_param(struct Operand* op);
extern struct InterCodes* add_add(struct Operand* result, struct Operand* op1, struct Operand* op2);
extern struct InterCodes* add_sub(struct Operand* result, struct Operand* op1, struct Operand* op2);
extern struct InterCodes* add_mul(struct Operand* result, struct Operand* op1, struct Operand* op2);
extern struct InterCodes* add_div(struct Operand* result,struct  Operand* op1, struct Operand* op2);

extern struct InterCodes* translate_Exp(struct treeNode *node, struct Operand* place);
extern struct InterCodes* translate_Cond(struct treeNode *node, struct Operand* label_true,struct Operand* label_false);
extern struct InterCodes* translate_Stmt(struct treeNode *node);
extern struct InterCodes* translate_CompSt(struct treeNode *node);
extern struct InterCodes* translate_StmtList(struct treeNode *node);
extern struct InterCodes* translate_StmtList(struct treeNode *node);
extern struct InterCodes* translate_VarDec(struct treeNode *node,struct Operand *place);
extern struct InterCodes* translate_DefList(struct treeNode *node);
extern struct InterCodes* translate_Def(struct treeNode *node);
extern struct InterCodes* translate_DecList(struct treeNode *node);
extern struct InterCodes* translate_Dec(struct treeNode *node);
extern struct InterCodes* translate_FunDec(struct treeNode *node);
extern struct InterCodes* translate_VarList(struct treeNode *node);
extern struct InterCodes* translate_ParamDec(struct treeNode *node);
extern struct InterCodes* translate_ExtDef(struct treeNode *node);
extern struct InterCodes* translate_ExtDecList(struct treeNode *node);
extern struct InterCodes* translate_Args(struct treeNode *node,struct Operand *arg_list,int *arg_num);
extern struct InterCodes* translate_array(struct treeNode *node,struct Operand *place);



#endif
