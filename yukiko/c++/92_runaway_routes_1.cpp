#include <bits/stdc++.h>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N,M,K;

int main(){
  cin >> N >> M >> K;

  vector<map<int, vector<int>>> G(N);
  REP(i,0,M){
    int a,b,c;
    cin >> a >> b >> c;
    --a;
    --b;
    G[a][c].push_back(b);
    G[b][c].push_back(a);
  }

  vector<int> d_list(K);
  REP(i,0,K){ cin >> d_list[i]; }

  set<int> candidate_towns;
  REP(i,0,N){ candidate_towns.insert(i); }

  for (int d: d_list) {
    set<int> rest_towns;
    for (int c: candidate_towns) {
      if (!G[c][d].empty()) {
        for (int t: G[c][d]) {
          rest_towns.insert(t);
        }
      }
    }
    candidate_towns = rest_towns;
  }

  cout << candidate_towns.size() << endl;
  for (int c: candidate_towns) {
    cout << c + 1 << " ";
  }
  cout << endl;
}
