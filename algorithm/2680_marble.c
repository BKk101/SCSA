#include <stdio.h>

int map[11][11];
int visit[11][11];
int X,Y;
int N;
int dir[13];
int dx[] = {-2,0,0,-1,1};
int dy[] = {-2,-1,1,0,0};
int dis;
int sx,sy;

int main(void)
{
	int i,j;
	int nx,ny;

	scanf("%d%d", &X,&Y);
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 2) {sx = j; sy = i;}
		}
	}
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &dir[i]);
	visit[sy][sx] = 1;
	dis++;
	for (i=0;i<N;) {
		nx = sx + dx[dir[i]];
		ny = sy + dy[dir[i]];
		if (map[ny][nx] == 1 || nx<0 || nx>=X || ny<0 || ny>=Y) {i++; continue;}
		sx = nx;
		sy = ny;
		if (visit[sy][sx] == 0) {dis++; visit[sy][sx] = 1;}
	}
	printf("%d", dis);
	return 0;
}