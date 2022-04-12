#include <stdio.h>

int map[25][25];
int danjinum[350];
int danji;
int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void quick_sort(int s, int e, int * a)
{
	int T,P=e;
	int i,temp;

	if (e <= s) return ;
	for (i=T=s;i<e;i++) {
		if (a[i] < a[P]) {
			{temp = a[i]; a[i] = a[T]; a[T] = temp;}
			T++;
		}
	}
	if (P != T) {temp = a[P]; a[P] = a[T]; a[T] = temp;}
	quick_sort(s,T-1, a);
	quick_sort(T+1,e, a);
}

void convert(int x, int y)
{
	int i;
	int nx,ny;

	if (map[y][x] == 0) return;
	map[y][x] = danji;
	danjinum[danji-2]++;
	for (i=0;i<4;i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; //입력을 1,1 부터 받으면 경계에 0 채워져서 경계 검사안해도됨
		if (map[ny][nx] == 1) convert(nx,ny);
	}
}

int main(void)
{
	int i,j;
	danji = 2;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) 
			scanf("%1d", &map[i][j]);
	}
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (map[i][j] == 1) {
				convert(j,i);
				danji++;
			}
		}
	}
	printf("%d\n", danji-2);
	quick_sort(0, danji-3, danjinum);
	for (i=0;i<danji-2;i++) printf("%d\n", danjinum[i]);
}