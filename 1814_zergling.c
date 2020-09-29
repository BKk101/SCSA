#include <stdio.h>

typedef struct que
{
	int x;
	int y;
	int time;
}Que;

Que que[100*100];
int wp,rp;
int map[101][101];
int X,Y;
int sx,sy;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int in_que(int x, int y, int t)
{
	que[wp].y = y;
	que[wp].x = x;
	que[wp].time = t;
	wp++;
	return 1;
}

int BFS(void)
{
	Que q;
	int i;
	int nx,ny;

	in_que(sx, sy, 0);
	map[sy][sx] = 0;
	while (rp < wp) {
		q = que[rp++];
		for (i=0;i<4;i++) {
			nx = q.x + dx[i];
			ny = q.y + dy[i]; 
			if (nx < 1 || nx > X || ny <1 || ny > Y || map[ny][nx] == 0) continue;
			in_que(nx,ny, q.time+1);
			map[ny][nx] = 0;
		}
	}
	return q.time+3;
}

int main(void)
{
	int i,j;
	int cnt;

	scanf("%d%d", &X, &Y);
	for (i=1;i<=Y;i++) {
		for (j=1;j<=X;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	scanf("%d%d", &sx, &sy);
	printf("%d\n", BFS());
	cnt = 0;
	for (i=1;i<=Y;i++) {
		for (j=1;j<=X;j++) {
			if (map[i][j] == 1) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}