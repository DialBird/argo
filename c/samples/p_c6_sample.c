#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  char str[1000];
  int pal_n, user_n, top_n;
  int i,j, count;

  //初期化情報を取得
  fgets(str, sizeof(str), stdin);
  //stringにたいしてはsscanf
  sscanf(str, "%d %d %d", &pal_n, &user_n, &top_n);

  //初期化情報を元に配列を初期化
  double points[pal_n];
  int totals[user_n];

  //pointに格納する値を取得して格納
  fgets(str, sizeof(str), stdin);
  char *p;
  count = 1;
  p = strtok(str, " ");
  points[0] = atof(p);
  //strtokはNULLを徹底的注意する
  while (p != NULL) {
    p = strtok(NULL," ");
    if (p != NULL) {
      points[count] = atof(p);
      count++;
    }
  }

  //totalsに格納する値を計算して格納
  double total = 0.0;
  for (i=0;i<user_n;i++) {
    total = 0.0;
    fgets(str, sizeof(str), stdin);
    count = 1;
    p = strtok(str, " ");
    total += atoi(p) * points[0];
    while (p != NULL) {
      p = strtok(NULL, " ");
      if (p != NULL) {
        total += atoi(p) * points[count];
        count++;
      }
    }
    totals[i] = round(total);
  }

  int len = sizeof(totals)/sizeof(totals[0]);
  int tmp;
  for (i=0; i<len; ++i) {
    for (j=i+1; j<len; ++j) {
      if (totals[i] < totals[j]) {
        tmp =  totals[i];
        totals[i] = totals[j];
        totals[j] = tmp;
      }
    }
  }

  for (i=0;i<top_n;i++) {
    printf("%d\n", totals[i]);
  }
  return 0;
}
