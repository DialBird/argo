#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>


int main(int argc, char *argv[]){
  int err;
  char str[] = "hogefuga";
  regex_t pat;
  regmatch_t match[5];
  err = regcomp(&pat, "hoge", REG_EXTENDED);
  if (err != 0) {
    char buf[1024];
    regerror(err, &pat, buf, sizeof buf);
    puts(buf);
    exit(1);
  }
  if (!regexec(&pat, str, 5, match, 0)){
    puts("hit");
    int i;
    for (i=match[0].rm_so;i<match[0].rm_eo;i++) {
      putchar(str[i]);
    }
    putchar('\n');
  } else {
    puts("no hit");
  }
  REG_NOMATCH;
  exit(0);
}
