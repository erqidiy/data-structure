#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 16 
#define random(x) (rand() % x)


void initArrayFromRandomNumber(int ary[], int n) {
	int i;
	srand(time(NULL));
	for(i = 0; i < n; i++)
		ary[i] = random(100);
}

void display(int ary[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

void shellSort(int ary[], int n) {
	int i, j, k, key, dk;
	for(dk = n / 2; dk >= 1; dk /= 2) {
		for(i = 0; i < dk; i++) { // dk group
			for(j = i + dk; j < n; j += dk) { // insert sort
				key = ary[j];
				for(k = j - dk; k >= 0 && ary[k] > key; k -= dk)
					ary[k + dk] = ary[k];
				ary[k + dk] = key;
			}
		}
	}

}

int main() {
	int i, j, k;
	int ary[N];
	initArrayFromRandomNumber(ary, N);
	display(ary, N);
	shellSort(ary, N);
	display(ary, N);

	return 0;
}
