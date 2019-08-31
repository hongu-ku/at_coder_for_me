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
  int K;
  long long A, B;
  cin >> A >> B >> K;
  for (size_t i = A; i < B+1; i++) {
    if (i - A < K || B - i < K) {
      cout << i << endl;
    }
  }
}
