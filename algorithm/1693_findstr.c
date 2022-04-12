#include <stdio.h>

char str[10001];

int check_koi(char * s)
{
	int i;
	char * tar = "KOI";

	for (i=0;i<3;i++) {
		if (s[i] != tar[i])
			return 0;
	}
	return 1;
}

int check_ioi(char * s)
{
	int i;
	char * tar = "IOI";

	for (i=0;i<3;i++) {
		if (s[i] != tar[i])
			return 0;
	}
	return 1;
}

int main(void)
{
	int i;
	int koi, ioi;

	scanf("%s", str);
	ioi = koi = 0;
	for (i=0;str[i];i++) {
		if (str[i] == 'K') {
			if (check_koi(&str[i])) 
				koi++;
		}
		else if (str[i] == 'I') {
			if (check_ioi(&str[i])) 
				ioi++;
		}
	}
	printf("%d\n%d", koi, ioi);
	return 0;
}