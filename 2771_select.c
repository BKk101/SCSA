#include <stdio.h>
int a[3] = { 2, 5, 7 }; // 구슬
int b[3];     // 구슬을 담을 상자
int chk[3];     // 체크배열
int N = 3;      // 구슬은 3개
void DFS(int n)
{
	int i;

	if (n == 3) {
		for (i=0;i<3;i++) printf("%d ", b[i]);
		printf("\n");
		return ;
	}
	for (i=0;i<3;i++) {
		if (chk[i] == 1) continue;
		b[n] = a[i];
		chk[i] = 1;
		DFS(n+1);
		chk[i] = 0;
	}
}
int main(void)
{
    DFS(0);      // b[0]번 방에 담기 시작
}