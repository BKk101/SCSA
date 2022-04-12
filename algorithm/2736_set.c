#include <stdio.h>

int N;
int card[30][4];
int chk[30];
int rec[3];
int comb[3000][3];
int cp;
int max;

int Check(int a, int b, int c)
{
	for (int i=0;i<4;i++) {
		if ((card[a][i] == card[b][i] && card[a][i] == card[c][i]) ||
		(card[a][i] != card[b][i] && card[a][i] != card[c][i] && card[b][i] != card[c][i])) continue;
		return 0;
	}
	return 1;
}

void Comb(void)
{
	for (int i=0;i<N-2;i++) {
		for (int j=i+1;j<N-1;j++) {
			for (int k=j+1;k<N;k++) {
				if (!Check(i,j,k)) continue;
				comb[cp][0] = i; comb[cp][1] = j; comb[cp][2] = k;
				cp++;
			}
		}
	}
}

void DFS2(int s, int cnt)
{
	if (cnt>(N-comb[0][0])/3) return ;
	if (cnt + (N-comb[s][0])/3 <= max ) return;
	if (cnt>max) max = cnt;
	for (int i=s;i<cp;i++) {
		if (chk[comb[i][0]] || chk[comb[i][1]] || chk[comb[i][2]]) continue;
		chk[comb[i][0]] = chk[comb[i][1]] = chk[comb[i][2]] = 1;
		DFS2(i+1, cnt+1);
		chk[comb[i][0]] = chk[comb[i][1]] = chk[comb[i][2]] = 0;
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int i=0;i<N;i++) {
		scanf("%1d%1d%1d%1d", &card[i][0],&card[i][1],&card[i][2],&card[i][3]);
	}
	Comb();
	DFS2(0,0);
	printf("%d", max);
	return 0;
}