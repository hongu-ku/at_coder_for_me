#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define CON 1000000000000
#define SIX 1000000
using namespace std;

int main() {
  int a,b;
  string s = "No";
  cin >> a >> b;
  if(b % a == 0) {
    cout << a + b << endl;
    return 0;
  }
  cout << b-a << endl;
}
