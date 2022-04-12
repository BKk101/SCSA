#include <stdio.h>

typedef struct que
{
	int x;
	int y;
	int z;
	int time;
}Que;

Que que[100*100*100];
int wp,rp;
int box[101][101][101];
int X,Y,Z;
int sx,sy;
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};

int in_que(int x, int y, int z, int t)
{
	que[wp].y = y;
	que[wp].x = x;
	que[wp].z = z;
	que[wp].time = t;
	wp++;
	return 1;
}

int BFS(void)
{
	Que q;
	int i;
	int nx,ny,nz;

	while (rp < wp) {
		q = que[rp++];
		for (i=0;i<6;i++) {
			nx = q.x + dx[i];
			ny = q.y + dy[i];
			nz = q.z + dz[i];
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y || nz < 0 || nz >= Z || box[nz][ny][nx] != 0) continue;
			in_que(nx,ny,nz, q.time+1);
			box[nz][ny][nx] = 1;
		}
	}
	return q.time;
}

int main(void)
{
	int i,j,k;
	int ans;

	scanf("%d%d%d", &X, &Y, &Z);
	for (k=0;k<Z;k++) {
		for (i=0;i<Y;i++) {
			for (j=0;j<X;j++) {
				scanf("%d", &box[k][i][j]);
				if (box[k][i][j] == 1)
					in_que(j,i,k,0);			
			}
		}
	}
	ans = BFS();
	for (k=0;k<Z;k++) {
		for (i=0;i<Y;i++) {
			for (j=0;j<X;j++) {
				if (box[k][i][j] == 0) {
					ans = -1;
					break;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}