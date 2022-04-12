#include <stdio.h>

typedef struct fish
{
	int x;
	int y;
}Fish;

Fish fish[105];
int N,L,M;

int check(int x, int y, int h, int w)
{
	int i,j;
	int cnt = 0;
	
	for (i=0;i<M;i++) {
		if (fish[i].x >= x && fish[i].x <= x+w && fish[i].y >= y && fish[i].y <= y+h)
			cnt++;
	}
	return cnt;
}

int main(void)
{
	int x,y;
	int max;
	int num;
	int i,j,a;

	scanf("%d%d%d", &N,&L,&M);
	for (i=0;i<M;i++) {
		scanf("%d%d", &y, &x);
		fish[i].y = y;
		fish[i].x = x;
	}
	max = num = 0;
	for (i=0;i<M;i++) {
		for (j=0;j<M;j++) {
			x = fish[j].x;
			y = fish[i].y;
			for (a=1;a<L/2;a++) {
				num = check(x,y,a,(L/2)-a);
				if(num > max)
					max = num;
			}
		}
	}
	printf("%d", max);
}