#include <stdio.h>

char table[20001];
int N;
int i;

int make_num(void)
{
	int sum = 0;

	while (table[i] >= '0' && table[i] <= '9') {
		sum += table[i] - '0';
		sum *= 10;
		i++;
	}
	return sum/10;
}

void DFS(int lev)
{
    int num;

	if (table[i] >= '0' && table[i] <= '9') {
		num = make_num();
        if (lev == N) printf("%d ", num);
    }
    if (table[i] == '<') {
        i++;
        DFS(lev+1);
        i++;
        DFS(lev+1);
    }
    if (table[i] == '>') {
        i++;
        return ;
    }
}

int main(void)
{
    scanf("%d", &N);
    scanf("%s", table);
    DFS(0);
    return 0;
}