#include <stdio.h>

int belt[3000000];
int check[3001];

int main(void)
{
	int N,d,k,c;
	int i;
	int kind;
	int max;
	int t;

	scanf("%d%d%d%d", &N,&d,&k,&c);
	for (i=0;i<N;i++) {
		scanf("%d", &belt[i]);
	}
	check[c]=1;
	kind = 1;
	for (i=0;i<k;i++) {
		if (check[belt[i]] == 0) kind++;
		check[belt[i]]++;
	}
	max = kind;
	for (i=0;i<N;i++) {
		t = i+k;
		if (t>=N) t %= N;
		if (check[belt[i]] == 1)
			kind--;
		check[belt[i]]--;
		if (check[belt[t]] == 0)
			kind++;
		check[belt[t]]++;
		if (kind > max) max = kind;
	}
	printf("%d", max);
	return 0;
}