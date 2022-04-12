#include <stdio.h>

char a[100][100];

int main(void)
{
	int n;
	int i,j;
	char c = 'A';

	scanf("%d", &n);
	for (i=n-1;i>=0;i--) {
		for (j=n-1;j>=0;j--) {
			if (c > 'Z') c = 'A';
			a[j][i] = c++;
		}
	}
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}