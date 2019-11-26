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
typedef struct edge { ll to, cost; } E;

const ll N = 1e5+5;
ll d[N];       // 頂点sからの最短距離
ll V;          // 頂点数

vector<ll> dijkstra(ll s, vector<vector<edge> > & g) {
  ll n = g.size();
  vector<ll> d(n,INF);
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> > que;
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()) {
    P p = que.top();que.pop();
    ll v = p.second;
    if(d[v] < p.first) continue;
    rep(i, g[v].size()) {
      edge e = g[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to],e.to));
      }
    }
  }
  return d;
}
ll m,t,a,b,c,A[N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> V >> m >> t;
  rep(i,V) cin >> A[i];
  vector<vector<edge> > G(N),H(N);
  rep(i,m) {
    cin >> a >> b >> c;
    a--;b--;
    E t1 = {b,c};
    G[a].push_back(t1);
    t1 = {a,c};
    H[b].push_back(t1);
  }
  auto Go = dijkstra(0,G);
  auto Back = dijkstra(0,H);
  ll result = 0;
  rep(i,V) {
    result = max(result, (t - Go[i] - Back[i]) * A[i]);
  }
  cout << result << endl;
}
