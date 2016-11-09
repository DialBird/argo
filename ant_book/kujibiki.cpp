#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int m;
vector<int> k;
vector<int> kk;

bool binary_search(int x){
  int l = 0;
  int r = n*n;
  while (r - l >= 1) {
    int i = (r + l)/2;
    if (kk[i] == x) return true;
    else if (kk[i] < x) l = i + 1;
    else r = i;
  }
  return false;
}

int main(){
  cin>>n;
  cin>>m;
  for (int i=0;i++<n;) {
    int val;
    cin>>val;
    k.push_back(val);
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      kk.push_back(k[i] + k[j]);
    }
  }

  sort(kk.begin(), kk.end());
  unique(kk.begin(), kk.end());

  bool f = false;

  for (int i=0;i<n*n;i++) {
    if (binary_search(m-kk[i])) {
        f = true;
    }
  }

  if (f) puts("Yes");
  else puts("No");
  return 0;
}
