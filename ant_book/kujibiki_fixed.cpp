#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(it, container) for(auto it = container.begin();it!=container.end();it++)
#define REP(i, n) for(int i=0;i<n;i++)

int main(){
  vector<int> k;
  vector<int> kk;
  int m,n;
  cin>>m;
  cin>>n;
  REP (i, n) {
    int val;
    cin>>val;
    k.push_back(val);
  }
  FOR (f_it, k) {
    FOR (s_it, k) {
      kk.push_back(*f_it + *s_it);
    }
  }
  sort(kk.begin(), kk.end());
  unique(kk.begin(), kk.end());
  bool f = false;

  FOR (it, kk) {
    if (find(kk.begin(), kk.end(), m - *it) != kk.end()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
  }
}

