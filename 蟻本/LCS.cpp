// 動的計画法
// 最長共通部分列
// Longest Common Subsequence (LCS)

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

const int N = 3005;

int n,m;
ll w[N], v[N];
string s,t;
ll dp[N][N]; //[i][j]---S1...Siとt1...tiに対するLCSのながさ

void lsc() {
  rep(i, n) {
    rep(j, m) {
      if(s[i+1] == t[i+1]) {
        dp[i+1][j+1] = dp[i][j] + 1;
      } else {
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
      }
    }
  }
}

void print() {
  // 文字数ならDPをだすだけだが、文字自体を出すには
  string ans = "";
  int i = s.length();
  int j = t.length();
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      --i;
    } else if (dp[i][j] == dp[i][j - 1]) {
      --j;
    } else {
      ans = s[i - 1] + ans;
      --i;
      --j;
    }
  }
  cout << ans << endl;
}

int main() {
  rep(i,N) rep(j,N) dp[i][j] = -1;
  cin >> s >> t;
  n = s.length(), m = s.length();

  lsc();

  // 共通文字数を表示する時
  cout << dp[n][m] << endl;
  // 共通文字を表示する時
  print();
}
