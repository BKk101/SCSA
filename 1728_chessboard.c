#include <stdio.h>

int main(void)
{
	int R, C;
	int W, H;
	int i,j;
	char c;

	scanf("%d%d", &R, &C);
	scanf("%d%d", &H, &W);
	for (i=0;i<R*H;i++) {
		for (j=0;j<C*W;j++) {
			if ((j/W)%2 == (i/H)%2) c = 'X';
			else c = '.';
			printf("%c", c);
		}
		printf("\n");
	}
}