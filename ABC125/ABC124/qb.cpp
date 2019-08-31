#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
using namespace std;

int main() {
  int N,M,C,num = 0,result;
  cin >> N >> M >> C;
  int B[M];
  int A[N][M];
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for (int i=0; i<N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    result = C;
    for (int j = 0; j < M; j++) {
      result += A[i][j] * B[j];
    }
    if(result > 0) num++;
  }
  cout <<  num << endl;
  return 0;
}
