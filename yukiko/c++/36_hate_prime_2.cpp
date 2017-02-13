#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

long long N;

//素因数分解
vector<int> factor(long n){
  vector<int> res;
  int num = 2;
  int sqrt_n = sqrt(n);
  while (true) {
    if (n == 1) break;
    if (num > sqrt_n) {
      res.push_back(n);
      break;
    }

    while (n % num == 0) {
      n /= num;
      res.push_back(num);
    }
    ++num;
  }
  return res;
}

int main(){
  cin >> N;

  vector<int> primes = factor(N);
  cout << (primes.size() > 2 ? "YES" : "NO") << endl;
}
