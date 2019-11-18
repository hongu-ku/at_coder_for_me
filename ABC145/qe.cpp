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

const int N = 3005;
int n,t, max_value;
int a[N], b[N];
ll dp[N][N]; // i時間以下で食べ終わるときの最大値

int main () {
  ios::sync_with_stdio(false);
  cin >> n >> t;
  P p[N];
  // rep(i,N) rep(j,N) dp[i][j] = -1;
  rep(i,n) {
    cin >> a[i] >> b[i];
    max_value = max(b[i], max_value);
    p[i] = P(a[i], b[i]);
  }
  rep(i,n+1) {
    dp[0][i] = 0;
  }
  SORT(p, n);
  // rep(i,n) cout << p[i].first << endl;
  rep(i, n) {
    rep(j, t+1) {
      if(p[i].first > j) {
        dp[i+1][j] = dp[i][j];
      } else {
        dp[i+1][j] = max(dp[i][j-p[i].first] + p[i].second, dp[i][j]);
      }
    }
  }
  ll ans = 0;
  rep(i,n) ans = max(ans, dp[i][t-1] + p[i].second);
  cout << ans << endl;
}
