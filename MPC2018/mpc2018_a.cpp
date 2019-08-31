#include <iostream>
#include <string>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s[0] == 'M' && s[1] == 'U' && s[2] == 'J' && s[3] == 'I' && s[4] == 'N') {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
