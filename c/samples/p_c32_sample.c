#include <stdio.h>
#include <stdlib.h>

int main(void){
  char str[1000];
  int N, i;
  int total[4] = {0, 0, 0, 0};
  int res = 0;

  fgets(str, sizeof(str), stdin);
  N = atoi(str);

  //scanfはfgetsを含むが、whileが使えない
  for (i=0;i<N;i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    total[a] += b;
  }
  res = total[0]/100 * 5 + total[1]/100 * 3 + total[2]/100 * 2 + total[3]/100;
  printf("%d", res);
  return 0;
}
