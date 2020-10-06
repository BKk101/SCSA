#include <stdio.h>

int T;
int N;
int box[21];
int max;

void DFS(int n, int a, int b, int sum)
{
	int i,j;

	if (n == N) {
		if (sum > max) max = sum;
		return;
	}
	for (i=0;i<3;i++) {
		//if (i == 0) DFS(n+1,a,b,sum);
		if (i == 1) {
			if (box[n]>a) DFS(n+1,box[n],b,sum+box[n]);
			else DFS(n+1,a,b,sum);
		}
		if (i == 2) {
			if (box[n]<b) DFS(n+1,a,box[n],sum+box[n]);
			else DFS(n+1,a,b,sum);
		}
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &T);
	for (i=0;i<T;i++) {
		for (j=0;j<21;j++) box[j] = 0;
		max = 0;
		scanf("%d", &N);
		for (j=0;j<N;j++) scanf("%d", &box[j]);
		DFS(0,0,9999,0);
		printf("%d\n", max);
	}
	return 0;
}