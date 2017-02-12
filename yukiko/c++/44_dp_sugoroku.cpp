#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N;
long long dp[100][100];

long long calc(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];

  int total = x + 2*y;

  if (total > N) return 0;
  if (total == N) return 1;

  return dp[x][y] = calc(x+1, y) + calc(x, y+1);
}

int main(){
  cin >> N;

  REP(i,0,100){
    REP(j,0,100){
      dp[i][j] = -1;
    }
  }

  cout << calc(0,0) << endl;
}
