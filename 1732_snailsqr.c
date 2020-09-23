#include <stdio.h>

int arr[100][100];

int main(void)
{
	int n;
	int i,j,k;
	int num = 1;
	int cnt;

	scanf("%d", &n);
	for (i=0,j=0,cnt=n-1;cnt>=1;cnt-=2) {
		for (k=0;k<cnt;k++) {
			arr[i][j++] = num++;
		}
		for (k=0;k<cnt;k++) {
			arr[i++][j] = num++;
		}
		for (k=0;k<cnt;k++) {
			arr[i][j--] = num++;
		}
		for (k=0;k<cnt;k++) {
			arr[i--][j] = num++;
		}
		++i;
		++j;
	}
	if (n%2 == 1) arr[i][j] = num;
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}