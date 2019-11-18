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

const int n_max = 1e5 + 5;

int n,m,value;
int x[n_max], y[n_max];
vector<int> v[n_max];
vector<int> s[n_max];
bool h[n_max];
int dp[n_max];
int temp, result;

int depth(int i) {
  if(dp[i] != -1) return dp[i];
  for (int j=0; j<v[i].size(); j++) {
    temp = v[i][j];
    dp[i] = max(dp[i], depth(temp) + 1);
  }
  dp[i] = max(dp[i], 0);
  return dp[i];
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  rep(i,m) {
    cin >> x[i] >> y[i];
    s[x[i]].push_back(y[i]);
    v[x[i]].push_back(y[i]);
    h[y[i]] = true;
  }
  rep(i,n+1) dp[i] = -1;
  rep(i,n) {
    // cout << s[i+1].size() << endl;
    if(!h[i+1]) {
      depth(i+1);
    }
  }
  rep(i,n) {
    //cout << dp[i+1] << endl;
    result = max(result, dp[i+1]);
  }
  cout << result << endl;
}
