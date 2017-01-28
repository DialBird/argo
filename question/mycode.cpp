#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef pair<int,int> p_ii;
#define REP(i,first,last) for (int i=first;i<last;i++)

int N;
char game_results[6][6], arr2[6][6], arr3[6][6];
//6チームそれぞれの勝ち点

// int points[6];
vector<p_ii> points = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}};
//6チームの残り試合表
int rest_games[6][6];

auto sort_with_value = [](p_ii x, p_ii y) -> bool {
  return x.second > y.second;
};

void test(char arr[6][6]){
  REP(i,1,N){
    REP(j,i+1,N){
      if (arr[i][j] == '-'){
        arr2 = arr;
        arr2[i][j] = 'o';
        arr2[j][i] = 'x';
        test(arr2);
        arr3 = arr;
        arr3[i][j] = 'x';
        arr3[j][i] = 'o';
        test(arr3);
        return;
      }
    }
  }

  REP(i,1,N){
    REP(j,0,N){
      if (arr[i][j] == 'o'){
        points[i].second += 1;
      }
    }
  }
}

int main(){
  cin>>N;
  char val;
  REP(i,0,N){
    REP(j,0,N){
      cin >> val;
      game_results[i][j] = val;
    }
  }
  //0のところの未試合を全て勝ちにする
  REP(i,0,N){
    if (game_results[0][i] == '-') {
      game_results[0][i] = 'o';
      game_results[i][0] = 'x';
    }
  }
  //残りの試合の全組み合わせを考える
  //一個一個交換
  REP(i,1,N){
    REP(j,i+1,N){
      if (game_results[i][j] == '-') {
        arr2 = game_results;
        arr2[i][j] = 'o';
        arr2[j][i] = 'x';
        test(arr2);
        arr3 = game_results;
        arr3[i][j] = 'x';
        arr3[j][i] = 'o';
        test(arr3);
      }
    }
  }

}
