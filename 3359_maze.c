#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct que
{
	int x, y, t;
	int bomb;
}Que;
Que que[35 * 35];
int map[32][32];
int visit[4][32][32];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int rp, wp;
int R, C;
int ex, ey;

int BFS()
{
	Que q;
	int i;
	int nx, ny, nb;

	while (rp < wp) {
		q = que[rp++];
		if (q.x == ex && q.y == ey) return q.t;
		for (i = 0; i < 4; i++) {
			nx = q.x + dx[i]; ny = q.y + dy[i]; nb = q.bomb;
			if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
			if (map[ny][nx] == 2) nb--;
			if (nb < 0) continue;
			if (visit[q.bomb][ny][nx] == 1 || map[ny][nx] == 1) continue;
			visit[q.bomb][ny][nx] = 1;
			que[wp++] = (Que) { nx, ny, q.t + 1, nb };
		}
	}
	return -1;
}

int main(void)
{
	int i, j;
	scanf("%d%d", &R, &C);
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 3) { 
				que[wp++] = (Que) { j, i, 0, 3 }; 
				visit[3][i][j] = 1;
			}
			else if (map[i][j] == 4) { ex = j; ey = i; }
		}
	}
	printf("%d", BFS());

	return 0;
}