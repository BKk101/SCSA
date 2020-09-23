#include <stdio.h>

char Number[]="0123456789ABCDEFGHIJ";

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

void convert_base(int base, int n, char * num)
{
	char temp[20];
	int i,j;

	i = j = 0;
	while (n > 0) {
		temp[i++] = Number[n%base];
		n /= base;
	}
	while (--i >= 0) {
		num[j++] = temp[i];
	}
	num[j] = '\0';
}

void reverse(char * num, char * rnum)
{
	int len;
	int i;

	for (len=0;num[len];len++);
	for (i=0;i<len;i++) {
		rnum[i] = num[len-1-i];
	}
	rnum[i] = '\0';
}

int main(void)
{
	int B;
	int i;
	char num[20];
	char rnum[20];

	scanf("%d", &B);
	for (i=1;i<=300;i++) {
		convert_base(B, i*i, num); //길이의 반만 비교하면서 같은지 보면됨
		reverse(num, rnum);
		if (str_cmp(num, rnum) == 0) {
			convert_base(B,i, num);
			printf("%s %s\n", num, rnum);
		}
	}
	return 0;
}