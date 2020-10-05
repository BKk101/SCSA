#include <stdio.h>

int N;
int map[11][11];
int cnt;

int check(int x, int y)
{
	int i;

	for (i=0;i<x;i++) if (map[y][i] == 1) return 0;
	for (i=1;i<=x;i++) {
		if (y-i<0 || x-i<0) break;
		if (map[y-i][x-i] == 1) return 0;
	}
	for (i=1;i<=x;i++) {
		if (y+i>N || x-i<0) break;
		if (map[y+i][x-i] == 1) return 0;
	}
	return 1;
}

void DFS(int n)
{
	int i;
	
	if (n == N) {
		cnt++;
		return ;
	}
	for (i=0;i<N;i++) {
		if (check(n,i) == 0) continue; 
		map[i][n] = 1;
		DFS(n+1);
		map[i][n] = 0;
	}
}

int main(void)
{
	scanf("%d", &N);
	DFS(0);
	printf("%d", cnt);
	return 0;
}