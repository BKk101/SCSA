#include <stdio.h>

char map[100][100];
int	ans[100][100];

int move_cloud(int row, int col)
{
	int i,j;
	int cloud = 0;

	for (i=0;i<row;i++) {
		for (j=col-1;j>0;j--) {
			map[i][j] = map[i][j-1];
			if (map[i][j] == 'c') cloud++;
		}
		map[i][0] = '.';
	}
	return cloud;
}

int main(void)
{
	int row,col;
	int i,j,k;

	scanf("%d%d", &row,&col);
	for (i=0;i<row;i++) {
		for (j=0;j<col;j++) {
			scanf(" %c", &map[i][j]);
			ans[i][j] = -1;
		}
	}
	k = 0;
	do {
		for (i=0;i<row;i++) {
			for (j=0;j<col;j++) {
				if (map[i][j] == 'c' && ans[i][j] == -1) ans[i][j] = k;
			}
		}
		k++;
	} while (move_cloud(row,col));
	for(i=0;i<row;i++) {
		for (j=0;j<col;j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}