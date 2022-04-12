#include <stdio.h>

int main(void)
{
	int N;
	int i,j;
	int cnt=0;

	scanf("%d", &N);
	for (i=0;i<=N;i++) {
		for (j=i;j<=N;j++) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}