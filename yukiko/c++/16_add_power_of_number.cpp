#include <iostream>
#include <vector>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

const int devider = 1000003;
int x, N;
vector<int> dp(devider-1, -1);

int my_pow(long long x, int idx){
  int res = 1; 
  if (idx > 0) {
    res = my_pow(x*x % devider, idx/2);
    if (idx & 1) res = res * x % devider;
  }
  return res % devider;
}

int main(){
  cin >> x;
  cin >> N;
  x %= devider;

  int val;
  int amari;
  long long total = 0;

  REP(i,0,N) {
    cin >> val;
    amari = val % (devider - 1);
    if (dp[amari] == -1) {
      dp[amari] = my_pow(x, amari);
    }
    total += dp[amari];
    total %= devider;
  }

  cout << (total % devider) << endl;
}
