#include <stdio.h>

int Sqrt(int n)
{
	int i=1;
	while (i*i<=n)
		i++;
	return i-1;
}

int main(void)
{
	int R;
	int i;
	int sum = 0;

	scanf("%d", &R);
	for (i=1;i<R;i++) {
		sum += Sqrt(R*R-i*i);
	}
	printf("%d", 4*sum);
	return 0;
}