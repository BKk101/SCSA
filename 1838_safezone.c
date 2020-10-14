#include <stdio.h>

int map[105][105];
int copy[105][105];
int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void Rain(void)
{
	int i,j;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			map[i][j]--;
			copy[i][j] = map[i][j];
		}
	}
}

void FF(int x, int y)
{
	int i;
	int nx,ny;

	if (copy[y][x] < 1) return;
	copy[y][x] = 110;
	for (i=0;i<4;i++) {
		nx = x+dx[i]; ny = y+dy[i];
		if (nx<0 || ny<0 || nx>=N || ny>=N) continue;
		if (copy[ny][nx] <= 100) FF(nx,ny);
	}
}

int main(void)
{
	int i,j,k;
	int maxh,ans,area;

	scanf("%d", &N);
	maxh=0;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > maxh) maxh = map[i][j];
		}
	}
	ans = 1;
	for (k=1;k<maxh;k++) {
		Rain();
		area = 0;
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				if (copy[i][j] > 0 && copy[i][j] <= 100) {
					FF(j,i);
					area++;
				}
			}
		}
		if (area>ans) ans = area;
	}
	printf("%d", ans);
	return 0;
}