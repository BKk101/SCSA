#include <stdio.h>

int main(void)
{
	int T,N,C,M;
	int i;
	int t;
	int r;
	int q;
	int sum;

	scanf("%d", &T);
	for (i=0;i<T;i++) {
		sum = 0;
		scanf("%d%d%d", &N,&C,&M);
		t = N/C;
		sum += t;
		q = t/M;
		r = t%M;
		while (q>0) {
			sum += q;
			t = q+r;
			q = t/M;
			r = t%M;
		}
		printf("%d\n", sum);
	}
	return 0;
}