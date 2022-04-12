#include <stdio.h>

int time[105];


int calc(int t)
{
	int sum;

	if (t < 10) return 0;
	if (t >= 10 && t <= 30) return 500;
	else 
		sum = 500 + 300*((t-31)/10 + 1);
	if (sum > 50000)
		sum = 50000;
	return sum;
}

int main(void)
{
	int n;
	int sum=0;
	int i;

	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%d", &time[i]);
		//printf("%d %d\n", time[i], calc(time[i]));
		sum += calc(time[i]);
	}
	printf("%d", sum);
	return 0;
}