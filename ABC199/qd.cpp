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
const double PI = 3.14159265358979323846;

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

const ll N = 20;
const ll M = 400;
ll n, m;
int a, b;
vector<vector<int>> g(N);
vector<int> color(N, 3);

void bfs(int p)
{
  queue<int> que;
  vector<bool> memo(n, false);
  set<P> s;
  que.push(p);
  memo[p] = true;
  while (!que.empty())
  {
    int root = que.front();
    que.pop();
    for (auto to : g[root])
    {
      // cout << root << " => " << to << " : " << s.count({to, root}) << endl;
      if (s.count({to, root}) == 0)
      {
        if (color[to] < color[root])
          color[root]--;
        else
          color[to]--;
        if (!memo[to])
        {
          que.push(to);
          memo[to] = true;
        }
        s.insert({root, to});
        s.insert({to, root});
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  color.resize(n);
  g.resize(n);
  ll result = 1;
  rep(i, m)
  {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  rep(i, n)
  {
    if (color[i] == 3)
    {
      bfs(i);
    }
  }
  rep(i, n)
  {
    result *= color[i];
  }
  cout << result << endl;
}
