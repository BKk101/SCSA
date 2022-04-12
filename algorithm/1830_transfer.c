#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Info
{
	int x1, y1;
	int x2, y2;
}Info;

typedef struct que
{
	int id, t;
}Que;

Que que[5000*2];
int rp, wp;
Info bus[5005];
int visit[5005];
int M, N, K;
int sx, sy, dx, dy;
int min;

int Check(int n, int x1, int y1)
{
	if (x1 >= bus[n].x1 && x1 <= bus[n].x2) {
		if (y1 >= bus[n].y1 && y1 <= bus[n].y2) return 1;
	}
	return 0;
}

int Check2(int a, int b)
{
	if ((bus[a].x2 < bus[b].x1) || (bus[b].x2 < bus[a].x1)) return 0;
    if ((bus[a].y2 < bus[b].y1) || (bus[b].y2 < bus[a].y1)) return 0;
    return 1;
}

int BFS(void)
{
	Que q;
	int i;

	while (rp < wp) {
		q = que[rp++];
		if (Check(q.id, dx, dy)) return q.t;
		for (i = 1; i <= K; i++) {
			if (visit[i] == 1) continue;
			if (Check2(q.id,i)) {
				que[wp++] = (Que) {i,q.t+1};
				visit[i] = 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	int i,id,x1,x2,y1,y2;

	scanf("%d%d%d", &M, &N, &K);
	for (i = 0; i < K; i++) {
		scanf("%d%d%d%d%d", &id, &x1, &y1, &x2, &y2);
		bus[id].x1 = x1 < x2 ? x1 : x2;
		bus[id].x2 = x1 < x2 ? x2 : x1;
		bus[id].y1 = y1 < y2 ? y1 : y2;
		bus[id].y2 = y1 < y2 ? y2 : y1;
	}
	scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
	for (i = 1; i <= K; i++) {
		if (Check(i, sx, sy)) {
			que[wp++] = (Que) { i, 1 };
			visit[i] = 1;
		}
	}
	printf("%d", BFS());
	return 0;
}