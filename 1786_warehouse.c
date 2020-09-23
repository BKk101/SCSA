#include <stdio.h>

int arr[1010];

int main(void)
{
	int n;
	int i,j;
	int t;
	int s=1000,e=0;
	int area1, area2;
	int max;

	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%d", &t);
		scanf("%d", &arr[t]);
		if (t<s) s=t;
		if (t>e) e=t;
	}
	area1 = 0;
	for (i=s,t=s,max=arr[s];i<=e;i++) {
		if (arr[i] >= max) {
			area1 += max*(i-t);
			max = arr[i];
			t = i;
		}
	}

	area2 = 0;
	for (i=e,t=e,max=arr[e];i>=s;i--) {
		if (arr[i] >= max) {
			area2 += max*(t-i);
			max = arr[i];
			t = i;
		}
	}
	printf("%d", area1 + area2 + max);
	return 0;
}