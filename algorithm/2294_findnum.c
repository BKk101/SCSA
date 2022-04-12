#include <stdio.h>

char num[1000005];

int check(char *s)
{
    int len;
    int t;
    int i;
    int b;

    for(len=0;s[len];len++);
    t = s[len-1] - '0';
    num[len-1] = t + '0';
    for(i=len-2,b=0;i>=0;i--) {
        t = s[i] - t - b - '0';
        b = 0;
        if (t < 0) {
            b = 1;
            t += 10;
        }
        num[i] = t + '0';
    }
    if (num[0] == '0')
        return 0;
    else
        return 1;
}

void clear(void)
{
    int i;
    int len;

    for(len=0;num[len];len++);
    for (i=0;i<len;i++)
        num[i] = '\0';
}

int main(void)
{
    int i;
    int cnt;

    for (cnt=1;;) {
        clear();
        scanf("%s", num);
        if (num[0] == '0') break;
        if (check(num) == 1)
            printf("%d. %s\n", cnt, num);
        else
            printf("%d. IMPOSSIBLE\n", cnt);
        cnt++;
    }
    return 0;
}