#include <stdio.h>
#include <stdlib.h>

int main(void){
  char str[1000];
  int capa;
  int N, i;

  fgets(str, sizeof(str), stdin);
  capa = atoi(str);

  fgets(str, sizeof(str), stdin);
  N = atoi(str);

  int hour, min, copies;
  int data[24] = {};

  for (i=0;i<N;i++) {
    scanf("%d%d%d", &hour, &min, &copies);
    if (data[hour] == 0) {
      data[hour] = copies;
    } else {
      data[hour] += copies;
    }

  }

  int result = 0;
  for (i=0;i<sizeof(data)/sizeof(data[0]);i++) {
    int need_time;
    need_time = data[i] % capa > 0 ? data[i] / capa + 1 : data[i] / capa;
    result += need_time;
  }
  printf("%d", result);
  return 0;
}
