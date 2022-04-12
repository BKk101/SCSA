#if 0

#include <stdio.h>
#include <string.h>

char scroll[10 + 2];
char up[30 + 2];
char down[30 + 2];
int cnt;
int len;
int blen;

void DFS(int s, int ord, int idx)
{
	if (idx == len) {
		cnt++;
		return;
	}
	for (size_t p = s; p < blen; p++) {
		if (ord == 0) {
			if (up[p] == scroll[idx]) DFS(p+1, !ord, idx + 1);
		}
		else {
			if (down[p] == scroll[idx]) DFS(p + 1, !ord, idx + 1);
		}
	}
}

int main(void)
{
	scanf("%s", scroll);
	scanf("%s", up);
	scanf("%s", down);
	len = strlen(scroll);
	blen = strlen(up);
	DFS(0, 0, 0);
	DFS(0, 1, 0);
	printf("%d", cnt);
	return 0;
}
#endif
