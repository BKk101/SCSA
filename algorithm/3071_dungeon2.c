#include <stdio.h>

typedef struct que
{
	int x,y,z;
	int time;
}Que;
Que que[35*35*35];
int rp,wp;
int X,Y,Z;
char map[35][35][35];
int sx,sy,sz;
int ex,ey,ez;
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,-1,1};

void in_que(int x, int y, int z, int time)
{
	que[wp].x = x;
	que[wp].y = y;
	que[wp].z = z;
	que[wp].time = time;
	wp++;
}

void Input(void)
{
	int i,j,k;

	for (i=0;i<Z;i++) {
		for (j=0;j<Y;j++) {
			for (k=0;k<X;k++) {
				scanf(" %c", &map[i][j][k]);
				if (map[i][j][k] == 'S') {sz = i; sy = j; sx = k;}
				else if (map[i][j][k] == 'E') {ez = i; ey = j; ex = k;}
			}
		}
	}
}

void Clear(void)
{
	int i,j,k;
	rp = wp = 0;
	sx = sy = sz = 0;
	ex = ey = ez = 0;
	for (i=0;i<35;i++) {
		for (j=0;j<35;j++) {
			for (k=0;k<35;k++) {
				map[i][j][k] = 0;
			}
		}
	}
	for (i=0;i<35*35*35;i++) que[i] = (Que) {0,0,0,0};
}

int BFS(void)
{
	Que q;
	int i;
	int nx,ny,nz;

	while (rp<wp) {
		q = que[rp++];
		if (q.x == ex && q.y == ey && q.z == ez) return q.time;
		for (i=0;i<6;i++) {
			nx = q.x+dx[i];
			ny = q.y+dy[i];
			nz = q.z+dz[i];
			if (nx<0 || ny<0 || nz<0 || nx>=X || ny>=Y || nz>=Z) continue;
			if (map[nz][ny][nx] == '#') continue;
			in_que(nx,ny,nz,q.time+1);
			map[nz][ny][nx] = '#'; 
		}
	}
	return -1;
}

int main(void)
{
	int t;

	while (1) {
		scanf("%d%d%d", &Z,&Y,&X);
		if (X==0 && Y==0 && Z==0) break;
		Clear();
		Input();
		in_que(sx,sy,sz,0);
		t = BFS();
		if (t == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", t);
	}
	return 0;
}