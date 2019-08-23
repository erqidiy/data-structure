#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int ary[], int len) {
	int i, j, key;
	for(i = 1; i < len; i++) {
		key = ary[i];
		for(j = i - 1; j >= 0 && ary[j] > key; j--)
			ary[j + 1] = ary[j];
		ary[j + 1] = key;
	}
}

void insertionSortWithGuard(int ary[], int len) {
	int i, j, key;
	for(i = 2; i <= len; i++) {
		key = ary[i];
		ary[0] = key; // guard postion -> ary[0]
		j = i - 1;
		while(ary[j] > key) {
			ary[j + 1] = ary[j];
			j--;
		}
		ary[j + 1] = key;
	}
}

void display(int ary[], int len) {
	int i;
	for(i = 0; i < len; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

int main() {
	int data[] = {12, 7, 21, 10, 51, 4, 51, 23, 3, 61, 5, 53, 35, 9, 29, 17};
	int len = 16;


	int data2[] = {0, 12, 7, 21, 10, 51, 4, 51, 23, 3, 61, 5, 53, 35, 9, 29, 17};
	int len2 = 16;

	display(data, len);
	insertionSort(data, len);
	display(data, len);

	printf("\n****************************\n");

	display(data2, len2 + 1);
	insertionSortWithGuard(data2, len);
	display(data2, len2 + 1);

	return 0;
}
