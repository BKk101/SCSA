#include <stdio.h>

int bud[10001];
int M;
int N;

void Sort(void)
{
	int i,j;
	int t;

	for (i=N-1;i>0;i--) {
		for (j=0;j<i;j++) {
			if (bud[j] > bud[j+1]) {
				t =bud[j];
				bud[j] = bud[j+1];
				bud[j+1] = t;
			}
		}
	}
}
int check(int max)
{
	int i;
	int sum;

	sum = 0;
	for(i=0;i<N;i++) 
	{
		if (bud[i] <= max) sum += bud[i];
		else sum += max;
	}
	if (sum > M) return 1;
	else if (sum == M) return 0;
	else if (sum < M) return -1;
}

int Bsearch(int s, int e)
{
	int mid;
	int sol;

	s = bud[s];
	e = bud[e];
	sol = 0;
	while (s<=e) {
		mid = (s+e)/2;
		if (check(mid) == 0) return mid;
		else if (check(mid) == 1) e = mid -1;
		else if (check(mid) == -1) {
			sol = mid;
			s = mid +1;
		}
	} 
	return sol;
}

int main(void)
{
	int i;
	int sum;

	sum = 0;
	scanf("%d", &N);
	for (i=0;i<N;i++)
	{
		scanf("%d", &bud[i]);
		sum += bud[i];
	}
	scanf("%d", &M);
	Sort();
	if (sum <= M) printf("%d", bud[N-1]);
	else
		printf("%d", Bsearch(0, N-1));
	return 0;
}