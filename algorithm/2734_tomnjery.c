#include <stdio.h>
#define ABS(x,y) ((x)>(y) ? ((x)-(y)) : ((y)-(x)))

typedef struct pos
{
	int x,y;
}Pos;

int N;
Pos seed[170];
int catx,caty;
int ratx,raty;
int si;

int cat_move()
{
	int disx, disy;
	int dx,dy;

	disx = ABS(catx, ratx);
	disy = ABS(caty, raty);
	dx = disx > 1 ? 2:1;
	dy = disy > 1 ? 2:1;
	if (disy != 0) caty += ((raty-caty)/disy)*dy;
	else if (disy == 0) catx += ((ratx-catx)/disx)*dx;
	if (catx == ratx && caty == raty) return 1;
	else return 0;
}

int rat_move()
{
	int disx, disy;
	
	disx = ABS(ratx,seed[si].x);
	disy = ABS(raty,seed[si].y);
	if (disx != 0) ratx += ((seed[si].x-ratx)/disx);
	else raty += ((seed[si].y-raty)/disy);
	if (ratx == seed[si].x && raty == seed[si].y) si++;
	if (si > N) return 1;
	else return 0;
}

void Init()
{
	int i;

	scanf("%d", &N);
	scanf("%d%d", &ratx, &raty);
	for (i=1;i<N;i++) scanf("%d%d", &seed[i].x, &seed[i].y);
	seed[i].x = 0; seed[i].y = 1;
	scanf("%d%d", &catx, &caty);
	si = 1;
}

int main(void)
{
	int cat,rat;

	Init();
	cat = rat = 0;
	while(1) {
		if ((cat = cat_move())) break;
		if ((rat = rat_move())) break;
	}
	if (cat == 1) printf("0");
	if (rat == 1) printf("1");
	return 0;
}