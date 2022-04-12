#include <stdio.h>

int T,N;
int num[11];
int eq;
int left;
int right;
int cnt;

//int chk[11];
//char op[] = "+*%=";

void Clear(void)
{
	eq = cnt = left = right = 0;
}

void DFS(int n)
{
	int i,pre,f=0;
	int *t;

	if (n == N) {
		if (eq == 0) return;
		if (left == right) {cnt++;
			//printf("%d", num[0]);
			//for (i=1;i<n;i++) {
			//	printf("%c", op[chk[i]]);
			//	printf("%d", num[i]);
			//}
			//printf("\n");
		}
		return ;
	}
	if (eq == 1) t = &right;
	else t = &left;
	pre = *t;
	for (i=0;i<4;i++) {
		if (i==0) *t += num[n];
		else if (i==1) *t *= num[n];
		else if (i==2) *t %= num[n];  
		else if (i==3 && eq == 1) continue;
		else if (i==3 && eq == 0) {
			eq = 1; f = 1;
			right = num[n];	
		}
		//chk[n] = i;
		DFS(n+1);
		//chk[n] = 0;
		*t = pre;
		if (f==1 && eq == 1) {eq = 0; f = 0; right = 0;}
	}
}

int main(void)
{
	int i,j;

	scanf("%d", &T);
	for (i=0;i<T;i++) {
		Clear();
		scanf("%d", &N);
		for (j=0;j<N;j++) scanf("%d", &num[j]);
		left = num[0];
		DFS(1);
		printf("%d\n", cnt);
	}
	return 0;
}