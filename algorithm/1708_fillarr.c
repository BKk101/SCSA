#include <stdio.h>

int map[100][100];

int main(void)
{
	int n;
	int i,j,k;
	int m = 1;

	scanf("%d",&n);
	k = 1;
	for (i=0;i<n;i++) {
		if (k == 1) {
			for (j=0;j<n;j++) {
				map[i][j] = m++;
			}
		}
		else if (k == -1) {
			for (j=n-1;j>=0;j--) {
				map[i][j] = m++;
			}
		}
		k *= -1;
	}
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}