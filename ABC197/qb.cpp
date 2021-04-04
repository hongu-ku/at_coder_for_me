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
int h, w, x, y;
ll n;
vector<string> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w >> y >> x;
  s.resize(h);
  rep(i, h)
  {
    cin >> s[i];
  }
  x--;
  y--;
  if (s[y][x] == '#')
  {
    cout << 0 << endl;
    return 0;
  }
  int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
  int result = 1;
  rep(i, 4)
  {
    FOR(j, 1, 103)
    {
      int nx = x + j * dx[i], ny = y + j * dy[i];
      if (nx < 0 || w <= nx || ny < 0 || h <= ny || s[ny][nx] == '#')
        break;
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
