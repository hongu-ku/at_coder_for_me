#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int gcd_(int u, int v) {
  int r;
  while (0 != v) {
    r = u % v; u = v; v = r; /* swap */
  }
  return u;
}


int main() {
  int n, x, a;
  cin >> n >> x;
  int y[n];
  for (size_t i = 0; i < n; i++) {
    cin >> a;
    y[i] = a - x;
  }
  a = y[0];
  for (size_t i = 1; i < n; i++) {
    a = gcd_(a,y[i]);
  }
  if (a < 0) a = -a;
  cout << a << endl;
}
