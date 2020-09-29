#include <stdio.h>

char map[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int section;
int section_blnd;
int N;

void count(int x, int y, char c)
{
	int i;
	
	if (x < 0 || x >= N || y < 0 ||y >= N) return;
	if (map[y][x] != c) return;
	else map[y][x] = c - 'A' + 'a'; 
	for (i=0;i<4;i++) count(x+dx[i], y+dy[i], c);
}

void count2(int x, int y, char c)
{
	int i;
	
	if (x < 0 || x >= N || y < 0 ||y >= N) return;
	if (c == 'b' && map[y][x] != c) return;
	if (map[y][x] == 'b' && map[y][x] != c)  return;
	if (map[y][x] == 0) return;
	else map[y][x] = 0; 
	for (i=0;i<4;i++) count2(x+dx[i], y+dy[i], c);
}

int main(void)
{
	int i,j;

	scanf("%d", &N);
	for (i=0;i<N;i++)
		scanf("%s", map[i]);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') {
				count(j,i, map[i][j]);
				section++;
			}
		}
	}
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (map[i][j] != 0) {
				count2(j,i, map[i][j]);
				section_blnd++;
			}
		}
	}
	printf("%d %d", section, section_blnd);
	return 0;
}