#include <stdio.h>
typedef struct que
{
	int x,y,t;
	int bx,by;
}Que;
Que que[15*15*15*15*2];
int rp,wp;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int T,R,C;
char map[20][20];
int visit[20][20][20][20];
int rx,ry;
int bx,by;
int hx,hy;

int BFS(void)
{
	int i,nx,ny,nbx,nby;
	Que q;
	while (rp<wp) {
		q = que[rp++];
		if (q.t>10) return -1;
		if (q.x == hx && q.y == hy) return q.t;
		for (i=0;i<4;i++) {
			nx = q.x+dx[i]; ny = q.y+dy[i];
			nbx = q.bx+dx[i]; nby = q.by+dy[i];
			if (map[ny][nx] == '#') {nx = q.x; ny = q.y;}
			if (map[nby][nbx] == '#') {nbx = q.bx; nby = q.by;}
			if (visit[ny][nx][nby][nbx] == 1) continue;
			if ((nx == nbx && ny == nby) || (nbx == hx && nby == hy)) continue;
			visit[ny][nx][nby][nbx] = 1;
			que[wp++] = (Que) {nx,ny,q.t+1,nbx,nby};
		}
	}
	return -1;
}

void Clear(void)
{
	int i,j,k,l;
	rp = wp = 0;
	for (i=0;i<20;i++) {
		for (j=0;j<20;j++) {
			map[i][j] = 0;
			for (k=0;k<20;k++) {
				for (l=0;l<20;l++) {
					visit[i][j][k][l] = 0;
				}
			}
		}
	}
}

int main(void)
{
	int t,i,j;
	scanf("%d", &T);
	for (t=0;t<T;t++) {
		Clear();
		scanf("%d%d", &R,&C);
		for (i=0;i<R;i++) {
			for (j=0;j<C;j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == 'B') {bx = j; by = i;}
				else if (map[i][j] == 'R') {rx = j; ry = i;}
				else if (map[i][j] == 'H') {hx = j; hy = i;}
			}
		}
		que[wp++] = (Que) {rx,ry,0,bx,by};
		printf("%d\n",BFS());
	}
	return 0;
}