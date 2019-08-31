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

void h(int* a) {
  cout << a << a+1 << endl;
}

int main() {
  std::vector<int> v(3);
  v[0] =1;v[1]=2;v[2]=3;
  h(v.begin());
}
