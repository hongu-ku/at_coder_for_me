#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)
#define repr(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vi>;
// using vl = vector<long long>;
// using vvl = vector<vl>;
// using vs = vector<string>;
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const int MOD = 1e9 + 7;

struct mint {
    int n;
    mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

int kaijo (int a, int result) {
  if (a == 0) {
    return result;
  } else {
    return kaijo(a-1, result * a);
  }
}

int kaijo(int a) {
  return kaijo(a,1);
}

ll kaijo_ll (ll a, ll result) {
  if (a == 0) {
    return result;
  } else {
    return kaijo_ll(a-1, result * a);
  }
}

ll kaijo_ll(ll a) {
  return kaijo_ll(a,1);
}

int main () {
  string s;
  bool flag = true;
  cin >> s;
  std::vector<ll> v(s.length(), 0), result(s.length(), 0);
  ll count = s.length();
  s += "R";
  ll num = 1;
  for (ll i = 1; i < s.length(); i++) {
    if(s[i] == s[i-1]) {
      num++;
    } else if(flag) {
      for (ll j = 1; j <= num; j++) {
        v[i-j] = j;
      }
      flag = !flag;
      num = 1;
    } else {
      for (ll j = 1; j <= num; j++) {
        v[i-(num-j+1)] = -j;
      }
      flag = !flag;
      num = 1;
    }
  }

  rep(i,count) {
    if(v[i]%2 && v[i] < 0) {
      result[i+v[i]+1]++;
    } else if(v[i]%2 && v[i] > 0){
      result[i+v[i]-1]++;
    } else {
      result[i+v[i]]++;
    }
  }
  rep(i,count){
    cout << result[i] << ' ';
  }
}
