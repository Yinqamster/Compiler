#include "interCode.h"

extern struct treeNode *treeRoot;

struct InterCodes *CodeHead = NULL;
struct InterCodes *CodeTail = NULL;
int temp_num=0;
int label_num=0;

void visitTree(struct treeNode *node, int i){
	if(node == NULL){
		i=0;
		return;
	}
//	printf("node->type:%s\n",node->type);
	if(strcmp(node->type,"ExtDef")==0){
		translate_ExtDef(node);
		i++;
//		printf("NUUULL?%d\t%d\n",i,node->parent==NULL?1:0);
		if(node->parent==NULL) {
			visitTree(NULL, i);
		}
		else {
//	printf("node->type0:%s\n",node->parent->child[i]->type);
			visitTree(node->parent->child[i], i);
		}
//		printf("abcde\n");
	}
	else{
//	printf("node->type1:%s\n",node->child[0]->type);
		visitTree(node->child[0],0);
//		printf("abcdefg\n");
		i++;
		if(node->parent==NULL) {
			visitTree(NULL, i);
		}
		else {
//	printf("node->type2:%s\n",node->parent->child[i]->type);
			visitTree(node->parent->child[i], i);
		}
//		printf("abcdefghi\n");
	}
}

void insertCode(struct InterCodes *code){
	if(CodeHead == NULL){
		CodeHead = code;
		CodeTail = code;
		code->prev = code;
		code->next = code;
	}
	else{
		CodeTail->next = code;
		code->prev = CodeTail;
		code->next = CodeHead;
		CodeTail = code;
		CodeHead->prev = CodeTail;
	}
}

