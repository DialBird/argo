#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

long long N;
vector<bool> prime_check_list(10000000 + 1, true);
vector<int> prime_list;

int main(){
  cin >> N;

  int sqrt_n = sqrt(N);

  prime_check_list[0] = false;
  prime_check_list[1] = false;

  // Nの平方根までの素数を発見
  for (int i=2;i<=sqrt_n;i++) {
    if (prime_check_list[i]) {
      prime_list.push_back(i);
      for (int j=i*2;j<sqrt_n;j+=i) {
        prime_check_list[j] = false;
      }
    }
  }

  int count = 0;
  for (auto p: prime_list) {
    while (N % p == 0) {
      N /= p;
      count++;
    }
    if (N == 1) break;
  }

  if (count >= 3) {
    cout << "YES" << endl;
  } else if (count == 2 && N != 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
