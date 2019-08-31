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
  long long n,m;
  long long num = 0;
  cin >> n >> m;
  if (n > 1 && m > 1) {
    num = (n-2) * (m-2);
  } else if (n == 1 && m > 1){
    num = m -2;
  } else if (m == 1 && n > 1) {
    num = n-2;
  } else if (m == 1 && n == 1) {
    num = 1;
  } else {
  }
  cout << num << endl;
}
