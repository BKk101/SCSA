#include <stdio.h>

int a[200];

int main(void)
{
	int N,T;
	int i,j;
	int t;
	int cnt;

	scanf("%d%d", &N,&T);
	for (i=0;i<N;i++) {
		scanf("%d", &a[i]);
	}
	for (i=N-1;i>0;i--) {
		for (j=0;j<i;j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for (i=0, t=0, cnt=0;;i++) {
		if (t >= T) break;
		t += a[i];
		cnt++;
	}
	if (t > T) --cnt;
	printf("%d",cnt);
	return 0;
}