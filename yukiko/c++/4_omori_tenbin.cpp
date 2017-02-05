#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

int N;
int half = 0;
vector<int> weights;
//idxは100、totalは10000を取るので、これがないとRuntimeErrorになる
int dp[101][10001] = {};

bool solve(int idx, int total){
  if (dp[idx][total] == 1) return false;
  if (idx >= N || total > half) return false;

  int new_total = total + weights[idx];
  if (new_total == half) {
    return true;
  } else if (solve(idx + 1, total) || solve(idx + 1, new_total)) {
    return true;
  } else {
    // index（深さ）とその時のtotalの組み合わせはソーとしていることで結構見つかりやすい
    dp[idx][total] = 1;
    return false;
  }
}

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
    sort(weights.begin(), weights.end());
    if (solve(0,0)) {
      cout << "possible" << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
}
