#include <bits/stdc++.h>

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

// 蟻本P114

// べき乗 繰り返し二乗法
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if(n&1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// a*b/m
ll mul(ll a, ll b, ll m) {
    a = mod(a, m); b = mod(b, m);
    if (b == 0) return 0;
    ll res = mul(mod(a + a, m), b>>1, m);
    if (b & 1) res = mod(res + a, m);
    return res;
}


int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a,b;
  cin >> a >> b;
  ll c = gcd(a,b);
  cout << c << endl;
}
