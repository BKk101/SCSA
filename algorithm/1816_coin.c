#if 0

#include <stdio.h>
#include <stdlib.h>
#define MAX 64000 + 5
int N,W;
int coin[10 + 5];
int rec[MAX];

int main(void)
{
	int i, j;
	int temp;
	int min;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &coin[i]);
		rec[coin[i]] = 1;
	}
	scanf("%d", &W);
	for (i = 1; i <= W; i++) {
		if (rec[i] == 1) continue;
		min = MAX;
		for (j = 0; j < N; j++) {
			temp = i - coin[j];
			if (temp <= 0 || rec[temp] == 0) continue;
			if (rec[temp] < min) min = rec[temp];
		}
		rec[i] = min + 1;
	}
	if (rec[W] >= MAX) printf("impossible");
	else printf("%d", rec[W]);
	return 0;
}

#endif