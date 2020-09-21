#include <stdio.h>

int main(void)
{
	int n;
	int a,b,c;
	int i;

	scanf("%d", &n);
	a = 1;
	b = 1;
	for (i=2;i<n;i++) {
		c = a + b;
		a = b;
		b = c;
	}
	if (n < 3) c = 1;
	printf("%d", c);
	return 0;
}