#include <stdio.h>

int sum[10005];

int sum_divisor(int n)
{
	int sum = 0;
	int i;
	//진약수 구할때 <n 말고 <=n/2까지 하면됨
	for (i=1;i<=n/2;i++) {
		if (n%i == 0) sum += i;
	}
	return sum;
}


int main(void)
{
	int s,e;
	int i;
	int cnt = 0;

	scanf("%d%d", &s,&e);
	for (i=s;i<=e;i++) {
		sum[i] = sum_divisor(i);
	}
	for (i=s;i<=e;i++) {
		//if (sum[i] > 10000) break; 이 방법이 나을듯
		if (sum[i] == i)
			cnt++;
		else if (sum[i] <= 10000 && sum[sum[i]] == i)
			cnt++;
	}
	printf("%d\n", cnt);
	for (i=s;i<=e;i++) {
		if (sum[i] == i)
			printf("%d\n", i);
		else if (sum[i] <= 10000 &&  sum[sum[i]] == i)
			printf("%d %d\n", i, sum[i]);
	}
	return 0;
}