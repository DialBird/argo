#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

const int MAX_N = 1000;
const int MAX_V = 100;
int N;
vector<int> v_list;
vector<int> dp(MAX_N + 1, -1);

int solve(int idx){
  if (idx >= N) return 0;
  if (dp[idx] != -1) return dp[idx];

  int res_1 = solve(idx + 1);
  int res_2 = solve(idx + 2) + v_list[idx];
  return dp[idx] = MAX(res_1, res_2);
}

int main(){
  cin >> N;

  int val;
  REP(i,0,N){
    cin >> val;
    v_list.push_back(val);
  }

  cout << solve(0) << endl;
}
