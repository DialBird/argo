#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void do_head(FILE *fp, int nlines);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("wrong argument");
    exit(1);
  }
  int nlines = atoi(argv[1]);
  FILE *fp;
  if ((fp = fopen(argv[2], "r")) != NULL) {
    do_head(fp, nlines);
  }
  exit(0);
}

static void do_head(FILE *fp, int nlines){
  char *str[nlines];
  char buf[1024];
  int count = 0;
  int i,j;
  char *p;

  while (fgets(buf, sizeof buf, fp) != NULL) {
    buf[strlen(buf) - 1] = '\0';
    p = malloc(100);
    strcpy(p, buf);
    str[count % nlines] = p;
    count++;
  }
  if (count < nlines) {
    for (i=0;i<count;i++) {
      printf("%s", str[i]);
    }
  } else {
    for (j=count;j<count + nlines;j++) {
      puts(str[j % nlines]);
    }
  }
  free(p);
}
