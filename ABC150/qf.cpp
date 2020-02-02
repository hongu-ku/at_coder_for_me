#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>

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
typedef struct edge { int to, cost; } E;

const int N = 1e5+10;

int V,s,g;
int a,b;
int d[N];       // 頂点sからの最短距離
int q[N];
int pre[N];

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

int main () {
  cin >> V >> g >> s;
  vector<vector<edge> > G(N);
  rep(i,V-1) {
    cin >> a >> b;
    E t1 = {b,1};
    G[a].push_back(t1);
    t1 = {a,1};
    G[b].push_back(t1);
  }
  dijkstra(s,G);
  rep(i,V+1) {
    q[i] = d[i];
  }
  dijkstra(g,G);
  vector<P> p;
  rep(i,V) {
    p.push_back(P(q[i+1],d[i+1]));
  }
  VSORT(p);reverse(ALL(p));
  rep(i,V) {
    cout << p[i].first << " : " << p[i].second << endl;
  }
  rep(i,V) {
    if(p[i].first > p[i].second) {
      cout << p[i].first - 1 << endl;
      return 0;
    }
  }
}
