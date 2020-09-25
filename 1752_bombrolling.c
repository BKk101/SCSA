#include <stdio.h>
int time[100];
char pf[100];

int main(void)
{
	int S;
	int Q;
	int i;
	int clock;

	scanf("%d %d", &S, &Q);
	for (i=0;i<Q;i++) {
		scanf(" %d %c", &time[i], &pf[i]);
	}
	for (i=clock=0;i<Q;i++) {
		clock += time[i];
		if (clock > 210)
			break;
		if (pf[i] == 'T')
			S = (S%8) + 1;
	}
	printf("%d", S);
	return 0;
}