#include <stdio.h>

int candy[1000002];
int N;
int ans;

int main(void)
{
    int i,t;
    int a,b;

    scanf("%d", &N);
    for (i=0;i<N;i++) {
        scanf("%d", &t);
        candy[t]++;
    }
    candy[1000001] = 1;
    i = 1;
    while (i<1000001) {
        if (candy[i] == 0) while(candy[++i] == 0);
        if (i == 1000001) break;
        a = i;
        candy[i]--;
        if (candy[i] == 0) while(candy[++i] == 0);
        if (i == 1000001) break;
        b = i;
        candy[i]--;
        candy[a+b]++;
        ans += a+b;
    }
    printf("%d", ans);
    return 0;
}