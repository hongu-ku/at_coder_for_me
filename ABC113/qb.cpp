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
  int N,T,A,num;
  float a,min = 10000;
  cin >> N;
  int H[N];
  cin >> T >> A;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  for ( int i = 0; i < N; i++) {
    a = abs(A - (T - H[i]*0.006));
    if (a < min) {
      min = a;
      num = i+1;
    }
  }
  cout << num << endl;
}
