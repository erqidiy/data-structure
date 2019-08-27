#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linkNode {
	int data;
	struct linkNode *next;
}linkNode, *linkList;

linkList initList() {
	linkList list = malloc(sizeof(linkNode));
	list->next = NULL;
	return list;
}

/* create a link list by head insert */
void headInsert(linkList list) {
	int value;
	linkList tmp = NULL;
	printf("Input some values to create a list (ends with 0): ");
	scanf("%d", &value);
	while(value != 0) {
		tmp = malloc(sizeof(linkNode));
		tmp->data = value;
		tmp->next = list->next;
		list->next = tmp;
		scanf("%d", &value);
	}
}

/* create a link list by tail insert */
void tailInsert(linkList list) {
	linkList tmp, tail = list;
	int value;
	printf("Input some values to create a list (ends with 0): ");
	scanf("%d", &value);
	while(value != 0) {
		tmp = malloc(sizeof(linkNode));
		tmp->data = value;
		tail->next = tmp;
		tail = tmp;
		scanf("%d", &value);
	}
	tail->next = NULL;
}

/* reverse a list by head insert */
void reverse(linkList list) {
	linkList p, q;
	p = list->next;
	list->next = NULL;
	while(p != NULL) {
		q = p->next;
		p->next = list->next;
		list->next = p;
		p = q;
	}
}

/* sort a list (from small to big)*/
void sort(linkList list) {
	linkList pre, p, q, tmp;
	q = list->next;
	list->next = NULL;

	while(q != NULL) {
		tmp = q->next;
		pre = list;
		p = pre->next;

		while(p != NULL && q->data > p->data) {
			pre = p;
			p = p->next;
		}
		q->next = p;
		pre->next = q;
		q = tmp;
	}
}

/* print a list from begin to end */
void display(linkList list) {
	while(list != NULL) {
		printf("%d\t", list->data);
		list = list->next;
	}
	putchar('\n');
}

/* print a list from end to begin (by recursive) */
void displayReverse(linkList list) {
	if(list != NULL) {
		displayReverse(list->next);
		printf("%d\t", list->data);
	}
}

int main() {
	linkList list = initList();
	tailInsert(list);
	//headInsert(list);
	display(list->next);
	//displayReverse(list->next);

	//reverse(list);
	sort(list);
	display(list->next);

	return 0;
}
