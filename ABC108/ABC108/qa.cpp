#include <iostream>

using namespace std;
int main() {
  int k,s;
  cin >> k;
  if(k%2==0) {
    s = k/2 * k/2;
  } else {
    s = (k-1)/2 * (k+1)/2;
  }
  cout << s << endl;
}
