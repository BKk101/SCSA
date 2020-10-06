#include <stdio.h>

int N,M;
int Log[6];
int chk[7];

void DFS1(int n)
{
	int i;

	if (n == N) {
		for (i=0;i<N;i++) printf("%d ", Log[i]);
		printf("\n");
		return ;
	}
	for (i=1;i<=6;i++) {
		Log[n] = i;
		DFS1(n+1);
	}
}

void DFS2(int n, int b)
{
	int i;

	if (n == N) {
		for (i=0;i<N;i++) printf("%d ", Log[i]);
		printf("\n");
		return ;
	}
	for (i=b;i<=6;i++) {
		Log[n] = i;
		DFS2(n+1, i);
	}
}

void DFS3(int n)
{
	int i;

	if (n == N) {
		for (i=0;i<N;i++) printf("%d ", Log[i]);
		printf("\n");
		return ;
	}
	for (i=1;i<=6;i++) {
		if (chk[i] == 1) continue;
		else {
			Log[n] = i;
			chk[i] = 1;
		}	
		DFS3(n+1);
		chk[i] = 0;
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);
	if (M == 1) DFS1(0);
	else if (M == 2) DFS2(0, 1);
	else if (M == 3) DFS3(0);
	return 0;
}