#include <stdio.h>

typedef struct info
{
	int x,y;
}Info;
int map[105][105];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int rec[2000];
int ri,wi;
int N;
int cnt;

Info DFS(int gen, Info curv)
{
	Info t;
	int nx,ny;
	int i,s;

	if (gen==0) {
		map[curv.y][curv.x] = 1;
		curv.x += dx[rec[ri]]; curv.y += dy[rec[ri]];
		map[curv.y][curv.x] = 1;
		ri++;
		return curv;
	}
	t = DFS(gen-1, curv);
	if (ri == wi) {
		s = wi;
		for (i=0;i<ri;i++) {rec[wi++] = (rec[s-1-i]+1)%4;}
	}
	t = DFS(gen-1, t);
	return t;
}

void Clear(void)
{
	int i;
	ri = wi = 0;
	for (i=0;i<11;i++) rec[i] = 0;
}

int Check(int x, int y)
{
	int i,j;
	for (i=0;i<2;i++) {
		for (j=0;j<2;j++) {
			if (map[y+i][x+j] == 0) return 0; 
		}
	}
	return 1;
}

int main(void)
{
	Info in;
	int i,j,Gen;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		Clear();
		scanf("%d%d%d%d", &in.x,&in.y,&rec[wi++],&Gen);
		DFS(Gen,in);
	}
	//for (i=0;i<10;i++) {
	//	for (j=0;j<10;j++) printf("%d ", map[i][j]);
	//	printf("\n");
	//}
	cnt = 0;
	for (i=0;i<101;i++) {
		for (j=0;j<101;j++) {
			if (Check(j,i)) cnt++;
		}
	}
	printf("%d", cnt);
}