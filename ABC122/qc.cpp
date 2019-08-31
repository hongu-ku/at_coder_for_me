#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
using namespace std;

int main() {
  long long N,Q,l[100009],r[100009];
  string s;
  cin >> N >> Q >> s;
  std::vector<ll> v,t(N,0);
  for (size_t i = 0; i < Q; i++) {
    cin >> l[i] >> r[i];
  }
  for (size_t i = 1; i < N; i++) {
    if(s[i-1] == 'A' && s[i] == 'C') {
      t[i] = t[i-1] + 1;
    } else {
      t[i] = t[i-1];
    }
    // cout << "t[" << i << "] = " << t[i] << endl;
  }
  for (size_t i = 0; i < Q; i++) {
    cout << t[r[i]-1] - t[l[i]-1] << endl;
  }
}
