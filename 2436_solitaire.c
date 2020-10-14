#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define XX 9
#define YY 5

char map[YY + 1][XX + 1];
int T;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int pinx[10];
int piny[10];
int pi;
int minp;
int mint;


int search(int x, int y)
{
	int i;

	for (i = 0; i < pi; i++) {
		if (pinx[i] == x && piny[i] == y) return i;
	}
	return -1;
}

void DFS(int n)
{
	int i,j,t;
	int nx, ny, nx2, ny2;

	for (j = 0; j < pi; j++) {
		if (pinx[j] == -1) continue;
		for (i = 0; i < 4; i++) {
			nx = pinx[j] + dx[i]; ny = piny[j] + dy[i];
			if (nx < 0 || ny < 0 || nx >= XX || ny >= YY) continue;
			if (map[ny][nx] == '#' || map[ny][nx] == '.') continue;
			nx2 = nx + dx[i]; ny2 = ny + dy[i];
			if (nx2 < 0 || ny2 < 0 || nx2 >= XX || ny2 >= YY) continue;
			if (map[ny2][nx2] == '#' || map[ny2][nx2] == 'o') continue;
			map[ny][nx] = '.';
			t = search(nx, ny);
			map[piny[j]][pinx[j]] = '.';
			map[ny2][nx2] = 'o';
			pinx[t] = -1;
			pinx[j] = nx2; piny[j] = ny2;
			DFS(n + 1);
			pinx[t] = nx;
			map[ny][nx] = 'o';
			map[ny2][nx2] = '.';
			pinx[j] = nx-dx[i]; piny[j] = ny-dy[i];
			map[piny[j]][pinx[j]] = 'o';
		}
	}
	for (t = i = 0; i < pi; i++) {
		if (pinx[i] != -1) t++;
	}
	if (t <= minp) {
		if (t < minp) {
			minp = t;
			mint = n;
		}
		else if (t == minp) {
			if (n < mint) mint = n;
		}
	}
}

int main(void)
{
	int i,j,t;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		pi = 0;
		mint = minp = 0x7fffffff;
		for (i = 0; i < YY; i++) {
			for (j = 0; j < XX; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == 'o') {
					pinx[pi] = j;
					piny[pi] = i;
					pi++;
				}
			}
		}
		DFS(0);
		printf("%d %d\n", minp, mint);
	}
	return 0;
}