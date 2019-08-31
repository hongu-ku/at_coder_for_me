#include <iostream>

using namespace std;

int main() {
  int a,b;
  string s;
  cin >> a >> b;
  if(a * b % 2) {
    s = "Yes";
  } else {
    s = "No";
  }
  cout << s << endl;
}
