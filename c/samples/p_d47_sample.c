#include <stdio.h>
#include <stdlib.h>

int main(void){
  char str[1000];
  int count = 0;
  char *color[3] = {"Gold", "Silver", "Bronze"};

  while (fgets(str, sizeof(str), stdin) != NULL) {
    //文字連結はprintf
    printf("%s %s", color[count], str);
    count++;
  }
  return 0;
}
