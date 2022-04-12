#include <stdio.h>

char num[10][8]={"1111110","0011000","0110111","0111101","1011001","1101101","1101111","0111000","1111111","1111101"};
char input[12][8];
int A[3][11];
int B[3][11];
int C[6][11];
int CC[550000];
int AA[1005];
int BB[1005];
int ap,bp,cp;

int cmp(int n, char * str)
{
	int i;
	for (i=0;i<7;i++) {
		if (num[n][i] == '0' && str[i] == '1') return 0;
	}
	return 1;
}

void Init(void)
{
	int i,j;
	for (j=0;j<3;j++) {
		for (i=0;i<11;i++) C[j+3][i] = C[j][i] = A[j][i] = B[j][i] = -1;
	}
	for (i=0;i<3;i++) {
		for (j=0;j<10;j++) {
			if (cmp(j,input[i])) A[i][j] = j;
			if (cmp(j,input[i+3])) B[i][j] = j;
			if (cmp(j,input[i+6])) C[i][j] = j;
			if (cmp(j,input[i+9])) C[i+3][j] = j;
		}
	}
}

void DFS(int n, int sum)
{
	int i;
	if (n == 3) {
		AA[ap++] = sum/10;
		return ;
	}
	for (i=0;i<10;i++) {
		if (A[n][i] == -1) continue;
		DFS(n+1, (sum+A[n][i])*10);
	}
}

void DFS2(int n, int sum)
{
	int i;
	if (n == 3) {
		BB[bp++] = sum/10;
		return ;
	}
	for (i=0;i<10;i++) {
		if (B[n][i] == -1) continue;
		DFS2(n+1, (sum+B[n][i])*10);
	}
}

void DFS3(int n, int sum)
{
	int i;
	if (n == 6) {
		CC[cp++] = sum/10;
		return ;
	}
	for (i=0;i<10;i++) {
		if (C[n][i] == -1) continue;
		DFS3(n+1, (sum+C[n][i])*10);
	}
}

int main(void)
{
	int i,j,k,t;
	
	for (i=0;i<12;i++) scanf("%s", input[i]);
	Init();
	DFS(0,0);
	DFS2(0,0);
	DFS3(0,0);

	for (i=0;i<cp;i++) {
		for (j=0;j<bp;j++) {
			if (BB[j] > CC[i] || BB[j] == 0) continue;
			for (k=0;k<ap;k++) {
				if ((double)CC[i]/BB[j] == (double)AA[k]) {t = i; goto EXIT;}
			}
		}
	}
EXIT:
	printf("%d", CC[t]);
	return 0;
}