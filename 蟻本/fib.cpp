#include <iostream>

using namespace std;

int memo[100 + 1];

int fib(int n) {
  if(n<=1) return n;
  if (memo[n] != 0) return memo[n];
  return memo[n] = fib(n-2) + fib(n-1);
}

int main(int argc, char const *argv[]) {
  /* code */
  cout << fib(10) << endl;
  return 0;
}
