#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct binNode {
	int data;
	struct binNode *lchild, *rchild;
}binNode, *binTree;

bool insert(binTree *root, int value) {
	if(*root == NULL) {
		binNode * node = malloc(sizeof(binNode));
		node->data = value;
		node->lchild = node->rchild = NULL;
		*root = node;
		return true;
	}

	if((*root)->data == value)
		return false;
	else if((*root)->data > value)
		return insert(&((*root)->lchild), value);
	else
		return insert(&((*root)->rchild), value);
}

void inOrder(binTree root) {
	if(root != NULL) {
		inOrder(root->lchild);
		printf("%d\t", root->data);
		inOrder(root->rchild);
	}
}

int main() {
	binTree root = NULL;
	int ary[] = {18, 23, 15, 8, 16, 2, 9, 20, 27, 12, 56, 3};
	int i, len = 12;

	printf("Original data...\n");
	for(i = 0; i < len; i++)
		printf("%d\t", ary[i]);

	printf("\n\nConstructing BST...\n\n");

	for(i = 0; i < len; i++)
		insert(&root, ary[i]);

	printf("InOrder traversal:\n");
	inOrder(root);

	return 0;
}
