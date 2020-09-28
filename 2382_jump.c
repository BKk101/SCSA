#include <stdio.h>

int pos[1001];
int N;

void Sort(int * arr)
{
	int i,j;
	int t;

	for (i=N-1;i>0;i--) {
		for (j=0;j<i;j++) {
			if (arr[j] > arr[j+1]) {
				t =arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}
}

int bsearch_low(int s, int e, int dis)
{
	int mid;
	int dis2;
	int sol;
	int st;

	sol = 0;
	st = pos[s-1];
	while (s<=e) {
		mid = (s+e)/2;
		dis2 = pos[mid] - st;
		if (dis2 <= dis*2 && dis2 >= dis) {
			sol = mid;
			e = mid -1;
		}
		else if (dis2 < dis) s = mid +1;
		else if (dis2 > dis*2) e = mid -1;
	}
	return sol;
}

int bsearch_high(int s, int e, int dis)
{
	int mid;
	int dis2;
	int sol;
	int st;

	sol = 0;
	st = pos[s-1];
	while (s<=e) {
		mid = (s+e)/2;
		dis2 = pos[mid] - st;
		if (dis2 <= dis*2 && dis2 >=  dis) {
			sol = mid;
			s = mid +1;
		}
		else if (dis2 < dis) s = mid +1;
		else if (dis2 > dis*2) e = mid -1;
	}
	return sol;
}

int main(void)
{
	int i,j,k;
	int h,l;
	int cnt;
	int dis1, dis2;
	
	cnt = 0;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &pos[i]);
	Sort(pos);
	for (i=0;i<N-2;i++) {
		for (j=i+1;j<N-1;j++) {
			l = bsearch_low(j+1,N-1,pos[j]-pos[i]);
			h = bsearch_high(j+1,N-1,pos[j]-pos[i]);
			if (l != 0 && h != 0) cnt += h-l+1;
		}
	}
	printf("%d", cnt);
	return 0;
}