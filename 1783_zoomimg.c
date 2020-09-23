#include <stdio.h>

char a[50][50];
char zoom[250][250];

int main(void)
{
	int row,col;
	int zr,zc;
	int i,j;

	scanf("%d%d%d%d",&row,&col,&zr,&zc);
	for (i=0;i<row;i++) {
		for (j=0;j<col;j++) {
			scanf(" %c", &a[i][j]); 
		}
	}
	for (i=0;i<row*zr;i++) {
		for (j=0;j<col*zc;j++) {
			zoom[i][j] = a[i/zr][j/zc];
		}
	}
	for (i=0;i<row*zr;i++) {
		for (j=0;j<col*zc;j++) {
			printf("%c", zoom[i][j]);
		}
		printf("\n");
	}
	return 0;
}