#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int score[4][6][3];
int cmp[6][3];
int chk[20];
int ans[4];
int draw[4];
int win[4];
int d,w;

int Check(int c)
{
	int i,j,t,k;

	for (i=0;i<6;i++) {
		for (j=0;j<3;j++) cmp[i][j] = 0;
	}
	for (k=i=0;i<6;i++) {
		for (j=5-i;j>0;j--) {
			t = chk[k++];
			cmp[i][t]++;
			cmp[6-j][2-t]++;
		}
		if (cmp[i][0] != score[c][i][0] || cmp[i][1] != score[c][i][1] || cmp[i][2] != score[c][i][2]) return 0;
	}
	return 1;
}

void DFS(int n, int c)
{
	int i;

	if (d>draw[c] || w>win[c]) return;
	if (n == 15) {
		if (Check(c)) ans[c] = 1;
		return;
	}
	for (i = 0; i < 3; i++) {
		chk[n] = i;
		if (i == 0) w++;
		else if (i == 1) d+=2;
		DFS(n+1,c);
		if (i == 0) w--;
		else if (i == 1) d-=2;
		if (ans[c] == 1) return;
	}
}

int main(void)
{
	int i,j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 18; j++) {
			scanf("%d", &score[i][j / 3][j % 3]);
			if (j%3 == 0) win[i] += score[i][j/3][j%3];
			else if (j%3 == 1) draw[i] += score[i][j/3][j%3];
		}
	}
	for (i=0;i<4;i++) {
		//w = d = 0;
		DFS(0,i);
		printf("%d ", ans[i]);
	}
	return 0;
}