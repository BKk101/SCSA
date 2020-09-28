#include <stdio.h>

int number[200001];
int Tcase[200001];

int Bsearch_low(int s, int e, int d)
{
	int mid;
	int sol = -1;
	while (s<=e) {
		mid = (s+e)/2;
		if (number[mid] == d) {
			sol = mid;
			e = mid -1;
		}
		else if (number[mid] > d) e = mid -1;
		else if (number[mid] < d) s = mid +1;
	} 
	return sol;
}

int Bsearch_up(int s, int e, int d)
{
	int mid;
	int sol = -1;
	while (s<=e) {
		mid = (s+e)/2;
		if (number[mid] == d) {
			sol = mid;
			s = mid +1;
		}
		else if (number[mid] > d) e = mid -1;
		else if (number[mid] < d) s = mid +1;
	} 
	return sol;
}

int main(void)
{
	int N,T;
	int i;
	int low, up;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &number[i]);
	scanf("%d", &T);
	for (i=0;i<T;i++) scanf("%d", &Tcase[i]); 
	for (i=0;i<T;i++) {
		low = Bsearch_low(0,N-1,Tcase[i]);
		if (low != -1) {
		up = Bsearch_up(0,N-1,Tcase[i]);
		printf("%d ", up-low+1);
		}
		else printf("0 ");
	}
	return 0;
}