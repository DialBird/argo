#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N, M;
int scores[10][10];
int dp[1 << 9];

int main(){
  cin >> N >> M;

  int it_1, it_2, s;
  REP(i,0,M){
    cin >> it_1 >> it_2 >> s;
    scores[it_1][it_2] = s;
  }

  REP(bits,0,1<<N){
    int max = 0;
    REP(i,0,N){
      if ((bits & (1 << i)) == 0) continue;
      int plus = 0;
      REP(j,0,N){
        if ((bits & (1 << j)) == 0 || j == i) continue;
        plus += scores[i][j];
      }
      max = MAX(dp[bits ^ (1 << i)] + plus, max);
    }
    dp[bits] = max;
  }

  cout << dp[(1 << N) - 1] << endl;
}
