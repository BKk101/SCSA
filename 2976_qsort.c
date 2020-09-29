#include <stdio.h>
#define SWAP(a,b) {int t; t = (a); (a) = (b); (b) = t;}

int arr[30001];

void quick_sort(int s, int e, int * a)
{
	int T,P=e;
	int l;

	if (e <= s) return ;
	for (l=T=s;l<e;l++) {
		if (a[l]<a[P]) {
			SWAP(a[l],a[T]);
			T++;
		}
	}
	if (P != T) SWAP(a[P], a[T]);
	quick_sort(s,T-1,a);
	quick_sort(T+1,e,a); 
}

int main(void)
{
	int N;
	int i;

	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", arr+i);
	quick_sort(0,N-1,arr);
	for (i=0;i<N;i++) printf("%d ", arr[i]);
	return 0;
}