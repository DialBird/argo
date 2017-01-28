#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,f,l) for(int i=f;i<l;i++)
#define FOR(it,con) for(auto it=con.begin();it != con.end(); it++)
using namespace std;

class ANDEquation{
  public:
    vector<int> split(vector<int> arr, int n);
    int restoreY(vector<int> a);
};

vector<int> ANDEquation::split(vector<int> arr, int n){
  vector<int> new_arr;
  REP(i,0,n){ new_arr.push_back(arr[i]); }
  REP(i,n+1,arr.size()){ new_arr.push_back(arr[i]); }
  return new_arr;
}

int ANDEquation::restoreY(vector<int> a){
  sort(a.begin(),a.end());
  FOR(it,a){
    int ans = *it;
    vector<int> rest = split(a, distance(a.begin(),it));
    int hikaku = rest[0];
    for(auto it_2=rest.begin()+1;it_2 != rest.end();it_2++){
      hikaku = hikaku & *it_2;
    }
    if (hikaku == ans) return ans;
  }
  return -1;
}
