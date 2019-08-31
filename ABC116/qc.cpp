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
  int n,temp=0;
  cin >> n;
  std::vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  // int max = *max_element(h.begin(), h.end());
  for (int i = 0; i < 10000; i++) {
    temp = 0;
    // cout << i << endl;
    for (int j = 0; j < n; j++) {
      if (h[j] == 0 && temp == 0){
        // do nothing
      } else if(h[j] == 0 && temp == 1) {
        break;
      }  else {
        h[j] = h[j] - 1;
        temp = 1;
      }
    }
    if (temp == 0){
      cout << i << endl;
      return 0;
    }
  }
}
