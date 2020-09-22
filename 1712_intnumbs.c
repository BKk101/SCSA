#include <stdio.h>

int a[1000];

int main(void)
{
	int N;
	int i,j;
	int temp;
	int cnt=0;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &a[i]);
	}
	for (i=0;i<N;i++) {
		if (a[i] == 0) continue;
		for (j=0;j<N;j++) {
			if (j == i) continue;
			if (a[j] == a[i]) a[j] = 0;
		}
		a[i] = 0;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}