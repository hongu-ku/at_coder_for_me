// 最小全域木(Minimum Spanning Tree)MSTの解法1
// クラスカル法 kruskal  O(ElogV)

#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
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

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 5;

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

typedef pair<ll, ll> P;

const ll N = 1e6+5;

class UnionFind {
  int par[N]; // 親
  int rank[N]; // 木の深さ
  unsigned size_;
public:
  void init(int n) {
    for (int i=0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
    }
  }
  unsigned size() {return size_;}
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

// 返り値はそうコスト

struct edge {ll u,v, cost;};

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

edge es[N];
ll V, E; // 頂点数と辺数

ll kruskal() {
  sort(es, es+E, comp); // edge.cost が小さい順にソートする
  UnionFind uf;
  uf.init(V);  // Union-Findの初期化
  ll res = 0;
  rep(i,E) {
    edge e = es[i];
    if( !uf.same(e.u, e.v)) {
      uf.unite(e.u,e.v);
      res += e.cost;
    }
  }
  return res;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a,b,c;
  cin >> V >> E;
  vector<vector<P> > G(N);
  rep(i,E) {
    cin >> a >> b >> c;
    a--;b--;
    es[i] = (edge) {a,b,c};
  }
  cout << kruskal() << endl;
}
