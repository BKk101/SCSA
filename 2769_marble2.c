#include <stdio.h>
int a[3] = { 2, 5, 7 };   //구슬
int b[3];          // 구슬을 담을 상자
int N = 3;      // 구슬 3개

void DFS(int n)    //n는 구슬(a배열의 index)
{
	int i;

	if (n == 3) {
		printf("%d %d %d\n", b[0],b[1],b[2]);
		return ;
	}
	for (i=0;i<2;i++) {
		if (i == 0) b[n] = a[n];
		else b[n] = 0;
		DFS(n+1);
	}
}
int main(void)
{
    DFS(0);   //a[0]번 구슬부터 조합
}