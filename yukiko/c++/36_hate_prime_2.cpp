#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)

long long N;

//素因数分解
vector<int> prime_factorization(long n) {
  int sqrt_n = sqrt(n);
  vector<bool> prime_check_list(sqrt_n + 1, true);
  vector<int> primes;

  prime_check_list[0] = false;
  prime_check_list[1] = false;

  for (int i=2;i<=sqrt_n;i++) {
    if (prime_check_list[i]) {
      for (int j=i*2;j<sqrt_n;j+=i) {
        prime_check_list[j] = false;
      }
    }
  }

  for (int i=2;i<=sqrt_n;i++) {
    if (prime_check_list[i]) {
      while (n % i == 0) {
        n /= i;
        primes.push_back(i);
      }
    }
    if (n == 1) break;
  }

  if (n != 1) primes.push_back(n);

  return primes;
}

int main(){
  cin >> N;

  vector<int> primes = prime_factorization(N);

  cout << (primes.size() >= 3 ? "YES" : "NO") << endl;
}
