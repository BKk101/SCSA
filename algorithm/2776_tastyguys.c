#if 0

#include <stdio.h>

int N;
long long M;
int ans = 0x7fffffff;
int F[100000 + 10];
int S[100000 + 10];


int check(int mid)
{
	int i;
	long long sum = 0;

	for (i = 0; i < N; i++) {
		if (S[i] <= mid) {
			sum += F[i];
		}
		else {
			sum = 0;
		}
		if (sum >= M) return 1;
	}
	return 0;
}

int main(void)
{
	int i, max = 0;
	int low, high, mid;

	scanf("%d%lld", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d%d", &F[i], &S[i]);
		if (S[i] > max) max = S[i];
	}

	low = 1; high = max;
	while (low <= high) {
		mid = (low + high) / 2;
		if (check(mid)) {
			if (mid < ans) ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

#endif