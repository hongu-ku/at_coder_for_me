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

const int N = 1e5+10;

ll n;
ll k,r,s,p,a[N];
string t;
ll dp[3][N];
map<char, ll> m;

int main () {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k >> r >> s >> p >> t;
  m['s'] = r; m[0] = r;
  m['p'] = s; m[1] = s;
  m['r'] = p; m[2] = p;
  // rep(i,n) {
  //   if(t[i] = 'r') a[i] = 0;
  //   else if(t[i] = 's') a[i] = 1;
  //   else a[i] = 2;
  // }
  rep(i,3) dp[i][0] = 0;
  for(int i = 1; i <= k; i++) {
    ll tt[3] = {0,0,0};
    if(t[i-1] == 's') tt[0] = r;
    else if(t[i-1] == 'p') tt[1] = s;
    else tt[2] = p;
    rep(j,3) {
      dp[j][i] = tt[j];
    }
    // rep(l,3) cout << i << " : " << dp[l][i] << ' ';
    // cout << endl;
    for(int j = i+k; j <= n; j += k) {
      ll tt[3] = {0,0,0};
      if(t[j-1] == 's') tt[0] = r;
      else if(t[j-1] == 'p') tt[1] = s;
      else tt[2] = p;
      dp[0][j] = max(dp[1][j-k] + tt[0], dp[2][j-k] + tt[0]);
      dp[1][j] = max(dp[2][j-k] + tt[1], dp[0][j-k] + tt[1]);
      dp[2][j] = max(dp[1][j-k] + tt[2], dp[0][j-k] + tt[2]);
      // rep(l,3) cout << j << " : " << dp[l][j] << ' ';
      // cout << endl;
    }
  }
  ll result = 0;
  rep(i,k) {
    result += max({dp[0][n-i], dp[1][n-i], dp[2][n-i]});
    // cout << dp[0][n-i] << " : " << dp[1][n-i] << " : " << dp[2][n-i] << "    ";
    // cout << max({dp[0][n-i], dp[1][n-i], dp[2][n-i]}) << endl;
  }
  cout << result << endl;
}
