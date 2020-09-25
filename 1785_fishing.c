#include <stdio.h>

typedef struct fish
{
	int x;
	int y;
}Fish;

int map[10005][10005];
Fish fish[105];
int N,L,M;

int check(Fish f, int h, int w)
{
	int i,j;
	int cnt = 0;
	for (i=f.y;i<=f.y+h;i++) {
		for (j=f.x;j<=f.x+w;j++) {
			if (i>N || j>N) break;
			if(map[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	int x,y;
	int max = 0;
	int num;
	int i,a;

	scanf("%d%d%d", &N,&L,&M);
	for (i=0;i<M;i++) {
		scanf("%d%d", &y, &x);
		if (y>N || x>N) continue;
		map[y][x] = 1;
		fish[i].y = y;
		fish[i].x = x;
	}
	num = 0;
	for (i=0;i<M;i++) {
		for (a=1;a<L/2;a++) {
			//num = check(fish[i], a,(L/2)-a);
			if(num > max)
				max = num;
		}
	}
	printf("%d", max);
}