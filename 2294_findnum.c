#include <stdio.h>

char num[1000005];
char temp[1000005];
char *sam[]={"1","2","3","4","5","6","7","8","9","10","20","30","40","50","60","70","80","90"};

void clear(char *s)
{
	int i;
	for (i=0;i<1000005;i++)
		s[i] = '\0';
}

void str_cat(char *a, char *b)
{
	int alen, blen;
	int i;

	for(alen=0;a[alen];alen++);
	for(blen=0;b[blen];blen++);
	b[blen + alen] = '\0';
	for (i=blen+alen-1;i>=alen;i--) {
		b[i] = b[i-alen];
	}
	for (i=0;i<alen;i++) {
		b[i] = a[i];
	}
}

void str_cpy(char *des, char *src)
{
	while (*des++ = *src++);
}

int check_11(char *n)
{
	int len;
	int even, odd;
	int i;

	for (len=0;n[len];len++);
	for (i=odd=even=0;i<len;i++) {
		if (i%2 == 0)
			even += n[i]-'0';
		else
			odd += n[i]-'0';
	}
	if ((even - odd)%11 == 0)
		return 1;
	else
		return 0;
}

void div(char *s)
{
	int len;
	int t,r;
	int i,j;

	for (len=0;s[len];len++);
	j=0;
	t = 10*(s[0]-'0') + (s[1]-'0');
	num[j++] = '0' + t/11;
	r = t%11;
	for (i=2;i<len;i++) {
		t = 10*r+(s[i]-'0');
		num[j++] = '0' + t/11;
		r = t%11;
	}
}

int main(void)
{
	int i;
	int cnt;

	for (cnt=1;;) {
		clear(num);
		scanf("%s", num);
		if (num[0] == '0') break;
		for (i=0;i<18;i++) {
			clear(temp);
			str_cpy(temp, num);
			str_cat(sam[i], temp);
			if (check_11(temp)) {
				break;
			}
		}
		if (i == 18)
			printf("%d. IMPOSSIBLE\n", cnt);
		else {
			div(temp);
			printf("%d. %s\n", cnt, num);
		}
		cnt++;
	}
	return 0;
}