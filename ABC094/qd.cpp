#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned long int v[n];
  for (size_t i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v+n, greater<int>());
  for (int i = 1; i < n; i++) {
    if (i == count - 1) {
      cout << v[0] << ' ' << v[i] << endl;
      return 0;
    } else if (v[i] <= v[0]/2) {
      if (v[0]/2 - v[i] < v[i-1] - v[0]/2) cout << v[0] << ' ' << v[i] << endl;
      else cout << v[0] << ' ' << v[i-1] << endl;
      return 0;
    }
  }
}
