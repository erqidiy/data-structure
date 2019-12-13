#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 16

typedef struct binNode {
	char data;
	struct binNode *lchild, *rchild;
}binNode, *binTree;

typedef struct seqQueue {
	binTree data[MAX_SIZE];
	int front, rear;
}seqQueue, *queue;

typedef struct seqStack {
	binTree data[MAX_SIZE];
	int top;
}seqStack, *stack;

stack initStack() {
	stack s = malloc(sizeof(seqStack));
	s->top = -1;
	
	return s;
}

bool isStackEmpty(stack s) {
	return s->top == -1;
}

bool isStackFull(stack s) {
	return s->top == (MAX_SIZE -1);
}

bool push(stack s, binTree p) {
	if (isStackFull(s)) {
		puts("The stack is full.");
		return false;
	}

	s->top += 1;
	s->data[s->top] = p;

	return true;
}

bool pop(stack s, binTree *p) {
	if (isStackEmpty(s)) {
		puts("The stack is empty.");
		return false;
	}

	*p = s->data[s->top];
	s->top -= 1;

	return true;
}

bool getTop(stack s, binTree *p) {
	if (isStackEmpty(s)) {
		printf("The stack is empty. GetTop failed.");
		return false;
	}

	*p = s->data[s->top];

	return true;
}

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

queue initQueue() {
	queue q = malloc(sizeof(seqQueue));
	q->front = q->rear = 0;
	return q;
}

bool isEmpty(queue q) {
	return q->front == q->rear;
}

bool isFull(queue q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}

bool enQueue(queue q, binTree p) {
	if(isFull(q)) {
		printf("The queue is full. EnQueue failed.\n");
		return false;
	}
	q->data[q->rear] = p;
	q->rear = (q->rear + 1) % MAX_SIZE;
	return true;
}

bool deQueue(queue q, binTree *p) {
	if(isEmpty(q)) {
		printf("The queue is empty. DeQueue failed.\n");
		return false;
	}

	*p = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	return true;
}

int lengthOfQueue(queue q) {
	return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
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

int widthOfTree(binTree root) {
	if(root == NULL)
		return 0;
	int currentWidth, width = 1;
	queue q = initQueue();
	enQueue(q, root);
	binTree p = NULL;

	while(!isEmpty(q)) {
		currentWidth = lengthOfQueue(q);

		if(currentWidth > width)
			width = currentWidth;

		while(currentWidth > 0) {
			deQueue(q, &p);
			currentWidth -= 1;

			if(p->lchild != NULL)
				enQueue(q, p->lchild);

			if(p->rchild != NULL)
				enQueue(q, p->rchild);
		}
	}
	
	return width;
}

int heightOfTree(binTree root) {
	if(root == NULL)
		return 0;

	int i = heightOfTree(root->lchild);
	int j = heightOfTree(root->rchild);

	return (i > j) ? (i + 1) : (j + 1);
}

/* Date: 2019-12-13 9:30 
 * Function: No-Recursive-Traversal
*/

void preOrderNoRecursive(binTree root) {
	stack s = initStack();
	binTree p = root;

	while (p != NULL || !isStackEmpty(s)) {
		while (p != NULL) {
			printf("%c\t", p->data);
			push(s, p);
			p = p->lchild;
		}

		pop(s, &p);
		p = p->rchild;
	}
	putchar('\n');
}

void inOrderNoRecursive(binTree root) {
	stack s = initStack();
	binTree p = root;

	while (p != NULL || !isStackEmpty(s)) {
		while (p != NULL) {
			push(s, p);
			p = p->lchild;
		}

		pop(s, &p);
		printf("%c\t", p->data);
		p = p->rchild;
	}
	putchar('\n');
}

void postOrderNoRecursive(binTree root) {
	stack s = initStack();
	binTree p, pre;
	p = root;
	pre = NULL;

	while (p != NULL || !isStackEmpty(s)) {
		while (p != NULL) {
			push(s, p);
			p = p->lchild;
		}

		getTop(s, &p);

		if (p->rchild != NULL && p->rchild != pre) {
			p = p->rchild;
		}else {
			pop(s, &p);
			printf("%c\t", p->data);
			pre = p;
			p = NULL;
		}
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

	printf("\nPreOrderNR: \t");
	preOrderNoRecursive(root);

	printf("\nInOrder: \t");
	inOrder(root);

	printf("\nInOrderNR: \t");
	inOrderNoRecursive(root);

	printf("\nPostOrder: \t");
	postOrder(root);
	printf("\nPostOrderNR: \t");
	postOrderNoRecursive(root);

	printf("\nWidth of the tree: %d", widthOfTree(root));
	printf("\nHeight of the tree: %d\n", heightOfTree(root));

	return 0;
}
