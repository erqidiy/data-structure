#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int data;
	struct linkNode *next;
}linkNode;

typedef struct {
	linkNode *front, *rear;
}linkQueue, *queue;

queue initQueue() {
	linkNode *head = malloc(sizeof(linkNode));
	head->next = NULL;
	queue q = malloc(sizeof(linkQueue));
	q->front = q->rear = head;
	return q;
}

bool isEmpty(queue q) {
	return q->front == q->rear;
}

void enQueue(queue q, int value) {
	printf("EnQueue value = %d...\n", value);
	linkNode *aws = (linkNode *) malloc(sizeof(linkNode));
	aws->data = value;
	aws->next == NULL;

	q->rear->next = aws;
	q->rear = aws;
}

bool deQueue(queue q, int *value) {
	if(isEmpty(q)) {
		printf("The queue is empty. DeQueue failed.\n");
		return false;
	}

	linkNode * head = q->front->next;
	*value = head->data;
	q->front->next = head->next;

	// just one node left
	if(head == q->rear) {
		q->rear = q->front;
	}

	free(head);
	return true;
}

int main() {
	queue q = initQueue();
	int i, value;
	for(i = 1; i <= 10; i++)
		enQueue(q, i * 10);

	for(i = 1; i <= 5; i++)
		if(deQueue(q, &value))
			printf("DeQueue value: %d\n", value);


	return 0;
}
