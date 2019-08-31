#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define size_t unsigned long long
#define ll long long
#define REP(i,a) for(int i=0;i<(a);i++)
#define REPR(i,a) for(int i=(int)(a)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=a;i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
// using ll = long long;
// using vi = vector<int>;
// using vvi = vector<vi>;
// using vl = vector<long long>;
// using vvl = vector<vl>;
// using vs = vector<string>;
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

mint dp[101][4][4][4];

int main() {
  int N;
  dp[0][3][3][3] = 1;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < 4; j++) {
      for (size_t k = 0; k < 4; k++) {
        for (size_t l = 0; l < 4; l++) {
          for (size_t m = 0; m < 4; m++) {
            if (k==0&&l==1&&m==2) continue;
            if (k==1&&l==0&&m==2) continue;
            if (k==0&&l==2&&m==1) continue;
            if (j==0&&k==1&&m==2) continue;
            if (j==0&&l==1&&m==2) continue;
            dp[i+1][k][l][m] += dp[i][j][k][l];
          }
        }
      }
    }
  }
  mint ans = 0;
  REP(j,4) REP(k,4) REP(l,4) ans += dp[N][j][k][l];
  cout << ans.n << endl;
}
