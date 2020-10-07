#if 1
//BFS 풀이법
#include <stdio.h>

typedef struct que
{
	int x,y;
}Que;
Que que[100000];
int rp,wp;
int N;
int map[101][101];
int sum[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void in_que(int x, int y)
{
	que[wp].x = x;
	que[wp].y = y;
	wp++;
}

void BFS(void)
{
	Que q;
	int i;
	int nx,ny;

	while (rp<wp) {
		q = que[rp++];
		//if (sum[q.y][q.x] >= min) continue;
		for (i=0;i<4;i++) {
			nx = q.x+dx[i];
			ny = q.y+dy[i];
			if (nx > N || ny > N || nx < 1 || ny < 1) continue;
			if (sum[ny][nx] == 0) {
				sum[ny][nx] = sum[q.y][q.x]+map[ny][nx];
				in_que(nx,ny);
			}
			else { //sum 배열을 처음에 무한값으로 채우고 합이 작은 경우만 조건 걸어도됨
				if (sum[q.y][q.x]+map[ny][nx] < sum[ny][nx]) {
					sum[ny][nx] = sum[q.y][q.x]+map[ny][nx];
					in_que(nx,ny);
				}
			}
		}
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	//for (i=1;i<=N;i++) min += map[1][i]; ->이거 탐색하느라 없는거 보다 시간 더걸림
	//for (i=1;i<=N;i++) min += map[i][N];
	in_que(1,1);
	sum[1][1] = map[1][1];
	BFS();
	printf("%d", sum[N][N]);
	return 0;
}
#endif

#if 0
//DFS 풀이법

#include <stdio.h>

int N;
int map[101][101];
int visit[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int min;

void DFS(int x, int y, int sum)
{
	int i;
	int nx,ny;

	if (sum >= min) return ;
	if (x>N || y>N || x<1 || y<1) return ;
	if (visit[y][x] != 0 && sum >= visit[y][x]) return ;
	visit[y][x] = sum;
	if (x == N && y == N) {
        if (sum < min) min = sum;
	}
	for (i=0;i<4;i++) {
		nx = x+dx[i];
		ny = y+dy[i];
		DFS(nx,ny,sum+map[ny][nx]);
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	min = 9999;
	DFS(1,1,map[1][1]);
	printf("%d", visit[N][N]);
	return 0;
}

#endif