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

/* index starts with 1 */
void printArray(int ary[], int n) {
	int i;
	for(i = 1; i <= n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

void swap(int ary[], int i, int j) {
	int tmp = ary[i];
	ary[i] = ary[j];
	ary[j] = tmp;
}

void siftDown(int ary[], int i, int n) {
	int j;
	ary[0] = ary[i]; // pivot element
	for(j = 2 * i; j <= n; j = 2 * i) {
		if(j < n && ary[j] < ary[j + 1]) j++;
		if(ary[0] >= ary[j]) break;
		ary[i] = ary[j];
		i = j;
	}
	ary[i] = ary[0];
}

void createHeap(int ary[], int n) {
	int i;
	for(i = n / 2; i > 0; i--)
		siftDown(ary, i, n);
}

void heapSort(int ary[], int n) {
	int i;
	for(i = n; i > 1; i--) {
		swap(ary, 1, i);
		siftDown(ary, 1, i - 1);
	}

}
int main() {
	int ary[N + 1];
	initArray(ary, N + 1);
	printArray(ary, N);

	printf("Creating big root heap...\n");
	createHeap(ary, N);
	printArray(ary, N);
	
	printf("Using heap sort algorithm sorted...\n");
	heapSort(ary, N);
	printArray(ary, N);

	return 0;
}
