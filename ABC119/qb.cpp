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
  double total=0,x;
  string u;
  for (int i = 0; i < N; i++) {
    cin >> x >> u;
    total += u=="BTC" ? x*380000 : x;
  }
  cout << total << endl;
}
