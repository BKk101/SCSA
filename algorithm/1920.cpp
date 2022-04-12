#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int input[100001];

int comp(const void* a, const void* b) {
	if (*(int *)a > *(int *)b) return 1;
	else if (*(int *)a < *(int *)b) return -1;
	else return 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	//sort(input, input + n);
	qsort(input, n, sizeof(int), comp);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		if (binary_search(input, input + n, temp)) {
			printf("%d\n", 1);
		}
		else {
			printf("%d\n", 0);
		}
	}

	fclose(stdin);
	fclose(stdout);
}
