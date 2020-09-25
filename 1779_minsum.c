#include <stdio.h>

int num[15];
int N;

int main(void)
{
	int i,j;
	int t;
	int n1;
	int n2;
	int zero;
	int nat;

	scanf("%d", &N);
	for (i=nat=zero=0;i<N;i++) {
		scanf("%d", &t);
		if (t == 0) zero++;
		else num[nat++] = t;
	}
	for (i=nat-1;i>0;i--) {
		for (j=0;j<i;j++) {
			if (num[j] > num[j+1]) {
				t = num[j];
				num[j] = num[j+1];
				num[j+1] = t;
			}
		}
	}
	n1 = n2 = 0;
	j= 0;
	n1 += num[j++];
	n2 += num[j++];
	n1 *= 10;
	n2 *= 10;
	nat -= 2;
	for (i=0;i<(N/2);i++) {
		if (nat <= 0 && zero <= 0) break;
		if (zero-- <= 0 && nat-- > 0)
			n1 += num[j++];
		n1 *= 10;
		if (nat <= 0 && zero <= 0) break;
		if (zero-- <= 0 && nat-- > 0)
			n2 += num[j++];
		n2 *= 10;
	}
	printf("%d", (n1+n2)/10);
	return 0;
}