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
const size_t INF = 9223372036854775805;

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

typedef pair<ll, ll> P;

const ll N = 1e5+5;
string s;
vector<ll> v[N];
ll n;
ll a,b;
P p[N];

bool judge(ll g) {
  map<ll,ll> num;
  ll count = 0;
  rep(i,n) {
    if(g < p[i].first) return false;
    ll temp = (g - p[i].first) / p[i].second;
    if(num.find(temp) == num.end()) num[temp] = 1;
    else num[temp]++;
  }
  rep(i,n) {
    // cout << i << " : " << (num.find(i) == num.end() ? 0 : num[i]) << endl;
    count += num.find(i) == num.end() ? 0 : num[i];
    if(count > i + 1) return false;
  }
  return true;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  rep(i,n) {
    cin >> a >> b;
    p[i] = P(a,b);
  }
  ll u = INF, d = 0, m;
  while(u > d) {
    m = (u+d) / 2;
    // cout << u << " : " << d << " : " << m << endl;
    if(judge(m)) u = m;
    else d = m + 1;
  }
  // cout << judge(3) << endl;
  cout << u << endl;
}
