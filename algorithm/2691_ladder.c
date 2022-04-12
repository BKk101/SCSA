#include <stdio.h>

int N,M,H;
int map[35][25];

int Go(void) 
{
	int i,j,s,ans;

	ans = 0;
	for (j=1;j<=N;j+=2) {
		s = j;
		for (i=1;i<=H;i++) {
			if (map[i][s] == 1 && map[i][s+1] == 1) s+=2;
			else if (map[i][s] == 1 && map[i][s-1] == 1) s-=2;
		}
		if (s != j) return 0;
		//printf("%d -> %d\n", (j+1)/2,(s+1)/2);
	}
	return 1;
}

int DFS(int n)
{
	int i,j, t;

	if (Go() == 1) return n;
	if (n == 3) return -1;
	for (i=1;i<N;i+=2) {
		for (j=1;j<=H;j++) {
			if (map[j][i] == 1 || map[j][i+2] == 1) continue;
			map[j][i] = map[j][i+1] = map[j][i+2] = 1;
			if ((t = DFS(n+1)) != -1) return t;
			map[j][i] = map[j][i+1] = map[j][i+2] = 0;
		}
	}
	return -1;
}

int main(void)
{
	int i,j;
	int a,b;

	scanf("%d%d%d", &N,&M,&H);
	N = 2*(N-1)+1;	  
	for (i=0;i<M;i++) {
		scanf("%d%d", &a,&b);
		b = 2*(b-1)+1;
		map[a][b] = map[a][b+1] = map[a][b+2] = 1;
	}
	printf("%d\n", DFS(0));
	//for (i=1;i<=H;i++) {
	//	for (j=1;j<=N;j++) {
	//		printf("%d ", map[i][j]);
	//	}
	//	printf("\n");
	//}
	return 0;
}