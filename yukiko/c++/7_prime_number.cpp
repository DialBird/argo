#include <iostream>
#include <vector>

using namespace std;

#define REP(i,first,last) for (int i=first;i<last;i++)
const int MAX_N = 10000;

int N;
vector<bool> primes(MAX_N + 1, true);
vector<int> dp(MAX_N + 1, 0);

int main(){
  cin >> N;

  dp[0] = 1;
  dp[1] = 1;
  primes[0] = false;
  primes[1] = false;

  vector<int> prime_list;
  for (int i=2;i<=N;i++) {
    if (primes[i]) {
      prime_list.push_back(i);
      for (int j=i*2;j<=N;j+=i) {
        primes[j] = false;
      }
    }
    dp[i] = -1;
    for (auto p: prime_list) {
      if (dp[i-p] == -1) {
        dp[i] = 1;
        break;
      }
    }
  }

  cout<< (dp[N] == 1 ? "Win" : "Lose") <<endl;
}
