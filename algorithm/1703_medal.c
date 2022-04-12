#include <stdio.h>
 
int medal[3][10];

typedef struct man
{
      int id;
      int score;
}Man;

void sort_a(Man * a, int n)
{
      int i,j;
      Man temp;

      for (i=n-1;i>0;i--) {
            for (j=0;j<i;j++) {
                  if (a[j].score < a[j+1].score) {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                  }
            }
      }
}

int main(void)
{
      // 여기서부터 작성
      int i, j, k, n;
      Man man[10] = {0};
      int temp;
      char *p[] = {"GOLD : ", "SILVER : ", "BRONZE : "};

      scanf("%d", &n);
      for (i=0;i<n;i++) {
            scanf("%d", &man[i].id);
            for (j=0;j<4;j++) {
                  scanf("%d", &temp);
                  man[i].score += temp;
            }
      }
      sort_a(man, n);
      //for (i=0;i<n;i++) printf("%d %d\n", man[i].id, man[i].score);
      for (i=0, j=0, k=0;i<n;i++) {
            medal[j][k] = man[i].id;
            if (man[i].score != man[i+1].score) {
                  j++;
                  k = 0;
            }
            else k++;
      }
      for (i=0;i<3;i++) {
            printf("%s", p[i]);
            for (j=0;j<10;j++) {
                  if (medal[i][j] != 0)
                        printf("%d ", medal[i][j]);
            }
            printf("\n");
      }
      return 0;
}