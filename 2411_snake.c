#include <stdio.h>
typedef struct pos
{
	int x;
	int y;
}Pos;

int map[101][101];
Pos snake[102];
char time[10001];
int dir; //0123 우하좌상
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int len;
int N,K,L;

int move(int t)
{
	int rtn;
	int i;

	for (i=len;i>0;i--) snake[i] = snake[i-1];
	if (time[t-1] == 'D') {
		dir = (++dir)%4;
		snake[0].x += dx[dir];
		snake[0].y += dy[dir];
	}
	else if (time[t-1] == 'L') {
		--dir;
		dir = dir < 0 ? 3 : dir;
		snake[0].x += dx[dir];
		snake[0].y += dy[dir];
	}
	else {
		snake[0].x += dx[dir];
		snake[0].y += dy[dir];
	}
	if (snake[0].x > N || snake[0].x < 1 || snake[0].y > N || snake[0].y < 1) return 0;
	for (i=1;i<=len;i++) {//충돌체크
		if (snake[i].x == snake[0].x && snake[i].y == snake[0].y) return 0;
	}
	if (map[snake[0].y][snake[0].x] == 1) {
		map[snake[0].y][snake[0].x] = 0;
		len++;
		return 1;
	}
	else {
		snake[len].x = snake[len].y = 0;
		return 1;
	}
}

int main(void)
{
	int i;
	int x,y;
	int loop;
	int t;
	char c;

	scanf("%d %d", &N,&K);
	for (i=0;i<K;i++) {
		scanf("%d%d", &y, &x);
		map[y][x]  = 1;
	}
	scanf("%d", &L);
	for (i=0;i<L;i++) {
		scanf("%d %c", &t, &c);
		time[t] = c;
	}
	snake[0].x = snake[0].y = 1;
	loop = dir = 0;
	len = 1;
	for (;;) {
		loop++;
		if (move(loop) == 0) break;
	}
	//printf("%d %d\n", snake[0].x,snake[0].y);
	printf("%d", loop);
	return 0;
}