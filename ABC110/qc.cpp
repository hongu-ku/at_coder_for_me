#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

const char z = 'z', a = 'a';


int main() {
  string s,t,result="Yes";
  char temp = '0';
  cin >> s >> t;
  char v[z-a];
  for (size_t i = 0; i < z-a; i++) {
    v[i] = 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (v[s[i] - a] == 0 ) {
      v[s[i] - a] = t[i];
    } else {
      if(v[s[i] - a] != t[i]) {
        result = "No";
        break;
      }
    }
  }
  cout << result << endl;
  return 0;
}
