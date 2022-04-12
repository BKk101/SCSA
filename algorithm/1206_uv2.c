#if 0

#include <stdio.h>

typedef struct que {
	int x, y;
	int sum;
}Que;
int a[100 + 10][100 + 10];
int visit[100 + 10][100 + 10];
int N;
int sol;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int lastnode = 0;
Que heap[100 * 100 * 10];

int push(Que q)
{
	int n, p;
	if (lastnode == 100*100*10 -1) return 0;
	heap[++lastnode] = q;
	n = lastnode; //child
	p = n / 2; //parent
	while (p > 0) {
		if (heap[p].sum > heap[n].sum) {
			Que temp;
			temp = heap[p];
			heap[p] = heap[n];
			heap[n] = temp;

			n = p;
			p = n / 2;
		}
		else break;
	}
	return 1;
}

int pop(Que *p)
{
	int n, lc, rc, c;
	if (lastnode == 0) return 0;
	*p = heap[1];
	heap[1] = heap[lastnode--];

	n = 1; lc = 2; rc = 3;
	while (lc <= lastnode) {
		if (lc == lastnode) c = lc;
		else c = heap[lc].sum < heap[rc].sum ? lc : rc;

		if (heap[n].sum > heap[c].sum) {
			Que temp;
			temp = heap[n];
			heap[n] = heap[c];
			heap[c] = temp;

			n = c; lc = n * 2; rc = lc + 1;
		}
		else break;
	}
	return 1;
}

int	BFS()
{
	Que temp;
	int nx, ny, nsum;
	int i;
	while (pop(&temp)) {
		if (temp.x == N - 1 && temp.y == N - 1) return temp.sum;
		for (i = 0; i < 4; i++) {
			nx = temp.x + dx[i]; ny = temp.y + dy[i];
			nsum = temp.sum + a[temp.y][temp.x];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (nsum >= visit[ny][nx]) continue;
			visit[ny][nx] = nsum;
			push((Que) { nx, ny, nsum });
		}
	}
	return 0;
}

int main(void)
{
	int i, j;

	// 입력받는 부분
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &a[i][j]);
			visit[i][j] = 0x7fffffff;
		}
	}

	// 여기서부터 작성
	Que s = (Que) { 0, 0, a[0][0] };
	visit[0][0] = s.sum;
	push(s);
	sol = BFS();

	// 출력하는 부분
	printf("%d", sol);

	return 0;
}

#endif
