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

const int n_max = 100 + 5, w_max = 1e5 + 5;

int n,W;
ll w[n_max], v[n_max];

ll dp[n_max][w_max]; //[i][j]---i番目の品物の中で、重さの総和がj以下の時の価値の最大値

int main() {
  rep(i,n_max) rep(j,w_max) dp[i][j] = -1;
  cin >> n >> W;
  rep(i,n) cin >> w[i] >> v[i];
  rep(i,W+1) dp[0][i] = 0;
  rep(i, n) {
    rep(j, W+1) {
      if(w[i] > j) {
        dp[i+1][j] = dp[i][j];
      } else {
        dp[i+1][j] = max(dp[i][j-w[i]] + v[i], dp[i][j]);
      }
    }
  }
  cout << dp[n][W] << endl;
}
