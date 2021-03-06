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

struct a {
  int damage;
  int hit;
  int rate;

  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
   bool operator<( const a& right ) const {
       return rate == right.rate ? damage < right.damage : rate > right.rate;
   }
};

const ll N = 1e3+5;
const ll DP = 1e7+5;
string s;
ll n,k,result=INF,h;
ll a,b,m;

ll dp[DP];



int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> n;
  vector<struct a> v(n);
  rep(i,n) {
      cin >> a >> b;
      m = max(m,a);
      v[i].damage = b;
      v[i].hit = a;
      v[i].rate = 1.0*a/b;
  }
  VSORT(v);
  rep(i,h+m+5) {
      dp[i] = INF;
  }
  dp[0] = 0;
  rep(i,n) {
      for(int j=0; j < h; j++) {
          if(dp[j] != INF) {
              dp[j+v[i].hit] = min(dp[v[i].hit+j], dp[j] + v[i].damage);
          }
      }
  }
  for(int i = h; i <= h+m; i++) {
      result = min(result, dp[i]);
  }
  std::cout << result << endl;
}
