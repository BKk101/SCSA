#include <stdio.h>

typedef struct que
{
	int x,y,t;
}Que;
Que que[55*55*2];
int rp,wp;
int N,M;
char map[55][55];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char c='1';

void in_que(int x, int y, int t)
{
	que[wp].x = x;
	que[wp].y = y;
	que[wp].t = t;
	wp++;
}

void FF(int x, int y)
{
	int i;
	int nx,ny;

	map[y][x] = c;
	for (i=0;i<4;i++) {
		nx = x+dx[i];
		ny = y+dy[i];
		if (map[ny][nx]!='X' || nx<0 || ny<0 || ny>=N || nx>=M) continue;
		map[ny][nx] = c;
		FF(nx,ny);
	}
}

int BFS(void)
{
	Que q;
	int i;
	int nx,ny;
	while (rp<wp) {
		q = que[rp++];
		for (i=0;i<4;i++) {
			nx = q.x+dx[i]; ny = q.y+dy[i];
			if (map[ny][nx]=='1' || nx<0 || ny<0 || ny>=N || nx>=M) continue;
			if (map[ny][nx] == '2') return q.t;
			map[ny][nx] = '1';
			in_que(nx,ny,q.t+1);
		}
	}
	return -1;
}

int main(void)
{
	int i,j;
	scanf("%d%d", &N, &M);
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) scanf(" %c", &map[i][j]);
	}
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (map[i][j] == 'X') {
				FF(j,i);
				c++;
			}
		}
	}
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (map[i][j] == '1') in_que(j,i,0);
		}
	}
	printf("%d", BFS());
	return 0;
}