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
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  VSORT(A);
  while(true) {
    for (int i = 1; i < N; i++) {
      A[i] = A[i] % A[0] ? A[i] % A[0] : A[0];
    }
    VSORT(A);
    if(A[0] == A[N-1]) break;
  }
  cout << A[0] << endl;
}
