#include <stdio.h>
#include <string.h>
int main(void){
  char a, b, c, d, e;
  scanf("%c %c %c %c %c", &a, &b, &c, &d, &e);
  if (b == '+') {
    if (e == 'x') {
      printf("%d\n", (int)a + (int)c - (int)'0'*2);
    } else if (a == 'x') {
      printf("%d\n", (int)e - (int)c);
    } else {
      printf("%d\n", (int)e - (int)a);
    }
  } else {
    if (e == 'x') {
      printf("%d\n", (int)a - (int)c);
    } else if (a == 'x') {
      printf("%d\n", (int)c + (int)e - (int)'0'*2);
    } else {
      printf("%d\n", (int)a - (int)e);
    }
  }

  return 0;
}
