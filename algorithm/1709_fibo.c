#include <stdio.h>
int num[50]; //속도개선 버전 brancing?

int fibo(int n)
{
	if (n == 1 || n == 2) return 1;
	if (num[n] != 0) return num[n];
	return num[n] = fibo(n-2) + fibo(n-1); 
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}