#ifndef DOMTREE_H
#define DOMTREE_H
struct treeNode{
	int line;
	int flag;
	struct treeNode *child[7];
	struct treeNode *parent;
	char type[32];
	char text[32];
};
#endif
