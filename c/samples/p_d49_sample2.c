#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(void){
  //stdin用の容量
  char str[1000];

  //regex系の容量
  char buf[1000];
  regex_t preg;
  //noaki\nで6個分
  regmatch_t match[6];
  char *pat = "noaki\n$";
  int err;

  fgets(str, sizeof str, stdin);
  if ((err = regcomp(&preg, pat, REG_EXTENDED)) != 0) {
    regerror(err, &preg, buf, sizeof buf);
    puts(buf);
    exit(1);
  }
  if (regexec(&preg, str, 6, match, 0) == 0) {
    str[match[0].rm_so] = '\0';
  }
  puts(str);
  return 0;
}
