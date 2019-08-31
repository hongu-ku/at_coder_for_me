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
  int n,k;
  cin >> n >> k;
  long long min = INF;
  std::vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  VSORT(h);
  for (int i = 0; i < n-k+1; i++) {
    min = min > h[i+k-1] - h[i] ? h[i+k-1] - h[i] : min;
  }

  cout << min << endl;
}
