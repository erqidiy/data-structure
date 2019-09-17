#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct threadNode {
	char data;
	struct threadNode *lchild, *rchild;
	int ltag, rtag;
}threadNode, *threadTree;

// create a binTree using preOrder traversal
void createTree(threadTree *root, char pre[], int *index) {
	char value = pre[*index];
	*index += 1;

	if(value == '#') {
		*root = NULL;
		return;
	}

	threadNode * node = malloc(sizeof(threadNode));
	node->data = value;
	node->ltag = node->rtag = 0;
	*root = node;

	createTree(&(node->lchild), pre, index);
	createTree(&(node->rchild), pre, index);
}

// preOrder Traversal
void preOrder(threadTree root) {
	if(root != NULL) {
		printf("%c\t", root->data);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

// inOrder Traversal
void inOrder(threadTree root) {
	if(root != NULL) {
		inOrder(root->lchild);
		printf("%c\t", root->data);
		inOrder(root->rchild);
	}
}

// postOrder Traversal
void postOrder(threadTree root) {
	if(root != NULL) {
		postOrder(root->lchild);
		postOrder(root->rchild);
		printf("%c\t", root->data);
	}
}

// threading a binTree by inOrder traversal
void threadInOrder(threadTree root, threadTree *pre) {
	if(root != NULL) {
		threadInOrder(root->lchild, pre);
		
		// step 1
		if(root->lchild == NULL) {
			root->lchild = *pre;
			root->ltag = 1;
		}
		// step 2
		if(*pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rchild = root;
			(*pre)->rtag = 1;
		}
		// step 3 : just for next node
		*pre = root;

		threadInOrder(root->rchild, pre);
	}
}

// all the steps to thread a binTree
void thread(threadTree root) {
	threadTree pre = NULL;
	threadInOrder(root, &pre);
	pre->rchild = NULL;
	pre->rtag = 1;
}

// return the first node to be visited in the inOrder traversal
threadNode * getFirst(threadTree root) {
	while(root->ltag == 0)
		root = root->lchild;
	return root;
}

// return the next node to be visited after root
threadNode * getNext(threadTree root) {
	if(root->rtag == 0)
		return getFirst(root->rchild);
	else
		return root->rchild;
}

// inOrder traversal - no recursive method
void inOrderTraversal(threadTree root) {
	threadNode * p = getFirst(root);
	while(p != NULL) {
		printf("%c\t", p->data);
		p = getNext(p);
	}
}

// just the same as inOrderTraversal()
void inOrderTraversal2(threadTree root) {
	threadNode * p;
	for(p = getFirst(root); p != NULL; p = getNext(p))
		printf("%c\t", p->data);
}

int main() {
	char pre[] = {'A', 'B', 'D', '#', '#', 'E', 'H', '#', '#', '#', 'C', 'F', '#', 'I', '#', '#', 'G', '#', '#'};
	int index = 0;
	threadTree root = NULL;
	createTree(&root, pre, &index);

	printf("\nPreOrder:\n");
	preOrder(root);

	printf("\nInOrder:\n");
	inOrder(root);

	printf("\nPostOrder:\n");
	postOrder(root);
	
	printf("\n\nThreading tree...\n");
	thread(root);
	printf("\nInOrder Traversal after threaded...\n");
	inOrderTraversal(root);

	printf("\nInOrder Traversal after threaded...\n");
	inOrderTraversal2(root);

	return 0;
}
