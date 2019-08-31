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
  int n,x;
  cin >> n >> x;
  int j = n;
  int m[n];
  const int count = n;
  for (size_t i = 0; i < count; i++) {
    cin >> m[i];
  }
  for (size_t i = 0; i < count; i++) {
    x-=m[i];
  }
  SORT(m, n);
  while (x>=0) {
    x-=m[0];
    j++;
  }
  cout << j-1 << endl;
}
