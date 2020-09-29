#include <stdio.h>

typedef struct que
{
	int row;
	int col;
	int time;
}Que;

Que que[100*100];
int rp, wp;
int map[101][101];
int start[2];
int end[2];
int R,C;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int in_que(int x, int y, int t)
{
	que[wp].row = y;
	que[wp].col = x;
	que[wp].time = t;
	wp++;
	return 1;
}

int move(void)
{
	Que q;
	int i;
	int nx,ny;

	in_que(start[0], start[1], 0);
	map[start[1]][start[0]] = 1;
	while (rp < wp) {
		q = que[rp++];
		if (q.row == end[1] && q.col == end[0]) return q.time;
		for (i=0;i<4;i++) {
			nx = q.col + dx[i];
			ny = q.row + dy[i]; 
			if (nx < 1 || nx > C || ny <1 || ny > R || map[ny][nx] == 1) continue;
			in_que(nx,ny, q.time+1);
			map[ny][nx] = 1;
		}
	}
}

int main(void)
{
	int i,j;
	int ans;

	scanf("%d%d", &C, &R);
	scanf("%d%d", &start[0], &start[1]);
	scanf("%d%d", &end[0], &end[1]);
	for (i=0;i<=R;i++) {
		for (j=0;j<=C;j++) {
			if (i == 0 || j == 0) map[i][j] = 1;
			else scanf("%1d", &map[i][j]);
		}
	}
	ans = move();
	printf("%d", ans);
}