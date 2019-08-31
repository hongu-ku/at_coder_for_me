#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

long long barger(int L) {
  long long num;
  if(L ==0) {
    return 1;
  }
  num = 2 * barger(L-1) + 3;
  return num;
}


int main() {
  const long long p = 1e12;
  int a = p << 2;
  cout << p << endl;
}
