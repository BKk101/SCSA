#include <stdio.h>

int num[1001];

int main(void)
{
	int K, N;
	int cnt = 0;
	int i;
	int m;

	scanf("%d%d", &N, &K);
	for (i=0;i<=1000;i++) num[i] = 1;
	while (cnt != K) {
		for (i=2;i<=N;i++) {
			if (num[i] == 1) {
				m=i;
				break;
			}
		}
		for (i=1;m*i<=N;i++) { 
			if (cnt == K) break;
			if (num[m*i] == 1) {
				num[m*i] = 0;
				cnt++;
			}
		}
	}
	printf("%d", m*(i-1));
	return 0;
}