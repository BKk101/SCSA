#include <stdio.h>
int map[1000][1000];

int main(void)
{
	int row,col;
	int i,j;
	int t;

	scanf("%d%d", &row, &col);
	for (i=0;i<row;i++) {
		for (j=0;j<col;j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i=0;i<row;i++) {
		t = 1;
		for (j=0;j<col;j++) {
			if (map[i][j] == 0) t = 1;
			else {
				map[i][j] = t++;
			}
		}
	}

	for (i=0;i<row;i++) {
		for (j=0;j<col;j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}