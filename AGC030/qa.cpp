#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t long long;
using namespace std;

int main() {
  long long a,b,c,num=0;
  cin >> a >> b >> c;
  if(a+b < c) num += 2*b + a + 1;
  // else if (a+b==c) num +=
  else num += b+c;
  cout << num << endl;
}
