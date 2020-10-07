#include <stdio.h>

int map[101][101];
int chk[101];
int N;
int M;
int que[1000];
int rp,wp;
int cnt;

void BFS(void)
{
	int i;
	int q;

	while (rp<wp) {
		q = que[rp++];
		for (i=1;i<=N;i++) {
			if (i == q) continue;
			if (map[q][i] == 1 && chk[i] == 0) {
				que[wp++] = i;
				chk[i] = 1;
				cnt++;
			}
		}
	}
}

int main(void)
{
	int i,j;
	int a,b;

	scanf("%d%d", &N,&M);
	for (i=0;i<M;i++) {
		scanf("%d%d", &a,&b);
		map[a][b] = map[b][a] = 1;
	}
	que[wp++] = 1;
	BFS();
	if (cnt != 0) cnt -= 1;
	printf("%d", cnt);
	return 0;
}