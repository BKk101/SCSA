#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int que[100 * 100];
int rp, wp;
int N, M, D;
int map[100 + 2][100 + 2];
int cost[100 + 2][100 + 2];

void BFS(void)
{
	int i, j, q;

	for (j=1;j<=N;j++) {
		wp = rp = 0;
		que[wp++] = j;
		cost[j][j] = 0;
		while (rp < wp) {
			q = que[rp++];
			for (i = 1; i <= N; i++) {
				if (map[q][i] == 0) continue;
				if (cost[j][q] + map[q][i] < cost[j][i]) {
					cost[j][i] = cost[j][q] + map[q][i];
					que[wp++] = i;
				}
			}
		}
	}
}

int main(void)
{
	int i,j,a,b,l,cnt,max;

	scanf("%d%d%d", &N, &M, &D);
	for (i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &l);
		map[b][a] = map[a][b] = l;
	}
	for (i = 0; i < 102; i++) {
		for (j = 0; j < 102; j++) cost[i][j] = 0x7fffffff;
	}
	BFS();
	max = 0;
	for (i = 1; i <= N; i++) {
		cnt = 0;
		for (j = 1; j <= N; j++) {
			if (cost[i][j] < D) cnt++;
		}
		if (cnt > max) max = cnt;
	}
	printf("%d", max);
	return 0;
}