#include <stdio.h>

char check[50][2];
char str[100001];
int N;

int check_err(char c)
{
	int i;

	for (i=0;i<N;i++) {
		if (c == check[i][0])
			return i;
	}
	return -1;
}

int main(void)
{
	int i;
	int len;
	int idx;
	char t;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf(" %c %c", &check[i][0], &check[i][1]);
	}
	scanf("%d", &len);
	for (i=0;i<len;i++) {
		scanf(" %c", &str[i]);
	}
	for (i=0;i<len;i++) {
		t = str[i];
		if ((idx = check_err(t)) != -1)
			printf("%c", check[idx][1]);
		else
			printf("%c", t);
	}
	return 0;
}