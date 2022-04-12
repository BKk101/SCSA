#include <stdio.h>

int T;
int K;
int N;
int cnt;

void DFS(int n, int sum)
{
	int i;
	
	if (sum > K || n > N) return ;
	if (sum == K) {
		cnt++;
		return ;
	}
	for (i=0;i<K;i++) {
		DFS(n+1,sum+(i)*(1<<n));
	}
}

int main(void)
{
	int i;
	int t;

	scanf("%d", &T);
	for (i=0;i<T;i++) {
		scanf("%d", &K);
		t = K;
		N = 1;
		while ((t/=2)>0) N++;
		cnt = 1;
		DFS(0,0);
		printf("%d\n",cnt);
	}
	return 0;
}