#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define size_t unsigned long long
#define ll long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repr(i, a) for (int i = (int)(a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (int)(b)-1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using namespace std;

int ceil(int a, int b)
{
  // a / b　の繰り上げ くりあげ 繰上げ くり上げ
  return (a + b - 1) / b;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << ceil(a, b) << endl;
  return 0;
}