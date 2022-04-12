#include <stdio.h>

int map[11][11];
int copy[11][11];
int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void Watch(int x, int y)
{
	int nx,ny;
	int sx, sy;
	int dir;

	copy[y][x] = 2;
	for (dir=0;dir<4;dir++) {
        sx = x; sy = y;
	    for (;;) {
			nx = sx+dx[dir];
			ny = sy+dy[dir];
			if (copy[ny][nx] == 1 || nx<0 || nx>=N || ny<0 || ny>=N) break;
			copy[ny][nx] = 2;
			sx = nx;
			sy = ny;
		}
	}
}

int Count(void)
{
	int i,j;
	int cnt=0;

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (copy[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void Clear(void)
{
	int i,j;

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			copy[i][j] = map[i][j];
		}
	}
}

int main(void)
{
	int i,j,k;
	int ans;
	int t;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			scanf("%d", &map[i][j]);
			copy[i][j] = map[i][j];
		}
	}
	ans = 100;
	for (i=0;i<N*N;i++) {
		if (copy[i/N][i%N] == 1) continue;
		for (j=i+1;j<N*N;j++) {
			if (copy[j/N][j%N] == 1) continue;
			for (k=j+1;k<N*N;k++) {
				if (copy[k/N][k%N] == 1) continue;
				Watch(i%N, i/N);
				Watch(j%N, j/N);
				Watch(k%N, k/N);
				if ((t = Count()) < ans) ans = t;
				Clear();
			}
		}
	}
	printf("%d", ans);
	return 0;
}