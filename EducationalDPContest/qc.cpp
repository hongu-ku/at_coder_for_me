// 動的計画法

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

const int n_max = 1e5 + 5;

int n,k;
int a[n_max], b[n_max], c[n_max];

int dp[4][n_max]; //(a,b,c)をした時のi日めの幸福度の最大値

void rec(int i) {
  dp[0][i] = max(dp[1][i-1] + a[i], dp[2][i-1] + a[i]);
  dp[1][i] = max(dp[0][i-1] + b[i], dp[2][i-1] + b[i]);
  dp[2][i] = max(dp[1][i-1] + c[i], dp[0][i-1] + c[i]);
  if(i+1 < n) rec(i+1);
}

int main() {
  rep(i,n_max) rep(j,4) dp[j][i] = INF;
  cin >> n ;
  rep(i,n) cin >> a[i] >> b[i] >> c[i];
  dp[0][0] = a[0];
  dp[1][0] = b[0];
  dp[2][0] = c[0];
  rec(1);
  cout << max({dp[0][n-1],dp[1][n-1],dp[2][n-1]}) << endl;
}
