#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

int W, H, N;

int main(){
  cin >> W;
  cin >> H;
  cin >> N;

  vector<bool> w_list(W, false);
  vector<bool> h_list(H, false);

  int s, k;
  REP (i,0,N) {
    cin >> s;
    cin >> k;
    
    w_list[s-1] = true;
    h_list[k-1] = true;
  }
  
  int w_not_used_count = count(w_list.begin(), w_list.end(), false);
  int h_not_used_count = count(h_list.begin(), h_list.end(), false);

  cout << (W * H) - (w_not_used_count * h_not_used_count) - N << endl;
}
