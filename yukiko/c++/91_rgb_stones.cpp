#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

vector<int> stones(3);

int check(int n){
  int lack = 0;
  int plus = 0;
  for (auto s: stones) {
    if (n <= s) {
      plus += (s - n) / 2;
    } else {
      lack += n - s;
    }
  }
  return lack <= plus;
}

int bs(int min, int max){
  int mid = (min + max) / 2;
  if (mid == min) {
    return mid;
  } else {
    return check(mid) ? bs(mid, max) : bs(min, mid);
  }
}

int main(){
  REP(i,0,3){ cin >> stones[i]; }
  auto max = max_element(stones.begin(), stones.end());
  auto min = min_element(stones.begin(), stones.end());

  cout << bs(*min, *max) << endl;
}
