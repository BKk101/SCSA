#include <stdio.h>

int map[100][100];
int x[3] = {1,-1,0};
int y[3] = {1,0,-1};
int main(void)
{
	int N;
	int i,j;
	int num;
	int cnt;
	int dir;
	int t;

	scanf("%d", &N);
	t = N;
	num = 1;
	for (i=j=cnt=dir=0;N>0;) {
		map[i][j] = num;
		num = (num)%10 + 1;
		cnt++;
		if (cnt == N) {
			dir = (++dir)%3;
			cnt = 0;
			N--;
		}
		i += y[dir];
		j += x[dir];
	}
	for (i=0;i<t;i++) {
		for (j=0;j<t;j++) {
			if (map[i][j] != 0)
				printf("%d ", map[i][j]-1);
		}
		printf("\n");
	}
	return 0;
}