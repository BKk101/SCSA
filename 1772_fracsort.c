#include <stdio.h>

typedef struct pos
{
	int m;
	int s;
}Pos;

Pos num[100000];

int main(void)
{
	int N;
	int i,j;
	int idx;

	scanf("%d", &N);
	for (i=2;i<=N;i++) {
		for (j=1;j<i;j++) {
			idx = (100000 * (double)j/i);
			if (num[idx].m != 0 && i < num[idx].m) {
				num[idx].m = i;
				num[idx].s = j;
			}
			else if (num[idx].m == 0) {
				num[idx].m = i;
				num[idx].s = j;
			}
		}
	}
	printf("0/1\n");
	for (i=0;i<100000;i++) {
		if (num[i].m != 0)
			printf("%d/%d\n", num[i].s, num[i].m);
	}
	printf("1/1\n");
	return 0;
}