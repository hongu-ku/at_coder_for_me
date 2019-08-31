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
  int N;
  cin >> N;
  int a[N+2];
  const int count = N;
  int temp;
  a[0] = 0;
  a[N+1] = 0;
  for (size_t i = 0; i < count; i++) {
    cin >> a[i+1];
  }
  long long value;
  for (size_t i = 1; i < count + 1; i++) {
    value = 0;
    for (size_t j = 0; j < count + 2; j++) {
      if (i == j) {
        break;
      }else {
        temp = a[j+1] - a[j];
        value = temp < 0 ? value - temp : value + temp;
      }
    }
    cout << value << endl;
  }
}
