#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

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

void h(int* a) {
  cout << a << a+1 << endl;
}

int main() {
  cout << abs(5-10) << endl;
  cout << abs(14-10) << endl;
  cout << -17+10 << endl;
}
