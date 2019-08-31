#include <iostream>

using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  int a = m/n;
  for(int i = a; i > 1 ; i--) {
    if(m % i == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}
