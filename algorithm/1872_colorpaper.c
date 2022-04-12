#include <stdio.h>

int map[100][100];

void fill(int x, int y)
{
	int i,j;

	for (i=y;i<y+10;i++) {
		for (j=x;j<x+10;j++) {
			map[i][j] = 1;
		}
	}
}

int main(void)
{
	int N;
	int i,j;
	int x,y;
	int area;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d", &x, &y);
		fill(x,y);
	}
	for (i=area=0;i<100;i++) {
		for (j=0;j<100;j++) {
			if (map[i][j] == 1)
				area++;
		}
	}
	printf("%d", area);
	return 0;
}