#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, S;
int Y[10005];
int C[10005];
int chk[10005];

int main(void)
{
	int i, j;
	long long cost;

	scanf("%d%d", &N, &S);
	for (i = 0; i < N; i++) {
		scanf("%d%d", &C[i], &Y[i]);
	}
	cost = 0;
	for (i = 0; i < N; i++) {
		if (chk[i] == 1) continue;
		for (j = 0; i+j < N; j++) {
			if (C[i] + S * j <= C[i+j]) {
				cost += Y[i+j] * (C[i] + S * j);
				chk[i+j] = 1;
			}
		}
	}
	printf("%lld", cost);
	return 0;
}

#if 0

void DFS(int n, int pre, int cost)
{
	int i, s;

	if (cost >= min) return;
	if (n == N) {
		if (cost < min) min = cost;
		return;
	}
	if (pre <= Y[n]) s = Y[n];
	else s = 0;
	for (i = s; i <= sum - pre; i += 5) {
		DFS(n + 1, pre - Y[n] + i, cost + (pre - Y[n] + i)* S + C[n] * i);
	}
}

#endif
