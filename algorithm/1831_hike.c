#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define sqr(x) ((x)*(x))

typedef struct que
{
	int x, y, p;
}Que;
Que que[101 * 101 * 100];
int map[105][105];
int visit[105][105];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int rp, wp;
int ex, ey;
int N;
int min;

int power(int a, int b)
{
	if (a == b) return 0;
	if (a > b) return (a - b)*(a - b);
	if (a < b) return (b - a);
	return -1;
}

void BFS()
{
	Que q;
	int i;
	int nx, ny, np;
	while (rp < wp) {
		q = que[rp++];
		if (q.p >= min) continue;
		if (q.x == ex && q.y == ey) {
			if (q.p < min) min = q.p;
			continue;
		}
		for (i = 0; i < 4; i++) {
			nx = q.x + dx[i]; ny = q.y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			np = q.p + power(map[ny][nx], map[q.y][q.x]);
			if (np >= visit[ny][nx]) continue;
			visit[ny][nx] = np;
			que[wp++] = (Que) { nx, ny, np };
		}
	}
}
int main(void)
{
	int i, j;
	scanf("%d", &N);
	scanf("%d%d", &ey, &ex);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = 0x7fffffff;
			if (i == 1 || j == 1 || i == N || j == N) {
				que[wp++] = (Que) { j, i, sqr(map[i][j]) };
				visit[i][j] = sqr(map[i][j]);
			}
		}
	}
	min = 0x7fffffff;
	BFS();
	printf("%d",min);
	return 0;
}