void printCode(char *fileName){
	FILE *fp = fopen(fileName, "w");
	if(fp == NULL)
		return;
	visitTree(treeRoot, 0);
	struct InterCodes* temp = CodeHead;
	CodeTail->next=NULL;
	while(temp != NULL){
//			printf("kind %d\n",temp->code->kind);
		switch(temp->code->kind){
			case ASSIGN:
				printf_operand(temp->code->u.assign.left, fp);
				fprintf(fp, " := ");
				printf_operand(temp->code->u.assign.right, fp);
				fprintf(fp, "\n");
				break;
			case PLUS:
				printf_operand(temp->code->u.binop.result, fp);
				fprintf(fp, " := ");
				printf_operand(temp->code->u.binop.op1, fp);
				fprintf(fp, " + ");
				printf_operand(temp->code->u.binop.op2, fp);
				fprintf(fp, "\n");
				break;
			case MINUS:
				printf_operand(temp->code->u.binop.result, fp);
				fprintf(fp, " := ");
				printf_operand(temp->code->u.binop.op1, fp);
				fprintf(fp, " - ");
				printf_operand(temp->code->u.binop.op2, fp);
				fprintf(fp, "\n");
				break;
			case MUL:
				printf_operand(temp->code->u.binop.result, fp);
				fprintf(fp, " := ");
				printf_operand(temp->code->u.binop.op1, fp);
				fprintf(fp, " * ");
				printf_operand(temp->code->u.binop.op2, fp);
				fprintf(fp, "\n");
				break;
			case DIV:
				printf_operand(temp->code->u.binop.result, fp);
				fprintf(fp, " := ");
				printf_operand(temp->code->u.binop.op1, fp);
				fprintf(fp, " / ");
				printf_operand(temp->code->u.binop.op2, fp);
				fprintf(fp, "\n");
				break;
			case RETURN:
				fprintf(fp, "RETURN ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, "\n");
				break;
			case LABEL:
				fprintf(fp, "LABEL ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, " :\n");
				break;
			case GOTO:
				fprintf(fp, "GOTO ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, "\n");
				break;
			case IFGOTO:
				fprintf(fp, "IF ", fp);
				printf_operand(temp->code->u.triop.left, fp);
				printf_type(temp->code, fp);
				printf_operand(temp->code->u.triop.right, fp);
				fprintf(fp, " GOTO ");
				printf_operand(temp->code->u.triop.label, fp);
				fprintf(fp, "\n");
				break;
			case DEC:
				fprintf(fp, "DEC ", fp);
				printf_operand(temp->code->u.assign.left, fp);
				fprintf(fp, " ");
				fprintf(fp, "%d", temp->code->u.assign.right->u.value);
				fprintf(fp, "\n");
				break;
			case ARG:
				fprintf(fp, "ARG ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, "\n");
				break;
			case CALL:
				printf_operand(temp->code->u.assign.left, fp);
				fprintf(fp, " := CALL ");
				printf_operand(temp->code->u.assign.right, fp);
				fprintf(fp, "\n");
				break;
			case PARAM:
				fprintf(fp, "PARAM ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, "\n");
				break;
			case READ:
				fprintf(fp, "READ ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, "\n");
				break;
			case WRITE:
				fprintf(fp, "WRITE ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, "\n");
				break;
			case FUNCTION:
				fprintf(fp, "FUNCTION ");
				printf_operand(temp->code->u.single.op, fp);
				fprintf(fp, " :\n");
				break;
		}
		temp=temp->next;
	}
	fclose(fp);
}

void printf_operand(struct Operand *op, FILE *fp){
//	printf("kkkkind%d\n",op->kind);
	switch(op->kind){
		case TEMPVAR_op:
			fprintf(fp, "t%d", op->u.temp_no);
			break;
		case VARIABLE_op:
			fprintf(fp, "v%d", op->u.var_no);
			break;
		case CONSTANT_op:
			fprintf(fp, "#%d", op->u.value);
			break;
		case REFERENCE_op:
			fprintf(fp, "&v%d", op->u.var_no);
			break;
		case ADDRESS_op:
			fprintf(fp, "*t%d", op->u.temp_no);
			break;
		case LABEL_op:
			fprintf(fp, "label%d", op->u.label_no);
			break;
		case FUNCTION_op:
			fprintf(fp, "%s", op->u.func_name);
			break;
		case PARAM_op:
			fprintf(fp, "%s", op->u.param_name);
			break;
	}
}

void printf_type(struct InterCode* inter, FILE *fp){
	switch(inter->u.triop.relopType){
		case LT:
			fprintf(fp, " < ");
			break;
		case GT:
			fprintf(fp, " > ");
			break;
		case EQ:
			fprintf(fp, " == ");
			break;
		case NE:
			fprintf(fp, " != ");
			break;
		case LE:
			fprintf(fp, " <= ");
			break;
		case GE:
			fprintf(fp, " >= ");
			break;
	}
}

relop_type get_relop(struct treeNode *node){
	char value[32];
	strcpy(value,node->text);
	if(strcmp(value,"==")==0) return EQ;
	if(strcmp(value,"!=")==0) return NE;
	if(strcmp(value,">")==0) return GT;
	if(strcmp(value,"<")==0) return LT;
	if(strcmp(value,">=")==0) return GE;
	if(strcmp(value,"<=")==0) return LE;
}

//assign
struct InterCodes* add_assign(struct Operand* left, struct Operand* right){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = ASSIGN;
	InCode->code->u.assign.left = left;
	InCode->code->u.assign.right = right;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_call(struct Operand* left, struct Operand* right){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = CALL;
	InCode->code->u.assign.left = left;
	InCode->code->u.assign.right = right;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_dec(struct Operand* left, struct Operand* right){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = DEC;
	InCode->code->u.assign.left = left;
	InCode->code->u.assign.right = right;
	insertCode(InCode);
	return InCode;
}

//triop
struct InterCodes* add_triop(relop_type type,struct Operand* c1, struct Operand* c2, struct Operand* label){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = IFGOTO;
	InCode->code->u.triop.relopType=type;
	InCode->code->u.triop.label=label;
	InCode->code->u.triop.left=c1;
	InCode->code->u.triop.right=c2;
	insertCode(InCode);
	return InCode;
}

//single op
struct InterCodes* add_return(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = RETURN;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_label(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = LABEL;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_goto(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = GOTO;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_read(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = READ;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_write(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = WRITE;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_arg(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = ARG;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_function(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = FUNCTION;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_param(struct Operand* op){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = PARAM;
	InCode->code->u.single.op=op;
	insertCode(InCode);
	return InCode;
}

//binop
struct InterCodes* add_plus(struct Operand* result, struct Operand* op1, struct Operand* op2){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = PLUS;
	InCode->code->u.binop.result=result;
	InCode->code->u.binop.op1=op1;
	InCode->code->u.binop.op2=op2;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_minus(struct Operand* result, struct Operand* op1, struct Operand* op2){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = MINUS;
	InCode->code->u.binop.result=result;
	InCode->code->u.binop.op1=op1;
	InCode->code->u.binop.op2=op2;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_mul(struct Operand* result, struct Operand* op1, struct Operand* op2){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = MUL;
	InCode->code->u.binop.result=result;
	InCode->code->u.binop.op1=op1;
	InCode->code->u.binop.op2=op2;
	insertCode(InCode);
	return InCode;
}
struct InterCodes* add_div(struct Operand* result,struct  Operand* op1, struct Operand* op2){
	struct InterCodes *InCode = (struct InterCodes*)malloc(sizeof(struct InterCodes));
	InCode->prev=NULL;
	InCode->next=NULL;
	InCode->code = (struct InterCode*)malloc(sizeof(struct InterCode));
	InCode->code->kind = DIV;
	InCode->code->u.binop.result=result;
	InCode->code->u.binop.op1=op1;
	InCode->code->u.binop.op2=op2;
	insertCode(InCode);
	return InCode;
}


struct Operand* myConst(int value){
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind = CONSTANT_op;
	op->u.value = value;
	return op;
}

struct Operand* myVar(int id){
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind = VARIABLE_op;
	op->u.var_no = id;
	return op;
}

struct Operand* new_temp(){
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind = TEMPVAR_op;
//	printf("%d\n",temp_num);
	op->u.temp_no=temp_num++;
	return op;
}

struct Operand* new_label() {
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind=LABEL_op;
	op->u.label_no=label_num++;
	return op;
}

struct Operand* new_reference(int id) {
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind=REFERENCE_op;
	op->u.addr_no=id;
	return op;
}

struct Operand* new_function(char *func_name) {
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind = FUNCTION_op;
	op->u.func_name=func_name;
	return op;
}

struct Operand* new_param(char *param_name) {
	struct Operand *op = (struct Operand*)malloc(sizeof(struct Operand));
	op->kind=PARAM_op;
	op->u.param_name=param_name;
	return op;

}

struct InterCodes* translate_Exp(struct treeNode *node, struct Operand* place){
	if(node->child[0]==NULL)
		return NULL;
//	printf("node->child0->type:%s\n",node->child[0]->type);
	struct InterCodes* code0, *code1, *code2, *code3, *code4;
	if(strcmp(node->child[0]->type, "INT")==0){
		struct Operand *rightOperand = myConst(atoi(node->child[0]->text));
		code0 = add_assign(place, rightOperand);
		return code0;
	}
//	printf("null?%d\n",node->child[1]==NULL?1:0);
	if(strcmp(node->child[0]->type, "ID")==0&&node->child[1]==NULL){
//		printf("~~\n");
		int MyId = getIDFromTable(node->child[0]);
//		printf("MyId:%d\n",MyId);
		struct Operand *op = myVar(MyId);
		code0 = add_assign(place,op);
		return code0;
	}
	if(strcmp(node->child[0]->type,"Exp") == 0 && strcmp(node->child[1]->type,"ASSIGNOP")==0){
		int id = getIDFromTable(node->child[0]->child[0]);
		struct Operand *var = myVar(id);
		struct Operand *t1 = new_temp();
		code0 = translate_Exp(node->child[2],t1);    //??? is place?
		code1 = add_assign(var, t1);
		if(place!=NULL) {
		code2 = add_assign(place, var);
		}
		return code0;
	}
//	printf("sssssss%s\n",node->child[1]->type);
	if(strcmp(node->child[0]->type,"Exp") == 0 && 
			(strcmp(node->child[1]->type,"PLUS") == 0 || 
			 strcmp(node->child[1]->type,"MINUS") == 0|| 
			 strcmp(node->child[1]->type,"STAR") == 0 ||
			 strcmp(node->child[1]->type,"DIV") == 0)){
//		printf("ccccccc\n");
		struct Operand *op1 = new_temp();
		struct Operand *op2 = new_temp();
		code0 = translate_Exp(node->child[0], op1);
		code1 = translate_Exp(node->child[2], op2);
		if(strcmp(node->child[1]->type, "PLUS") == 0)
			code2 = add_plus(place, op1, op2);
		else if(strcmp(node->child[1]->type, "MINUS") == 0)
			code2 = add_minus(place, op1, op2);
		else if(strcmp(node->child[1]->type, "STAR") == 0)
			code2 = add_mul(place, op1, op2);
		else if(strcmp(node->child[1]->type, "DIV") == 0)
			code2 = add_div(place, op1, op2);
		return code0;
	}
	if(strcmp(node->child[0]->type, "MINUS") == 0){
		struct Operand *t1 = new_temp();
		code0 = translate_Exp(node->child[1], t1);
		struct Operand *t2 = myConst(0);
		code1 = add_minus(place, t2, t1);
		return code0;
	}
	if(strcmp(node->child[1]->type, "RELOP") == 0 || strcmp(node->child[0]->type, "NOT") == 0 || strcmp(node->child[1]->type, "AND") == 0 || strcmp(node->child[1]->type, "OR") == 0){
		struct Operand *label1 = new_label();
		struct Operand *label2 = new_label();
		struct Operand *const0 = myConst(0);
		struct Operand *const1 = myConst(1);
		code0 = add_assign(place, const0);
		code1 = translate_Cond(node, label1, label2);
		code2 = add_label(label1);
		code3 = add_assign(place, const1);
		code4 = add_label(label2);
		return code0;
	}
	if(strcmp(node->child[1]->type,"LP")==0 && strcmp(node->child[2]->type, "RP") == 0){
		char *function = node->child[0]->text;
		if(strcmp(function, "read") == 0){
			if(place==NULL) {
			struct Operand *t1 = new_temp();
//			printf("temp_no:%d\n",temp_num);
			code0 = add_read(t1);
			}
			else {
				code0=add_read(place);
//			printf("temp_no:%d\n",temp_num);
			}
			return code0;
		}
		struct Operand *func = new_function(function);
		if(place != NULL && place->kind != ADDRESS_op){
			code0 = add_call(place, func);
		}
		else if(place != NULL && place->kind==ADDRESS_op) {
			struct Operand *t = new_temp();
			code0 = add_call(t, func);
			code1 = add_assign(place, t);
		}
		else {
			struct Operand *t1 = new_temp();
			code0=add_call(t1,func);
		}
		return code0;
	}
	if(strcmp(node->child[2]->type, "Args")==0){
		int num = 0;
		char *func_name = node->child[0]->text;
//		printf("func_name:%s\n",func_name);
		struct Operand *arg_list = (struct Operand *)malloc(sizeof(struct Operand) * 8);
		code0 = translate_Args(node->child[2], arg_list, &num);
		if(strcmp(func_name, "write") == 0){
		//	code1 = add_write(arg_list[0]);
			if(arg_list->kind == ADDRESS_op) {
				struct Operand *t = new_temp();
				code1=add_assign(t,arg_list);
				code2 = add_write(t);
			}
			else {
				code1 = add_write(arg_list);
			}
			return code0;
		}
		int i;
//		printf("num %d\n",num);
		for(i = 0; i < num; i++){
//			printf("value %d\n",(arg_list+i)->u.value);
			code1 = add_arg(arg_list+i);
//			code2 = add_arg(arg_list[i]);
		}
		struct Operand *function = new_function(func_name);
		if(place != NULL&&place->kind != ADDRESS_op) {
			code2=add_call(place,function);
		}
		else if(place !=NULL&&place->kind==ADDRESS_op) {
			struct Operand *t = new_temp();
			code2 = add_call(t, function);
			code3 = add_assign(place, t);
		}
		else {
			struct Operand *t = new_temp();
			code2 = add_call(t,function);
		}
		return code0;
	}
	if(strcmp(node->child[0]->type, "LP") == 0) {
//		printf("ttttt%s\n",node->child[1]->type);
		return translate_Exp(node->child[1], place);
	}
	if(strcmp(node->child[0]->type, "LB") == 0)
		return translate_array(node, place);
	return NULL;
}

struct InterCodes* translate_Cond(struct treeNode *node, struct Operand* label_true,struct Operand* label_false) {
	struct treeNode *child0 = node->child[0];
//		printf("child0->type:%s\n",child0->type);
	struct InterCodes *code0=NULL,*code1=NULL,*code2=NULL,*code3=NULL;
	if(node->child[1] != NULL) {
		struct treeNode *child1 = node->child[1];
//		printf("child1->type:%s\n",child1->type);
		//Exp1 RELOP Exp2
		if(strcmp(child1->type,"RELOP")==0) {
			struct Operand *t1 = new_temp();
			struct Operand *t2 = new_temp();

//			printf("aaa\n");
			code0 = translate_Exp(child0,t1);
			struct treeNode *child2 = node->child[2];
			code1 = translate_Exp(child2,t2);

			relop_type op = get_relop(child1);

			code2 = add_triop(op,t1, t2, label_true);
			code3 = add_goto(label_false);

			return code0;
		}
		//NOT Exp1
		if(strcmp(child0->type,"NOT")==0) {
			return translate_Cond(node->child[1],label_true,label_false);
		}
		//Exp1 AND Exp2
		if(strcmp(child1->type,"AND")==0) {
			struct Operand *label = new_label();
			code1 = translate_Cond(child0,label,label_false);
			code2 = add_label(label);
			code3 = translate_Cond(node->child[2],label_true,label_false);
			return code1;
		}
		//Exp1 OR Exp2
		if(strcmp(child1->type,"OR")==0) {
			struct Operand *label = new_label();
			code1 = translate_Cond(child0,label_true,label);
			code2 = add_label(label);
			code3 = translate_Cond(node->child[2],label_true,label_false);
			return code1;
		}
		//other
		struct Operand *t1 = new_temp();
		code1=translate_Exp(node,t1);
		struct Operand *c1 = myConst(0);
		code2=add_triop(NE,t1,c1,label_true);
		code3=add_label(label_false);
		return code1;
	}
}


struct InterCodes* translate_ExtDef(struct treeNode *node){
	struct InterCodes* code0, *code1;
	if(node->child[0] == NULL)
		return NULL;
//	printf("node->child1->type:%s\n",node->child[1]->type);
	if(strcmp(node->child[1]->type,"SIMI")==0)
		return NULL;
	else{
		//Specifier ExtDecList SEMI
		if(strcmp(node->child[1]->type, "ExtDecList")==0){
			return translate_ExtDecList(node->child[1]);
		}
		//Specifier FunDec CompSt
		else if(node->child[1]->type, "FunDec"){
			code0 = translate_FunDec(node->child[1]);
			code1 = translate_CompSt(node->child[2]);
			return code0;
		}
	}
	return NULL;
}

struct InterCodes* translate_Stmt(struct treeNode *node) {
	struct treeNode *child0 = node->child[0];
	struct InterCodes *code0,*code1,*code2,*code3,*code4,*code5,*code6;
//	printf("child0->type%s\n",child0->type);
	//Exp SEMI
	if(strcmp(child0->type,"Exp")==0) {
		return translate_Exp(child0,NULL);
	}
	//CompSt
	if(strcmp(child0->type,"CompSt")==0) {
		return translate_CompSt(child0);
	}
	//RETURN Exp SEMI
	if(strcmp(child0->type,"RETURN")==0) {
		struct Operand *t1 = new_temp();
		code0=translate_Exp(node->child[1],t1);
		code1=add_return(t1);
		return code0;
	}
	if(strcmp(child0->type,"IF")==0) {
		struct treeNode *child5 = node->child[5];
	//IF LP Exp RP Stmt1
		if(child5==NULL) {
			struct Operand *label1 = new_label();
			struct Operand *label2 = new_label();
			code0=translate_Cond(node->child[2],label1,label2);
			code1=add_label(label1);
			code2=translate_Stmt(node->child[4]);
			code3=add_label(label2);
			return code0;
		}
	//IF LP Exp RP Stmt1 ELSE Stmt2
		else {
			struct Operand *label1 = new_label();
			struct Operand *label2 = new_label();
			struct Operand *label3 = new_label();
//			printf("before cond\n");
			code0=translate_Cond(node->child[2],label1,label2);
//			printf("after cond\n");
			code1=add_label(label1);
			code2=translate_Stmt(node->child[4]);
			code3=add_goto(label3);
			code4=add_label(label2);
			code5=translate_Stmt(node->child[6]);
			code6=add_label(label3);
			return code0;

		}
	}
	//WHILE LP Exp RP Stmt1
	if(strcmp(child0->type,"WHILE")==0){
		struct Operand *label1 = new_label();
		struct Operand *label2 = new_label();
		struct Operand *label3 = new_label();
		code0=add_label(label1);
		code1=translate_Cond(node->child[2],label2,label3);
		code2=add_label(label2);
		code3=translate_Stmt(node->child[4]);
		code4=add_goto(label1);
		code5=add_label(label3);
		return code0;
	}
}

struct InterCodes* translate_CompSt(struct treeNode *node) {
	struct InterCodes *code0=NULL,*code1=NULL;
	struct treeNode *child0=node->child[0];
//	printf("start\n");
	//LC DefList StmtList RC
	if(child0==NULL) {
		return NULL;
	}
	if(node->child[1]!=NULL&&strcmp(node->child[1]->type,"DefList")==0) {
		code0=translate_DefList(node->child[1]);
	}
	if(strcmp(node->child[2]->type,"StmtList")==0) {
//		printf("before\n");
		code1=translate_StmtList(node->child[2]);
//		printf("after\n");
	}
//	printf("finish\n");
	return code0;
}

struct InterCodes* translate_StmtList(struct treeNode *node) {
	struct InterCodes *code0=NULL,*code1=NULL;
	if(node==NULL) return NULL;
	struct treeNode *child0 = node->child[0];
	//Stmt StmtList
	code0=translate_Stmt(child0);
	code1=translate_StmtList(node->child[1]);
	return code0;
}
int get_structure_size(union varp vp, enum type varType) {
}
union varp getVar(struct treeNode *node,enum type *varType) {
}

struct InterCodes* translate_VarDec(struct treeNode *node, struct Operand *place) {
	struct InterCodes *code0=NULL,*code1=NULL,*code2=NULL,*code3=NULL;
	struct treeNode *child0 = node->child[0];
	//ID
	if(strcmp(child0->type,"ID")==0) {
		//TODO:
		int id = getIDFromTable(child0);
		struct Operand *v1 = myVar(id);
		enum type varType;
		union varp vp = getVar(child0,&varType);
		if(place != NULL) {
			*place = *v1;
		}
		if(varType == myint || varType == myfloat) {
			return NULL;
		}
		else if(varType == myarray || varType == mystruct) {
			int size = get_structure_size(vp,varType);
			struct Operand *c1 = myConst(size);
			code0 = add_dec(v1,c1);
			return code0;
		}
	}
	//VarDec LB INT RB
	else {
		return translate_VarDec(child0,NULL);
	}
}

struct InterCodes* translate_DefList(struct treeNode *node) {
	struct InterCodes *code0=NULL,*code1=NULL;
	if(node==NULL) return NULL;
	struct treeNode *child0 = node->child[0];
	//Def DefList
	code0=translate_Def(child0);
	code1=translate_DefList(node->child[1]);
	return code0;

}

struct InterCodes* translate_Def(struct treeNode *node) {
	struct treeNode *child0 = node->child[0];
	//Specifier DecList SEMI
	//if 3.1 add translate_Specifier
	return translate_DecList(node->child[1]);
}

struct InterCodes* translate_DecList(struct treeNode *node) {
	struct InterCodes *code0=NULL,*code1=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"Dec")==0) {
		//Dec
		if(node->child[1]==NULL) {
			return translate_Dec(child0);
		}
		//Dec COMMA DecList
		else {
			code0=translate_Dec(child0);
			code1=translate_DecList(node->child[2]);
			return code0;
		}
	}
}

struct InterCodes* translate_Dec(struct treeNode *node) {
	struct InterCodes *code0=NULL,*code1=NULL,*code2=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"VarDec")==0) {
		//VarDec
		if(node->child[1]==NULL) {
			return translate_VarDec(child0,NULL);
		}
		//VarDec ASSIGNOP Exp
		else {
			struct Operand *t1 = NULL;
			code0=translate_VarDec(child0,t1);
			struct Operand *t2 = new_temp();
			code1=translate_Exp(node->child[2],t2);
			code2=add_assign(t1,t1);
			return code0;
		}
	}

}

struct InterCodes* translate_FunDec(struct treeNode *node) {
	//TODO:
	struct InterCodes *code0=NULL,*code1=NULL,*code2=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"ID")==0) {
		char *func_name=child0->text;
		struct msgFun *func_node=getFunMsg(child0);
		struct Operand *func1 = new_function(func_name);
		code0=add_function(func1);
		//ID LP VarList RP
		if(node->child[3]!=NULL) {
			struct argList *param = func_node->msg;
			while(param!=NULL) {
				int id = getVarIDByName(param->name);
				struct Operand *p1 = myVar(id);
				code1=add_param(p1);
				param=param->next;
			}
		}
		//ID LP RP
//		printf("finish\n");
		return code0;
	}
	return NULL;
}

struct InterCodes* translate_VarList(struct treeNode *node){
	struct InterCodes *code0=NULL,*code1=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"ParamDec")==0){
		//ParamDec
		if(node->child[1]==NULL) {
			return translate_ParamDec(child0);
		}
		//ParamDec COMMA VarList
		else {
			code0=translate_ParamDec(child0);
			code1=translate_VarList(node->child[2]);
			return code0;
		}
	}

}

struct InterCodes* translate_ParamDec(struct treeNode *node) {
	struct InterCodes *code0=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(node->child[1]->type,"VarDec")==0) {
		code0=translate_VarDec(node->child[1],NULL);
		return code0;
	}
	return NULL;
}

struct InterCodes* translate_ExtDecList(struct treeNode *node) {
	struct InterCodes *code0=NULL,*code1=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"VarDec")==0){
		//VarDec
		if(node->child[1]==NULL) {
			return translate_VarDec(child0,NULL);
		}
		//VarDec COMMA ExtDecList
		else {
			code0=translate_VarDec(child0,NULL);
			code1=translate_VarList(node->child[2]);
			return code0;
		}
	}

}


struct InterCodes* translate_Args(struct treeNode *node,struct Operand *arg_list,int *arg_num) {
	//TODO add args
	struct InterCodes *code0=NULL,*code1=NULL,*code2=NULL,*code3=NULL;
	struct treeNode *child0 = node->child[0];
	if(strcmp(child0->type,"Exp")==0) {
	//Exp
		struct Operand *t1 = new_temp();
		if(node->child[1]==NULL) {
			code0=translate_Exp(child0,t1);
			arg_list[*arg_num]=*t1;
			(*arg_num)++;
		}
	//Exp COMMA Args
		else if(node->child[1]!=NULL) {
			code0=translate_Args(node->child[2],arg_list,arg_num);
			code1=translate_Exp(child0,t1);
			arg_list[*arg_num]=*t1;
			(*arg_num)++;
		}

		return code0;
	}
}

struct InterCodes *translate_array(struct treeNode *node,struct Operand *place) {
	//TODO about array
	struct InterCodes *code0=NULL,*code1=NULL,*code2=NULL,*code3=NULL;
	struct treeNode *child0 = node->child[0];

	int id = getIDFromTable(node->child[0]->child[0]);
	struct Operand *t1 = myVar(id);
	struct Operand *t2 = new_temp();
	int array_size = atoi(node->child[1]->child[0]->text);
	code0 = translate_Exp(node->child[0], t2);
	struct Operand *size = myConst(4);
	struct Operand *t3;
	code1 = add_mul(t3, t2, size);
	
	struct Operand *t4 = new_temp();
	code2 = add_plus(t4, t1, t3);
	return code0;








}
