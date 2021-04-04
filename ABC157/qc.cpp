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
const ll INF = 1LL << 60;
const ll N = 3;

typedef pair<int, char> P;

ll n, m;
vector<P> v(N);

void solve()
{
  VSORT(v);
  string result(n, '0');
  rep(i, m)
  {
    result[v[i].first] = v[i].second;
    if (i != 0)
    {
      if (v[i].first == v[i - 1].first && v[i].second != v[i - 1].second)
      {
        cout << -1 << endl;
        return;
      }
    }
    if (v[i] == P(0, '0') && n != 1)
    {
      cout << -1 << endl;
      return;
    }
  }
  if (n > 1 && result[0] == '0')
    result[0] = '1';

  cout << result << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  v.resize(m);
  int s;
  char c;
  rep(i, m)
  {
    cin >> s >> c;
    v[i] = P(s - 1, c);
  }

  solve();
  return 0;
}
