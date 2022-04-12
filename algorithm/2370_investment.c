#include <stdio.h>

int table[35][10];
int inv[10];
int ans[10];
int M,C;
int max;

void DFS(int n, int sum, int pro)
{
	int i;

	if (sum > M) return ;
	if (sum == M || n > C) {
		if (pro>max) {
			max = pro;
			for (i=1;i<=C;i++) ans[i] = inv[i];
		}
		return ;
	}
	for (i=0;i<=M;i++) {
		inv[n] = i;
		DFS(n+1,sum+i,pro+table[i][n]);
		inv[n] = 0;
	}
}

int main(void)
{
	int i,j;

	scanf("%d%d", &M, &C);
	for (i=1;i<=M;i++) {
		for (j=0;j<=C;j++) {
			scanf("%d", &table[i][j]);
		}
	}
	DFS(1,0,0);
	printf("%d\n", max);
	for (i=1;i<=C;i++) printf("%d ", ans[i]);
}