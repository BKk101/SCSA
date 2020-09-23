#include <stdio.h>

char a[1050000];

void fold(int n, int s, int e, char c) {
    if (n == 0) return;
    if (c == 'l')
        a[(s+e)/2] = '^';
    else if (c == 'r')
        a[(s+e)/2] = 'V';
    fold(n-1,s,(s+e)/2,'l');
    fold(n-1,((s+e)/2)+1, e,'r');
}

int power(int n, int i) 
{
    long long res = 1;

    while (i-->0) {
        res *= n;
    }
    return res;
}

int main(void)
{
    int i;
    int n;
    int len;
    //비트연산 이용해보기
    scanf("%d", &n);
    for (i=0,len=0;i<n;i++) {
        len += power(2,i);
    }//<-그냥power로 구하면됨 또는 비트연산 1 << n 한것
    a[len/2] = 'V';
    fold(n-1,0,len/2,'l');
    fold(n-1,(len/2)+1,len,'r');
    printf("%s", a);
    return 0;
}

#if 0
void str_cpy(char * des, char *src)
{
    while ((*des++ = *src++));
}

int str_len(char * s)
{
    int len;

    for(len=0;s[len];len++);
    return len;
}

int main(void)
{
    int n;
    int i,j,k;
    char c;

    scanf("%d", &n);
    str_cpy(a,"V");
    str_cpy(t,"V");
    for (i=1;i<n;i++) {
        c = '^';
        a[0] = c;
        for (j=0,k=1;j<str_len(t);j++) {
            c = ((c != 'V') ? 'V' : '^');
            a[k++] = t[j];
            a[k++] = c;
        }
        a[k] = '\0';
        str_cpy(t,a);
    }
    printf("%s", a);
    return 0;
}
#endif