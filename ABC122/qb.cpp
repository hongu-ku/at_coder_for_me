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
  string s;
  cin >> s;
  int num=0,result=0;
  for (size_t i = 0; i < s.length(); i++) {
    if(s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C') {
      num++;
    } else {
      result = max(result,num);
      num = 0;
    }
    // cout << num << endl;
  }
  result = max(result,num);
  cout << result << endl;
}
