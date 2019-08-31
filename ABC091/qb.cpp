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
  int N,M;
  cin >> N;
  string a;
  vector<string> s,t;
  for (size_t i = 0; i < N; i++) {
    /* code */
    cin >> a;
    s.push_back(a);
  }
  cin >> M;
  for (size_t i = 0; i < M; i++) {
    /* code */
    cin >> a;
    t.push_back(a);
  }
  int num = 0;
  for (size_t i = 0; i < N; i++) {
    string temp = s[i];
    int g = 0;
    for (size_t j = 0; j < N; j++) {
      if (s[i] == s[j]) g++;
    }
    for (size_t l = 0; l < M; l++) {
      if (s[i] == t[l]) g--;
    }
    if (num < g) num = g;
  }

  cout << num << endl;
}
