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
  int N,D,X;
  int choco = 0;
  cin >> N;
  int A[N];
  cin >> D >> X;
  for (size_t i = 0; i < N; i++) {
    cin >> A[i];
  }
    for (size_t j = 0; j < N; j++) {
      for (size_t i = 0; i < 10000; i++) {
        if (1+i*A[j] > D) {
          break;
        } else {
          choco++;
        }
      }
    }
    cout << choco + X << endl;
  }
