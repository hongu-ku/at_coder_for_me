#include <bits/stdc++.h>
// #include <numeric>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define size_t unsigned long long
#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)
#define repr(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;

// 蟻本P108
// 最大公約数
template <typename T> T gcd(T a, T b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

/**
* 最大公約数をa,b,...から求める
* @param [in] list 2つ以上の正整数
* @return 最大公約数
*/
template <typename T> T G_C_D(const vector<T> &list)
{
    if (list.size() < 2) return list[0];

    T a = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        a = gcd(a, list[i]);
    }
    return a;
}

// ax + by = gcd(a,b)の解を求める(1つ)
template <typename T> T extgcd(T a, T b, T& x, T& y) {
  int d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y,x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

// 最小公倍数もついでに
// 最小公倍数と最大公約数をかけ合わせると2数の積
template <typename T> T lcm(T a, T b) {
  return a / gcd(a, b) * b ;
}

/**
* 最小公倍数をa,b,...から求める
* @param [in] list 1つ以上の正整数
* @return 最小公約数
*/
template <typename T> T L_C_M(const vector<T> &list)
{
    if (list.size() < 2) return list[0];

    T a = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        a = lcm(a, list[i]);
    }
    return a;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b,c;
  cin >> a >> b >> c;
  vector<int> v = {a,b,c};
  int d = L_C_M(v);
  cout << d << endl;
}
