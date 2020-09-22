#include <stdio.h>

int main(void)
{
	int N;
	int i;
	int ans;

	scanf("%d",&N);
	i = N/14;
	if (i == 0) ans = 14;
	else 
		ans = (N - 14*i) <= (14*(i+1) - N) ? 14*i : 14*(i+1);
	printf("%d", ans);
	return 0;
}