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
  int num[2] = {0,0};
  cin >> s;
  int ini = s.length();
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '0') {
      num[0]++;
    } else {
      num[1]++;
    }
  }
  int result = num[0] > num[1] ? num[0] - num[1] : num[1] - num[0];
  cout << ini - result << endl;

}
