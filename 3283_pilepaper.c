#include <stdio.h>

typedef struct pos
{
	int x,y;
}Pos;
Pos paper[21];
int chk[21];
int N;
int max;

void DFS(int n, int idx)
{
	int i;

	for (i=0;i<N;i++) {
		if (chk[i] == 1) continue;
		if (paper[i].x <= paper[idx].x && paper[i].y <= paper[idx].y) {
			chk[i] = 1;
			DFS(n+1, i);
			chk[i] = 0;
		}
	}
	if (n > max) max = n;
}

int main(void)
{
	int i;
	int a,b;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d",&a,&b);
		paper[i].x = a>b ? a:b;
		paper[i].y = a>b ? b:a;
	}
	max = 0;
	for (i=0;i<N;i++) {
		chk[i] = 1;
		DFS(1,i);
		chk[i] = 0;
	}
	printf("%d", max);
	return 0;
}