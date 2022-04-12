#include <stdio.h>

char dish[51];

int main(void)
{
	int hei = 0;
	int i;

	scanf("%s", dish);
	hei = 10;
	i = 1;
	while (dish[i]) {
		if (dish[i] == dish[i-1])
			hei += 5;
		else
			hei += 10;
		i++;
	}
	printf("%d", hei);
	return 0;
}