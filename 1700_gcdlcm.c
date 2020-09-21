#include <stdio.h>
 
int main(void)
{
    int a,b;
	int big,small;
	int i;
	int gcd,lcm;

	scanf("%d%d", &a,&b);
	small = a > b ? b : a;
	for (i=1;i<=small;i++) {
		if (a%i == 0 && b%i == 0) gcd = i;
	}
	lcm = (a*b)/gcd;
	printf("%d\n%d\n", gcd, lcm);
    return 0;
}