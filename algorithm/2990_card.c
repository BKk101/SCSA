#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int left[30];
int right[30];
int psum[30];
int max;

void DFS(int ai, int bi, int sum)
{
	
	if (psum[N-1] - psum[bi-1] + sum <= max) return;
	if (ai >= N || bi >= N) {
		if (sum > max) max = sum;
		return;
	}
	if (left[ai] > right[bi]) {
		DFS(ai, bi + 1, sum+right[bi]);
	}
	else {
		DFS(ai + 1, bi, sum);
		DFS(ai + 1, bi + 1, sum);
	}
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &left[i]);
	for (i = 0; i < N; i++) {
		scanf("%d", &right[i]);
		if (i>0) psum[i] = psum[i - 1] + right[i];
		else psum[i] = right[i];
	}
	DFS(0, 0, 0);
	printf("%d", max);
	return 0;

}