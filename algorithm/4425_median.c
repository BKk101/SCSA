#if 0

#include <stdio.h>
#define MAX 20000 + 10
int N;
int maxlastnode;
int minlastnode;
int maxheap[MAX/2];
int minheap[MAX/2];
int sol[MAX / 2];
int cnt;

int asc(int a, int b)
{
	return a <= b;
}

int desc(int a, int b)
{
	return a >= b;
}

int push(int *heap, int *lastnode, int (*f)(int,int), int q)
{
	int n, p;

	if (*lastnode == MAX - 1) return 0;
	heap[++(*lastnode)] = q;
	n = *lastnode; //child
	p = n / 2; //parent
	while (p > 0) {
		if (!f(heap[p], heap[n])) {
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

int pop(int *heap, int *lastnode, int(*f)(int, int), int *p)
{
	int n, lc, rc, c;

	if (*lastnode == 0) return 0;
	*p = heap[1];
	heap[1] = heap[(*lastnode)--];

	n = 1; lc = 2; rc = 3;
	while (lc <= *lastnode) {
		if (lc == *lastnode) c = lc;
		else c = f(heap[lc], heap[rc]) ? lc : rc;

		if (!f(heap[n], heap[c])) {
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
	int i, a;

	scanf("%d", &N);
	scanf("%d", &a);


	push(maxheap, &maxlastnode, desc, a);
	sol[cnt++] = a;
	for (i = 0; i < N-1; i++) {
		scanf("%d", &a);
		if (a <= maxheap[1]) {
			push(maxheap, &maxlastnode, desc, a);
			if (maxlastnode - minlastnode > 1) {
				pop(maxheap, &maxlastnode, desc, &a);
				push(minheap, &minlastnode, asc, a);
			}
		}
		else {
			push(minheap, &minlastnode, asc, a);
			if (maxlastnode != minlastnode) {
				pop(minheap, &minlastnode, asc, &a);
				push(maxheap, &maxlastnode, desc, a);
			}
		}
		if (i % 2) sol[cnt++] = maxheap[1];
	}

	for (i = 0; i < cnt; i++) printf("%d\n", sol[i]);
	return 0;
}

#endif
