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
  int s,b,num;
  cin >> s;
  int a[1000000];
  for (int i = 0; i < 1000000; i++) {
    a[i] = 0;
  }
  a[s] = 1;
  num = s;
  for (int i = 1; i < 1000000; i++) {
    if (num % 2 == 0) {
      b = num/2;
    } else {
      b = 3*num+1;
    }
    num = b;
    // cout << num << endl;
    if (a[b] == 1) {
      cout << i+1 << endl;
      return 0;
    } else {
      a[b] = 1;
    }
  }
}
