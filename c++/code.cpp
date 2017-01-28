#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)
#define FOR(it,con) for (auto it=con.begin();it!=con.end();it++)

const int devider = 1000002;
int x,N;
vector<int> amari_list(devider, -1);

int pow(long long x, int a){
  int res = 1;
  if (a > 0) {
    res = pow(x*x % (devider+1), a/2);
    if (a & 1) res = res*x % (devider+1);
  }
  return res % (devider+1);
}

int main(){
  cin >> x;
  cin >> N;
  x %= (devider+1);
  int val;
  long long result = 0;
  REP(i,0,N) {
    cin >> val;
    int target = val % devider;

    if (amari_list[target] == -1) {
      int amari = pow(x, target);
      amari_list[target] = amari;
    }
    result += amari_list[target];
    result %= (devider+1);
  }

  cout<<result % (devider + 1)<<endl;
}
