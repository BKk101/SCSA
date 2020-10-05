#include <stdio.h>
#define MIN(x,y) ((x) < (y) ? (x) : (y))
int N;
int num[11][11];
int sum1;
int min2;
int chk[11];

void DFS1(int n)
{
	int i;
	int min1;

	min1 = 99;
	if (n == N) return ;
	for (i=0;i<N;i++) {
		if (num[n][i] < min1) min1 = num[n][i];
	}
	sum1 += min1;
	DFS1(n+1);
}

void DFS2(int n, int sum)
{
	int i;

	if (n == N) {
		if (sum < min2) min2 = sum;
		return ;
	}
	for (i=0;i<N;i++) {
		if (chk[i] == 1) continue;
		if (sum+num[n][i] > min2) continue;
		chk[i] = 1;
		DFS2(n+1, sum + num[n][i]);
		chk[i] = 0;
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			scanf("%d", &num[i][j]);
		}
	}
	min2 = 999;
	DFS1(0);
	DFS2(0,0);
	printf("%d\n%d", sum1, min2);
	return 0;
}