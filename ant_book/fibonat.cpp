#include <iostream>
#include <vector>

using namespace std;

// long memo[10000000] = {};
vector<long> memo;

long fib(int n){
  if (n <= 1) return 1;
  if (memo[n] != 0) return memo[n];
  memo[n] = fib(n-1) + fib(n-2);
  return memo[n];
}

int main(int argc, char *argv[]){
  if (argc != 2) {
    fprintf(stderr, "wrong\n");
    exit(1);
  }
  memo.resize(atoi(argv[1])+1);
  long res;
  res = fib(atoi(argv[1]));
  cout<<res<<endl;
}
