#include <stdio.h>

int map[10][10];
int dir[4];

int main(void)
{
	int N;
	int i,j;
	int x,y;
	int dis;
	int move;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) map[i][j] = -2;
	}
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++)
			scanf("%1d", &map[i][j]);
	}
	for (i=0;i<4;i++)
		scanf("%d", &dir[i]);
	map[0][0] = -1;
	for (x=y=dis=move=0;;) {
		if (map[0][1] == 1 && map[1][0] == 1) break;
		if (dir[move] == 1) {
			j=0; i=1;
		}
		else if (dir[move] == 2) {
			j=-1; i=0;
		}
		else if (dir[move] == 3) {
			j=0; i=-1;
		}
		else if (dir[move] == 4) {
			j=1; i=0;
		}
		if (map[y+i][x+j] == 1 || y+i < 0 || y+i >= N || x+j < 0 || x+j >= N)
			move = (++move)%4;
		else if (map[y+i][x+j] == -1)
			break;
		else {
			y += i; x += j;
			map[y][x] = -1;
			dis++;
		}
	}
	printf("%d", dis);
	return 0;
}