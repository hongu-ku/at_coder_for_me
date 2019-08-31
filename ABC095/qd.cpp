#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define SORT_DOWN(v, n) sort(v, v+n, greater<int>());
#define VSORT_DOWN(v) sort(v.begin(),v.end(), greater<int>());
#define INF 999999999
using namespace std;

int main() {
  int n;
  long long c;
  cin >> n >> c;
  long long x[n], v[n];
  long long num=0;
  long long max=0;

  // vector<pair<long long, long long> > v;
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> v[i];
  }
  for (size_t i = 0; i < n; i++) {
    num=0;
    for (size_t j = 0; j <= i; j++) {
      num+=v[j];
    }
    num-=x[i];
    max = max>num ? max : num;
  }
  for (size_t i = 0; i < n; i++) {
    num=0;
    for (size_t j = i; j < n; j++) {
      num+=v[j];
    }
    num-=c-x[i];
    max = max>num ? max : num;
  }
  for (size_t i = 0; i < n-1; i++) {
    for (size_t j = i+1; j < n; j++) {
      num = 0;
      for (size_t k = 0; k <= i; k++) {
        num += v[k];
      }
      for (size_t k = j; k < n; k++) {
        num += v[k];
      }
      num -= c-x[j] > x[i] ? c-x[j] + 2 * x[i] : 2 * (c-x[j]) + x[i];
      // cout << i << ':' << j << ':' << num << endl;
      max = num < max ? max : num;
    }
  }
  cout << max << endl;
}
