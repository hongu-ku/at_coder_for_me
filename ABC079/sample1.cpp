#include <iostream>
#include <math.h>
using namespace std;

int main () {
  int N,M;
  cin >> N;
  int a[4];
  for (int i = 3; i >= 0; i--) {
    a[i] = N / (int) pow(10,i);
    N -= a[i] * (int) pow(10,i);
  }
  if ( (a[1] == a[2]) && (a[0] == a[1] || a[3] == a[2])) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
