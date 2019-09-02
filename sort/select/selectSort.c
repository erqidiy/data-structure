#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
#define MAX_VAL 1000000
#define random(x) (rand() % x)

void initArray(int ary[], int n) {
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++)
		ary[i] = random(MAX_VAL);
}

void printArray(int ary[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

void swap(int ary[], int i, int j) {
	int tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;
}

void selectSort(int ary[], int n) {
	int i, j, k;
	for(i = 0; i < n - 1; i++) {
		k = i;
		for(j = i + 1; j < n; j++) {
			if(ary[j] < ary[k])
				k = j;
		}
		if(i != k)
			swap(ary, i, k);
	}
}

int main() {
	int ary[N];
	initArray(ary, N);
	printArray(ary, N);
	
	printf("Using select sort algorithm sorted...\n");
	selectSort(ary, N);
	printArray(ary, N);

	return 0;
}
