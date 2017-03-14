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

  int atari = 0;

  // 一箱目を食べきるのに必要な買う本数
  int first_buy = 0;
  int first_atari = 0;
  REP(i,0,N){
    if (atari > 0) {
      --atari;
    } else {
      ++first_buy;
    }
    atari += ice_box[i] - '0';
  }
  first_atari = atari;

  // 二箱目以降を食べきるのに必要な買う本数
  atari = first_atari;
  int second_buy = 0;
  REP(i,0,N){
    if (atari > 0) {
      --atari;
    } else {
      ++second_buy;
    }
    atari += ice_box[i] - '0';
  }

  // 最後となる
  atari = K < N ? 0 : first_atari;
  int last_buy = 0;

  REP(i,0,K % N){
    if (atari > 0) {
      --atari;
    } else {
      ++last_buy;
    }
    atari += ice_box[i] - '0';
  }

  if (K < N) {
    cout << last_buy << endl;
  } else {
    cout << first_buy + ((K / N) - 1) * second_buy + last_buy << endl;
  }
}
