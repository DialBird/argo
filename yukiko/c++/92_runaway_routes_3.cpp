#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N,M,K;

int main(){
  cin >> N >> M >> K;
  vector<int> a(M), b(M), c(M);
  REP(i,0,M){ 
    cin >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
  }

  vector<int> d_list(K);
  REP(i,0,K){ cin >> d_list[i]; }

  bool candidate_towns[N];
  bool rest_towns[N];
  REP(i,0,N){
    candidate_towns[i] = true;
    rest_towns[i] = false;
  }

  REP(i,0,K){
    REP(j,0,M){
      if (c[j] != d_list[i]) continue;

      rest_towns[a[j]] |= candidate_towns[b[j]];
      rest_towns[b[j]] |= candidate_towns[a[j]];
    }
    REP(j,0,N){
      candidate_towns[j] = rest_towns[j];
      rest_towns[j] = false;
    }
  }

  int cnt = 0;
  REP(i,0,N){
    if (candidate_towns[i]) ++cnt;
  }
  cout << cnt << endl;

  REP(i,0,N){
    if (candidate_towns[i]) {
      cout << i+1 << " ";
    }
  }
  cout << endl;
}
