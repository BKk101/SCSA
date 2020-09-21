#include <stdio.h>

int main(void)
{
	int N;
	int Sum;
	int i;
	int ans = 0;
	int t = 0;

	scanf("%d%d", &N, &Sum);
	for (i=1;i<=N;i++) {
		t += i;
	}
	for (i=1;i<N;i++) {
		if ((2*i+1) == (t-Sum)) {
			ans = i;
			break;
		}
	}
	if ((ans == 0) || (ans%2 == 0)) printf("Error");
	else printf("%d %d", i,i+1);
}