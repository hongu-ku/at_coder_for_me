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
  char a,b;
  cin >> b;
  switch (b) {
    case 'A':
    a = 'T';
    break;
    case 'T':
    a = 'A';
    break;
    case 'G':
    a = 'C';
    break;
    case 'C':
    a = 'G';
    break;
  }
  cout << a << endl;
}
