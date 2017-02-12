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

  solve(rest_str.substr(1), new_str + rest_str[0]);
  solve(rest_str.substr(0, rest_str.size()-1), new_str + rest_str[rest_str.size()-1]);
}

int main(){
  cin >> S;

  solve(S, "");
  
  cout << unq_count(results) << endl;
}
