#include <stdio.h>

int N;
int candi[4][4];
int max,mp;
int maxi;
int ans;

int cmp(int a, int b)
{
	int t;

	if (candi[a][3] < candi[b][3]) t = b;
	else if (candi[a][3] > candi[b][3]) t = a;
	else if (candi[a][3] == candi[b][3]) {
		if (candi[a][2] < candi[b][2]) t = b;
		else if (candi[a][2] > candi[b][2]) t = a;
		else if (candi[a][2] == candi[b][2]) t = 0;
	}
	return t;
}

int main(void)
{
	int i;
	int a,b,c;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d%d", &a,&b,&c);
		candi[1][a]++; candi[2][b]++; candi[3][c]++;
	}
	mp = max = 0;
	for (i=1;i<=3;i++) {
		candi[i][0] = candi[i][1] + 2*candi[i][2] + 3*candi[i][3];
		if (candi[i][0] > max) {
			max = candi[i][0];
			maxi = i;
		}
		else if (candi[i][0] == max) {
			if (maxi == 0) maxi = cmp(a,i);
			else maxi = cmp(maxi,i);
			a = i;
		}
	}
	printf("%d %d", maxi,max);
	return 0;
}