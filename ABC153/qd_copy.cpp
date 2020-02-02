#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
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
const ll INF = 1e9 + 5;

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

typedef pair<int, int> P;

const ll N = 20;
char s[N][N];
int n,h,w,result;
ll a[N];
int d[N*N][N*N];

void warshall_floyd() {
  rep(k,h*w) rep(i,h*w) rep(j,h*w) {
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  rep(i,N*N) rep(j,N*N) {
    if(i != j) d[i][j] = INF;
  }
  rep(i,h) {
    rep(j,w) {
      cin >> s[i][j];
    }
  }
  rep(i,h) rep(j,w) {
    if(i != 0 && s[i][j] == '.' && s[i-1][j] == '.') {
      d[i*w+j][(i-1)*w+j] = 1; d[(i-1)*w+j][i*w+j] = 1;
    }
    if(j != 0 && s[i][j] == '.' && s[i][j-1] == '.') {
      d[i*w+j][i*w+j-1] = 1; d[i*w+j-1][i*w+j] = 1;
    }
  }
  warshall_floyd();
  rep(i,h*w) rep(j,h*w) {
    // cout << "d[" << i << "][" << j << "] = " << d[i][j] << endl;
    if (d[i][j] != INF) result = max(d[i][j], result);
  }
  cout << result << endl;
}
