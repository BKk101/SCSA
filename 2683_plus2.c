#include <stdio.h>

int N,K;
int num[13];
int chk[13];
int sum[5000];
int sp;

void quick_sort(int s, int e, int * a)
{
	int i,t;
	int T,P=e;

	if (s>=e) return ;
	for (T=i=s;i<e;i++) {
		if (a[i]>a[P]) {
			t = a[i];
			a[i] = a[T];
			a[T] = t;
			T++;
		}
	}
	if (P != T) {
		t = a[P];
		a[P] = a[T];
		a[T] = t;
	}
	quick_sort(s,T-1,a);
	quick_sort(T+1,e,a);
}

void DFS(int n)
{
	int i,temp;
	
	if (n == N) {
		for (temp=i=0;i<N;i++) {
			if (chk[i] == 1) temp += num[i];
		}
		sum[sp++] = temp;
		return ;
	}
	chk[n] = 1;
	DFS(n+1);
	chk[n] = 0;
	DFS(n+1);
}

int main(void)
{
	int i,cnt;

	scanf("%d%d", &N, &K);
	for (i=0;i<N;i++) scanf("%d", &num[i]);
	DFS(0);
	quick_sort(0,sp-1,sum);
	cnt = 1;
	for (cnt=i=1;i<sp;i++) {
		if (sum[i] != sum[i-1]) cnt++;
		if (sum[i] == K) break;
	}
	if (sum[0] == K) cnt = 1;
	printf("%d", cnt);
	return 0;
}