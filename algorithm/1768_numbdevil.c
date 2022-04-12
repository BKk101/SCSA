#include <stdio.h>

int main(void)
{
	int K;
	int zero;
	int one;
	int a,b;
	int i;

	scanf("%d", &K);
	for (a=1,b=1,i=4;i<=K;i++) {
		zero = a+b;
		a = b;
		b = zero;
	}
	if (K < 4) zero = 1;
	if (K == 1) zero = 0;

	for (a=1,b=1,i=3;i<=K;i++) {
		one = a+b;
		a = b;
		b = one;
	}
	if (K < 3) one = 1;
	if (K == 0) one = 0;
	printf("%d %d", zero, one);
	return 0;
}