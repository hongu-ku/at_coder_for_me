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
  int a,b,c,k;
  cin >> a >> b >> c >>k;
  int n[] = {a,b,c};
  SORT(n, 3);
  cout << n[2] * pow(2, k) + n[0] + n[1] <<endl;
}
