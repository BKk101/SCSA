#include <stdio.h>

int M;
int R,B,Y;
int cost[10][3];
int max;

void DFS(int n, int sum, int r, int b, int y)
{
	int i;

	if (n == M) {
		if (sum>max) max = sum;
		return ;
	}
	for (i=0;i<=3;i++) {
		if (r<cost[n][0]*i || b<cost[n][1]*i || y<cost[n][2]*i) continue;
		DFS(n+1, sum+i, r-cost[n][0]*i, b-cost[n][1]*i, y-cost[n][2]*i);
	}
}

int main(void)
{
	int i;

	scanf("%d%d%d%d", &M, &R, &B, &Y);
	for (i=0;i<M;i++) {
		scanf("%d%d%d", &cost[i][0],&cost[i][1],&cost[i][2]);
	}
	DFS(0,0,R,B,Y);
	printf("%d", max);
	return 0;
}