#include <stdio.h>

typedef struct que
{
	int x,y;
	int dis;
}Que;

Que que[200*200];
int map[101][101];
int rp,wp;
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
int Y,X;
int R,C,S,K;

int in_que(int x, int y, int dis)
{
	que[wp].x = x;
	que[wp].y = y;
	que[wp].dis = dis;
	wp++;
	return 1;
}

int BFS(void)
{
	Que q;
	int i;
	int nx,ny;

	while (rp<wp) {
		q = que[rp++];
		for (i=0;i<8;i++) {
			nx = q.x + dx[i];
			ny = q.y + dy[i];
			if (map[ny][nx] == 1 || nx<1 || nx>X || ny<1 || ny>Y) continue;
			if (nx == K && ny == S) return q.dis+1;
			in_que(nx,ny,q.dis+1);
			map[ny][nx] = 1;
		}
	}
	return -1;
}

int main(void)
{
	int ans;

	scanf("%d%d", &Y, &X);
	scanf("%d%d%d%d", &R, &C, &S, &K);
	in_que(C,R,0);
	map[R][C] = 1;
	ans = BFS();
	printf("%d", ans);
	return 0;
}