#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N, K;

int main(){
  cin >> N >> K;
  vector<char> ice_box(N);

  REP(i,0,N){
    cin >> ice_box[i];
  }

  // 一箱目を食べきるのに必要な買う本数
  int box_buy = 0;
  // 一箱食べ終わった時に残っている当たり本数
  int box_atari = 0;
  // N本アイスを食べるために買う必要がある本数
  vector<int> necessary_buys(N + 1);

  REP(i,0,N){
    if (box_atari > 0) {
      --box_atari;
    } else {
      ++box_buy;
    }
    necessary_buys[i + 1] = box_buy;
    box_atari += ice_box[i] - '0';
  }

  if (K <= N) {
    cout << necessary_buys[K] << endl;
  } else {
    int interval_buy = MAX(0, box_buy - box_atari);
    int last_buy = MAX(0, necessary_buys[K % N] - box_atari);
    cout << box_buy + ((K / N) - 1) * interval_buy + last_buy << endl;
  }
}
