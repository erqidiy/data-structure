#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 10
#define random(x) (rand() % x)

void initArrayFromRandomValue(int ary[], int n) {
	int i;
	for(i = 0; i < n; i++)
		ary[i] = random(100);
}

void display(int ary[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

void insertSort(int ary[], int n) {
	int i, j, key;
	for(i = 1; i < n; i++) {
		key = ary[i];
		for(j = i - 1; j >= 0 && ary[j] > key; j--)
			ary[j + 1] = ary[j];
		ary[j + 1] = key;
	}
}

int main() {
	srand(time(NULL));
	int *ary = malloc(sizeof(int) * N);
	initArrayFromRandomValue(ary, N);
	display(ary, N);
	insertSort(ary, N);
	display(ary, N);

	return 0;
}
