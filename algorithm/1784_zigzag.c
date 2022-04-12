#include <stdio.h>

int arr[100][100];

int main(void)
{
	int n;
	int i,j;
	int num;
	int flag = 0;

	scanf("%d", &n);
	for (i=0,j=0,num=1;num<=n*n;num++) {
		arr[i][j] = num;
		if ((j == 0 || i == n-1) && flag == 0) {
			if (i<n-1) i++;
			else j++;
			flag = 1;
		}
		else if ((i == 0 || j == n-1) && flag == 1) {
			if (j<n-1) j++;
			else i++;
			flag = 0;
		}
		else if (flag == 1) {
			i--;
			j++;
		}
		else if (flag == 0) {
			i++;
			j--;
		}
	}
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}