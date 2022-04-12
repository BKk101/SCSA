#if 0

#include <stdio.h>

long long max;
long long sum;
long long stack[100000 + 10];
int sp;
int N;

int push(long long n)
{
	stack[sp] = n;
	sp++;
	return 0;
}

int pop(void)
{
	if (sp == 0) return -1;
	sp--;
	return 0;
}


int main(void)
{
	int i;
	long long temp;

	for (;;) {
		scanf("%d", &N);
		if (N == 0) break;
		for (i = 0; i < N; i++) {
			scanf("%d", &temp);
			if (sp == 0 || temp <= stack[sp - 1]) {
				push(temp);
			}
			else {
				while (sp && temp >= stack[sp - 1]) pop();
				push(temp);
			}
			sum += sp - 1;
			if (sum > max) max = sum;
		}
		printf("%lld\n", max);
	
	}
	return 0;
}


#endif
