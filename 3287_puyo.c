#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define XX 6
#define YY 12

typedef struct pos
{
	int x, y;
}Pos;
Pos pos[XX*YY];
int T;
char map[YY + 3][XX + 3];
int visit[YY + 3][XX + 3];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int pi;
int cnt;
int flag;


void FF(int x, int y, char c)
{
	int i;

	if (x < 0 || y < 0 || x >= XX || y >= YY) return;
	if (visit[y][x] == 1 || map[y][x] != c) return;
	cnt++;
	pos[pi++] = (Pos) { x, y };
	visit[y][x] = 1;
	for (i = 0; i < 4; i++) FF(x + dx[i], y + dy[i], c);
}

void Clear(void)
{
	int i,j;
	if (cnt >= 4) {
		flag = 1;
		for (i = 0; i < pi; i++) map[pos[i].y][pos[i].x] = '.';
	}
	for (i = 0; i < YY; i++ ) {
		for (j = 0; j < XX; j++) visit[i][j] = 0;
	}
	cnt = pi = 0;
}

void Down(void)
{
	int i, j, t;
	char c;

	for (j = 0; j < XX; j++) {
		for (t = i = YY - 1; i > 0; i--) {
			if (map[i][j] != '.') {
				c = map[i][j];
				map[i][j] = '.';
				map[t--][j] = c;
			}
		}
	}
}

int Check(void)
{
	int i, j, ans;

	ans = 0;
	do {
		flag = 0;
		for (i = 0; i < YY; i++) {
			for (j = 0; j < XX; j++) {
				if (map[i][j] != '.') {
					FF(j, i, map[i][j]);
					Clear();
				}
			}
		}
		Down();
		if (flag == 1) ans++;
	} while (flag);
	return ans;
}

int main(void)
{
	int i, j, t;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		for (i = 0; i < YY; i++) {
			for (j = 0; j < XX; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		printf("%d\n", Check());
	}
	return 0;
}