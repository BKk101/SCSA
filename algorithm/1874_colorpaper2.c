#include <stdio.h>

int map[101][101];

void fill(int x, int y)
{
	int i,j;

	for (i=y;i<y+10;i++) {
		for (j=x;j<x+10;j++) {
			map[i][j] = 1;
		}
	}
}

int check(int y, int x)
{
	int len=0;

	if (map[y+1][x] == 0) len++;
	if (map[y-1][x] == 0) len++;
	if (map[y][x+1] == 0) len++;
	if (map[y][x-1] == 0) len++;
	return len;
}

int main(void)
{
	int N;
	int i,j;
	int x,y;
	int round;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d", &x, &y);
		fill(x,y);
	}
	round = 0;
	for (i=1;i<100;i++) {
		for (j=1;j<100;j++) {
			if (map[i][j] == 1) {
				round += check(i,j);
			}
		}
	}
	printf("%d", round);
	return 0;
}