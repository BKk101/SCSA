#if 0

#include <stdio.h>
#define MAXN (100)
int L;//���� ���� �ʰ� �����ִ� �ִ�Ÿ�
int N;//����� ����
int dist[MAXN + 10];//����� ���̰Ÿ�
int time[MAXN + 10];//����ð�
int ans[MAXN + 10];
int rec[MAXN + 10];
int cnt;

void InputData(void) {
	scanf("%d", &L);
	scanf("%d", &N);
	for (int i = 1; i <= N + 1; i++) {
		scanf("%d", &dist[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &time[i]);
	}
}

int mintime(int n)
{
	int idx;
	int i = n;
	int min = 0x7fffffff;
	int dis = dist[i];
	while (dis <= L && i-- > 0) {
		if (ans[i] + time[i] < min) {
			min = ans[i] + time[i];
			idx = i;
		}
		dis += dist[i];
	}
	rec[n] = idx;
	return min;
}

void print(int i)
{
	if (i == 0) {
		printf("%d\n", cnt);
		return;
	}
	cnt++;
	print(rec[i]);
	printf("%d ", i);
}

int main(void)
{
	InputData();
	for (int i = 1; i <= N + 1; i++) {
		ans[i] = mintime(i);
	}
	printf("%d\n", ans[N + 1]);
	if (ans[N+1]) print(rec[N + 1]);
	return 0;
}

#endif
