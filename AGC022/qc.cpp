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
  int a,b,c;
  int num = 0;
  cin >> a >> b >> c;
  int v[3] = {a,b,c};
  while(true) {
    SORT(v,3);
    if (v[0] == v[1] && v[1] == v[2]) {
      cout << num << endl;
      return 0;
    } else if (v[1] - v[0] >= 2) {
      v[0] += 2;
    } else if (v[1] - v[0] < 2) {
      v[0]++;
      v[1]++;
    }
    num++;
  }
}
