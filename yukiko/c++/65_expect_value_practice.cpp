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

const int MAX_K = 20;
int K;
vector<double> dp(MAX_K + 4, 0);

int main(){
  cin >> K;

  dp[K] = 0.0;
  dp[K - 1] = 1.0;

  for (int i=K-2;i>=0;i--) {
    for (int j=1;j<=6;j++) {
      dp[i] += dp[i+j] / 6;
    }
    dp[i] += 1;
  }

  cout << dp[0] << endl;
}
