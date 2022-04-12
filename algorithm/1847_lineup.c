#include <stdio.h>

int line[100];

int push(int n)
{
	int len;
	int i;

	for(len=0;line[len]!=0;len++);
	for (i=len;n>0;n--){
		line[i] = line[i-1];
		i--;
	}
	return len;
}

int main(void)
{
	int N;
	int i;
	int t;
	int len;
	
	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &t);
		len = push(t);
		line[len-t] = i+1;
	}
	for (i=0;i<=len;i++) {
		printf("%d ", line[i]);
	}
	return 0;
}