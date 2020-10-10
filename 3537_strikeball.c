#include <stdio.h>

typedef struct cnt
{
	int strk,ball;
}Cnt;

int N;
int cnt;
int input[5][3];

Cnt Check(int tar, int src)
{
	int i,t;
	int chk[10] = {0,};
	int chk2[5] = {0,};
	int bp = 0;
	Cnt cnt = {0,0};

	t = 10*tar;
	while ((t/=10) > 0) chk[t%10]++;
	for (i=0;i<5;i++) {
		if (tar%10 == src%10) {
			cnt.strk++;
			chk[tar%10]--;
		}
		else chk2[bp++] = src%10;
		tar /= 10;
		src /= 10;
	}
	for (i=0;i<bp;i++) {
		if (chk[chk2[i]]>0) {
			cnt.ball++;
			chk[chk2[i]]--;
		}
	}
	return cnt;
}

int main(void)
{
	int i,j;
	Cnt chk;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d%d", &input[i][0], &input[i][1], &input[i][2]);
	}
	for (i=10000;i<=99999;i++) {
		for (j=0;j<N;j++) {
			chk = Check(input[j][0],i);
			if (chk.strk != input[j][1] || chk.ball != input[j][2]) break;
		}
		if (j == N) cnt++;
	}
	printf("%d", cnt);
	return 0;
}