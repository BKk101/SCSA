#include <stdio.h>

int arr[1010];

int main(void)
{
	int n;
	int i,j;
	int t;
	int s=1000,e=0;
	int max;
	int maxi;

	scanf("%d", &n);
	for (i=maxi=max=0;i<n;i++) {
		scanf("%d", &t);
		scanf("%d", &arr[t]);
		if (t<s) s=t;
		if (t>e) e=t;
		if (arr[t]>max) {
			max = arr[t];
			maxi = t;
		}
	}
	for (i=t=s,max=arr[s];i<=maxi;i++) {
		if (arr[i] >= max) {
			max = arr[i];
			t = i;
		}
		arr[i] = max;
	}
	for (i=t=e,max=arr[e];i>=maxi;i--) {
		if (arr[i] >= max) {
			max = arr[i];
			t = i;
		}
		arr[i] = max;
	}
	for (i=s,t=0;i<=e;i++) {
		t += arr[i];
	}
	printf("%d", t);
	return 0;
}