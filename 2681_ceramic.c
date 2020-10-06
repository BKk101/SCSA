#include <stdio.h>

int T;
int N;
int M;
int clay[28];
int cnt;

void DFS(int n, int sum)
{
	int i;
	int t;

	if (sum == M) {
		cnt++;
		return ;
	}
	if (n > 26 || sum > M) return ;
	for (i=0;i<=M;i++) {
		t = n;
		if (clay[n] < i) continue;
		while (clay[++t] == 0);
		DFS(t,sum + i);
	}
}

void Clear(void)
{
	int i;
	for (i=0;i<27;i++) clay[i] = 0;
	cnt = 0;
}

int main(void)
{
	int i,j;
	int t;

	scanf("%d", &T);
	for (i=0;i<T;i++) {
		Clear();
		scanf("%d%d", &N, &M);
		for (j=0;j<N;j++) {
			scanf("%d", &t);
			clay[t]++;
		}
		for (j=1;j<27;j++) {
			if (clay[j] != 0) break;
		}
		clay[27] = 1;
		DFS(j,0);
		printf("%d\n", cnt);
	}
	return 0;
}