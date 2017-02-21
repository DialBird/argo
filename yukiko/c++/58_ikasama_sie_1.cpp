#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

const int MAX_N = 10;
int N,K;

int main(){
  cin >> N >> K;

  double taro_dp[MAX_N+1][MAX_N*6+1] = {};
  double jiro_dp[MAX_N+1][MAX_N*6+1] = {};

  taro_dp[0][0] = 1;
  jiro_dp[0][0] = 1;

  // 太郎の結果
  for (int i=1;i<=N;++i) {
    for (int j=i;j<=N*6;++j) {
      if (i <= K) {
        for (int k=4;k<=6;++k) {
          if (j >= k) {
            taro_dp[i][j] += taro_dp[i-1][j-k] / 3.0;
          }
        }
      } else {
        for (int k=1;k<=6;++k) {
          if (j >= k) {
            taro_dp[i][j] += taro_dp[i-1][j-k] / 6.0;
          }
        }
      }
    }
  }

  //二郎の結果
  for (int i=1;i<=N;++i) {
    for (int j=i;j<=N*6;++j) {
      for (int k=1;k<=6;++k) {
        if (j >= k) {
          jiro_dp[i][j] += jiro_dp[i-1][j-k] / 6.0;
        }
      }
    }
  }

  double result = 0;

  for (int i=N;i<=N*6;++i) {
    for (int j=N;j<i;++j) {
      result += taro_dp[N][i] * jiro_dp[N][j];
    }
  }

  cout << result << endl;
}
