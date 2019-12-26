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
const ll INF = 9223372036854775805;

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

const ll N = 1e6+5;
string s;
vector<ll> v[N];
ll n,r,b,x,y;
ll a[N];


bool solve(ll g) {
  ll xx = r / x, yy = g - xx, red, blue;
  red = r - xx * x - yy;
  blue = b - yy * y - xx;
  // cout << xx << " : " << yy << " : " << red << " : " << blue << endl;
  if(red >= 0 && blue >= 0) return true;
  if(blue < 0) return false;
  xx += red / (x - 1); yy -= red / (x - 1);
  red = r - xx * x - yy;
  blue = b - yy * y - xx;
  // cout << xx << " : " << yy << " : " << red << " : " << blue << endl;
  if(red >= 0 && blue >= 0) return true;
  if(blue < 0) return false;
  xx--;yy++;
  red = r - xx * x - yy;
  blue = b - yy * y - xx;
  // cout << xx << " : " << yy << " : " << red << " : " << blue << endl;
  if(red >= 0 && blue >= 0) return true;
  if(blue < 0) return false;
  return false;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> r >> b >> x >> y;
  ll u = r / x + b / y, d = 0, m;
  while(u > d) {
    m = (u+d) / 2 + 1;
    // cout << u << " : " << d << " : " << m << endl;
    if(solve(m)) d = m;
    else u = m - 1;
  }
  // solve(100);
  cout << u << endl;
}
