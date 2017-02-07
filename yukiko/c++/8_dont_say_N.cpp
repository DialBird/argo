#include <iostream>
#include <vector>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

int P;

int main(){
  cin >> P;
  int n,k;
  REP (i,0,P) {
    cin >> n;
    cin >> k;
    if (k < n && n % (k + 1) == 1) {
      cout << "Lose" << endl;
    } else {
      cout << "Win" << endl;
    }
  }
}
