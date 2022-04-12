#if 0

//type: int, priority: minheap

#include <stdio.h>
#define MAX_DATA 10
#define MAX_HEAP (MAX_DATA + 1)

int heap[MAX_HEAP];
int lastnode = 0;

int push(int d)
{
	int n, p;
	if (lastnode == MAX_DATA) return 0;
	heap[++lastnode] = d;

	n = lastnode; //child
	p = n / 2; //parent
	while (p>0) {
		if (heap[p] > heap[n]) {
			int temp;
			temp = heap[p];
			heap[p] = heap[n];
			heap[n] = temp;

			n = p;
			p = n / 2;
		}
		else break;
	}
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
			int temp;
			temp = heap[n];
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
	int i;
	int d;
	int a[] = { 1,5,3,4,6,3 };

	for (i = 0; i < 6; i++) {
		push(a[i]);
	}
	while (pop(&d)) {
		printf("%d\n", d);
	}
	return 0;
}


#endif
