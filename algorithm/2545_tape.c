#include <stdio.h>
#define ABS(x,y) ((x)>(y)? (x)-(y):(y)-(x))
int N;
int tape[25];
int min;

void DFS(int n, int l, int r, int a, int b)
{
	int i;
	
	if (n == N) {
		if (a != b) return;
		if (ABS(l,r)<min) {
			min = ABS(l,r);
			//printf("%d %d\n", l,r);
		}
		return ;
	}
	DFS(n+1,l+tape[n],r,a+1,b);
	DFS(n+1,l,r+tape[n],a,b+1);
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &tape[i]);
	min = 0x7fffffff;
	DFS(0,0,0,0,0);
	printf("%d", min);
}