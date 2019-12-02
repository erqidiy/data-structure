/* FileName: countSort.c
 * Function: Sorting the array(index starts with 1) using count sort algorithm
 * Author: erqitao
 * Date: 2019-12-02
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 100
#define MAX_NUM 32
#define random(x) (rand() % x + 1)

void initArray(int ary[], int size) {
	srand(time(NULL));
	for (int i = 1; i <= size; i++)
		ary[i] = random(MAX_NUM);
}

void printArray(int ary[], int size) {
	for (int i = 1; i <= size; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

void countSort(int data[], int result[], int dataSize, int count[], int countSize) {
	int i, indexOfCount = 0;
	for (i = 1; i <= countSize; i++)
		count[i] = 0;

	for (i = 1; i <= dataSize; i++)
		count[data[i]] = count[data[i]] + 1;

	for (i = 2; i <= countSize; i++)
		count[i] = count[i] + count[i - 1];

	for (i = 1; i <= dataSize; i++) {
		result[count[data[i]]] = data[i];
		count[data[i]]  -= 1;
	}
}

int main() {
	int ary[ARRAY_SIZE + 1];
	int result[ARRAY_SIZE + 1];
	int count[ARRAY_SIZE + 1];

	initArray(ary, ARRAY_SIZE);
	puts("Initial Data...");
	printArray(ary, ARRAY_SIZE);

	countSort(ary, result, ARRAY_SIZE, count, MAX_NUM);

	puts("Using count sort sorted...");
	printArray(result, ARRAY_SIZE);

	return 0;
}
