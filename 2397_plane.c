#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define YY 13
#define XX 5

int T;
int map[YY + 3][XX + 3];
int copy[YY+3][XX+3];
int dx[] = { -1,0,1 };
int max;

void DFS(int x, int y, int s)
{
	int i;

	if (x<1 || x>XX) return;
	s += map[y][x];
	if (y==1) {
		if (s>max) max = s;
		return;
	}
	for (i=0;i<3;i++) {
		DFS(x+dx[i],y-1,s);
	}
}

void Bomb(int y)
{
	int i,j;

	for (i=y;i>y-5;i--) {
		for (j=1;j<=XX;j++) {
			if (map[i][j] == -7) map[i][j] = 0;
		}
	}
}

void Res(int y)
{
	int i,j;

	for (i=y;i>y-5;i--) {
		for (j=1;j<=XX;j++) {
			map[i][j] = copy[i][j];
		}
	}
}

int main(void)
{
	int i, j, t;
	char c;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		max = -70;
		for (i = 1; i <= YY; i++) {
			for (j = 1; j <= XX; j++) {
				scanf(" %c", &c);
				if (c == '0') copy[i][j] = map[i][j] = 0;
				else if (c == 'X') copy[i][j] = map[i][j] = -7;
				else if (c == '*') copy[i][j] = map[i][j] = 10;
			}
		}
		for (i=12;i>=5;i--) {
			Bomb(i);
			DFS(3,13,0);
			Res(i);
		}
		printf("%d\n", max);
	}
	return 0;
}