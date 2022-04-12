#include <stdio.h>
//0,1,2,3 상하좌우
typedef struct pipe
{
	char dir[5];
}Pipe;

Pipe pipe[12] = {"","0110","1001","0011","0101","1100","1010","1011","0111","1101","1110","1111"};
int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};
int map[11][11];
int visit[11][11];
int N;
int pnum;

void Fill(int x, int y, int in)
{
	int i;
	
	if (x<0 || x>=N || y<0 || y>=N) return ;
	if (visit[y][x] == 1 || map[y][x] == 0) return ;
	if (in != -1 && pipe[map[y][x]].dir[in] == '0') return ;
	visit[y][x] = 1;
	pnum--;
	for (i=0;i<4;i++) {
		if (pipe[map[y][x]].dir[i] == '1') {
			Fill(x+dx[i], y+dy[i], 3-i);
		}
	}
}

int main(void)
{
	int sx,sy;
	int i,j;
	scanf("%d", &N);
	scanf("%d%d", &sx, &sy);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			scanf("%1x", &map[i][j]);
			if (map[i][j] != 0) pnum++;
		}
	}
	Fill(sx,sy,-1);
	printf("%d", pnum);
	return 0;
}