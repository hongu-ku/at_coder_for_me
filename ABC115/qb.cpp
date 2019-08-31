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
  int n,num = 0;
  cin >> n;
  int p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  SORT(p,n);
  for (int i = 0; i < n-1; i++) {
    num += p[i];
  }
  num += p[n-1]/2;
  cout << num << endl;
}
