#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define rep(i,a) for(int i=0;i<(a);i++)
#define repr(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const int MOD = 1e9 + 7;

struct mint {
    int n;
    mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

typedef pair<int, int> P;

const int N = 1e5+5;
const int Q = 2e5+5;
string s;
vector<int> v[N];
int n, q;

class UnionFind {
  int par[N]; // 親
  int rank[N]; // 木の深さ

public:
  void init(int n) {
    for (int i=0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
    }
  }
  // 木の根を求める
  int find(int x) {
    if(par[x] == x) {
     return x;
    } else {
     return par[x] = find(par[x]);
    }
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  // xとyが同じ集合に属するかいなか
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int p[Q], a[Q], b[Q];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  UnionFind uf;
  uf.init(n);
  rep(i,q) cin >> p[i] >> a[i] >> b[i];
  rep(i,q) {
    if (p[i] == 0) {
      uf.unite(a[i], b[i]);
    } else {
      cout << (uf.same(a[i],b[i]) ? "Yes" : "No") << endl;
    }
  }
}
