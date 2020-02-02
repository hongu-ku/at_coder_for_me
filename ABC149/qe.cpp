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
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
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

typedef pair<int, int> P;

const ll N = 1e5+5;
ll n,result, m, l, r;
vector<ll> a;

int main () {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  cin >> n >> m;
  rep(i,n) {
    cin >> l;
    a.push_back(l);
  }
  VSORT(a);
  ll x0 = 0, x1 = 300000;
  while(x1-x0 > 1) {
    ll x = (x0+x1) / 2;
    ll t = 0; // x以上の組み合わせの数
    rep(i,n) t += n - Lower_bound(a, x-a[i]);
    if(t >= m) x0 = x;
    else x1 = x;
    // cout << x << endl;
  }

  vector<ll> s(n+1, 0);
  for(int i=n-1;i>=0;i--) s[i] = s[i+1] + a[i];
  ll ans = 0, mm = 0;
  rep(i,n) {
    ll i0 = Lower_bound(a,x0 - a[i]);
    mm += n - i0;
    ans += s[i0] + a[i] * (n - i0);
    cout << i << " : " << s[i] << endl;
  }
  ans -= x0 * (mm - m);
  cout << ans << endl;
}
