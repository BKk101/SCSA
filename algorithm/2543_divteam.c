#include <stdio.h>
 
int score[101];
int T;
int N;
int Kmin;
int Kmax;
int t;
 
void init(void)
{
    int i;
 
    N = 0;
    Kmin = 0;
    Kmax = 0;
    t = 0;
    for (i=0;i<101;i++) score[i] = 0;
}
 
int check()
{
    int i;
    int cnt;
 
    cnt = 0;
    for (i=0;i<101;i++) {
        if (score[i] > 0) {
            cnt++;
            if (score[i] > Kmax) return 0;
        }
    }
    if (cnt < 3) return 0;
    return 1;
}
 
int Max(int a, int b, int c)
{
    if (a>b) {
        if(c>a) return c;
        else return a;
    }
    else {
        if(c>b) return c;
        else return b;
    }
}
 
int Min(int a, int b, int c)
{
    if (a<b) {
        if(c<a) return c;
        else return a;
    }
    else {
        if(c<b) return c;
        else return b;
    }
}
 
int classify(int min, int max)
{
    int i,j,k;
    int p1,p2;
    int sum1,sum2,sum3;
    int summin;
     
    summin = 9999;
    for(i=min+1;i<=max-1;i++) {
        for (j=i+1;j<=max;j++) {
            p1 = i;
            p2 = j;
            sum1=sum2=sum3=0;
            for (k=min;k<p1;k++) sum1 += score[k];
            if (sum1 < Kmin) continue;
            for (k=p1;k<p2;k++) sum2 += score[k];
            if (sum2 < Kmin) continue;
            for (k=p2;k<=max;k++) sum3 += score[k];
            if (sum3 < Kmin) continue;
            if (Max(sum1,sum2,sum3)-Min(sum1,sum2,sum3) < summin) summin = Max(sum1,sum2,sum3)-Min(sum1,sum2,sum3);
        }
    }
    return summin;
}
 
int main(void)
{
    int i,j;
    int r;
    int smin,smax;
 
    scanf("%d", &T);
    for (i=0;i<T;i++) {
        init();
        smin = 999;
        smax = 0;
        scanf("%d %d %d", &N, &Kmin, &Kmax);
        for (j=0;j<N;j++) {
            scanf("%d", &t);
            if (t<smin) smin = t;
            if (t>smax) smax = t;
            score[t]++;
        }
        if (check() == 0) {
            printf("-1\n");
            continue;
        }
        r = classify(smin,smax);
        if (r == 9999) r = -1;
        printf("%d\n", r);
    }
    return 0;
}