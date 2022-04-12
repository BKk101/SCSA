#include <stdio.h>

int D;
int N;
int shop_d[55];
int shop_t[55];
int min;

void DFS(int n, int pre, int time)
{
	int i;

	if (time >= min) return ;
	if (n == N+1) {
		if (pre+shop_d[n] > D) return;
		if (time < min) min = time;
		return ;
	}
	for (i=0;i<2;i++) {
		if (pre + shop_d[n] <= D) {
			if (i == 1) DFS(n+1,0,time + shop_t[n]);
			else DFS(n+1,pre + shop_d[n],time);
		}
	}
}

int main(void)
{
	int i;
	scanf("%d %d", &D, &N);
	for (i=1;i<=N+1;i++) scanf("%d", &shop_d[i]);
	for (i=1;i<=N;i++) scanf("%d", &shop_t[i]);
	min = 0x7fffffff;
	DFS(1,0,0);
	printf("%d", min);
	return 0;
}