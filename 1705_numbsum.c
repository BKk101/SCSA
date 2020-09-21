#include <stdio.h>

int main(void)
{
	int N;
	int sum[4] = {0};
	int i;
	int temp;
	int len;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &temp);
		sum[0] = temp;
		len = 1;
		while ((temp /=10) > 0) len++;
		sum[len] += sum[0];
	}
	printf("%d %d %d", sum[3], sum[2], sum[1]);
}