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
  string a;
  std::vector<char> v,w;
  char b = 'z';
  cin >> a;
  for (size_t i = 0; i < a.length(); i++) {
    v.push_back(a[i]);
    w.push_back(a[i]);
  }
  VSORT(v);
  if (a.length() == 26) {
    cout << -1 << endl;
    return 0;
  }
  for (size_t i = 0; i < v.size(); i++) {
    if (v[i] + 1 != v[i+1]) {
      w.push_back(v[i]+1);
      a += v[i]+1;
      break;
    }
  }
  cout << a << endl;
  return 0;
}
