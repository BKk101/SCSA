#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int score[4][6][3];
int cmp[4][6][3];
int chk[20];
int flag;
int ans[4];

int Check(int c)
{
	int i,j,t,k;

	for (i=0;i<6;i++) {
		for (j=0;j<3;j++) cmp[c][i][j] = 0;
	}
	for (k=i=0;i<6;i++) {
		for (j=5-i;j>0;j--) {
			t = chk[k++];
			cmp[c][i][t]++;
			cmp[c][6-j][2-t]++;
		}
		if (cmp[c][i][0] != score[c][i][0] || cmp[c][i][1] != score[c][i][0] 
|| cmp[c][i][2] != score[c][i][2]) return 0;
	}
	return 1;
}

void DFS(int n)
{
	int i;

	if (flag == 4) return;
	if (n == 16) {
		for (i=0;i<4;i++) {
			if (ans[i] == 1) continue;
			if (ans[i] = Check(i))flag++;
		}
		return;
	}
	for (i = 0; i < 2; i++) {
		chk[n] = i;
		DFS(n+1);
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
	DFS(0);
	for (i=0;i<4;i++) printf("%d ", ans[i]);
	return 0;
}