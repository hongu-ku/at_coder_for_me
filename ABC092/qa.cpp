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
  int a,b,c,d,y,w;
  cin >> a >> b >> c >> d;
  if (a < b) {
    y = a;
  } else {
    y = b;
  }
  if (c < d) {
    w = c;
  } else {
    w = d;
  }
  cout << y+w << endl;
}
