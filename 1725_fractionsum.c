#include <stdio.h>

int frac[101][2];
int ans[2] = {0,1};
int check[101];

int gcd(int a, int b)
{
	int p,q,r;
	
	p = a>b ? a : b;
	q = a>b ? b : a;
	r = p%q;
	while (r != 0) {
		p = q;
		q = r;
		r = p%q;
	}
	return q;
}

int main(void)
{
	int N;
	int i;
	int t;

	scanf("%d", &N);
	t = 1;
	for (i=0;i<N;i++) {
		scanf("%d%d", &frac[i][0], &frac[i][1]);
		ans[1] = (frac[i][1]*t) / gcd(frac[i][1], t);
		t = ans[1];
	}
	for (i=0;i<N;i++) {
		frac[i][0] *= (ans[1]/frac[i][1]);
		ans[0] += frac[i][0]; 
	}

	if (ans[0] == 0)
		printf("%d", ans[0]);
	else {
		t = gcd(ans[0],ans[1]);
		ans[0] /= t;
		ans[1] /= t;
		printf("%d/%d", ans[0],ans[1]);
	}
	return 0;
}

#if 0
//잘못된 코드
#include <stdio.h>

int frac[101][2];
int ans[2] = {0,1};
int check[101];

int gcd(int a, int b)
{
	int p,q,r;
	
	p = a>b ? a : b;
	q = a>b ? b : a;
	r = p%q;
	while (r != 0) {
		p = q;
		q = r;
		r = p%q;
	}
	return q;
}

int main(void)
{
	int N;
	int i;
	int t;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d%d", &frac[i][0], &frac[i][1]);
		if (frac[i][0] != 0) {
			t = gcd(frac[i][0], frac[i][1]);
			if (t != 1) {
				frac[i][0] /= t;
				frac[i][1] /= t;
			}
		}
		if (check[frac[i][1]] == 0) {
			ans[1] *= frac[i][1];
			check[frac[i][1]] = 1;
		}
	}
	for (i=0;i<N;i++) {
		frac[i][0] *= (ans[1]/frac[i][1]);
		ans[0] += frac[i][0]; 
	}
	if (ans[0] == 0)
		printf("%d", ans[0]);
	else {
		t = gcd(ans[0],ans[1]);
		ans[0] /= t;
		ans[1] /= t;
		printf("%d/%d", ans[0],ans[1]);
	}
	return 0;
}

#endif