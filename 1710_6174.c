#include <stdio.h>


int Max(int * num)
{
	int i,j;
	int max;
	int idx;
	int a[4];
	int ans = 0;

	for (i=0;i<4;i++) a[i] = num[i];
	for (j=0;j<4;j++) {
		max = 0;
		for (i=0;i<4;i++) {
			if (a[i] > max) {
				max = a[i];
				idx = i;
			}
		}
		ans += max;
		ans *= 10;
		a[idx] = -1;
	}
	return ans/10;
}

int Min(int * num)
{
	int i,j;
	int min;
	int idx;
	int a[4];
	int ans = 0;

	for (i=0;i<4;i++) a[i] = num[i];
	for (j=0;j<4;j++) {
		min = 9;
		for (i=0;i<4;i++) {
			if (a[i] < min) {
				min = a[i];
				idx = i;
			}
		}
		ans += min;
		ans *= 10;
		a[idx] = 10;
	}
	return ans/10;
}

int main(void)
{
	int num[4];
	int i;
	int temp;
	int cnt = 1;

	for (i=0;i<4;i++) {
		scanf("%1d", &num[i]);
	}
	temp = Max(num) - Min(num);
	while (temp != 6174) {
		cnt++;
		for (i=3;i>=0;i--) {
			num[i] = temp % 10;
			temp /= 10; 
		} 
		temp = Max(num) - Min(num);
	}
	printf("%d\n", cnt);
	return 0;
}