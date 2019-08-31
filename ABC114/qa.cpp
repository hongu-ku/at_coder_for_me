#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "NO";
  int x;
  cin >> x;
  if(x == 3 || x == 5 || x == 7) s = "YES";
  cout << s << endl;
}
