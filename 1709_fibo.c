#include <stdio.h>

int fibo(int n)
{
	if (n == 1 || n == 2) return 1;
	return fibo(n-2) + fibo(n-1);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}