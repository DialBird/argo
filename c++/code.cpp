#include <iostream>
#include <vector>

using namespace std;

#define REP(i,f,l) for (int i=f;i<l;i++)

int N;
int c = 0;

void check(){
  char t;
  int total = 0;
  int s_total,l_total;
  vector<int> points(5);
  cin>>t;
  REP(i,0,5) {
    cin>>points[i];
    total += points[i];
  }

  if (total < 350) return;

  s_total = points[1] + points[2];
  l_total = points[3] + points[4];
  if (t == 's' && s_total >= 160) c++;
  if (t == 'l' && l_total >= 160) c++;
}

int main(){
  cin>>N;
  REP(i,0,N) {
    check();
  } 
  cout<<c<<endl;
  return 0;
}
