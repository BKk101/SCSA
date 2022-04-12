#include <stdio.h>

int X,Y;
int map[11][11];
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int sect;
int max;

void Flood(int x, int y)
{
	int i;

	if (x<0 || x>X || y<0|| y>Y) return ;
	if (map[y][x] == 0) return;
	map[y][x] = 0;
	sect++;
	for (i=0;i<8;i++) {
		Flood(x+dx[i], y+dy[i]);
	}
}

int main(void)
{
	int i,j;

	scanf("%d%d", &Y,&X);
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			scanf("%d", &map[i][j]);		
		}
	}
	max = 0;
	for (i=0;i<Y;i++) {
		for (j=0;j<X;j++) {
			sect = 0;
			if (map[i][j] == 1)	Flood(j,i);
			if (sect > max) max = sect;
		}
	}
	printf("%d", max);
	return 0;
}