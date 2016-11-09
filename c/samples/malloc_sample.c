#include <stdio.h>
#include <stdlib.h>

int main(void){
  //mallocが返すのはポインターなので、この形
  int *ip;
  //int[10]と同じ領域が欲しい場合はこのように打つ
  ip = malloc(10*sizeof(int));
  ip[0] = 123;

  //格納したい場合はこのようにする（取り出す場合も同様）
  int i;
  for (i=1;i<10;i++) {
    ip[i*sizeof(int)] = 3;
  }


  char **cm;

  cm = malloc(10*sizeof(char*));

  for (i=0;i<10;i++) {
    cm[i*sizeof(char*)] = "hogefuga";
  }
  printf("%d\n", sizeof(char*));
  for (i=0;i<10;i++) {
    puts(cm[i*sizeof(char*)]);
  }
  
  exit(0);
}
