

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

const ll MOD = 1e9 + 7;

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

const int N = 3005;

string s;
int n;
double p[N];
double dp[N][N];
bool memo[N][N];

double cal(int i, int j) {
  if(memo[i][j]) return dp[i][j];
  else if(i < j) dp[i][j] = 0;
  else if(i==1) {
    dp[1][0] = 1-p[i]; dp[1][1] = p[i];
  } else if(j==0) dp[i][j] = cal(i-1, j) * (1.0-p[i]);
  else dp[i][j] = cal(i-1, j-1) * p[i] + cal(i-1, j) * (1.0-p[i]);
  memo[i][j] = true;
  return dp[i][j];
}

int main () {
  cin >> n;
  rep(i,n) cin >> p[i+1];
  rep(i,N) rep(j,N) dp[i][j] = 0;
  rep(i,n+1) cal(n, i);
  double result = 0.0;
  for (int i = (n+1)/2; i <= N; i++) {
    result += dp[n][i];
  }
  // rep(i,n) rep(j,n+1) {
  //   cout << "dp[" << i+1 << "][" << j << "] = ";
  //   pd(dp[i+1][j]); br();
  // }
  pd(result);br();
}
