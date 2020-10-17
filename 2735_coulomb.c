#include <stdio.h>
int T, N, M;
int marb[10];
int holex[10];
int chk[10];
int hole[10];
int max;

void sort(void) {
	int i, j;
	for (i = 1; i < M; i++) {
		for (j = i + 1; j <= M; j++) {
			if (holex[i] > holex[j]) {
				int temp = holex[i];
				holex[i] = holex[j];
				holex[j] = temp;
			}
		}
	}
}

int Cal()
{
	int i, j,p;
	int pow[10] = { 0, };

	for (i = 1; i < M; i++) {
		if (hole[i] == 0) continue;
		for (j = i + 1; j <= M; j++) {
			if (hole[j] == 0) continue;
			p = (hole[j] * hole[i]) / (holex[j] - holex[i]);
			pow[i] += p;
			pow[j] += -p;
		}
	}
	for (i = 1; i <= M; i++) {
		if (pow[i] != 0) return 0;
	}
	return 1;
}

void DFS(int n, int cnt)
{
	int i,t;
	if (n > M) {
		if (Cal()) {
			if (cnt > max) max = cnt;
		}
		return;
	}
	for (i = 0; i <= N; i++) {
		if (chk[i] != 0) continue;
		if (i != 0) chk[i] = 1;
		hole[n] = marb[i];
		t = i > 0 ? 1 : 0;
		DFS(n + 1, cnt + t);
		chk[i] = 0;
		hole[n] = 0;
	}
}

int main(void)
{
	int i, t;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		max = 0;
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; i++) scanf("%d", &marb[i]);
		for (i = 1; i <= M; i++) scanf("%d", &holex[i]);
		//sort();
		DFS(1, 0);
		printf("%d\n", max);
		fflush(stdout);
	}
	return 0;
}