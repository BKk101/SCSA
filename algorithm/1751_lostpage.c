#include <stdio.h>

int main(void)
{
	int N;
	int P;
	int ans[3];

	scanf("%d%d", &N, &P);
	if (P%2 == 0) {
		ans[0] = P-1;
		ans[1] = N-(P-1);
		ans[2] = N-(P-1)+1;
	}
	else {
		ans[0] = P+1;
		ans[1] = N-(P-1)-1;
		ans[2] = N-(P-1);
	}
	if (P > N/2)
		printf("%d %d %d", ans[1],ans[2],ans[0]);
	else
		printf("%d %d %d", ans[0],ans[1],ans[2]);	
	return 0;
}