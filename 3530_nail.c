#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct pos
{
	int x, y;
}Pos;

int N;
int map[101][101];
Pos nail[5];
Pos frame[5];
int chk[5];
int max;

int Cal(int n, int f, int d, int mod)
{
	int i, j, h, w, s, t, area;
	
	h = d < 1 ? frame[f].y : frame[f].x;
	w = d < 1 ? frame[f].x : frame[f].y;
	area = 0;
	if (mod == 1) { s = n + 1; t = 0; }
	else { s = 0; t = n + 1; }
	for (i = nail[n].y; i < nail[n].y + h; i++) {
		for (j = nail[n].x-w/2; j < nail[n].x + w/2; j++) {
			if (map[i][j] == t) {
				map[i][j] = s;
				area++;
			}
		}
	}
	return area;
}

void DFS(int n, int area)
{
	int i, j, t;

	if (n == N) {
		if (area > max) {
			max = area;
		}
		return;
	}
	for (i = 0; i < N; i++) {
		if (chk[i] == 1) continue;
		for (j = 0; j < 2; j++) {
			t = Cal(n, i, j, 1);
			chk[i] = 1;
			DFS(n + 1, area+t);
			Cal(n, i, j, 0);
			chk[i] = 0;
		}
	}
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d%d", &nail[i].x, &nail[i].y);
	for (i = 0; i < N; i++) scanf("%d%d", &frame[i].x, &frame[i].y);
	DFS(0,0);
	printf("%d", max);
	return 0;
}