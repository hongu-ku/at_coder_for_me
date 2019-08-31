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
  int n,m,num;
  int sum = 0;
  cin >> n >> m;
  std::vector<int> x(m),dis(m-1);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  if (n >= m) {
    num = 0;
  } else {
    VSORT(x);
    for (int i = 1; i < m; i++) {
      dis[i-1] = x[i] - x[i-1];
    }
    VSORT(dis);
    for(int i = 0; i < n-1; i++) {
      sum += dis[m-2-i];
    }
    num = x[m-1] - x[0] - sum;
  }
  cout << num << endl;
}
