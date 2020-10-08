#include <stdio.h>
typedef struct que
{
	int x,y;
	int dir;
	int time;
}Que;

Que que[100*100*5];
int rp,wp;
int X,Y;
int map[105][105];
int visit[5][105][105];
int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,1,-1};
int turn[5][3] = {{0,0,0},{1,3,4},{2,4,3},{3,2,1},{4,1,2}}; //오,왼
int sx,sy,sdir;
int ex,ey,edir;

void in_que(int x, int y, int dir, int time)
{
	que[wp].x = x;
	que[wp].y = y;
	que[wp].dir = dir;
	que[wp].time = time;
	wp++;
}

int BFS()
{
	Que q;
	int i,j;
	int nx,ny,ndir;
	int ans=0x7fffffff;

	in_que(sx,sy,sdir,0);
	visit[sdir][sy][sx] = 1;
	while (rp<wp) {
		q = que[rp++];
		if (q.x == ex && q.y == ey && q.dir == edir) return q.time;
		for (i=1;i<=3;i++) {
			nx = q.x+dx[q.dir]*i;
			ny = q.y+dy[q.dir]*i;
			if (nx<1 || nx>X || ny<1 || ny>Y) break;
			if (map[ny][nx] == 1) break;
			if (visit[q.dir][ny][nx] == 1) continue;
			visit[q.dir][ny][nx] = 1;
			in_que(nx,ny,q.dir,q.time+1);
		}
		for (i=1;i<=2;i++) {
			ndir = turn[q.dir][i];
			if (visit[ndir][q.y][q.x] == 1) continue;
			visit[ndir][q.y][q.x] = 1;
			in_que(q.x,q.y,ndir,q.time+1);
		}
	}
}
int main(void)
{
	int i,j;

	scanf("%d%d", &Y, &X);
	for (i=1;i<=Y;i++) {
		for (j=1;j<=X;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d%d%d", &sy, &sx, &sdir);
	scanf("%d%d%d", &ey, &ex, &edir);
	printf("%d", BFS());
	return 0;
}