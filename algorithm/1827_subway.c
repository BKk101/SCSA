#include <stdio.h>

int N,M;
int map[101][101];
int cost[101];
int que[100*100];
int path[101];
int rp,wp;

void BFS()
{
	int i,q;

	que[wp++] = 1;
	cost[1] = 0;
	while (rp<wp) {
		q = que[rp++];
		for (i=1;i<=N;i++) {
			if (map[q][i] == 0) continue;
			if (map[q][i] + cost[q] < cost[i]) {
				cost[i] = cost[q] + map[q][i];
				que[wp++] = i;
				path[i] = q;
			}
		}
	}
}

void path_print(int n)
{
	if(n == 0) return;
	path_print(path[n]);
	printf("%d ", n);
}

int main(void)
{
	int i,j;

	scanf("%d%d", &N, &M);
	for (i=1;i<=N;i++) {
		cost[i] = 0x7fffffff;
		for (j=1;j<=N;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	BFS();
	printf("%d\n", cost[M]);
	path_print(M);
	return 0;
}