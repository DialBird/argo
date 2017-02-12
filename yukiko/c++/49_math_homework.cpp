#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x < y ? x : y)

int main(){
  int first_num;
  string str;

  cin >> first_num;
  cin >> str;

  char next_operator;
  int next_int;
  int result = first_num;
  stringstream ss(str);

  while (ss.peek() != -1) {
    ss >> next_operator;
    ss >> next_int;

    if (next_operator == '*') {
      result += next_int;
    } else {
      result *= next_int;
    }
  }

  cout << result << endl;
}
