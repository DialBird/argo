#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *xmalloc(size_t size){
  void *m = malloc(size);
  if (!m) {
    perror("malloc()");
    exit(1);
  }
  return m;
}

int main(int argc, char *argv[]){
  char S[50001];
  int M;
  fscanf(stdin, "%s", S);
  fscanf(stdin, "%d", &M);
  int i;
  char *point = (char*)xmalloc(sizeof(char*));
  char str[11];
  int count = 0;
  for (i=0;i<M;i++) {
    fscanf(stdin, "%s", str);
    point = S;
    while ((point = strstr(point, str)) != NULL) {
      count++;
      point += 1;
    }
  }
  free(point);
  printf("%d\n", count);
  exit(0);
}
