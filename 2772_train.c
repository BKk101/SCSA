#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a,b) {int t; t = (a); (a) = (b); (b) = t;}

int N, M, K;
int map[50 + 3][50 + 3];
int visit[50 + 3];
int chk[50 + 3];
int cp;
int cnt;

void quick_sort(int s, int e, int * a)
{
	int T, P = e;
	int l;

	if (e <= s) return;
	for (l = T = s; l < e; l++) {
		if (a[l] > a[P]) {
			SWAP(a[l], a[T]);
			T++;
		}
	}
	if (P != T) SWAP(a[P], a[T]);
	quick_sort(s, T - 1, a);
	quick_sort(T + 1, e, a);
}

void DFS(int s)
{
	int i;
	
	if (visit[s] == 1) return;
	visit[s] = 1;
	cnt++;
	for (i = 1; i <= N; i++) {
		if (map[s][i] != 0) {
			DFS(i);
		}
	}
}

int main(void)
{
	int i,a,b,sum;

	scanf("%d%d%d", &N, &M, &K);
	for (i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		map[b][a] = map[a][b] = 1;
	}
	for (i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			cnt = 0;
			DFS(i);
			chk[cp++] = cnt;
		}
	}
	quick_sort(0, cp - 1, chk);
	sum = chk[0];
	for (i = 0; i < K; i++) sum += chk[i + 1];
	printf("%d", sum);
	return 0;
}