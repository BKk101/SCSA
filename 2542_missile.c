#include <stdio.h>
#define ABS(x,y) ((x)>(y) ? (x)-(y):(y)-(x))
typedef struct ship
{
	int x,y;
	int hp;
}Ship;

Ship warship[16];
int chk[16];
int N;
int M;
int power;
int range;
int min;

void Fire(int i, int * lst)
{
	int j;
	int dis;

	for (j=0;j<N;j++) {
		lst[j] = 0;
		if (chk[j] == 1) continue;
		dis = ABS(warship[i].x, warship[j].x) + ABS(warship[i].y, warship[j].y);
		if (dis <= range) {
			warship[j].hp -= power;
			lst[j] = 1;
		}
		if (warship[j].hp <= 0) chk[j] = 1;
	}
}

void Re(int * lst)
{
	int i;

	for (i=0;i<N;i++) {
		if (lst[i] == 1) {
			warship[i].hp += power;
			if (warship[i].hp > 0) chk[i] = 0;
		}
	}
}

void DFS(int n)
{
	int i;
	int chklst[16];// 이거 없애고 범위내 군함에서 hp 계속 빼고 더하면서 가능한듯
	int left;

	if (n == M) {
		for (left=i=0;i<N;i++) if (chk[i] == 0) left++;
		if (left < min) min = left;
		return ;
	}
	for (i=0;i<N;i++) {
		if (chk[i] == 1) continue;
		Fire(i, chklst);
		DFS(n+1);
		Re(chklst);
	}
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d%d", &warship[i].x, &warship[i].y, &warship[i].hp);
	}
	scanf("%d%d%d", &M,&power,&range);
	min = 99;
	DFS(0);
	printf("%d", min);
	return 0;
}