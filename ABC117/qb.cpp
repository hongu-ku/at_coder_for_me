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
  int n,sum = 0;
  string s;
  cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  VSORT(v);
  for (int i = 0; i < n-1; i++){
    sum += v[i];
  }
  if (v[n-1] < sum) {
    s = "Yes";
  } else {
    s = "No";
  }
  cout << s << endl;
}
