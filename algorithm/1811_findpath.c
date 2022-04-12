#include <stdio.h>

int que[1010];
int rp,wp;
int N,K;
char code[1010][35];
int visit[1010];
int ans[1010];

int haming(int a, int b)
{
	int cnt=0;
	int i;

	for (i=0;i<K;i++)
		if (code[a][i] != code[b][i]) cnt++;
	return cnt;
}

int BFS(int si, int ei)
{
	int i;
	int hd;
	int q;

	que[wp++] = si;
	while (rp < wp) {
		q =que[rp++];
		if (q == ei) return 1;
		for (i=1;i<=N;i++) {
			hd = haming(q, i);
			if (hd != 1 || visit[i] != 0) continue;
			que[wp++] = i;
			visit[i] = q;
		}
	}
	return 0;
}

void print_path(int s, int n)
{
	if (n == s) {printf("%d ", s); return;}
	print_path(s, visit[n]);
	printf("%d ", n);
}

int main(void)
{
	int i;
	int si,ei;

	scanf("%d%d", &N,&K);
	for (i=1;i<=N;i++)
		scanf("%s", code[i]);
	scanf("%d%d", &si,&ei);
	if (BFS(si, ei) == 0) printf("-1");
	else print_path(si, ei);
}