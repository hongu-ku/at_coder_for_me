#include <iostream>
#define y "Yes"
#define n "No"

using namespace std;


int main() {
  string s;
  int a;
  cin >> a;
  if (a) {
    s = y;
  } else {
    s = n;
  }
  cout << s << endl;
}
