#include <stdio.h>

int arr[100][100];

int main(void)
{
	int n;
	int i,j;
	int num;

	scanf("%d", &n);
	for (i=0,j=n/2,num=1;num<=n*n;num++) {
		arr[i][j] = num;
		if (num%n == 0) ++i;
		else {
			--i;
			--j;
		}
		if (j<0) j=n-1;
		if (i<0) i=n-1;
	}
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}