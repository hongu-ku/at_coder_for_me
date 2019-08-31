#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  int N,count,a;
  std::vector<int> v,w;
  cin >> N;
  count = N;
  for (size_t i = 0; i < count; i++) {
    cin >> a;
    v.push_back(a);
  }
  for (size_t i = 0; i < count; i++) {
    cin >> a;
    w.push_back(a);
  }
  for (int mask = 0; mask < N; mask++) {
    cout << v[mask] << w[i];
  }

}
