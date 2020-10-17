#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct que
{
	int x, y;
	long long t;
}Que;
Que que[30 * 30 * 50];
int rp, wp;
int N, A, B;
char map[32][32];
long long visit[32][32];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ex, ey;
long long max;

void BFS()
{
	int i, nx, ny;
	long long nt;
	Que q;
	while (rp < wp) {
		q = que[rp++];
		for (i = 0; i < 4; i++) {
			nx = q.x + dx[i]; ny = q.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			nt = (map[q.y][q.x] == map[ny][nx]) ? q.t + A : q.t + B;
			if (nt >= visit[ny][nx]) continue;
			visit[ny][nx] = nt;
			que[wp++] = (Que) { nx, ny, nt };
		}
	}
}

void Clear(void)
{
	int i, j;
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) visit[i][j] = 0x7fffffff;
	}
	rp = wp = 0;
}

int main(void)
{
	int i,j;

	scanf("%d%d%d", &N, &A, &B);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	max = 0;
	for (i = 0; i < N*N; i++) {
		Clear();
		que[wp++] = (Que) { i%N, i / N, 0 };
		visit[i / N][i%N] = 0;
		BFS();
		for (j=0;j<N*N;j++) {
			if (visit[j/N][j%N]>max) max = visit[j/N][j%N];
		}
	}
	printf("%lld", max);
	return 0;
}