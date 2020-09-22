#include <stdio.h>

int main(void)
{
	int N;
	int a,b;
	int i;
	
	scanf("%d", &N);
	a = 2;
	for (i=0;i<N;i++) {
		b = a + a-1;
		a = b;
	}
	printf("%d", b*b);
	return 0;
}