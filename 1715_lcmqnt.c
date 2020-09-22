#include <stdio.h>

int a[10] = {12, 18, 21, 36, 15, 19, 22, 24, 31, 55};

int main(void)
{
	int N1, N2;
	int small;
	int i;
	int gcd, lcm;
	int cnt = 0;

	scanf("%d%d", &N1, &N2);
	small = N1 > N2 ? N2 : N1;
	for (i=1;i<=small;i++) {
		if (N1%i == 0 && N2%i == 0) gcd = i;
	}
	lcm = (N1*N2)/gcd;
	for (i=0;i<10;i++) 
		if (a[i]%lcm == 0) cnt++;
	printf("%d", cnt);
	return 0;
}