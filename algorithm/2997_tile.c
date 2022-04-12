#if 0

#include <stdio.h>

int N, M;
int cnt;
int rec[10 + 5];

void DFS(int n, int s, int sum)
{
	int i;
	if (n == 0) {
		if (sum == M) {
			//for (i = 1; i <= N; i++) printf("%d ", rec[i]);
			//printf("\n");
			cnt++;
		}
		return;
	}
	for (i = s; i <= sqrt(10000/N); i++) {
		if (sum + i * i > M) break;
		rec[n] = i;
		DFS(n - 1, i, sum + i * i);
		rec[n] = 0;
	}
}	
int main(void)
{
	scanf("%d%d", &N, &M);
	DFS(N, 1, 0);
	printf("%d\n", cnt);
	return 0;
}

#endif

#if 0

#include <stdio.h>
#define MAX 10
int N, M;
int tile[MAX + 2];
int area;

int Comb(int n, int s)
{
	int a;

	if (n == 0) {
		return 0;
	}
	for (int i = s; i < N; i++) {
		if (area > M) {

		}
	}
}

int main(void)
{
	int t, min;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tile[i]);
		area += tile[i] * tile[i];
	}
	if (area == M) min = 0;
	else min = 0x7fffffff;
	for (int i = 1; i <= N; i++) {
		t = Comb(i,0);
		if (t<min) min = t;
	}
	printf("%d", min);
	return 0;
}

#endif
