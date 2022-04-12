#include <stdio.h>

int sum[36];

int main(void)
{
	int N;
	int i,j;
	int k = 0;
	int cnt = 0;

	scanf("%d", &N);
	for (i=1;i<=6;i++) {
		for (j=1;j<=6;j++) {
			sum[k++] = i+j;
		}
	}
	for (i=0;i<36;i++) {
		if (sum[i] == N)
			cnt++;
	}
	printf("%.4f%%", 100 * (cnt/36.0));
	return 0;
}