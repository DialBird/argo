#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define REP(i,f,l) for(int i=f;i<l;i++)
#define FOR(it, con) for(auto it=con.begin();it!=con.end();it++)
#define MAX_N 100
#define MAX_M 100

int M,N;
char field[MAX_N][MAX_M+1];
// vector<int> A;

void check(int x, int y){
  field[x][y] = '.';

  REP(dx,-1,2){
    REP(dy,-1,2){
      int nx = x + dx;
      int ny = y + dy;
      if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') check(nx, ny);
    }
  }
}

int main(){
  int res;
  cin>>N; 
  cin>>M; 
  REP(i,0,N){
    REP(j,0,M){
      char val;
      cin>>val;
      field[i][j] = val;
    }
  }

  REP(i,0,N){
    REP(j,0,M){
      if (field[i][j] == 'W') {
        cout<<"come"<<endl;
        check(i,j);
        res++;
      }
    }
  }
  cout<<res<<endl;
}
