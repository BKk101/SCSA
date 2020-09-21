#include <stdio.h>

int player[200][4];
int num[100];

int main(void)
{
	int n;
	int i,j;

	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%d%d%d", &player[i][0], &player[i][1], &player[i][2]);
	}
	for (i=0;i<3;i++) {
		for (j=0;j<100;j++) num[j] = 0;
		for (j=0;j<n;j++) {
			num[player[j][i]-1]++;
		}
		for (j=0;j<n;j++) {
			if (num[player[j][i]-1] == 1) player[j][3] += player[j][i];
		}
	}
	for (i=0;i<n;i++) printf("%d\n", player[i][3]);
	return 0;
}