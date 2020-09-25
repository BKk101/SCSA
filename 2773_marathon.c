#include <stdio.h>
#define ABS(x,y) ((x)>(y) ? ((x)-(y)) : ((y)-(x)))

typedef struct pos
{
	int x;
	int y;
}Pos;
Pos point[100005];

int main(void)
{
	int N;
	int x,y;
	int oldx,oldy;
	int dis;
	int max;
	int d1,d2,d3;
	int i;
	int idx;

	scanf("%d", &N);
	scanf("%d%d", &point[0].x, &point[0].y);
	oldx = point[0].x;
	oldy = point[0].y;
	max = dis = 0;
	for (i=1;i<N;i++) {
		scanf("%d%d", &point[i].x, &point[i].y);
		dis += ABS(point[i].x,oldx) + ABS(point[i].y,oldy);
		oldx = point[i].x;
		oldy = point[i].y;
	}
	for (i=1;i<N-1;i++) {
		d1 = ABS(point[i].x,point[i-1].x) + ABS(point[i].y,point[i-1].y);
		d2 = ABS(point[i].x,point[i+1].x) + ABS(point[i].y,point[i+1].y);
		d3 = ABS(point[i+1].x,point[i-1].x) + ABS(point[i+1].y,point[i-1].y);
		if (d1+d2-d3 > max)
			max = d1+d2-d3;
	}
	printf("%d", dis-max);
	return 0;
}