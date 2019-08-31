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
  int x1,x2,y1,y2,x,xx,y,yy;

  cin >> x1 >> y1 >> x2 >> y2;
  x = x2 - (y2 - y1);
  y = y2 + (x2 - x1);
  xx = x - (x2 - x1);
  yy = y - (y2 - y1);
  cout << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
}
