#include <stdio.h>

int main(void)
{
	double num[5];
	int i,j;
	double min, max;
	double temp;
	int maxi = 0, mini = 0;

	for (i=0;i<5;i++) {
		scanf("%lf", &num[i]);
	}
	for (i=4;i>0;i--) {
		for (j=0;j<i;j++) {
			if (num[j] > num[j+1]) {
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	min = 2147483647; max = -2147483647;
	//min = abs(3.5-a[0]); max = abs(3.5-a[0]); 로 넣어주기
	for (i=0;i<5;i++) {
		temp = num[i] > 3.5 ? num[i] - 3.5 : 3.5 - num[i];
		if (temp < min) {
			min = temp;
			mini = i;
		}
		if (temp > max) {
			max = temp;
			maxi = i;
		}
	}	
	printf("%lf %lf", num[mini], num[maxi]);
	return 0;
}