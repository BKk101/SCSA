#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000+5

typedef struct que {
	int n, c, r;
}Que;
typedef struct list {
	int n;
	struct list *next;
}t_list;

int N, K;
int cost[MAX];
int road[MAX];
int visit[MAX][MAX];
Que heap[MAX*MAX];
int leaf;
t_list vill[MAX];

void addlist(t_list *head, int n)
{
	while (head->next) head = head->next;
	head->next = calloc(1,sizeof(t_list));
	head->next->n = n;
}

int push(Que q)
{
	int n, p;

	if (leaf == MAX - 1) return 0;
	heap[++leaf] = q;
	n = leaf; //child
	p = n / 2; //parent
	while (p > 0) {
		if (heap[p].c > heap[n].c) {
			Que temp = heap[p];
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

	if (leaf == 0) return 0;
	*p = heap[1];
	heap[1] = heap[leaf--];

	n = 1; lc = 2; rc = 3;
	while (lc <= leaf) {
		if (lc == leaf) c = lc;
		else c = heap[lc].c < heap[rc].c ? lc : rc;

		if (heap[n].c > heap[c].c) {
			Que temp = heap[n];
			heap[n] = heap[c];
			heap[c] = temp;
			n = c; lc = n * 2; rc = lc + 1;
		}
		else break;
	}
	return 1;
}

int BFS(void)
{
	Que temp;
	Que ntemp;
	t_list *cur;

	push((Que) { 1, 0, 0 });
	visit[1][0] = 0;
	while (pop(&temp)) {
		if (temp.n == N) return temp.c;
		cur = vill[temp.n].next;
		while (cur) {
			ntemp.n = cur->n;
			if (temp.r > 0) {
				ntemp.c = temp.c;
				ntemp.r = temp.r - 1;
				if (visit[ntemp.n][ntemp.r] > ntemp.c) {
					push(ntemp);
					visit[ntemp.n][ntemp.r] = ntemp.c;
				}
			}
			ntemp.c = temp.c + cost[temp.n];
			ntemp.r = road[temp.n] - 1;
			if (visit[ntemp.n][ntemp.r] > ntemp.c) {
				push(ntemp);
				visit[ntemp.n][ntemp.r] = ntemp.c;
			}
			cur = cur->next;
		}
	}
	return -1;
}

int main(void)
{
	int i,j;
	int a, b;
	int sol;

	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d%d", &cost[i], &road[i]);
		for (j = 0; j <= N; j++) {
			visit[i][j] = 0x7fffffff;
		}
	}
	for (i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		addlist(&vill[a], b);
		addlist(&vill[b], a);
	}
	sol = BFS();
	printf("%d\n", sol);
	return 0;
}

#endif