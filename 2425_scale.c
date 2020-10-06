#include <stdio.h>

int scale[13];
int marble[8];
char ans[8];
int N;
int M;

void DFS(int n, int l, int r)
{
	int i;

	if (n == N) {
		for (i=0;i<M;i++) {
			if (marble[i]+l == r) ans[i] = 'Y';
		}
		return ;
	}
	for (i=0;i<3;i++) {
		if (i == 0) DFS(n+1,l,r);
		else if (i == 1) DFS(n+1,l+scale[n],r);
		else if (i == 2) DFS(n+1,l,r+scale[n]);
	}
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &scale[i]);
	scanf("%d", &M);
	for (i=0;i<M;i++) scanf("%d", &marble[i]);
	DFS(0,0,0);
	for (i=0;i<M;i++) {
		if (ans[i] != 'Y') ans[i] = 'N';
		printf("%c ", ans[i]);
	}
	return 0;
}