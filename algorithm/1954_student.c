#include <stdio.h>
#define SWAP(a,b) {Stu t; t = (a); (a) = (b); (b) = t;}

typedef struct stu
{
	int score;
	int id;
}Stu; 

Stu arr[30001];

void quick_sort(int s, int e, Stu * a)
{
	int T,P=e;
	int l;

	if (e <= s) return ;
	for (l=T=s;l<e;l++) {
		if (a[l].score>a[P].score) {
			SWAP(a[l],a[T]);
			T++;
		}
		else if (a[l].score == a[P].score && a[l].id < a[P].id) {
			SWAP(a[l],a[T]);
			T++;
		}
	}
	if (P != T) SWAP(a[P], a[T]);
	quick_sort(s,T-1,a);
	quick_sort(T+1,e,a); 
}

int main(void)
{
	int N;
	int i;
	int ans[3];

	scanf("%d", &N);
	for (i=0;i<N;i++) {
		scanf("%d", &arr[i].score);
		arr[i].id = i+1;
	}
	quick_sort(0,N-1,arr);
	printf("%d %d %d", arr[0].id, arr[1].id, arr[2].id);
	return 0;
}