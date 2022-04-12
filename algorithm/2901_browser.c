#if 0

#include <stdio.h>
#include <string.h>
#define FULL 100 + 10

char back_stack[FULL][70 + 10];
char for_stack[FULL][70 +10];
int for_sp, back_sp;

//void strcpy(char *des, char *src)
//{
//	while (*des++ = *src++);
//}
//
//int strncmp(char * s1, char * s2, int n)
//{
//	while (*s1 && *s2 && --n>=0) {
//		if (*s1++ != *s2++) return *s1 - *s2;
//	}
//	return *s1 - *s2;
//}

int push(char des[][80], int *sp, char *s)
{
	if (*sp == FULL) return -1;
	strcpy(des[*sp], s);
	(*sp)++;
	return 0;
}

int pop(char des[][80], int *sp, char *s)
{
	if (*sp == 0) return -1;
	strcpy(s, des[*sp - 1]);
	(*sp)--;
	return 0;
}

int main(void)
{
	int ret;
	char str[70 + 10];
	char cur[70 + 10];

	strcpy(cur, "http://www.acm.org/");
	for(;;) {
		gets(str);
		if (strncmp(str, "VISIT", 3) == 0) {
			ret = push(back_stack, &back_sp, cur);
			strcpy(cur, str + 6);
			for_sp = 0;
		}
		else if (strncmp(str, "BACK", 3) == 0) {
			if (back_sp) push(for_stack, &for_sp, cur);
			ret = pop(back_stack, &back_sp, cur);
		}
		else if (strncmp(str, "FORWARD", 3) == 0) {
			if (for_sp) push(back_stack, &back_sp, cur);
			ret = pop(for_stack, &for_sp, cur);
		}
		else break;
		if (ret == -1) printf("Ignored\n");
		else printf("%s\n", cur);
	}
	return 0;
}

#endif