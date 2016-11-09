#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

#define REP(i,f,l) for(int i=f;i<l;i++)
#define FOR(it, con) for(auto it=con.begin();it!=con.end();it++)

array<int, 6> yens{500,100,50,10,5,1};
array<int, 6> yen_count;
int G;

array<int,6> ar;
int res;

int inject(array<int,6> count){
  int sum = 0;
  FOR(it,count){
    sum += *it; 
  }
  return sum;
}

void check(array<int,6> count, int rest){
  REP(i,0,6){
    int num = min(rest/yens[i], yen_count[i]);
    rest -= num*yens[i];
    count[i] += num;
    if (rest == 0) {
      ar = count;
      int sum = 0;
      for (int i=0;i<6;i++) {
        sum += count[i];
      }
      res = sum;
      break;
    }
  }
}

int main(){
  REP (i,0,6) {
    int val;
    cin>>val;
    yen_count[i] = val;
  }
  reverse(yen_count.begin(), yen_count.end());
  cin>>G;

  array<int,6> count{};

  check(count, G);

  if (res == 0) {
    cout<<"ない"<<endl;
  }else {
    cout<<res<<endl;
    FOR(it,ar){
      cout<<*it<<" ";
    }
    cout<<endl;
  }
  return 0;
}

