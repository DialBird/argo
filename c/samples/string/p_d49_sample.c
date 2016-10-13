#include <stdio.h>
#include <string.h>

int main(void){
  //1000バイト分確保
  char str[1000];
  char *tp;
  char *pat = "noaki\n";
  
  fgets(str, sizeof(str), stdin);

  if (strlen(str) >= 5) {
    //一度\nの後ろまでポインタを進め、取得したい部分の最初のアドレスまで戻る
    tp = str + strlen(str) - 6;

    //strcmpでnpに格納されたアドレスと文字列が等しいかを比較する(文字列なのでポインタを渡す)
    if (strcmp(np, pat) == 0) {
      *tp = '\0';
    }
  }
  puts(str);
  return 0;
}
