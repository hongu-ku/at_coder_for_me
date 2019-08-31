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
  long long N,M,h=0,cost =0;
  cin >> N >> M;
  long long a,b;
  vector<pair<long long , long long> > v(N);
  for (long long i = 0; i < N; i++) {
    cin >> a >> b;
    v[i].first = a;
    v[i].second = b;
  }
  VSORT(v);
  for (long long i = 0; i < N; i++) {
    h += v[i].second;
    cost += v[i].first * v[i].second;
    if(h > M) {
      cost -= (h-M) * v[i].first;
      break;
    }
  }
  cout << cost << endl;
}
