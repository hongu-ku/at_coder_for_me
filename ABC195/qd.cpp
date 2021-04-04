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
int si()
{
  int x;
  scanf("%d", &x);
  return x;
}
long long sl()
{
  long long x;
  scanf("%lld", &x);
  return x;
}
string ss()
{
  string x;
  cin >> x;
  return x;
}
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 5;

struct mint
{
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b)
{
  a.n += b.n;
  if (a.n >= MOD)
    a.n -= MOD;
  return a;
}
mint operator-(mint a, mint b)
{
  a.n -= b.n;
  if (a.n < 0)
    a.n += MOD;
  return a;
}
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

typedef pair<int, int> P;

const ll N = 1e6 + 5;
ll n, m, q, w, v;
vector<P> ni;
vector<ll> x, l, r;

ll rec(ll r, ll l)
{
  auto x_c = x;
  auto nimotu = ni;
  x_c.erase(x_c.begin() + l - 1, x_c.begin() + r);
  VSORT(x_c);
  ll result = 0;
  for (auto box : x_c)
  {
    ll max_value = 0;
    ll memo = -1;
    bool flag = false;
    if (nimotu.size() == 0)
      break;
    rep(i, nimotu.size())
    {
      if (nimotu[i].first > box)
      {
        if (memo == -1)
          break;
        nimotu.erase(nimotu.begin() + memo);
        result += max_value;
        flag = true;
        break;
      }
      if (max_value < nimotu[i].second)
      {
        max_value = nimotu[i].second;
        memo = i;
      }
    }
    if (!flag && memo != -1)
    {
      nimotu.erase(nimotu.begin() + memo);
      result += max_value;
    }
  }
  return result;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  ni = vector<P>(n);
  x = vector<ll>(m);
  l = vector<ll>(q);
  r = vector<ll>(q);
  rep(i, n)
  {
    cin >> w >> v;
    ni[i] = {w, v};
  }
  VSORT(ni);
  rep(i, m) cin >> x[i];
  rep(i, q) cin >> l[i] >> r[i];
  rep(i, q)
  {
    cout << rec(r[i], l[i]) << endl;
  }
}
