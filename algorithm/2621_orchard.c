#include <stdio.h>

int map[11][11];
int N;
int ans;

int check(int y, int x)
{
	int i,j;
	int z1,z2,z3,z4;

	z1 = z2 = z3 = z4 = 0;
	for (i=0;i<y;i++) {
		for (j=0;j<x;j++) {
			if (map[i][j] == 1) z1++;
		}
	}
	for (i=0;i<y;i++) {
		for (j=x;j<N;j++) {
			if (map[i][j] == 1) z2++;
		}
	}
	for (i=y;i<N;i++) {
		for (j=0;j<x;j++) {
			if (map[i][j] == 1) z3++;
		}
	}
	for (i=y;i<N;i++) {
		for (j=x;j<N;j++) {
			if (map[i][j] == 1) z4++;
		}
	}
	if (z1 == z2 && z1 == z3 && z1 == z4) return 1;
	else return 0;
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (i=1;i<N;i++) {
		for (j=1;j<N;j++) {
			if (check(i,j)) ans++;
		}
	}
	if (ans == 0) ans = -1;
	printf("%d", ans);
	return 0;
}