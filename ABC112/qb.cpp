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
  int n,T,min=2000;
  cin >> n >> T;
  int c[n],t[n];
  for (size_t i = 0; i < n; i++) {
    cin >> c[i] >> t[i];

  }
  for (size_t i = 0; i < n; i++) {
    if(t[i] <= T) {
      if(c[i] < min) min = c[i];
    }
  }
  if(min == 2000) cout << "TLE" <<endl;
  else cout << min << endl;
}
