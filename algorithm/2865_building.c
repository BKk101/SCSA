#include <stdio.h>
int N;
int cost[11][11];
int chk[11];
int min;

void DFS(int n, int sum)
{
	int i;

	if (n == N) {
		if (sum < min) min = sum;
		return ;
	}
	for (i=0;i<N;i++) {
		if (chk[i] == 1) continue;
		if (sum >= min) continue;
		chk[i] = 1;
		DFS(n+1, sum + cost[n][i]);
		chk[i] = 0;
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	min = 9999;
	DFS(0,0);
	printf("%d", min);
	return 0;
}