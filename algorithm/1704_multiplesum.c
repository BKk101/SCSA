#include <stdio.h>

int main(void)
{
	int N;
	int i = 1;
	int sum = 0;
	
	scanf("%d", &N);
	while (sum < 10000) {
		sum += N * (i++);
	}
	i -= 2;
	printf("%d", i * N);
}