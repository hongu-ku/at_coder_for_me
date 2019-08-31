#include <iostream>
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
  const long long a = (long long) pow(10, 9) + 7;
  int n;
  long long num = 1;
  cin >> n;
  long long index = 0;
  vector<long long> y(n);
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    y[i] = y[i] - (i + 1); // 空きの数
  }
  for (int i = 1; i < y.size(); i++) {
    if(y[i] + index == i-1) {
      num *= i+1;
      index++;
      if(num >= a) num %= a;
      y.erase(y.begin());
    }
  }
  while(n - index) {
    num *= n - index;
    if(num >= a) num %= a;
    index++;
  }
  cout << num % a << endl;
}
