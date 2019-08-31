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
  int a[8][8] = {};
  int count = 8;
  for (size_t i = 0; i < count; i++) {
    for (size_t j = 0; j < count; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
