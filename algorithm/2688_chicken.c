#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ABS(x,y) ((x)>(y)?(x)-(y):(y)-(x))

typedef struct pos
{
	int x, y;
}Pos;
int N, M, cp,hp;
int map[50 + 2][50 + 2];
Pos home[50 * 2];
Pos chick[15];
int chk[15];
int MIN;

int Dis(void)
{
	int i,j,d,min,sum;

	sum = 0;
	for (j = 0; j < hp; j++) {
		min = 0x7fffffff;
		for (i = 0; i < cp; i++) {
			if (chk[i] == 0) continue;
			d = ABS(home[j].x, chick[i].x) + ABS(home[j].y, chick[i].y);
			if (d < min) min = d;
		}
		sum += min;
	}
	return sum;
}

void DFS(int n, int cnt)
{
	int d;

	if (cnt> M) return;
	if (n == cp) {
		if (cnt == 0) return;
		d = Dis();
		if (d < MIN) MIN = d;
		return;
	}
	chk[n] = 1;
	DFS(n + 1,cnt+1);
	chk[n] = 0;
	DFS(n + 1,cnt);
}

int main(void)
{
	int i, j;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) home[hp++] = (Pos) { j, i };
			else if (map[i][j] == 2) chick[cp++] = (Pos) { j, i };
		}
	}
	MIN = 0x7fffffff;
	DFS(0,0);
	printf("%d", MIN);
	return 0;
}