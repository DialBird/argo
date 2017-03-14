#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N;

int main(){
  cin >> N;
  vector<int> blocks(N);
  int sum = 0;

  REP(i,0,N){
    cin >> blocks[i];
    sum += blocks[i];
  }

  // ピラミッド構成ブロックの数はnの二乗になり、それぞれのピラミッドの最も高い列はn個のブロックになる
  // そして、与えられたブロックの合計値でできるもっとも大きいピラミッドを作るのが最短
  // この作業は各列の「余っているブロック」のみ動かすので、余っているブロックをカウントすればいい。
  int p_top_num = sqrt(sum);
  int p_row_cnt = 1 + (p_top_num - 1) * 2;

  int required = 1;
  int amari = 0;

  REP(i,0,p_top_num){
    if (i < N && required <= blocks[i]) {
      amari += blocks[i] - required;
    }
    ++required;
  }

  required = p_top_num - 1;
  REP(i,p_top_num,p_row_cnt){
    if (i < N && required <= blocks[i]) {
      amari += blocks[i] - required;
    }
    --required;
  }

  REP(i,p_row_cnt,N){
    amari += blocks[i];
  }

  cout << amari <<endl;
}
