#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct binNode {
	char data;
	struct binNode *lchild, *rchild;
}binNode, *binTree;

void initTree(binTree *root, char ary[], int *index) {
	if(ary[*index] == '#') {
		*root = NULL;
		*index += 1;
		return;
	}
	binTree tmp = malloc(sizeof(binNode));
	tmp->data = ary[*index];
	*index += 1;
	*root = tmp;
	initTree(&(tmp->lchild), ary, index);
	initTree(&(tmp->rchild), ary, index);
}

void preOrder(binTree root) {
	if(root) {
		printf("%c\t", root->data);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

void inOrder(binTree root) {
	if(root) {
		inOrder(root->lchild);
		printf("%c\t", root->data);
		inOrder(root->rchild);
	}
}

void postOrder(binTree root) {
	if(root) {
		postOrder(root->lchild);
		postOrder(root->rchild);
		printf("%c\t", root->data);
	}
}

int main() {
	binTree root = NULL;
	char ary[] = {'A', 'B', 'D', '#', '#', 'E', 'H', '#', '#', '#', 'C', 'F', '#', 'I', '#', '#', 'G', '#', '#'};
	int index = 0;

	initTree(&root, ary, &index);
	
	printf("PreOrder: \t");
	preOrder(root);

	printf("\nInOrder: \t");
	inOrder(root);

	printf("\nPostOrder: \t");
	postOrder(root);

	return 0;
}
