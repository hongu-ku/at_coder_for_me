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

const int N = 85;
string s;
vector<P> vp(4);
vector<ll> v(4);
int h,w;
int a[N][N],b[N][N],c[N][N];
ll dp[N][N];

ll solve(int i, int j) {
  if(dp[i][j] != -1) return dp[i][j];
  int nx[] = {i+1,i}, ny[] = {j, j+1};
  rep(k,2) {
    if(nx[k] < h && ny[k] < w) {
      dp[i][j] =
    }
  }


  ll temp1 = solve(i-1,j), temp2 = solve(i,j-1);
  v = {temp1 + a[i][j] - b[i][j], temp1 + b[i][j] - a[i][j], temp2 + a[i][j] - b[i][j], temp2 + b[i][j] - a[i][j]};
  vp = {P(abs(v[0]),0),  P(abs(v[1]),1), P(abs(v[2]),2),  P(abs(v[3]),3)};
  VSORT(vp);
  dp[i][j] = v[vp[0].second];
  return dp[i][j];
}

int main () {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  cin >> h >> w;
  memset(dp, -1, sizeof dp);
  rep(i,h) rep(j,w) {
    cin >> a[i][j];
  }
  rep(i,h) rep(j,w) {
    cin >> b[i][j];
  }
  rep(i,h) rep(j,w) {
    c[i][j] = abs(a[i][j] - b[i][j]);
  }
  dp[h-1][w-1] = abs(a[h-1][w-1] - b[h-1][w-1]);
  br();
  // rep(i,h) {
  //   rep(j,w) cout << dp[i][j] << " ";
  //   br();
  // }
  solve(h-1, w-1);
  br();
  rep(i,h) {
    rep(j,w) cout << dp[i][j] << " ";
    br();
  }
  cout << dp[h-1][w-1] << endl;
}
