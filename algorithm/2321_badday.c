#if 0

#include <stdio.h>

long long sum;
int stack[80000 + 10];
int sp;
int N;

int push(int n)
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
	int i, temp;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (sp == 0 || temp < stack[sp-1]) {
			push(temp);
		}
		else {
			while (sp && temp >= stack[sp-1]) pop();
			push(temp);
		}
		sum += sp - 1;
	}
	printf("%lld", sum);
	return 0;
}

#endif
