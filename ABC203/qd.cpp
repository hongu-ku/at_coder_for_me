// 2次元累積和
// 二分探索
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

const ll MOD = LONG_MAX;
const ll INF = 1e9 + 5;
const double PI = 3.14159265358979323846;

typedef pair<int, int> P;

ll n, k;

int main()
{
  cin >> n >> k;
  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i, n) rep(j, n)
  {
    cin >> a[i][j];
  }
  ll result = INF;
  rep(i, n - k + 1)
  {
    rep(j, n - k + 1)
    {
      vector<ll> v;
      FOR(y, i, i + k)
      {
        FOR(x, j, j + k)
        {
          v.push_back(a[y][x]);
        }
      }
      VSORT(v);
      reverse(ALL(v));
      result = min(result, v[k * k / 2]);
    }
  }
  cout << result << endl;
}
