#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

#define REP(i,f,l) for(int i=f;i<l;i++)
#define FOR(it, con) for(auto it=con.begin();it!=con.end();it++)
#define MAX_N 100
#define MAX_M 100

array<int, 6> yens{500,100,50,10,5,1};
array<int, 6> yen_count;
int G;

int res = 10000;

int inject(array<int,6> count){
  int sum = 0;
  FOR(it,count){
    sum += *it; 
  }
  return sum;
}

void check(array<int,6> count, int sum){
  REP(i,0,6){
    array<int,6> new_count(count);
    int new_sum;
    if (new_count[i] < yen_count[i]) {
      new_count[i] += 1;
      new_sum = sum + yens[i];
      if (new_sum == G && inject(new_count) < res) {
        FOR(it,new_count){
          cout<<*it;
        }
        cout<<endl;
        res = inject(new_count);
      }else if (new_sum < G) {
        check(new_count, new_sum);
      }
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

  check(count, 0);

  if (res == 10000) {
    cout<<"ない"<<endl;
  }else {
    cout<<res<<endl;
  }
  return 0;
}

