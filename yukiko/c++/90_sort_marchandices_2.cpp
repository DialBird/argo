#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N, M;
int scores[10][10];
vector<int> nums;

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

  int ans = 0;
  do {
    int sum = 0;
    REP(i,0,N-1){
      REP(j,i+1,N){
        sum += scores[nums[i]][nums[j]];
      }
    }
    ans = MAX(sum, ans);
  } while (next_permutation(nums.begin(), nums.end()));

  cout << ans << endl;
}
