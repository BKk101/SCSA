#include <stdio.h>

int X,Y;
int map[11][11];
int visit[11][11];
int chk[21][3];
int delt[] = {-1,0,1};
int max;

void func(int pos, int dir, int mode)
{
	int x,y;
	int nx,ny;
	int t;
	
	chk[pos][dir] = mode;
	if (mode == 1) t = 1;
	else t = -1;
	if (pos<X) {x=pos; y=0;}
	else {x=0; y=pos-X;}
	visit[y][x] += t;
	for (;;) {
		if (pos<X) {nx=x+delt[dir]; ny=y+1;}
		else {nx=x+1; ny=y+delt[dir];}
		if (nx<0 || ny<0 || nx>=X || ny>=Y) break;
		visit[ny][nx] += t;
		x = nx; y = ny;
	}	
}

void DFS(int n)
{
	int i,j,sum;

	if (n == 3) {
		for (sum=i=0;i<Y;i++) {
			for (j=0;j<X;j++) {
				if (visit[i][j] != 0) sum+=map[i][j];
			}
		}
		if (sum>max) {
			max = sum;
			//printf("%d\n", sum);
			//for (i=0;i<Y;i++) {
			//	for (j=0;j<X;j++) printf("%d", visit[i][j]);
			//	printf("\n");
			//}
			//for (i=0;i<X+Y;i++) {
			//	for (j=0;j<3;j++) {
			//		if (chk[i][j] == 1) printf("(%d %d) ", i,j);
			//	}
			//}
			//printf("\n\n");
		}
		return ;
	}
	for (i=0;i<X+Y;i++) {
		for (j=0;j<3;j++) {
			if (chk[i][j] == 1) continue;
			func(i,j,1);
			DFS(n+1);
			func(i,j,0);
		}
	}
}

int main(void)
{
	int i,j,k,l;
	scanf("%d%d", &Y,&X);
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	DFS(0);
	printf("%d", max);
	return 0;
}