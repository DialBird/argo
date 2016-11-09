#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int i,j, N;
  fscanf(stdin, "%d", &N);

  int point = 0;
  int count = 0;
  for (i=0;i<N;i++) {
    char a[21], b[21];
    fscanf(stdin, "%s %s", a, b);
    if (strlen(a) != strlen(b)) continue;
    count = 0;
    for (j=0;j<strlen(a);j++) {
      if (a[j] != b[j]) count++;
    }
    if (count == 0) {
      point += 2;
    } else if (count == 1) {
      point += 1;
    }
  }

  printf("%d", point);
  return 0;
}
