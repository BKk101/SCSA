#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int T,N;
int blk[52];
int max;

int check(int i, int bp)
{
	int chk[4] = { 0, };
	int j;

	if (i == 1) {
		if (bp == (N - 1)) return 1;
		if (blk[bp] == 2) return 1;
		else return 0;
	}
	else {
		for (j = 0; j < i; j++) chk[blk[bp+j]]++;
		for (j = 1; j <= 3; j++) {
			if (chk[j] > 1) return 0;
		}
		return 1;
	}
}

void DFS(int n, int bp)
{
	int i;

	//가지치기 추가
	if (bp > N) return ;
	if (bp == N) {
		if (n-1 > max) max = n-1;
		return ;
	}
	for (i = 1; i <= 3; i++) {
		if (check(i, bp)) 
			DFS(n+1, bp + i);
	}
}
int main(void)
{
	int i,k;

	scanf("%d", &T);
	for (k = 0; k < T; k++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) scanf("%d", &blk[i]);
		max = -1;
		DFS(1, 0);
		printf("%d\n", max);
	}
	return 0;
}