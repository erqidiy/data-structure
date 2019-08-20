#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 16

typedef struct {
	int data[MAX_SIZE];
	int front, rear;
}seqQueue, *queue;

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

bool enQueue(queue q, int value) {
	if(isFull(q)) {
		printf("The queue is full. EnQueue failed.\n");
		return false;
	}

	q->data[q->rear] = value;
	q->rear = (q->rear + 1) % MAX_SIZE;
	return true;
}

bool deQueue(queue q, int *value) {
	if(isEmpty(q)) {
		printf("The queue is empty. DeQueue failed.\n");
		return false;
	}
	*value = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	return true;
}

int main() {
	queue q = initQueue();
	int i, value;
	for(i = 0; i < 20; i++)
		enQueue(q, (i + 1) * 10);

	for(i = 0; i < 20; i++)
		if(deQueue(q, &value))
			printf("DeQueue value: %d\n", value);

	return 0;
}
