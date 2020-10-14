#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a,b) {int t; t = (a); (a) = (b); (b) = t;}

int N, K;
char str[40];
int num[30];
int np;

void quick_sort(int s, int e, int * a)
{
	int i, P, T;

	P = e;
	if (s >= e) return;
	for (T = i = s; i < e; i++) {
		if (a[i] > a[P]) {
			SWAP(a[i], a[T]);
			T++;
		}
	}
	if (T != P) {
		SWAP(a[P], a[T]);
	}
	quick_sort(s, T - 1, a);
	quick_sort(T + 1, e, a);
}

int main(void)
{
	int i, j, k, cnt;
	scanf("%d%d", &N, &K);
	scanf("%s", str);
	for (i = 0; i < N / 4; i++) {
		str[N + i] = str[i];
		for (j = i; j < N; j += (N / 4)) {
			for (k = 0; k < N / 4; k++) {
				if (str[j + k] < 65) num[np] += str[j + k] - '0';
				else num[np] += str[j + k] - 'A' + 10;
				num[np] *= 16;
			}
			num[np] /= 16;
			np++;
		}
	}
	quick_sort(0, np - 1, num);
	cnt = 1;
	for (i = 1; i < np; i++) {
		if (num[i] != num[i - 1]) cnt++;
		if (cnt == K) {
			printf("%d", num[i]);
			break;
		}
	}
	return 0;
}