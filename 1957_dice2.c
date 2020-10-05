#include <stdio.h>

int N;
int M;
int Log[10];

void Throw(int n, int sum)
{
	int i;
	if (n == N) {
		if (sum == M) {
			for (i=0;i<N;i++) printf("%d ", Log[i]);
			printf("\n");
		}
		return ;
	} 
	for (i=1;i<=6;i++) {
		Log[n] = i;
		Throw(n+1, sum + i);
	}
}
int main(void)
{
	scanf("%d%d", &N,&M);
	Throw(0, 0);
	return 0;
}