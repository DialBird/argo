#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char str[1000];
    char *sp;
    int num;
    char *tani[3] = {"km", "m", "cm"};

    fgets(str, sizeof(str), stdin);
    //改行をとる
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    
    //spaceで区切る
    sp = strchr(str, ' ');
    *sp = '\0';
    num = atoi(str);

    //stringにswitchは効かないので
    if (strcmp(sp + 1, tani[0]) == 0) {
        printf("%d", num * 1000000);
    } else if (strcmp(sp + 1, tani[1]) == 0) {
        printf("%d", num * 1000);
    } else {
        printf("%d", num * 10);
    }
    return 0;
}
