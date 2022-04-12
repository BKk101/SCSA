#include <stdio.h>

int a[9];

int main(void)
{
	int i,j;
	int sum=0;
	int temp;
	int idx1, idx2;

	for (i=0;i<9;i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for (i=8;i>0;i--) {
		for (j=0;j<i;j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	for (i=0;i<8;i++) {
		for (j=i+1;j<9;j++) {
			temp = sum;
			temp -= (a[i]+a[j]);
			if (temp == 100) {
				idx1 = i;
				idx2 = j;
				goto P1;
			}
		}
	}
P1:
	for (i=0;i<9;i++) {
		if (i == idx1 || i == idx2)
			continue;
		else
			printf("%d\n", a[i]);
		
	}
	return 0;
}