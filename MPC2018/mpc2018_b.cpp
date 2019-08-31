#include <iostream>
#include <string>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  int a;
  string s;
  cin >> a;
  cin >> s;
  if(a == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  for(int i=0; i<s.length(); i++) {
    if (s[i] == '+') {
      a++;
    } else {
      a--;
    }
    if(a == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
