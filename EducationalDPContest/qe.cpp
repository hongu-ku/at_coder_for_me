// 動的計画法
// knapsack

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
#include <stack>

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

const int n_max = 100 + 5;
const ll v_max = 1e5 + 5;

int n,W,value;
ll w[n_max], v[n_max];

ll dp[n_max][v_max]; //[i][j]---i番目の品物の中で、価値の総和がj以下で最大の時の重さの最小値

int main() {
  cin >> n >> W;
  rep(i,n) {
    cin >> w[i] >> v[i];
    value += v[i];
  }
  rep(i,n+1) rep(j, value+1) dp[i][j] = INF;
  rep(i,n+1) dp[i][0] = 0;
  rep(i, n+1) {
    rep(j, value+1) {
      if(j >= v[i]) {
        dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
      } else dp[i+1][j] = dp[i][j];
    }
  }
  // cout << "[1:dp[1][30]] = " << 1 << " : " << dp[1][30] << endl;
  for (int i = value; i >= 0; i--) {

    if(dp[n][i] <= W) {
      cout << i << endl;
      return 0;
    }
  }
}
