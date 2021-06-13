#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
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

const ll MOD = LONG_MAX;
const ll INF = 1e9 + 5;
const double PI = 3.14159265358979323846;

typedef pair<int, int> P;

ll k, n;

int main()
{
  cin >> n;
  vector<int> t(n);
  rep(i, n) cin >> t[i];
  VSORT(t);
  reverse(ALL(t));
  int sum = 0;
  rep(i, n)
  {
    sum += t[i];
  }
  int target = (sum + 2 - 1) / 2;
  int a = sum / 2 + t[0] + 5;
  vector<vector<int>> dp(n + 1, vector<int>(a, 0));
  rep(i, n)
  {
    rep(j, a)
    {
      // cout << i << ", " << j << endl;
      if (j < t[i])
        dp[i + 1][j] = dp[i][j];
      else
        dp[i + 1][j] = max(dp[i][j], dp[i][j - t[i]] + t[i]);
    }
  }
  int memo = INF;
  int result = INF;
  rep(i, a)
  {
    // cout << dp[n][i] << endl;
    if (memo > abs(dp[n][i] - target))
    {
      memo = abs(dp[n][i] - target);
      result = max(dp[n][i], sum - dp[n][i]);
    }
  }
  cout << result << endl;
  // rep(i, n) rep(j, a)
  // {
  //   cout << i << ", " << j << " => " << dp[i][j] << endl;
  // }
}
