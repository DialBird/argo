#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <getopt.h>

static void do_grep(regex_t *pat, FILE *src);
int swt = 0;

int main(int argc, char *argv[]){
  int opt;
  int err;
  int i;
  regex_t pat;

  if (argc < 2) exit(1);

  while ((opt = getopt(argc, argv, "iv")) != -1) {
    switch (opt) {
      case 'i':
        err = regcomp(&pat, argv[1], REG_EXTENDED | REG_NOSUB | REG_NEWLINE | REG_ICASE);
        break;
      case 'v':
        swt = 1;
        err = regcomp(&pat, argv[1], REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
        break;
      case '?':
        fprintf(stderr, "Usage: %s [-iv] [-f PATTERN] [<file>...]\n", argv[0]);
        exit(1);
        break;
      default:
        err = regcomp(&pat, argv[1], REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
    }
  }

  if (err != 0) {
    char buf[1024];

    regerror(err, &pat, buf, sizeof buf);
    puts(buf);
    exit(2);
  }

  if (argc == 2) {
    do_grep(&pat, stdin);
  } else {
    for (i=2;i<argc;i++) {
      FILE *fp;
      if ((fp = fopen(argv[i], "r")) == NULL) exit(3);
      
      do_grep(&pat, fp);
      fclose(fp);
    }
  }
  regfree(&pat);
  exit(0);
}

static void do_grep(regex_t *pat, FILE *src){
  char buf[4096];

  while (fgets(buf, sizeof buf, src)) {
    int match;
    match = regexec(pat, buf, 0, NULL, 0) == 0;
    if (swt) match = !match;
    if (match)
      fputs(buf, stdout);
  }
}
