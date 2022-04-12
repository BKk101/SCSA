#include <stdio.h>

int number[50001];
int Tcase[10001];

int Bsearch(int s, int e, int d)
{
	int mid;

	while (s<=e) {
		mid = (s+e)/2;
		if (number[mid] == d) return mid+1;
		else if (number[mid] > d) e = mid -1;
		else if (number[mid] < d) s = mid +1;
	} 
	return 0;
}

int main(void)
{
	int N,T;
	int i;
	int ans;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &number[i]);
	scanf("%d", &T);
	for (i=0;i<T;i++) scanf("%d", &Tcase[i]); 
	for (i=0;i<T;i++) {
		ans = Bsearch(0,N,Tcase[i]);
		printf("%d\n", ans);
	}
	return 0;
}