#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  string s;
  int min = 10000;
  int a;
  cin >> s;
  for (size_t i = 2; i < s.length(); i++){
    a = (s[i-2]- 48) * 100 + (s[i-1] - 48) * 10 + s[i] - 48;
    min = abs(753 - a) < min ? abs(753 - a): min;
  }
  cout << min << endl;
}
