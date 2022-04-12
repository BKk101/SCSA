#include <stdio.h>

typedef struct que
{
	int x;
	int y;
	int time;
}Que;

Que que[1000*1000];
int wp,rp;
int box[1001][1001];
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

	while (rp < wp) {
		q = que[rp++];
		for (i=0;i<4;i++) {
			nx = q.x + dx[i];
			ny = q.y + dy[i]; 
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y || box[ny][nx] != 0) continue;
			in_que(nx,ny, q.time+1);
			box[ny][nx] = 1;
		}
	}
	return q.time;
}

int main(void)
{
	int i,j;
	int ans;

	scanf("%d%d", &X, &Y);
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				in_que(j,i,0);			
		}
	}
	ans = BFS();
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			if (box[i][j] == 0) {
				ans = -1;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}