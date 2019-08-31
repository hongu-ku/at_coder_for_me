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
  int n,temp;
  cin >> n;
  std::vector<int> v;
  std::vector<int> w;

  int count = n;
  for (size_t i = 0; i < count; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  copy(v.begin(), v.end(), back_inserter(w) );
  VSORT(v);
  int mid_max = v[(count+1)/2];
  int mid_min = v[(count-1)/2];
  for (size_t i = 0; i < count; i++) {
    if (mid_max == mid_min) cout << mid_max << endl;
    else if (mid_max <= w[i]) cout << mid_min << endl;
    else cout << mid_max << endl;
  }
}
