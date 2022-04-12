#include <stdio.h>
#define ABS(x,y) ((x)>(y) ? (x)-(y):(y)-(x))
int N;
int mat_S[15];
int mat_B[15];
int visit[15];
int min;

int ans[15];

int Cal(void)
{
	int i;
	int sum,mul;

	sum = 0; mul = 1;
	for (i=0;i<N;i++) {
		if (visit[i] == 1) {
			mul *= mat_S[i];
			sum += mat_B[i];
		}
	}
	if (sum == 0 && mul == 1) return -1;
	return ABS(mul, sum);
}

void DFS(int n)
{
	int i,t;

	if (n == N) {
		if ((t = Cal()) != -1) {
			if (t<min) {
				min = t;
				for (i=0;i<N;i++) ans[i] = visit[i];
			}
		}
		return;
	}
	for (i=0;i<2;i++) {
		visit[n] = i;
		DFS(n+1);
		visit[n] = 0;
	}
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d", &mat_S[i], &mat_B[i]);
	}
	min = 0x7fffffff;
	DFS(0);
	printf("%d", min);
	return 0;
}