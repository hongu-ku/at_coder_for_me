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
  int  a,b;
  int num = 0;
  cin >> a >> b;
  // for (size_t i = 0; i < 5; i++) {
  //   /* code */
  //   x += {(int)a[i] - (int) '0'} * pow(10, a.length() - i - 1);
  //   y += {(int)b[i] - (int) '0'} * pow(10, b.length() - i - 1);
  // }
  for (size_t i = a; i <= b; i++) {
    /* code */
    string g = to_string(i);
    if (g[0] == g[4] && g[1] == g[3]) {
      num++;
    }
  }
  cout << num << endl;
}
