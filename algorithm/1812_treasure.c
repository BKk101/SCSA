#include <stdio.h>

typedef struct que
{
	int x,y;
	int time;
}Que;

Que que[50*50];
int rp,wp;
int X,Y;
char map[51][51];
int visit[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int in_que(int x, int y, int t)
{
	que[wp].x = x;
	que[wp].y = y;
	que[wp].time = t;
	wp++;
}

int BFS(void)
{
	Que q;
	int i;
	int nx,ny;
	
	while (rp<wp) {
		q=que[rp++];
		for (i=0;i<4;i++) {
			nx = q.x+dx[i];
			ny = q.y+dy[i];
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y || map[ny][nx] == 'W' || visit[ny][nx] == 1) continue;
			in_que(nx,ny, q.time+1);
			visit[ny][nx] = 1;
		}
	}
	return q.time;
}

void Init(void)
{
	int i,j;

	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++)
			visit[i][j] = 0;
	}
	rp = wp = 0;
}

int main(void)
{
	int i,j;
	int t,max;

	scanf("%d%d", &Y, &X);
	for (i=0;i<Y;i++) {
		scanf("%s", map[i]);
	}
	max = 0;
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			if (map[i][j] == 'L') {
				Init();
				in_que(j,i,0);
				visit[i][j] = 1;
				if ((t = BFS()) > max) max = t;
			}
		}
	}
	printf("%d", max);
}