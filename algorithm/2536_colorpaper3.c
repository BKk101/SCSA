#include <stdio.h>
int map[105][105];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int qx[] = {1,1,-1,-1};
int qy[] = {-1,1,1,-1};

int Cross(int x, int y)
{
	int i;

	for (i=0;i<4;i++) {
		if (map[y+dy[i]][x+dx[i]] == 1) return 1;
	}
	return 0;
}

int Diagonal(int x, int y)
{
	int i;

	for (i=0;i<4;i++) {
		if (map[y+qy[i]][x+qx[i]] == 1) return 1;
	}
	return 0;
}

int main(void)
{
	int x1,y1,w1,h1;
	int x2,y2,w2,h2;
	int i,j;
	int type;

	scanf("%d%d%d%d", &y1,&x1,&w1,&h1);
	scanf("%d%d%d%d", &y2,&x2,&w2,&h2);
	for (i=y1;i<y1+h1;i++) {
		for (j=x1;j<x1+w1;j++) {
			map[i][j] = 1;
		}
	}
	for (i=y2;i<y2+h2;i++) {
		for (j=x2;j<x2+w2;j++) {
			if (map[i][j] == 1) {type = 3; goto EXIT;}
			else map[i][j] = 2;
		}
	}
	for (i=y2;i<y2+h2;i++) {
		for (j=x2;j<x2+w2;j++) {
			if (Cross(j,i) == 1) {type = 2; goto EXIT;}
		}
	}
	for (i=y2;i<y2+h2;i++) {
		for (j=x2;j<x2+w2;j++) {
			if (Diagonal(j,i) == 1) {type = 1; goto EXIT;}
		}
	}
	type = 4;
EXIT:
	printf("%d", type);
}