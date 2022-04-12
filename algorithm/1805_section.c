#include <stdio.h>
#define SWAP(a,b) {int t; t = (a); (a) = (b); (b) = t;}

typedef struct pos
{
	int x,y;
	int x2,y2;
}Pos;
Pos rec[105];
int M,N,K;
int map[105][105];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int area[100*100];
int cnt;

void quick_sort(int s, int e, int * a)
{
	int T,P=e;
	int l;

	if (e <= s) return ;
	for (l=T=s;l<e;l++) {
		if (a[l]<a[P]) {
			SWAP(a[l],a[T]);
			T++;
		}
	}
	if (P != T) SWAP(a[P], a[T]);
	quick_sort(s,T-1,a);
	quick_sort(T+1,e,a); 
}

void Flood(int x, int y)
{
	int i,j;
	int nx,ny;

	if (map[y][x] != 0) return ;
	map[y][x] = cnt+2;
	area[cnt]++;
	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx<0 || ny<0 || nx>=N || ny>=M) continue;
		if (map[ny][nx] == 0) Flood(nx,ny);
	}
}

int main(void)
{
	int i,j,l;

	scanf("%d%d%d", &M,&N,&K);
	for (i=0;i<K;i++) {
		scanf("%d%d%d%d", &rec[i].x,&rec[i].y,&rec[i].x2,&rec[i].y2);
		for (j=rec[i].y;j<rec[i].y2;j++) {
			for (l=rec[i].x;l<rec[i].x2;l++) {
				map[j][l] = 1;
			}
		}
	}
	for (i=M-1;i>=0;i--) {
		for (j=0;j<N;j++) {
			if (map[i][j] == 0) {
				Flood(j,i);
				cnt++;
			}
		}
	}
	quick_sort(0,cnt-1,area);
	printf("%d\n", cnt);
	for (i=0;i<cnt;i++) {
		printf("%d ", area[i]);
	}
	return 0;
}