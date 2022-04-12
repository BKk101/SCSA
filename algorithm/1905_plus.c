#include <stdio.h>

int T;
int arr[20];
int N;
int K;
int ans;

void DFS(int n, int sum)
{
	int i;

	if (sum == K || ans == 1) {
		ans = 1;
		return ;
	}
	if (sum > K || n == N) return ;
	for (i=0;i<2;i++) {
		if (i==0) DFS(n+1, sum + arr[n]);
		else DFS(n+1, sum);
	}
}

void Clear(void)
{
	int i;
	ans=N=K=0;
	for (i=0;i<20;i++) arr[i] = 0;
}

int main(void)
{
	int i,j;
	scanf("%d", &T);
	for (i=0;i<T;i++) {
		Clear();
		scanf("%d%d", &N, &K);
		for (j=0;j<N;j++) scanf("%d", &arr[j]);
		DFS(0,0);
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}