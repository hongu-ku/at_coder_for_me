#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
// #include <string>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  int a[] = {1,2,3,4,5};
  vector<int> v(a,a+5);
  for (size_t i = 0; i < v.size();) {
    cout << v.size() << ": " << v[i] << endl;
    v.erase(v.begin());
  }
}
