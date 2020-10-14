#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[505][505];
int cost[505][505];
int que[500 * 500];
int rp, wp;
int N,M;

void BFS(void)
{
	int i, j, q;

	for (j = 1; j <= M; j++) {
		rp = wp = 0;
		que[wp++] = j;
		cost[j][j] = 0;
		while (rp < wp) {
			q = que[rp++];
			for (i = 1; i <= N; i++) {
				if (map[q][i] == 0) continue;
				if (map[q][i] + cost[j][q] < cost[j][i]) {
					cost[j][i] = cost[j][q] + map[q][i];
					que[wp++] = i;
				}
			}
		}
	}
}

int main(void)
{
	int i,j,a,b;
	long long sum;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
		if (a > M) M = a;
	}
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= M; j++) cost[i][j] = 0x7fffffff;
	}
	BFS();
	sum = 0;
	a = 0;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= M; j++) {
			if (cost[i][j] != 0x7fffffff && cost[i][j] != 0) {
				sum += cost[i][j];
				a++;
			}
		}
	}
	printf("%.3f", (double)sum / a);
	return 0;
}