#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define CON 1000000000000
#define SIX 1000000
using namespace std;

int main() {
  string s;
  int n;
  cin >> n;
  if (n == 0) {
    s = "Yes";
  } else {
    s = "No";
  }
  cout << n << endl;
  return 0;
}
