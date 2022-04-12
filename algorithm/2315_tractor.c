#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ABS(x,y) ((x)>(y)?(x)-(y):(y)-(x))

int map[505][505];
int visit[505][505];
int N, D;
int min, max;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int area;

void FF(int x, int y)
{
	int i,nx,ny;

	if (visit[y][x] == D) return;
	visit[y][x] = D;
	area++;
	for (i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (ABS(map[ny][nx],map[y][x])<=D) FF(nx, ny);
	}
}

int search(void)
{
	int i, j,sum;

	sum = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (visit[i][j] != D) {
				area = 0;
				FF(j, i);
				if (area >= (N*N + 1) / 2) return area;
				sum += area;
				if (N*N - sum < (N*N + 1) / 2) return -1;
			}
		}
	}
	return -1;
}
int main(void)
{
	int i,j;
	int low, high;
	scanf("%d", &N);
	max = 0;
	min = 0x7fffffff;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] < min) min = map[i][j];
			if (map[i][j] > max) max = map[i][j];
		}
	}
	low = 0;
	high = max - min;
	while (low <= high) {
		D = (low + high) / 2;
		if (search() == -1) low = D + 1;
		else high = D;
	}
	printf("%d", D);
	return 0;
}