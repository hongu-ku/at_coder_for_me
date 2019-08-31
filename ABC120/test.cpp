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
  std::vector<string> v;
  for (int i = 0; i < 10; i++) {
  v.push_back("abc" + to_string(i));
  }
  v.begin() + 5 = v.begin();
  v[0] = " aa"  ;
  for (int i = 0; i < 10; i++) {
    cout << v[i] << endl;
  }
}
