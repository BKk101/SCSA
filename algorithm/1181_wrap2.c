#if 0

#include <stdio.h>
#define MAX 5000 + 10
int N;
int heap[MAX];
int lastnode = 0;
int sol;


int push(int q)
{
	int n, p;

	if (lastnode == MAX - 1) return 0;
	heap[++lastnode] = q;
	n = lastnode; //child
	p = n / 2; //parent
	while (p > 0) {
		if (heap[p] > heap[n]) {
			int temp = heap[p];
			heap[p] = heap[n];
			heap[n] = temp;
			n = p;
			p = n / 2;
		}
		else break;
	}
	return 1;
}

int pop(int *p)
{
	int n, lc, rc, c;

	if (lastnode == 0) return 0;
	*p = heap[1];
	heap[1] = heap[lastnode--];

	n = 1; lc = 2; rc = 3;
	while (lc <= lastnode) {
		if (lc == lastnode) c = lc;
		else c = heap[lc] < heap[rc] ? lc : rc;

		if (heap[n] > heap[c]) {
			int temp = heap[n];
			heap[n] = heap[c];
			heap[c] = temp;
			n = c; lc = n * 2; rc = lc + 1;
		}
		else break;
	}
	return 1;
}

int main(void)
{
	int i, temp;
	int a, b;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &temp);
		push(temp);
	}
	while (lastnode > 1) {
		pop(&a);
		pop(&b);
		sol += a + b;
		push(a + b);
	}
	printf("%d", sol);

	return 0;
}

#endif
