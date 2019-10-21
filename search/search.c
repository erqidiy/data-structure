#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 100
#define ARRAY_SIZE 10
#define random(x) (rand() % x)

int sequenceSearch(int ary[], int n, int data) {
    int i;
    for (i = 0; i < n; i++) {
        if (ary[i] == data)
            return i;
    }
    return -1;
}

int sequenceSearchOrdered(int ary[], int n, int data) {
    int i = 0;
    while (i < n && data > ary[i]) {
        i++;
    }

    if (i < n && data == ary[i])
        return i;

    return -1;
}

int binarySearch(int ary[], int n, int data) {
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (ary[mid] == data) {
            return mid;
        } else if (ary[mid] < data) {
          low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void insertSort(int ary[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = ary[i];
        for (j = i - 1; j >=0 && ary[j] > key; j--) {
            ary[j + 1] = ary[j];
        }
        ary[j + 1] = key;
    }
}

int * initArray(int ary[], int n) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        ary[i] = random(MAX_NUM);
    }
}

void printArray(int ary[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", ary[i]);
    }
    putchar('\n');
}

int main() {
    int ary[ARRAY_SIZE]; 
    initArray(ary, ARRAY_SIZE);
    printArray(ary, ARRAY_SIZE);
    
    printf("Sorted...\n");
    insertSort(ary, ARRAY_SIZE);
    printArray(ary, ARRAY_SIZE);

    int value, index = 0;
    printf("Input a value to be found: ");
    scanf("%d", &value);
//      index = sequenceSearch(ary, ARRAY_SIZE, value);
//      index = binarySearch(ary, ARRAY_SIZE, value);
    index = sequenceSearchOrdered(ary, ARRAY_SIZE, value);

    if (index == -1) {
        printf("Not found.\n");
    } else {
        printf("Found! Index = %d\n", index);
    }
    
}
