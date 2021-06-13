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

typedef pair<int, int> P;

const ll N = 2001;
string s;
ll n, result = 0, m;
vector<vector<int>> g;

void dfs(int i, vector<bool> &seen)
{
  seen[i] = true;
  result++;
  for (auto e : g[i])
  {
    if (!seen[e])
    {
      dfs(e, seen);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  g.resize(n);
  vector<int> a(m), b(m);
  rep(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]].push_back(b[i]);
  }
  rep(i, n)
  {
    vector<bool> seen(n, false);
    dfs(i, seen);
  }

  cout << result << endl;
}
