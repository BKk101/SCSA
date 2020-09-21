#include <stdio.h>

int R[100];

int main(void)
{
	int N,P;
	int temp;
	int cnt = 0;

	scanf("%d%d", &N, &P);
	temp = (N*N)%P;
	while (R[temp] == 0) {
		R[temp]++;
		cnt++;
		temp = (temp * N) % P;
	}
	printf("%d", cnt);
	return 0;
}