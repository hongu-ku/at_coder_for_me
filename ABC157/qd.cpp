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
const ll N = 1e5 + 5;

typedef pair<int, int> P;

class UnionFind
{
public:
  int par[N], size[N];
  void init(int n)
  { // init
    for (int i = 0; i < n; i++)
    {
      par[i] = i;
      size[i] = 1;
    }
  }

  int root(int x)
  { //find
    if (par[x] == x)
    {
      return x; //根
    }
    else
    {
      return par[x] = root(par[x]); //経路圧縮
    }
  }

  bool same(int x, int y)
  {
    return root(x) == root(y);
  }

  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    size[y] += size[x];
    par[x] = y;
  }

  int sizes(int x)
  {
    return size[x];
  }
};

ll n, m, k;
vector<int> a, b, c, d;

void solve()
{
  UnionFind uf;
  uf.init(n);
  rep(i, m)
  {
    uf.unite(a[i], b[i]);
  }
  vector<int> relationship(n, 0);
  rep(i, m)
  {
    relationship[a[i]]++;
    relationship[b[i]]++;
  }
  rep(i, k)
  {
    if (uf.same(c[i], d[i]))
    {
      relationship[c[i]]++;
      relationship[d[i]]++;
    }
  }
  int result[n];
  rep(i, n)
  {
    result[i] = uf.sizes(uf.root(i)) - relationship[i];
  }
  rep(i, n) cout << result[i] - 1 << " ";
  cout << endl;
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  b.resize(m);
  a.resize(m);
  c.resize(k);
  d.resize(k);
  rep(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  rep(i, k)
  {
    cin >> c[i] >> d[i];
    c[i]--;
    d[i]--;
  }

  solve();
  return 0;
}
