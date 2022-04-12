#if 0

#include <stdio.h>
#define ABS(x) ((x)>0 ? (x) :-(x))

int N;
int a[100000 + 10];
int sol1, sol2;

int main(void)
{
	int i;
	int zero = -1;

	// 입력받는 부분
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	/*
	for (i = 0; i < N-1; i++) {
		if (a[i] * a[i + 1] < 0) zero = i + 1;
	}

	if (zero == -1 && a[0] > 0) {
		printf("%d %d", a[0], a[1]);
		return 0;
	}
	if (zero == -1 && a[0] < 0) {
		printf("%d %d", a[N-2], a[N-1]);
		return 0;
	}
	*/
	int mid, high, low, nuet, min, temp;
	
	min = 0x7fffffff;
	low = 0; high = N - 1;
	while (low<high) {
		//mid = (low + high)/2;
		nuet = a[low] + a[high];
		if (ABS(nuet) < min) {
			min = ABS(nuet);
			sol1 = a[low]; sol2 = a[high];
			if (nuet == 0) break;
		}
		if (nuet > 0) {
			high--;//high = (zero + high) / 2 -1;
		}
		else {
			low++;//low = (low + zero - 1) / 2 +1;
		}
	}

	// 출력하는 부분
	printf("%d %d", sol1, sol2);

	return 0;
}

#endif