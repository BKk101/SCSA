#include <stdio.h>
#define ABS(x,y) ((x)>(y) ? (x)-(y) : (y)-(x))
int X,Y;
int N;
int posx[101];
int posy[101];
int dis;
int map[101][101];

int main(void)
{
    int i,j;
    int a,b;

    scanf("%d%d", &X,&Y);
    scanf("%d", &N);
    for (i=0;i<=N;i++) {
        scanf("%d%d", &a,&b);
        if (a == 1) {
            posy[i] = 0;
            posx[i] = b;
        }
        else if (a == 2) {
            posy[i] = Y;
            posx[i] = b;
        }
        else if (a == 3) {
            posx[i] = 0;
            posy[i] = b;
        }
        else if (a == 4) {
            posx[i] = X;
            posy[i] = b;
        }
    }
    for (i=0;i<N;i++) {
        if ((posx[N]==0 || posx[N]==X) && posx[N] == posx[i]) {
            dis += ABS(posy[N], posy[i]);
        }
        else if ((posy[N]==0 || posy[N]==Y) && posy[N] == posy[i]) {
            dis += ABS(posx[N], posx[i]);
        }
        else {
            if (posx[N] + posx[i] == X) {
                dis += (posy[N]+posy[i] <= 2*Y-posy[N]-posy[i] ? posy[N]+posy[i]:2*Y-posy[N]-posy[i]);
                dis += X;
            }
            else if (posy[N] + posy[i] == Y) {
                dis += (posx[N]+posx[i] <= 2*X-posx[N]-posx[i] ? posx[N]+posx[i]:2*X-posx[N]-posx[i]);
                dis += Y;
            }
            else dis += ABS(posx[N], posx[i]) + ABS(posy[N], posy[i]);
        }
    }
    printf("%d", dis);
    return 0;
}