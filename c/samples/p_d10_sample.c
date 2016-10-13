#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  char str[1000];
  char *first;
  char *last;
  char *m;
  int count = 0;

  while (fgets(str, sizeof(str), stdin) != NULL) {
    str[strlen(str) - 1] = '\0';
    m = malloc(100);
    switch (count) {
      case 0:
        strcpy(m, str);
        first = m;
        break;
      case 1:
        strcpy(m, str);
        last = m;
        break;
    }
    count++;
  }

  printf("%s@%s", first, last);
  free(m);
  return 0;
}

