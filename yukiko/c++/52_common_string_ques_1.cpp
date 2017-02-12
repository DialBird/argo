#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;++i)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

string S;
vector<string> results;

int unq_count(vector<string> results){
  sort(results.begin(), results.end());

  int count = 1;
  for (int i=1;i<results.size();++i) {
    if (results[i-1].compare(results[i]) != 0) {
      ++count;
    }
  }
  return count;
}

void solve(string rest_str, string new_str){
  if (rest_str.empty()) {
    results.push_back(new_str);
    return;
  }

  string origin_rest_str = rest_str;
  string origin_new_str = new_str;

  char f_c = rest_str.front();
  rest_str.erase(rest_str.begin());
  new_str.push_back(f_c);
  solve(rest_str, new_str);
  rest_str = origin_rest_str;
  new_str = origin_new_str;

  char b_c = rest_str.back();
  rest_str.pop_back();
  new_str.push_back(b_c);
  solve(rest_str, new_str);
}

int main(){
  cin >> S;

  solve(S, "");
  
  cout << unq_count(results) << endl;
}
