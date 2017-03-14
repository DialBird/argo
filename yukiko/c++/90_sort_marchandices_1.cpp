#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N, M;
int scores[10][10];
vector<int> nums;
vector<int> made;
vector<int> fl(9, 0);
int ans = 0;

void solve(int cnt){
  if (cnt >= N) {
    int sum = 0;
    REP(i,0,N-1){
      REP(j,i+1,N){
        sum += scores[made[i]][made[j]];
      }
    }
    ans = MAX(sum, ans);
    return;
  }

  REP(i,0,N){
    if (fl[i] != 1) {
      fl[i] = 1;
      made.push_back(nums[i]);
      solve(cnt + 1);
      made.pop_back();
      fl[i] = 0;
    }
  }
}

int main(){
  cin >> N >> M;

  REP(i,0,N){
    nums.push_back(i);
  }

  int it_1, it_2, s;
  REP(i,0,M){
    cin >> it_1 >> it_2 >> s;
    scores[it_1][it_2] = s;
  }

  solve(0);
  cout << ans << endl;
}
