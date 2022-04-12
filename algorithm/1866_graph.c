#include <stdio.h>

int map[14][14];
int color[14];
int N;
int M;

int DFS(int n)
{
	int i;
	int chk[14]={0,};

	if (n > N) return 1;
	for (i=1;i<n;i++) {
		if (map[n][i] == 1) chk[color[i]]++;
	}
	for (i=1;i<=M;i++) {
		if (chk[i] != 0) continue;
		color[n] = i;
		if (DFS(n+1) == 1) break;
	}
	if (i>M) return -1;
	else return 1;
}

int main(void)
{
	int i,j;

	scanf("%d%d", &N, &M);
	for (i=1;i<=N;i++) {
		for (j=1;j<=i;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	if (DFS(1) == -1) printf("-1");
	else {
		for (i=1;i<=N;i++) printf("%d ", color[i]);
	}
	return 0;
}