#include <stdio.h>

int map[101][101];
//int visit[101][101];
int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int max;

int Check2(int x, int y, int lev)
{
    if (x<0 || x>N || y<0 || y>N) return 0;
    return map[y][x];
}

void Check(int x, int y, int lev)
{
    int i;
    int min=99;
    int t;

    for (i=0;i<4;i++) {
        t = Check2(x+dx[i], y+dy[i], lev);
        if (t < min) min = t;
    }
    if (min == lev) {
        map[y][x] = lev+1;
        max = lev+1;
    }
}

int main(void)
{
    int i,j,k;

    scanf("%d", &N);
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) max = 1;
        }
    }
    for (k=1;k<51;k++) {
        for (i=0;i<N;i++) {
            for (j=0;j<N;j++) {
                if (map[i][j] == k) Check(j,i,k);
            }
        }
    }
    printf("%d", max);
    return 0;
}