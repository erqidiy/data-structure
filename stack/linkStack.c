#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linkNode {
	int data;
	struct linkNode *next;
}linkNode, *stack;

stack initStack() {
	stack s = malloc(sizeof(linkNode));
	s->next = NULL;
	return s;
}

bool isEmpty(stack s) {
	return s->next == NULL;
}

void push(stack s, int value) {
	stack t = malloc(sizeof(linkNode));
	t->data = value;

	t->next = s->next;
	s->next = t;
}

bool pop(stack s, int *value) {
	if(isEmpty(s)) {
		printf("The stack is empty. Pop failed.\n");
		return false;
	}
	/* using head insertion to create a link stack */
	stack top = s->next;
	*value = top->data;
	s->next = top->next;
	free(top);
	return true;
}

int main() {
	stack s = initStack();
	int i, value;
	for(i = 1; i <= 20; i++)
		push(s, i);

	for(i = 1; i <= 16; i++) {
		if(pop(s, &value)) {
			printf("Pop value: %d\n", value);
		}
	}

	return 0;
}
