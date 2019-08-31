#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;
  if (a < 1200) {
    cout << "ABC" << endl;
  } else if (a >= 2800) {
    cout << "AGC" << endl;
  } else {
    cout << "ARC" << endl;
  }
  return 0;
}
