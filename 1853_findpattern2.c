#include <stdio.h>

char map[100][100];
char p[100][100];
char temp[100][100];
char temp2[100][100];

void rotate(int psize)
{
	int i,j;
	
	for (i=0;i<psize;i++) {
		for (j=0;j<psize;j++) {
			temp[i][j] = temp2[psize-j-1][i];
		}
	}
	for (i=0;i<psize;i++) {
		for (j=0;j<psize;j++) {
			temp2[i][j] = temp[i][j];
		}
	}
}

int check_pattern(int y, int x, int psize)
{
	int i,j;
	
	for (i=0;i<psize;i++) {
		for (j=0;j<psize;j++) {
			if (map[y+i][x+j] != temp[i][j]) return 0;
		}
	}
	return 1;
}

int main(void)
{
    int msize,psize;
	int i,j,k;
	int ans = 0;

	scanf("%d", &msize);
	for (i=0;i<msize;i++) {
		for (j=0;j<msize;j++) {
			scanf(" %c", &map[i][j]); //scanf("%1d", &n); 으로하면 연속된 숫자도 1자리씩 입력받아줌
		}
	}
	scanf("%d", &psize);
	for (i=0;i<psize;i++) {
		for (j=0;j<psize;j++) {
			scanf(" %c", &p[i][j]);
		}
	}


	for (i=0;i<psize;i++) {
		for (j=0;j<psize;j++) {
			temp2[i][j] = p[i][j];
		}
	}

	for (i=0;i<=msize-psize;i++) {
		for (j=0;j<=msize-psize;j++) {
			for (k=0;k<4;k++) {
				rotate(psize);
				if (check_pattern(i,j,psize) == 1) ans++;
			}
		}
	}
	printf("%d", ans);
    return 0;
}