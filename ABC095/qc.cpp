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
  int a,b,c,x,y;
  int num=0;
  cin >> a >> b >> c >> x >> y;
  if (a+b > 2*c) {
    if(x <= y) {
      if(b >= 2*c) {
        num=c*2*y;
      } else {
        num=c*2*x+b*(y-x);
      }
    } else {
      if(a >= 2*c) {
        num=c*2*x;
      } else {
        num=c*2*y+a*(x-y);
      }
    }
  } else {
    num=a*x+b*y;
  }
  cout << num << endl;
}
