#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;
const int MAX_N = 10000;

int x,N;

#define REP(i,first,last) for (int i=first;i<last;i++)

int pow(int x, int a) {
  int res = 1;
  if (a > 0) {
    res = pow(x*x, a/2);
    if (a & 1) res *= res;
  }
}

int main(){
  cin >> x;
  cin >> N;
  long hoge = 1;
  REP(j,0,N){
    hoge *= x;
    hoge %= 10;
  } 
  cout <<"result "<<hoge<<endl;
}
