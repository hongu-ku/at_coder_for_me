#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

using namespace std;

int main() {
  int A,B,C;
  string s="No";
  cin >> A >> B >> C;

  if (A==B && B==C) {
    s = "Yes";
  }

  cout << s << endl;
}
