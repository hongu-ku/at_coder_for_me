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
  string s;
  size_t num=0;
  bool a = true;
  cin >> s;
  for (size_t i = 2; i < s.length() -1; i++) {
    if(s[i] == 'C') num++;
  }
  for (size_t i = 1; i < s.length(); i++) {
    if(s[i] == 'B' || s[i] == 'A' || (s[i] > 'C' && s[i] <= 'Z')) a = false;
  }
  if(s[0] == 'A' && a && num == 1) cout << "AC" << endl;
  else cout << "WA" << endl;
}
