#include <stdio.h>
#define ABS(x,y) ((x)>(y) ? (x)-(y):(y)-(x))
typedef struct pos
{
	int x,y;
}Pos;

Pos snack[11];
Pos robot[11];
int chk[11];
int T;
int N;
int min;

void Clear(void)
{
	int i;

	for (i=0;i<11;i++) {
		snack[i].x = robot[i].x = 0;
		snack[i].y = robot[i].y = 0;
		chk[i] = 0;
	}
	min = 9999;
}

void DFS(int n, int sum)
{
	int i;
	int dis;
	if (n == N) {
		if (sum < min) min = sum;
		return ;
	}
	for (i=0;i<N;i++) {
		if (chk[i] == 1) continue;
		dis = ABS(robot[n].x,snack[i].x) + ABS(robot[n].y,snack[i].y); //제일처음에 거리계산해서 표만들고 하면 편함
		if (sum+dis >= min) continue;
		chk[i] = 1;
		DFS(n+1, sum+dis);
		chk[i] = 0;
	}
}

int main (void)
{
	int i,j;

	scanf("%d",&T);
	for (j=0;j<T;j++) {
		Clear();
		scanf("%d", &N);
		for (i=0;i<N;i++) {
			scanf("%d%d", &snack[i].y, &snack[i].x);
		}
		for (i=0;i<N;i++) {
			scanf("%d%d", &robot[i].y, &robot[i].x);
		}
		DFS(0,0);
		printf("%d\n", min);
	}
	return 0;
}