#include <stdio.h>

char str[51];

int is_word(char c)
{
	if (c != ' ' && c != '.' && c!= '!')
		return 1;
	return 0;
}

void print_word(char * s, char * e)
{
	while (--e>=s) {
		if (*e >= 'a' && *e <= 'z') *e += -32;
		printf("%c", *e);
	}
}

int main(void)
{
	int i;
	int flag;
	char * s;
	char * e;

	gets(str); //fgets 사용
	//fgets(str, 50, stdin);
	s = e = NULL;
	for (i=0,flag=0;str[i];i++) {
		if (flag == 0 && is_word(str[i])) {
			flag = 1;
			s = &str[i];
		}
		if (flag == 1 && is_word(str[i]) == 0) {
			flag = 0;
			e = &str[i];
		}
		if (s && e) {
			print_word(s,e);
			s = e = NULL;
		}
		if (str[i] == ' ' || str[i] == '.' || str[i] == '!')
			printf("%c", str[i]);
	}
	if (s != NULL)
		print_word(s,&str[i]);
	return 0;
}