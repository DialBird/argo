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

int N;
int half = 0;
vector<int> weights;
vector<bool> dp(10001, false);

int main(){
  cin >> N;
  int total = 0;
  REP(i,0,N){
    int val;
    cin >> val;
    weights.push_back(val);
    total += val;
  }
  if (total & 1) {
    cout << "impossible" << endl;
  } else {
    half = total >> 1;
    dp[0] = true;

    for (auto w: weights) {
      for (int i=10000-w;i>=0;--i) {
        if (dp[i]) dp[i+w] = true;
        if (dp[half]) break;
      }
      if (dp[half]) break;
    }

    if (dp[half]) {
      cout << "possible" << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
}
