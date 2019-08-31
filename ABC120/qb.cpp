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
  int a,b,k,num = 0;
  cin >> a >> b >> k;
  for (int i = a+b; i > 0; i--) {
    if(a%i ==0 && b%i == 0) {
      num++;
    }
    if(num == k) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
