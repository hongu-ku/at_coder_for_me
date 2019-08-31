#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
  int N,m,a,max=0;
  cin >> N;
  vector<pair<long long, long long> > v(N);
  std::vector<string> s(N);
  for(int i=0; i<N; i++) {
    cin >> v[i].first >> v[i].second;
    a = abs(v[i].first) + abs(v[i].second);
    max = a > max ? a : max;
    s[i] = "";
  }
  // cout << a << endl;
  m = max;
  if(m > 40) return 0;
  std::vector<int> d(m);
  for (size_t i = 0; i < m; i++) {
    d[i] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (size_t j = 0; j < m; j++) {
      if(v[i].first < 0) {
        s[i] += 'L';
        v[i].first++;
      } else if(v[i].first > 0) {
        s[i] += 'R';
        v[i].first--;
      } else if(v[i].second < 0) {
        s[i] += 'D';
        v[i].second++;
      } else if(v[i].second > 0) {
        s[i] += 'U';
        v[i].second--;
      } else {
        s[i] += 'L';
        v[i].first++;
      }
    }
    // cout << "v[" << i << "] = [" << v[i].first << " , " << v[i].second << "]"
    // << endl;
    if(v[i].first!=0 || v[i].second!=0) {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << m << endl;
  for (size_t i = 0; i < m; i++) {
    cout << d[i] << " ";
  }
  char bs = 8;
  cout << bs << bs << bs << endl;
  for (size_t i = 0; i < N; i++) {
    cout << s[i] << endl;
  }
}
