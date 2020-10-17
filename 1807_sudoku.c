#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct pos
{
	int x, y;
}Pos;

int map[11][11];
Pos blk[81];
int bp;
int f;

int sqr(Pos a, int n)
{
	int i, j;
	int chk2[10] = { 0, };

	for (i = (a.y / 3) * 3; i < (a.y / 3) * 3 + 3; i++) {
		for (j = (a.x / 3) * 3; j < (a.x / 3) * 3 + 3; j++) {
			chk2[map[i][j]]++;
		}
	}
	if (chk2[n] == 0) return 0;
	else return 1;
}

int ver(Pos a, int n)
{
	int i;
	int chk2[10] = { 0, };
	
	for (i = 0; i < 9; i++) {
		chk2[map[i][a.x]]++;
	}
	if (chk2[n] == 0) return 0;
	else return 1;	
}

int hor(Pos a, int n)
{
	int i;
	int chk2[10] = { 0, };

	for (i = 0; i < 9; i++) {
		chk2[map[a.y][i]]++;
	}
	if (chk2[n] == 0) return 0;
	else return 1;
}

void DFS(int n)
{
	int i,j;

	if (n == bp) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) printf("%d ", map[i][j]);
			printf("\n");
		}
		f = 1;
		return;
	}
	for (i = 1; i < 10; i++) {
		if (sqr(blk[n],i) || ver(blk[n],i) || hor(blk[n],i)) continue;
		map[blk[n].y][blk[n].x] = i;
		DFS(n + 1);
		map[blk[n].y][blk[n].x] = 0;
		if (f == 1) return;
	}
}

int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) blk[bp++] = (Pos) { j, i };
		}
	}
	DFS(0);
	return 0;
}