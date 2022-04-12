#include <stdio.h>

int N;
int a[6];
int b[6];
int cnt;

void Change(int *a, int *b)
{
    if (*a > *b) {
        (*a)--;
        (*b)++;
    }
    else if (*a < *b) {
        (*a)++;
        (*b)--;
    }
}

int main(void)
{
	int i,j;
	int t;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &t);
		a[t]++;
	}
	for (i=0;i<N;i++) {
		scanf("%d", &t);
		b[t]++;
	}
	for (i=1;i<=5;) {
	    if ((a[i]+b[i])%2 == 1) {printf("-1"); return 0;}
	    if (a[i] == b[i]) i++;
	    else {
	        cnt++;
	        Change(&a[i], &b[i]);
	        for (j=i+1;j<=5;j++) {
	            if (a[j] != b[j]) {
	                Change(&a[j], &b[j]);
	                break;
	            }
	        }
	    }
	}
	printf("%d", cnt);
    return 0;
}