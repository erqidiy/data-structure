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

void merge(int ary[], int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0, size = high - low + 1;
	int *tmpAry = malloc(sizeof(int) * size);

	while(i <= mid && j <= high) {
		if(ary[i] <= ary[j])
			tmpAry[k++] = ary[i++];
		else
			tmpAry[k++] = ary[j++];
	}
	while(i <= mid)
		tmpAry[k++] = ary[i++];
	while(j <= high)
		tmpAry[k++] = ary[j++];

	for(i = 0; i < k; i++)
		ary[low + i] = tmpAry[i];
}

void mergeSort(int ary[], int low, int high) {
	int mid = (low + high) / 2;
	if(low < high) {
		mergeSort(ary, low, mid);
		mergeSort(ary, mid + 1, high);
		merge(ary, low, mid, high);
	}
}

int main() {
	int ary[N];
	initArray(ary, N);
	printArray(ary, N);

	printf("Using merge sort algorithm sorted...\n");
	mergeSort(ary, 0, N - 1);
	printArray(ary, N);

	return 0;
}
