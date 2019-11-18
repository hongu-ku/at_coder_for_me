
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

const int N = 305;

string s;
int n;
int a[N];
double dp[N][N][N]; // dp[i][j] 捜査回数iの時の
int memo[4];
vector<int> v(N,1);

void cal(int i, int j, int k) {
  if(dp[i][j][k] >= 0) return;
  if(i) cal(i-1, j, k);
  if(j) cal(i + 1, j - 1, k);
  if(k) cal(i, j+1, k-1);

  dp[i][j][k] = (i ? dp[i - 1][j][k] * i : 0) + (j ? dp[i + 1][j - 1][k] * j : 0) + (k ? dp[i][j + 1][k - 1] * k : 0) + n;
  dp[i][j][k] *= 1.0 / (i + j + k);
}

int main () {
  cin >> n;
  memset(dp, -1, sizeof dp);
  rep(i,n) {
    cin >> a[i+1];
    memo[a[i+1]]++;
  }
  dp[0][0][0] = 0.0;
  cal(memo[1],memo[2],memo[3]);
  pd(dp[memo[1]][memo[2]][memo[3]]);br();
}
