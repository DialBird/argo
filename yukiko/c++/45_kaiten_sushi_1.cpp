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
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

int solve(int idx, int total){
  if (idx >= N) return total;
  if (dp[idx][total]) return dp[idx][total];

  int res_1 = solve(idx + 1, total);
  int res_2 = solve(idx + 2, total + v_list[idx]);
  return dp[idx][total] = MAX(res_1, res_2);
}

int main(){
  cin >> N;

  int val;
  REP(i,0,N){
    cin >> val;
    v_list.push_back(val);
  }

  cout << solve(0, 0) << endl;
}
