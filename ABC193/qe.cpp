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
template <typename T>
T gcd(T a, T b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
const int T = 11;
int t;

// 最小公倍数もついでに
// 最小公倍数と最大公約数をかけ合わせると2数の積
template <typename T>
T lcm(T a, T b)
{
  return a / gcd(a, b) * b;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;

  vector<ll> X(t, 0), Y(t, 0), P(t, 0), Q(t, 0);
  rep(i, t) cin >> X[i] >> Y[i] >> P[i] >> Q[i];

  rep(i, t)
  {
    ll x = X[i], y = Y[i], p = P[i], q = Q[i];
    ll t_cycle = 2 * x + 2 * y;
    ll s_cycle = p + q;
    ll num = lcm(t_cycle, s_cycle);
    ll t_num = num / t_cycle, s_num = num / s_cycle;
    bool flag = false;
    rep(j, t_num)
    {
      rep(k, s_num)
      {
        if (s_cycle * k + p <= t_cycle * j + x && t_cycle * j + x < s_cycle * k + p + q)
        {
          cout << t_cycle * j + x << endl;
          flag = true;
          break;
        }
        if ((t_cycle * j + x <= s_cycle * k + p) && (s_cycle * k + p < t_cycle * j + x + y))
        {
          cout << s_cycle * k + p << endl;
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }
    cout << "infinity" << endl;
  }
}
