#if 0

#include <stdio.h>
#define DIV 20100529

int N;
int D[100000 + 5];
int main(void)
{
	scanf("%d", &N);
	D[0] = D[1] = 1;
	for (int i = 2; i <= N; i++) {
		D[i] = (D[i - 1] + 2 * D[i - 2]) % DIV;
	}
	printf("%d", D[N]);
	return 0;
}

#endif
