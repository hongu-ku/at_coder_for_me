// 動的計画法
// ナップサック問題

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

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repr(i, a) for (int i = (int)(a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (int)(b)-1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
int si()
{
  int x;
  scanf("%d", &x);
  return x;
}
long long sl()
{
  long long x;
  scanf("%lld", &x);
  return x;
}
string ss()
{
  string x;
  cin >> x;
  return x;
}
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &s) { printf("%s ", s.c_str()); }
void br() { putchar('\n'); }

const int MOD = 1e9 + 7;

struct mint
{
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b)
{
  a.n += b.n;
  if (a.n >= MOD)
    a.n -= MOD;
  return a;
}
mint operator-(mint a, mint b)
{
  a.n -= b.n;
  if (a.n < 0)
    a.n += MOD;
  return a;
}
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

const int n_max = 200;

int n, a;
int w[n_max], v[n_max];

// dp[i][j]はi番目以降の品物から重さの和がj以下なるように選んだときの価値の和の最大値を表す。
int dp[n_max + 1][n_max + 1];

// メモ化再帰
int rec(int i, int j)
{
  if (dp[i][j] >= 0)
  {
    // すでに調べたことががるならばその結果を再医療
    return dp[i][j];
  }
  int res;
  if (i == n)
  {
    res = 0;
  }
  else if (j < w[i])
  {
    res = rec(i + 1, j);
  }
  else
  {
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  // 結果をテーブルに記憶する
  return dp[i][j] = res;
}

// 狭義の動的計画法
// dp[n][j] = 0
// dp[i][j] = \begin{cases} dp[i+1][j] & (j < w[i])\\ max\{dp[i+1][j],\ dp[i+1][j-w[i]] + v[i]\} & (j \ge w[i]) \end{cases}
void solve_dp2()
{
  for (int j = 0; j <= a; j++)
  {
    dp[n][j] = 0;
  }
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j <= a; j++)
    {
      if (j < w[i])
        dp[i][j] = dp[i + 1][j];
      else
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
    }
  }
  cout << dp[0][a] << endl;
}

int main()
{
  cin >> n >> a;
  rep(i, n) cin >> w[i] >> v[i];
  printf("%d\n", rec(0, a));
}
