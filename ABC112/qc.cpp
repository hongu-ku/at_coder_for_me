#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;


int main() {
  int n,temp,hh;
  int p = 0;
  cin >> n;
  int x[n],y[n],h[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      do {
      hh = h[p] + fabs(x[p]-i) + fabs(y[p]-j);
      p++;
    } while (h[p-1] == 0 && p != n);
      p = 0;
      // hh = (h[0] + fabs(x[0]-i) + fabs(y[0]-j) > 0) ? h[0] + fabs(x[0]-i) + fabs(y[0]-j) : 0;
      for (int k = 0; k < n; k++) {
        temp = hh - fabs(x[k]-i) - fabs(y[k]-j) > 0 ? hh - fabs(x[k]-i) - fabs(y[k]-j) : 0;
        if(h[k] != temp) {
          break;
        }
        if(k == n-1) {
          cout << i << ' ' << j << ' ' << hh << ' ' << endl;
          return 0;
        }
      }
    }
  }
}
