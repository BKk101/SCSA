#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[7][7];
int K;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int cnt;

void DFS(int n, int ax, int ay)
{
	int i,j;
	int nax, nay;

	if (ax == 5 && ay == 5) {
		if (n >= (25 - K - 1)) cnt++;
		return;
	}
	for (i = 0; i < 4; i++) {
		nax = ax + dx[i]; nay = ay + dy[i];
		if (nax < 1 || nay < 1 || nax > 5 || nay > 5) continue;
		if (map[nay][nax] != 0) continue;
		map[nay][nax] = 2;
		DFS(n + 1, nax, nay);
		map[nay][nax] = 0;
	}
}

int main(void)
{
	int i,j, x, y;
	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d%d", &y, &x);
		map[y][x] = 1;
	}
	map[1][1] = 2;
	DFS(0, 1, 1);
	printf("%d", cnt);
	return 0;
}