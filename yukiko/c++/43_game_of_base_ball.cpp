#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int N;
vector<char> game_board;

int calc(vector<char> gb){
  vector<int> points(N, 0);
  int count = 0;

  for (int i=0;i<N-1;i++) {
    for (int j=i+1;j<N;j++) {
      if (gb[count] == 'o') {
        points[i] += 1;
      } else {
        points[j] += 1;
      }
      count++;
    }
  }

  int zero_result = points[0];

  sort(points.begin(), points.end());

  int order = 1;
  for (auto a: points) {
    if (zero_result < a) {
      zero_result = a;
      order++;
    }
  }
  return order;
}

int get_order(vector<char> gb, int idx){
  if (idx == gb.size()){
    return calc(gb);
  }
  
  int result = 0;
  if (gb[idx] == '-') {
    vector<char> gb_1 = gb;
    gb_1[idx] = 'o';
    vector<char> gb_2 = gb;
    gb_2[idx] = 'x';

    int res_1 = get_order(gb_1, idx + 1);
    int res_2 = get_order(gb_2, idx + 1);

    //関数を直接入れると遅くなる
    return MIN(res_1, res_2);
  } else {
    return get_order(gb, idx + 1);
  }
}

int main(){
  cin >> N;

  char val;
  REP(i,0,N) {
    REP(j,0,N) {
      cin >> val;
      if (i < j) game_board.push_back(val);
    }
  }

  cout << get_order(game_board, 0) << endl;
}
