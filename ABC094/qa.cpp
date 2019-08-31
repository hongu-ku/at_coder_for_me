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
  int a,b,x;
  cin >> a >> b >> x;
  if (a <= x && a + b >= x) cout << "YES" << endl;
  else cout << "NO" << endl;
}
