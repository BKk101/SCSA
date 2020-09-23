#include <stdio.h>

char str[100][15];
char rev[15];

int str_cmp(char * a, char * b)
{
	while (*a && *b) {
		if (*a == *b) {
			a++;
			b++;
		}
		else 
			break;
	}
	if (*a == *b)
		return 0;
	else
		return 1;
}

void reverse_str(char * s, int len)
{
	int i;

	i = 0;
	while (--len >= 0)
		rev[i++] = s[len];
	rev[i] = '\0';
}

int main(void)
{
	int N;
	int i,j;
	int len;
	char ans;

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%s", str[i]);
	}
	for (i=0;i<N;i++) {
		for(len=0;str[i][len];len++);
		reverse_str(str[i], len);
		for (j=i;j<N;j++) {
			if (str_cmp(rev,str[j]) == 0) {
				ans = rev[len/2];
				goto P1;
			}
		}
	}
P1:
	printf("%d %c", len, ans);
	return 0;
}