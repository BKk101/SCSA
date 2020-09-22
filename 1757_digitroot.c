#include <stdio.h>

int a[1000];
int root[1000];

void digit_root(int n)
{
	int t;
	int i;

	for (i=0;i<n;i++) {
		root[i] = a[i];
		while (root[i] >= 10) {
			t = root[i];
			root[i] = 0;
			while(t > 0) {
				root[i] += t%10;
				t/=10;
			}
		}
	}
}

int main(void)
{
	int n;
	int t;
	int max = -1;
	int i,j,idx;

	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	for (i=n-1;i>0;i--) {
		for (j=0;j<i;j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	digit_root(n);
	for (i=0;i<n;i++) {
		if (root[i]>max) {
			max = root[i];
			idx = i;
		}
	}
	printf("%d",a[idx]);
	return 0;
}