#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 16
#define random(x) (rand() % x)

void initArray(int ary[], int n) {
	srand(time(NULL));
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

void swap(int ary[], int i, int j) {
	int tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;
}

void bubbleSort(int ary[], int n) {
	int i, j;
	bool changed;
	for(i = 0; i < n - 1; i++) {
		changed = false;
		for(j = n - 1; j > i; j--) {
			if(ary[j] < ary[j - 1]) {
				swap(ary, j, j-1);
				changed = true;
			}
		}
		if(!changed)
			return;
	}
}

int main() {
	int ary[N];
	initArray(ary, N);
	display(ary, N);
	bubbleSort(ary, N);
	display(ary, N);

	return 0;
}
