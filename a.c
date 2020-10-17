#include <stdio.h>

/////////////////////////////////////////////////////////
// 1) 경로 체크 vs. 점 체크
// 2) visit 배열 초기화
/////////////////////////////////////////////////////////

int N, M, min, min_cnt;
int metro[100 + 10][100 + 10];
int visit[100 + 10][100 + 10];
int rec[110 * 110]; sol[110 * 110];

void Input_Value()
{
   scanf("%d %d", &N, &M);
   for (int i = 1; i <= N; i++)
   {
      for (int j = 1; j <= N; j++)
      {
         scanf("%d", &metro[i][j]);
      }
   }
}
void DFS(int line, int time, int cnt)
{
   if (line == M)
   {
      if (time < min)
      {
         min = time;
         min_cnt = cnt;
         for (int i = 0; i < cnt; i++) sol[i] = rec[i];
      }
      return;
   }
   if (time > min) return;
   for (int i = 1; i <= N; i++)
   {
      if (visit[line][i] == 1 || line == i) continue;
      visit[line][i] = 1; rec[cnt] = i;
      DFS(i, time + metro[line][i], cnt + 1);
      visit[line][i] = 0; rec[cnt] = 0;
   }
}
int main(void)
{
   Input_Value();
   min = 0x7ffffff; rec[0] = 1;
   DFS(1, 0, 1);
   printf("%d\n", min);
   for (int i = 0; i < min_cnt; i++) printf("%d ", sol[i]);
   return 0;
}