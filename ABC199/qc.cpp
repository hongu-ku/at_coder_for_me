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

const ll N = 1e5 + 5;
string s;
ll n, result, q;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s >> q;
  vector<int> t(q), a(q), b(q);
  rep(i, q)
  {
    cin >> t[i] >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<string> str(2);
  int ini = 0;
  str[0] = s.substr(0, n);
  str[1] = s.substr(n, n);
  rep(i, q)
  {
    if (t[i] == 2)
      ini = (ini + 1) % 2;
    else
    {
      if (a[i] < n && b[i] < n)
        swap(str[ini][a[i]], str[ini][b[i]]);
      else if (a[i] < n)
        swap(str[ini][a[i]], str[(ini + 1) % 2][b[i] - n]);
      else if (b[i] < n)
        swap(str[ini][b[i]], str[(ini + 1) % 2][a[i] - n]);
      else
        swap(str[(ini + 1) % 2][a[i] - n], str[(ini + 1) % 2][b[i] - n]);
    }
  }
  cout << str[ini] + str[(ini + 1) % 2] << endl;
}
