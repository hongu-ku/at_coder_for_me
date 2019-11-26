// ベルマンフォード法(O(V*E))V:頂点、E:辺の数
// 単一始点最短路問題
// 負の辺を含む時はこっち
// 含まない時はdijkstraダイクストラ(O(ElogV))が良い。

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

// 頂点fromから頂点toへのコストcostの辺
struct edge { ll from, to, cost; };
typedef pair<ll, ll> P;
const int N = 1e3+5;
const int M = 2e3+5;
const ll INF = 1e17+5;

edge es[M]; // 辺
ll d[N]; // 最短距離
ll V,E;  // Vは頂点数, Eは辺数
// vector<P> G[N];

// s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s) {
  rep(i,V) d[i] = -INF;
  d[s] = 0;
  rep(i,2*V) {
    // cout << i << endl;
    bool update = false;
    rep(i,E) {
      edge e = es[i];
      if(d[e.from] != -INF && d[e.to] < d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        // cout << e.to << " :  " << d[e.to] << endl;
        update = true;
      }
    }
    if(!update) break;
  }
}

// trueなら負の閉路が存在する
bool find_negative_loop() {
  rep(i,V) d[i] = -INF;

  rep(i,2 * V) rep(j,E){
    edge e = es[j];
    if(d[e.to] < d[e.from] + e.cost) {
      d[e.to] = d[e.from] + e.cost;

      // n回目にも更新があるなら負の閉路が存在する
      // cout << i << " : " << e.to << endl;
      if(i >= V - 1 && e.to == V-1) return true;
    }
  }
  return false;
}
ll a,b,c;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> V >> E;
  rep(i,E) {
    cin >> a >> b >> c;
    a--;b--;
    es[i] = (edge) {a,b,c};
  }
  if(find_negative_loop()) {
    cout << "inf" << endl;
    return 0;
  }
  shortest_path(0);
  cout << d[V-1] << endl;
}
