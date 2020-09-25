#include <stdio.h>

int num[100001];

int main(void)
{
	int N;
	int i;
	int inc,dec;
	int max;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &num[i]);
	}
	dec = inc = 1;
	max = 0;
	for (i=0;i<N-1;i++) {
		if (num[i+1] >= num[i]) {
			inc++;
			if (inc > max) {
				max = inc;
			}
		}
		else inc = 1;

		if (num[i+1] <= num[i]) {
			dec++;
			if (dec > max) {
				max = dec;
			}
		}
		else dec = 1;
	}
	printf("%d", max);
	return 0;
}