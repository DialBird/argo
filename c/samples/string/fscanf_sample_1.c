#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]){
  char str[1000];
  scanf("%s", str);

  regex_t pat;
  /* int err; */
  /*  */
  /* err = regcomp(&pat, "noaki$", REG_EXTENDED | REG_NOSUB | REG_NEWLINE); */
  /* if (err != 0) { */
  /*   char buf[1024]; */
  /*   regerror(err, &pat, buf, sizeof buf); */
  /*   puts(buf); */
  /*   exit(1); */
  /* } */
  /*  */
  /* regmatch_t patternMatch[32]; */
  /* int matched; */
  /* matched = (regexec(&pat, str, 32, patternMatch, 0) == 0); */
  /* if (matched) { */
  /*   int new_len; */
  /*   new_len = sizeof (str) / sizeof(str[0]) - 5; */
  /*   printf("%d", new_len); */
  /* } else { */
  /*  */
  /* } */
  return 0;
}
