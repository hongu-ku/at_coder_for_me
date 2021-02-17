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

// 蟻本P114

const ll MOD = 1e9 + 7;

// べき乗 繰り返し二乗法
ll mod_pow(ll x, ll n)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll mod(ll a)
{
  return (a % MOD + MOD) % MOD;
}

// a*b/MOD
ll mul(ll a, ll b)
{
  a = mod(a);
  b = mod(b);
  if (b == 0)
    return 0;
  ll res = mul(mod(a + a), b >> 1);
  if (b & 1)
    res = mod(res + a);
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  ll c = gcd(a, b);
  cout << c << endl;
}
