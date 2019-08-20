#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 16

typedef struct binNode {
	char data;
	struct binNode *lchild, *rchild;
}binNode, *binTree;

typedef struct {
	binTree data[MAX_SIZE];
	int front, rear;
}seqQueue, *queue;

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

queue initQueue() {
	queue q = malloc(sizeof(seqQueue));
	q->front = q->rear = 0;
}

bool isEmpty(queue q) {
	return q->front == q->rear;
}

bool isFull(queue q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}

bool enQueue(queue q, binTree root) {
	if(isFull(q)) {
		printf("The queue is full. EnQueue is failed.\n");
		return false;
	}

	q->data[q->rear] = root;
	q->rear = (q->rear + 1) % MAX_SIZE;

	return true;
}

bool deQueue(queue q, binTree *root) {
	if(isEmpty(q)) {
		printf("The queue is empty. DeQueue is failed.\n");
		return false;
	}

	*root = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	return true;
}

void layorOrder(binTree root) {
	if(root == NULL)
		return;
	queue q = initQueue();
	binTree tmp;
	enQueue(q, root);

	while(!isEmpty(q)) {
		deQueue(q, &tmp);
		printf("%c\t", tmp->data);
		if(tmp->lchild)
			enQueue(q, tmp->lchild);
		if(tmp->rchild)
			enQueue(q, tmp->rchild);
	}
	putchar('\n');
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

	printf("\nLoyorOrder: \t");
	layorOrder(root);

	return 0;
}
