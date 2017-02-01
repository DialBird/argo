#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

#define REP(i, first, last) for(int i=first;i<last;i++)

const int MAX_N = 10000;
vector<int> dp(MAX_N + 1, 0);
int N;

int bit_num(int n) {
  int count = 0;
  while (n > 0) {
    n &= n - 1;
    count++;
  }
  return count;
}

int solve(int N){
  queue<int> que;
  que.push(1);
  while (!que.empty()) {
    int q = que.front();
    int move_count = bit_num(q);
    array<int, 2> list{move_count, -move_count};
    for (auto li: list) {
      if ((q+li) == N) {
        return dp[q] + 1;
      } else if (0 < (q+li) && (q+li) < N && dp[q+li] == 0) {
        dp[q+li] = dp[q] + 1;
        que.push(q+li);
      }
    }
    que.pop();
  }
  return -1;
}

int main() {
  dp[1] = 1;
  cin >> N;
  if (N == 1) {
    cout << 1 << endl;
  } else {
    cout << solve(N) << endl;
  }
}
