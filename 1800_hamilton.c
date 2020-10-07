#include <stdio.h>

int map[13][13];
int visit[13];
int N;
int min;

void DFS(int n, int node, int cost)
{
	int i;

	if (cost >= min) return ; //가지치기
	if (n == N) {
		if (map[node][1] == 0) return; 
		cost += map[node][1];
		if (cost < min) min = cost;
		return ;
	}
	for (i=1;i<=N;i++) {
		if (visit[i] != 0 || map[node][i] == 0) continue;
		visit[i] = n+1;
		DFS(n+1,i,cost+map[node][i]);
		visit[i] = 0;
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	min = 9999;
	visit[1] = 1;
	DFS(1,1,0);
	printf("%d", min);
	return 0;
}