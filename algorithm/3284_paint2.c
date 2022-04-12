#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, R;
int map[30][30];
int dx[] = { 1,-1,-1,1 };
int dy[] = { 1,1,-1,-1 };


void DFS(int n, int x, int y, int k, int * cnt)
{
	int i;
	if (n > R) return;
	for (i = 0; i < 4 * n; i++) {
		if (!(x < 0 || y < 0 || x >= N || y >= N)) {
			if (map[y][x] == 0) { map[y][x] = k; (*cnt)++; }
		}
		y += dy[i / n]; x += dx[i / n];
	}
	DFS(n + 1, x, y - 1, k, cnt);
}

int Paint(int x, int y, int k)
{
	int cnt = 0;

	if (map[y][x] == 0) {
		map[y][x] = k;
		cnt++;
	}
	DFS(1, x, y - 1, k, &cnt);
	return cnt;
}

void Clear(int k)
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == k) map[i][j] = 0;
		}
	}
}

int main(void)
{
	int i,j,t;
	int sum, max;

	scanf("%d%d", &N, &R);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	max = 0;
	for (i = 0; i < N*N; i++) {
		sum = 0;
		sum += Paint(i%N, i / N, 2);
		for (j = i + 1; j < N*N; j++) {
			if (map[j / N][j&N] == 2) continue;
			t = Paint(j%N, j / N, 0);
			sum += t;
			if (sum > max) max = sum;
			sum -= t;
		}
		Clear(2);
	}
	printf("%d", max);
	return 0;
}