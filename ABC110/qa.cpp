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
  int n;
  string s = "No";
  cin >> n;
  if(n == 25) {
    s = "Christmas";
  } else if (n == 24) {
    s = "Christmas Eve";
  } else if (n == 23) {
    s = "Christmas Eve Eve";
  } else if (n == 22){
    s = "Christmas Eve Eve Eve";
  }
  cout << s << endl;
}
