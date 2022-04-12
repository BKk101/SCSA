#include <stdio.h>

double a[10000];
int N;

int main(void)
{
	int i,j,k;
	double temp;
	double max = -1;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%lf", &a[i]); 
	}
	for (i=0;i<N;i++) {
		temp = 1;
		for (j=i;j<N;j++) {
			temp *= a[j];
			if (temp > max)
				max = temp;
		}
	}
	printf("%.3f", max);
	return 0;
}

double solve(void)
{
    double maxv = 0, mul = 1;
    int i;
    for (i = 0; i < N; i++) //시작 요소 번호
    {
        if (mul > 1) mul *= a[i];//누적 곱이 1보다 크면 누적하는게 의미 있음
        else mul = a[i];//새로 시작하는게 좋음
        if (maxv < mul) maxv = mul;
    }
    return maxv;
}