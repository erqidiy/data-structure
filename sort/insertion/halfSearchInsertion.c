#include <stdio.h>
#include <stdlib.h>

void halfSearchInsertion(int ary[], int len) {
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
		
		for(j = i - 1; j > high; j--)
			ary[j + 1] = ary[j];
			ary[high + 1] = key;
	}
}

void display(int ary[], int len) {
	int i;
	for(i = 0; i < len; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

int main() {
	int ary[] = {12, 5, 21, 56, 33, 5, 21, 1, 76, 99, 56, 33, 21, 55, 65, 6};
	int len = 16;
	display(ary, len);
	halfSearchInsertion(ary, len);
	display(ary, len);

	return 0;
}
