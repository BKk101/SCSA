#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int score[4][6][3];
int chk[20];
int flag;

int Check()
{

}

void DFS(int c, int n)
{
	int i;

	if (n == 16) {
		if (Check()){}
		return;
	}
	for (i = 0; i < 2; i++) {
		chk[n] = i;
	}
}

int main(void)
{
	int i,j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 18; j++) {
			scanf("%d", &score[i][j / 3][j % 3]);
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 6; j++) {
			flag = 0;
			DFS(i, j, j+1);
			if (flag == 0) {
				printf("0 ");
				break;
			}
		}
		if (j == 6) printf("1 ");
	}
	return 0;
}

#if 0

if (n == 6) {
	if (chk[c][p][0] == score[c][p][0] && chk[c][p][1] == score[c][p][1] && chk[c][p][2] == score[c][p][2]) flag = 1;
	return;
}
if (chk[c][p][0] > score[c][p][0] || chk[c][p][1] > score[c][p][1] || chk[c][p][2] > score[c][p][2]) return;
for (i = 0; i < 3; i++) {
	if (i == 0) { chk[c][p][0]++; chk[c][n][2]++; }
	else if (i == 1) { chk[c][p][1]++; chk[c][n][1]++; }
	else if (i == 2) { chk[c][p][2]++; chk[c][n][0]++; }
	DFS(c, p, n + 1);
}
}

#endif