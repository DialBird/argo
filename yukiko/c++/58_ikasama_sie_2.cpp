#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <random>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N, K;
int trial = 9000000;

// xからyまでをランダムに出力する
auto random_range = [](int x, int y) {
  return rand() % (y - x + 1) + x;
};

int main(){
  cin >> N >> K;

  int taro_win = 0.0;

  REP(i,0,trial) {
    int taro_result = 0;

    REP(i,0,N){
      if (i < K) {
        taro_result += random_range(4, 6);
      } else {
        taro_result += random_range(1, 6);
      }
    }

    int jiro_result = 0;

    // 太郎のと一緒にすると、ランダム値が大体一緒になってしまうから
    REP(i,0,N){
      jiro_result += random_range(1, 6);
    }

    if (taro_result > jiro_result) ++taro_win;
  }

  printf("%.5f\n", (double)taro_win / trial);
}
