#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 16
#define N 6 
#define MAX_VALUE 32767
#define random(x) (rand() % x)

void initArray(int ary[], int n) {
	srand(time(NULL));
	int i;
	for(i = 1; i <= n; i++)
		ary[i] = random(MAX_NUM);
}

void printArray(int ary[], int n) {
	int i;
	for(i = 1; i <= n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

void initHuffmanNode(int ary[], int n) {
	int i;
	for(i = 1; i <= n; i++)
		ary[i] = -1;
}

int huffmanCode(int ary[], int n, int parent[]) {
	int i, j, s1, s2, min1, min2, wpl = 0;
	for(i = n + 1; i < 2*n; i++) {
		min1 = min2 = MAX_VALUE;
		s1 = s2 = 0;

		for(j = 1; j < i; j++) {
			if(parent[j] != -1) continue;
			if(ary[j] < min1) {
				min2 = min1;
				s2 = s1;
				min1 = ary[j];
				s1 = j;
			}else if(ary[j] < min2) {
				min2 = ary[j];
				s2 = j;
			}
		}
		
//		printf("min1 = %d (index = %d), min2 = %d (index = %d)\n", min1, s1, min2, s2);
		ary[j] = min1 + min2;
		parent[s1] = parent[s2] = j;
		wpl += ary[j];
	}
	return wpl;
}

int main() {
	int ary[2 * N];
	int parent[2 * N];
	initArray(ary, N);
	printArray(ary, N);

	initHuffmanNode(parent, 2 * N);
	int wpl = huffmanCode(ary, N, parent);

	printf("WPL = %d\n", wpl);

	return 0;
}
