#include <iostream>

using namespace std;

void swap (unsigned long int* a) {
  unsigned long int store = *(a+1);
  *(a+1) = *a;
  *a = store;
}

int main () {
  int n;
  cin >> n;
  unsigned long int a[] = {2,1};
  if (n != 1) {
    for (int i = 0; i < n-1; i++) {
      a[0] += a[1];
      swap(a);
    }
  }
  cout << a[1] << "\n";
  return 0;
}
