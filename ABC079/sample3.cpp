#include <iostream>
#include <math.h>
#define PLUS 0x2B
#define MINUS 0x2D

using namespace std;

int main () {
  int a[8];
  int p;
  cin >> p;
  const char plus = PLUS;
  const char minus = MINUS;
  if (p < 0 || p > 9999) {
    cout << "wrong entry\n";
    return 0;
  }
  for (int i = 3; i >= 0; i--) {
    a[i*2] = p / (int) pow(10,i);
    a[i*2+1] = -a[i*2];
    p -= a[i*2] * (int) pow(10,i);
  }

  // better input
  string abcd_str;
  cin << abcd_str;
  int b;
  char ch[3];
  for (int i = 0; i < 2; i++) {
    for (int j = 2; j < 4; j++) {
      for (int k = 4; k < 6; k++) {
        b = a[6] + a[i] + a[j] + a[k];
        ch[2] = i % 2 ? minus : plus;
        ch[1] = j % 2 ? minus : plus;
        ch[0] = k % 2 ? minus : plus;
        if (b - 7 == 0) {
          cout << a[6] << ch[0] << a[4] << ch[1] << a[2] << ch[2] << a[0] << "=7" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
