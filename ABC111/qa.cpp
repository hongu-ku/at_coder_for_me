#include <iostream>

using namespace std;

int main() {
  int n;
  int a;
  // string s = "Hello World";
  cin >> n;
  switch (n) {
    case 111:
      a = 999;
      break;
    case 119:
    a = 991;
    break;
    case 191:
    a = 919;
    break;
    case 911:
    a = 199;
    break;
    case 199:
    a = 911;
    break;
    case 919:
    a = 191;
    break;
    case 991:
    a = 119;
    break;
    case 999:
    a = 111;
    break;
  }
  cout << a << endl;
}
