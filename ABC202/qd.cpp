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

ll a, b, k;

vector<vector<ll>> comb(int n, int r)
{
  vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
  for (int i = 0; i < v.size(); i++)
  {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++)
  {
    for (int k = 1; k < j; k++)
    {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]) % MOD; // MODで割った数。
    }
  }
  return v;
}

int main()
{
  cin >> a >> b >> k;
  string result;
  vector<vector<ll>> v = comb(a + b, b);
  ll l = 0, r = a + b, num = a + b;
  rep(i, num)
  {
    ll z = l + v[a + b][b] * a / (a + b);
    if (k <= z)
    {
      result += 'a';
      r = z;
      a--;
    }
    else
    {
      result += 'b';
      l = z;
      b--;
    }
  }
  cout << result << endl;
}
