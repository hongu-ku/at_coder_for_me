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
  string a;
  cin >> a;
  string array[6] = {"abc","acb","bac","bca","cab","cba"};
  for (size_t i = 0; i < 6; i++) {
    if (a == array[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
