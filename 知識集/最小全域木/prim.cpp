// 最小全域木(Minimum Spanning Tree)MSTの解法1
// プリム法 prim  O(ElogV)

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

// 返り値はそうコスト
ll prim(vector<vector<P> > & G) {
  ll res = 0;
  priority_queue<P,vector<P>, greater<P> > que;
  ll n = G.size();
  vector<ll> min_cost(n,INF);
  vector<bool> x(n,false);
  min_cost[0] = 0;
  que.push(P(0,0));
  while(!que.empty()) {
    P p = que.top(); que.pop();
    ll v = p.second;
    if(x[v]) continue;
    x[v] = true;
    res += p.first;
    for(auto& e:G[v]) {
      ll u = e.first;
      ll c = e.second;
      if(!x[u]) {
        min_cost[u] = c;
        que.push(P(min_cost[u], u));
      }
    }
  }
  return res;
}


int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll V,m,a,b,c;
  cin >> V >> m;
  vector<vector<P> > G(N);
  rep(i,m) {
    cin >> a >> b >> c;
    a--;b--;
    G[a].push_back(P(b,c));
    G[b].push_back(P(a,c));
  }
  cout << prim(G) << endl;
}
