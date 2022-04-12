#include <stdio.h>

typedef struct que
{
	int x,y,t;
}Que;
Que que[1000*1000*5];
int rp,wp;
int H,W,N;
char map[1005][1005];
int visit[1005][1005];
int xpos[12];
int ypos[12];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

Que BFS(int tar)
{
	Que q;
	int i;
	int nx,ny;

	while(rp<wp) {
		q = que[rp++];
		if (q.x == xpos[tar] && q.y == ypos[tar]) return q;
		for (i=0;i<4;i++) {
			nx = q.x+dx[i]; ny = q.y+dy[i];
			if (nx<0 || ny<0 || nx>=W || ny>=H) continue;
			if (visit[ny][nx] == 1 || map[ny][nx] == 'X') continue;
			que[wp++] = (Que) {nx,ny,q.t+1};
			visit[ny][nx] = 1; //visit 체크를 타겟 공장번호로 하면 매번 초기화 안해도됨, visit[i][j] = tar;
		}
	}
}

void Clear(void)
{
	int i,j;
	for (i=0;i<wp;i++) que[i] = (Que) {0,0,0};
	for (i=0;i<H;i++) {
		for (j=0;j<W;j++) visit[i][j] = 0;
	}
	rp = wp = 0;
}

int main(void)
{
	int i,j;
	Que q;
	scanf("%d%d%d", &H,&W,&N);
	for (i=0;i<H;i++) {
		for (j=0;j<W;j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {que[wp++] = (Que) {j,i,0};}
			else if (map[i][j] >= '1' && map[i][j] <= '9') {xpos[map[i][j]-'0'] = j; ypos[map[i][j]-'0'] = i;} 
		}
	}
	for (i=1;i<=N;i++) {
		q = BFS(i);
		Clear();
		que[wp++] = q;
	}
	printf("%d", q.t);
	return 0;
}