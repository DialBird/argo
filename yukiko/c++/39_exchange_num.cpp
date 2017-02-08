#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

int N;

vector<int> convert_int_to_vector(int n){
  vector<int> result;
  string num_string = to_string(n);

  for (auto c: num_string) {
    result.push_back(c - '0');
  }

  return result;
}

int main(){
  cin >> N;
  
  vector<int> n_vec = convert_int_to_vector(N);

  // 最初から最後から二番目までの数字に対して実行する
  for (int i=0;i<n_vec.size() - 1;i++) {
    int target = n_vec[i];
    auto max_it = max_element(next(n_vec.begin(), i+1), n_vec.end());

    if (target < *max_it) {
      int another_target_idx;
      for (int j=i+1;j<n_vec.size();j++) {
        if (n_vec[j] == *max_it) another_target_idx = j;
      }
      n_vec[i] = n_vec[another_target_idx];
      n_vec[another_target_idx] = target;
      break;
    }
  }

  // 入れ替えたint配列をint型に変換する
  int result;
  stringstream ss;
  for (int i: n_vec) {
    ss << i;
  }
  ss >> result;

  cout << result << endl;
}
