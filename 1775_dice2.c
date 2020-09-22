#include <stdio.h>

int num[81];

int main(void)
{
	int N1, N2, N3;
	int i,j,k;
	int max;
	int ans;

	scanf("%d%d%d", &N1,&N2,&N3);
	for (i=1;i<=N1;i++) {
		for (j=1;j<=N2;j++) {
			for (k=1;k<=N3;k++) {
				num[i+j+k]++;
			}
		}
	}
	max = 0;
	for (i=0;i<81;i++) {
		if (num[i] > max) {
			max = num[i];
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}