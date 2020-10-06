#include <stdio.h>

int N;
int cow[20];
int copy[20];
int chk[20];
int max;

int check(int n)
{
	int i;
	int sum;
	int t;

	for (sum=i=0;i<n;i++) {
		if (chk[i] == 1) sum += cow[i];
		copy[i] = cow[i];
	}
	while (sum > 0) {
		t = 0;
		for (i=0;i<n;i++) {
			if (chk[i] == 1) t += copy[i]%10;
			copy[i] /= 10;
		}
		if (t != sum%10) return 1;
		sum /= 10;
	}
	return 0;
}

void DFS(int n)
{
	int i;
	int left;

	if (check(n) == 1) return ;
	for (left=i=0;i<n;i++) {
		if(chk[i] == 1) left++;
	}
	if (left > max) max = left;
	if (n == N) return ;
	for (i=1;i>=0;i--) {
		chk[n] = i;
		DFS(n+1);
		chk[n] = 0;
	}
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i=0;i<N;i++) scanf("%d", &cow[i]);
	DFS(0);
	printf("%d", max);
	return 0;
}