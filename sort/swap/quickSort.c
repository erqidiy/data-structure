#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 100
#define MAX_NUM 200
#define random(x) (rand() % x)

void initArrayFromRandomNumber(int *ary, int n) {
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++)
		ary[i] = random(MAX_NUM);
}

void display(int ary[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

int partition(int ary[], int low, int high) {
	int pivot = ary[low];
	while(low < high) {
		while(low < high && ary[high] >= pivot)
			high--;
		ary[low] = ary[high];
		while(low < high && ary[low] <= pivot)
			low++;
		ary[high] = ary[low];	
	}
	ary[low] = pivot;
	return low;
}

void quickSort(int ary[], int low, int high) {
	int mid;
	if(low < high) {
		mid = partition(ary, low, high);
		quickSort(ary, low, mid - 1);
		quickSort(ary, mid + 1, high);
	}
}

int main() {
	int ary[N];
	initArrayFromRandomNumber(ary, N);
	printf("Initial data: \n");
	display(ary, N);
	printf("\nSorted data:\n");
	quickSort(ary, 0, N - 1);
	display(ary, N);

	return 0;
}
