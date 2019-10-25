/*
Filename: binaryInsertionSort.c
Author: erqitao
Date: 2019-10-25
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 16
#define MAX_NUM 100
#define random(x) (rand() % x)

void initArray(int ary[], int n) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
        ary[i] = random(MAX_NUM);
}

void printArray(int ary[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", ary[i]);
    putchar('\n');
}

void binaryInsertionSort(int ary[], int len) {
	int i, j, key, low, high, mid;
	for(i = 1;i < len; i++) {
		key = ary[i];
		low = 0;
		high = i - 1;

		while(low <= high) {
			mid = (low + high) / 2;
			if(ary[mid] > key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		
		for(j = i - 1; j >= low; j--)
			ary[j + 1] = ary[j];
		ary[low] = key;
	}
}

int main() {
    int ary[ARRAY_SIZE];
    initArray(ary, ARRAY_SIZE);
    printArray(ary, ARRAY_SIZE);

    printf("Using Binary-Insertion-Sort Sorted...\n");
    binaryInsertionSort(ary, ARRAY_SIZE);
    printArray(ary, ARRAY_SIZE);

	return 0;
}
