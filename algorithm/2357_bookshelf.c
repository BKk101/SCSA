#include <stdio.h>

int T;
int N;
int B;
int cow[20];
int ans;

void Clear(void)
{
	int i;
	N = B = 0;
	ans = 9999999;
	for (i=0;i<20;i++) cow[i] = 0;
}

void DFS(int n, int sum)
{
	int i;

	if (sum >= B) {
		if (sum < ans) ans = sum;
		return ;
	}
	if (sum > ans || n == N) return ;
	for (i=0;i<2;i++) {
		if (i==0) DFS(n+1, sum + cow[n]);
		else DFS(n+1, sum);
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &T);
	for (i=0;i<T;i++) {
		Clear();
		scanf("%d%d", &N,&B);
		for (j=0;j<N;j++) scanf("%d", &cow[j]);
		DFS(0,0);
		printf("%d\n", ans-B);
	}
	return 0;
}