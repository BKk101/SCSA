#if 0

#include <stdio.h>
#define SWAP(a,b) {int t; t = (a); (a) = (b); (b) = t;}

int M, N, L;
int X[100000 + 10];
int A[100000 + 10];
int B[100000 + 10];

void InputData(void) {
	scanf("%d %d %d", &M, &N, &L);
	for (int i = 0; i < M; i++) {
		scanf("%d", &X[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i], &B[i]);
	}
}

void quick_sort(int s, int e, int * a)
{
	int T, P = e;
	int l;

	if (e <= s) return;
	for (l = T = s; l < e; l++) {
		if (a[l] < a[P]) {
			SWAP(a[l], a[T]);
			T++;
		}
	}
	if (P != T) SWAP(a[P], a[T]);
	quick_sort(s, T - 1, a);
	quick_sort(T + 1, e, a);
}

int main(void) {
	int ans = 0;
	int up, down;
	int high, low, mid;

	InputData();// 입력받는 부분
	quick_sort(0, M - 1, X);
	for (int i = 0; i < N; i++) {
		if (B[i] > L) continue;
		up = A[i] + L - B[i]; down = A[i] - (L - B[i]);
		low = 0; high = M - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (X[mid] < down) {
				low = mid + 1;
			}
			else if (X[mid] >= down && X[mid] <= up) {
				++ans;
				break;
			}
			else if(X[mid] > up) {
				high = mid - 1;
			}

		}
	}
	printf("%d\n", ans);// 출력하는 부분
	return 0;
}

#endif
