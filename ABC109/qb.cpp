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
  int n;
  cin >> n;
  string w[n];
  for (size_t i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (size_t i = 1; i < n; i++) {
    if(w[i-1].back() != w[i].front()) {
      cout << "No" << endl;
      return 0;
    } else {
      for (size_t j = 0; j < i; j++) {
        if(w[j] == w[i]) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}
