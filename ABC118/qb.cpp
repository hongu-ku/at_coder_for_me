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
  int n,m,num = 0,a;
  cin >> n >> m;
  std::vector<int> K(n);
  int A[m];
  for (int i = 0; i < m; i++) {
    A[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> K[i];
    for (int j= 0; j < K[i]; j++) {
      cin >> a;
      A[a-1] += 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if(A[i] == n) {
      num++;
    }
  }
  cout << num << endl;
}
