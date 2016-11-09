#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int compare_int(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

static void *xmalloc(size_t size){
    void *p = malloc(size);
    if (!p) {
        perror("malloc()");
        exit(1);
    }
    return p;
}

static void read_item_points(double *points, int count){
    int i;
    for (i=0;i<count;i++)
        fscanf(stdin, "%lf", &points[i]);
}

static void get_user_totals(int *totals, double *points, int pal_n, int user_n){
    int i, j;
    int tmp;
    double total = 0;
    for (i=0;i<user_n;i++) {
        total = 0;
        for (j=0;j<pal_n;j++) {
            fscanf(stdin, "%d", &tmp);
            total += tmp * points[j];
        }
        totals[i] = round(total);
    }
}

int main(void){
    int pal_n, user_n, top_n;
    int i;

    //初期化情報を取得
    fscanf(stdin, "%d %d %d", &pal_n, &user_n, &top_n);

    //初期化情報を元に配列を初期化
    double *points = xmalloc(sizeof(double) * pal_n);
    int *totals = xmalloc(sizeof(int) * user_n);

    //pointに格納する値を取得して格納
    read_item_points(points, pal_n);

    //totalsに格納する値を計算して格納
    get_user_totals(totals, points, pal_n, user_n);

    qsort(totals, user_n, sizeof(int), compare_int);

    for (i=0;i<top_n;i++) {
        printf("%d\n", totals[i]);
    }
    return 0;
}
