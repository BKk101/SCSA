#include <stdio.h>

double a[10000];

int main(void)
{
	int N;
	int i,j,k;
	double temp;
	double max = -1;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%lf", &a[i]); 
	}
	for (i=0;i<N-1;i++) {
		temp = 1;
		for (j=1;j<N-i;j++) {
			temp *= a[i+(j-1)];
			if (temp > max) {
				max = temp;
			}
		}
	}
	printf("%.3f", max);
	return 0;
}