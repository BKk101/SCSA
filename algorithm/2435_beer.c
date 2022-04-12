#if 0

#include <stdio.h>
#define ABS(x) ((x)>0 ? (x): -(x))
typedef struct que {
	int id;
}Que;

int T, N;
int x[100 + 5];
int y[100 + 5];
int rp, wp;
Que que[100 * 100];
int visit[100 + 5];

int dis(int x1, int y1, int x2, int y2)
{
	return ABS(x2 - x1) + ABS(y2 - y1);
}

int BFS(void)
{
	int i;
	int left;
	Que q;
	que[wp++] = (Que) { 0 };
	visit[0] = 20;
	while (rp < wp) {
		q = que[rp++];
		if (q.id == N + 1) return 1;
		for (i = 0; i < N + 2; i++) {
			left = 20 - (dis(x[q.id], y[q.id], x[i], y[i])+49)/50;
			if (i == q.id || left <= visit[i]) continue;
			que[wp++] = (Que) { i };
			visit[i] = left;
		}
	}
	return -1;
}
int main(void)
{
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < 100 + 5; i++) visit[i] = -1;
		rp = wp = 0;
		for (int i = 0; i < N+2; i++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		/*
		if (T == 47 && t == 2) {
			printf("%d\n", N);
			for (int i = 0; i < N + 2; i++) {
				printf("(%d %d)", x[i], y[i]);
			}
			continue;
		}
		*/
		if (BFS() == 1) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}

#endif
