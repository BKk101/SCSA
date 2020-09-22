#include <stdio.h>

int main(void)
{
	int x;
	int i,j;

	scanf("%x", &x);
	for (i=1;i<16;i++) {
		printf("%X*%X=%X\n", x,i,x*i);
	}
	return 0;
}