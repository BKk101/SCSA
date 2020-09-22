#include <stdio.h>

int a[100];

int check_p(int n)  //reverse num 함수로 다시짜기
{
	int temp = 0;
	int a = n;
	int p;
	int i = 0;

	while (a>0) {
		temp += a%10;
		temp *= 10;
		a/=10;
	}
	temp /= 10;
	p = a = n + temp;
	temp = 0;
	while (a>0) {
		temp += a%10;
		temp *= 10;
		a/=10;
	}
	temp /= 10;
	if (p == temp)
		return 1;
	else
		return 0;
}

int main(void)
{
	int N;
	int i;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &a[i]);
	}
	for (i=0;i<N;i++) {
		if (check_p(a[i])) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}