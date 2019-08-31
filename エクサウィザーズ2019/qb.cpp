#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
using namespace std;

int main() {
  int N,r=0,b=0;
  string s;
  cin >> N >> s;
  for (int i = 0; i < N; i++) {
    if(s[i] == 'R') {
      r++;
    } else {
      b++;
    }
  }
  if(r>b)s="Yes";
  else s="No";
  cout <<  s << endl;
  return 0;
}
