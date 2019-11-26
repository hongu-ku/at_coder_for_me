// ダイクストラ
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

const int MOD = 1e9 + 7;
const ll INF = 1e17;

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

const int N = 1e5+5;
typedef struct edge { ll to;P cost; } E;
vector<edge> G[N];// cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
ll en[N];       // 頂点sから両替所までの最短距離
ll sn[N];      // 頂点tから両替所までの最短距離
int n;          // 頂点数

void dijkstra_en(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(en, en+n, INF);
  en[s] = 0;
  que.push(P(0,s));

  while(!que.empty()) {
    P p = que.top();que.pop();
    ll v = p.second;
    if(en[v] < p.first) continue;
    rep(i, G[v].size()) {
      edge e = G[v][i];
      if(en[e.to] > en[v] + e.cost.first) {
        en[e.to] = en[v] + e.cost.first;
        que.push(P(en[e.to],e.to));
      }
    }
  }
}

void dijkstra_sn(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(sn, sn+n, INF);
  sn[s] = 0;
  que.push(P(0,s));

  while(!que.empty()) {
    P p = que.top();que.pop();
    ll v = p.second;
    if(sn[v] < p.first) continue;
    rep(i, G[v].size()) {
      edge e = G[v][i];
      if(sn[e.to] > sn[v] + e.cost.second) {
        sn[e.to] = sn[v] + e.cost.second;
        que.push(P(sn[e.to],e.to));
      }
    }
  }
}
ll m,a,b,c,e,s,t;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s >> t;
  s--;t--;
  // rep(i,n) rep(j,n) cost[i][j] = INF;
  rep(i,m) {
    cin >> a >> b >> c >> e;
    a--;b--;
    E t1 = {b,P(c,e)};
    G[a].push_back(t1);
    t1 = {a,P(c,e)};
    G[b].push_back(t1);
  }
  dijkstra_en(s);
  dijkstra_sn(t);
  ll d[n];
  d[n-1] = en[n-1] + sn[n-1];
  for(int i = n-2; i>= 0; i--) {
    d[i] = min(d[i+1], en[i] + sn[i]);
  }
  // rep(i,n) cout << d[i] << endl;
  rep(i,n) {pl(1e15 - d[i]); br();}
}
