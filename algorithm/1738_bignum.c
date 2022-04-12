#include <stdio.h>

char num1[101];
char num2[101];
char ans[202];

int num_len(char * num)
{
	int len;

	for (len=0;num[len];len++);
	return len;
}

int main(void)
{
	char op;
	int n1, n2;
	int i;
	int small, big;

	scanf(" %s", num1);
	scanf(" %c", &op);
	scanf(" %s", num2);

	n1 = num_len(num1) - 1;
	n2 = num_len(num2) - 1;
	if (op == '*') {
		ans[0] = '1';
		for (i=1;i<=n1+n2;i++)
			ans[i] = '0';
		ans[i] = '\0';
	}
	else if (op == '+') {
		if (n1 == n2) {
			ans[0] = '2';
			for (i=1;i<=n1;i++)
				ans[i] = '0';
			ans[i] = '\0';
		}
		else {
			small = n1 < n2 ? n1 : n2;
			big = n1 < n2 ? n2 : n1;
			ans[0] = '1';
			for (i=1;i<=big;i++)
				ans[i] = '0';
			ans[big-small] = '1';
			ans[i] = '\0';
		}
	}
	printf("%s", ans);
}