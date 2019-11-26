#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999
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
typedef struct edge { int to, cost; } E;

const int N = 1e5+5;
int pre[N];
int d[N];       // 頂点sからの最短距離
int V;          // 頂点数

// 始点sから各頂点への最短距離を求める
void dijkstra(int s, vector<vector<edge> > & g) {
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+V, INF);
  fill(pre, pre + V, -1);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()) {
    P p = que.top();que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    rep(i, g[v].size()) {
      edge e = g[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pre[e.to] = v;
        que.push(P(d[e.to],e.to));
      }
    }
  }
}

// 頂点tへの最短路
vector<int> get_path(int t) {
  vector<int> path;
  for(; t != -1; t = pre[t]) path.push_back(t); // tがsになるまでprv[t]を辿っていく
  //このままだとt->sになっているので逆順にする
  reverse(ALL(path));
  return path;
}

int n,m,a,b,c;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> V >> m;
  vector<vector<edge> > G(N);
  rep(i,m) {
    cin >> a >> b >> c;
    E t1 = {b,c};
    G[a].push_back(t1);
    t1 = {a,c};
    G[b].push_back(t1);
  }
  dijkstra(0,G);
  cout << d[6] << endl;
}
