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
  int n,m,x;
  int min = 0;
  int max = 0;
  cin >> n >> m >> x;
  int count = m;
  int a[m];
  for (size_t i = 0; i < count; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < count; i++) {
    if (a[i] < x) {
      min++;
    } else if (a[i] > x) {
      max++;
    }
  }
  if (min > max) cout << max << endl;
  else cout << min << endl;
}
