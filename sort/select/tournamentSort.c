#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TEAM_NUM 10
#define MAX_VALUE 32767
#define random(x) (rand() % x)

void initArray(int ary[], int n) {
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		ary[i] = random(random(128));
}

void printArray(int ary[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", ary[i]);
	putchar('\n');
}

/* return the rival of team t */
int rival(int t) {
	if (t % 2 == 0)
		return t + 1;
	else
		return t - 1;
}

/* the samller is winner */
int winner(int teams[], int n, int i, int j) {
	int u = (i >= n) ? i:teams[i];
	int v = (j >= n) ? j:teams[j];

	if (teams[u] <= teams[v]) 
		return u;
	else
		return v;
}
int * createWinnerTree(int ary[], int n) {
	int *teams = malloc(sizeof(int) * 2 * n);
	int i, j, k;
	for (i = 0; i < n; i++)
		teams[n + i] = ary[i];
	for (i = 2 * n - 1; i > 1; i -= 2) {
		j = rival(i);
		k = i / 2;
		teams[k] = winner(teams, n, i, j);
	}
	return teams;
}

int getWinner(int teams[], int n) {
	int t = teams[1];
	int value = teams[t];

	int i, j, k;
	i = t;
	k = i / 2;

	teams[t] = MAX_VALUE;
	while (i > 1) {
		j = rival(i);
		k = i / 2;
		teams[k] = winner(teams, n, i, j);
		i = k;
	}
	return value;
}

int main() {
	int ary[TEAM_NUM];
	int result[TEAM_NUM];
	int index = 0;

	initArray(ary, TEAM_NUM);
	printf("Original data...\n");
	printArray(ary, TEAM_NUM);

	int *teams = createWinnerTree(ary, TEAM_NUM);
	// printArray(teams, TEAM_NUM * 2);

	for (index = 0; index < TEAM_NUM; index++)
		result[index] = getWinner(teams, TEAM_NUM);
	printf("Tournament Sort result...\n");
	printArray(result, TEAM_NUM);
	return 0;
}
