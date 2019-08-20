#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 16

typedef struct {
	int data[MAX_SIZE];
	int top;
}seqStack, *stack;

stack initStack() {
	stack s = malloc(sizeof(seqStack));
	s->top = -1;
	return s;
}

bool isEmpty(stack s) {
	return s->top == -1;
}

bool isFull(stack s) {
	return s->top == MAX_SIZE -1;
}

bool push(stack s, int value) {
	if(isFull(s)) {
		printf("The stack is full. Push failed.\n");
		return false;
	}
	printf("Push value %d\n", value);
	s->top += 1;
	s->data[s->top] = value;
	return true;
}

bool pop(stack s, int *value) {
	if(isEmpty(s)) {
		printf("The stack is empty. Pop failed.\n");
		return false;
	}
	*value = s->data[s->top];
	s->top -= 1;
	return true;
}

int main() {
	stack s = initStack();
	int i, value;
	for(i = 0; i < 12; i++)
		push(s, (i + 1) * 10);

	printf("\n*****************************\n");

	for(i = 0; i < 20; i++) {
		if(pop(s, &value))
			printf("Pop value: %d\n", value);
	}


	return 0;
}
