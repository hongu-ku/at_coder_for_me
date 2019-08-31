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
  string a[3];
  for (size_t i = 0; i < 3; i++) {
    /* code */
    cin >> a[i];
  }
  cout << a[0][0] << a[1][1] << a[2][2] << endl; 
}
