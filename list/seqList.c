#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 16 // max size of sequence list

typedef struct {
	int data[MAX_SIZE];
	int length;
}seqList, *list;

list initList() {
	list l = malloc(sizeof(seqList));
	l->length = 0;
	return l;
}

bool isEmpty(list l) {
	return l->length == 0;
}

bool isFull(list l) {
	return l->length == MAX_SIZE;
}

// insert-index ranges from [1 , length + 1]
bool insert(list l, int index, int value) {
	if(isFull(l)) {
		printf("The list is full. Insert failed.\n");
		return false;
	}

	if(!(index >=1 && index <= l->length + 1)) {
		printf("Invalid insert position.\nInsert failed.\n");
		return false;
	}

	int i = 0;
	for(i = l->length; i >= index; i--)
		l->data[i] = l->data[i-1];
	l->data[index - 1] = value;
	l->length += 1;

	return true;
}

bool delete(list l, int index, int *value) {
	if(isEmpty(l)) {
		printf("The list is empty. Delete failed.\n");
		return false;
	}

	if(!(index >= 1 && index <= l->length)) {
		printf("Invalid delete postion. Delete failed.\n");
		return false;
	}

	int i;
	*value = l->data[index - 1];
	for(i = index; i <= l->length -1; i++)
		l->data[i - 1] = l->data[i];
	l->length -= 1;
	return  true;
}

void display(list l) {
	int i, len = l->length;
	for(i = 0; i < len; i++)
		printf("%d\t", l->data[i]);
	putchar('\n');
}


int main() {
	list l = initList();
	int i, value;
	for(i = 1; i <= 10; i++)
		insert(l, i, i * 10);

	insert(l, 1, 999);
	insert(l, 2, 888);

	display(l);

	printf("Input a postion to delete element: ");
	scanf("%d", &i);
	while(i != 0) {
		if(delete(l, i, &value)) {
			printf("Deleted value: %d\n", value);
			display(l);
		}
		printf("Input a postion to delete element: ");
		scanf("%d", &i);
	}

	return 0;
}
