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
const ll INF = 1e16 + 5;

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
vector<ll> v[N];
ll n;
ll a,b,q;
ll dif[N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a >> b >> q;
  vector<ll> s(a),t(b),x(q);
  rep(i,a) {
    cin >> s[i];
  }
  rep(i,b) {
    cin >> t[i];
  }
  rep(i,q) {
    cin >> x[i];
  }
  rep(i,q) {
    auto ite1 = upper_bound(ALL(s), x[i]);
    auto ite2 = upper_bound(ALL(t), x[i]);
    dif[i] = INF;
    rep(k,2) rep(j,2) {
      ll d1 = INF, d2 = INF;
      if(ite1-k-s.begin() >= 0 && ite1-k-s.begin() < s.size() && ite2-j-t.begin() >= 0 && ite2-j-t.begin() < t.size()) {
        d1 = abs(*(ite1-k) - x[i]) + abs(*(ite1-k) - *(ite2-j));
        d2 = abs(*(ite2-j) - x[i]) + abs(*(ite1-k) - *(ite2-j));
      }
      // ll d1 = ite1 - k - s.end() >= 0 || ite2 - j - t.begin() < 0 ? INF : abs(*(ite1-k) - x[i]) + abs(*(ite1-k) - *(ite2-j));
      // ll d2 = (ite2 - j - t.end() >= 0 && ite2 - j - t.begin() < 0) || (ite1 - k - s.begin() < 0 && ite1 - k - s.end >= 0) ? INF : abs(*(ite2-j) - x[i]) + abs(*(ite1-k) - *(ite2-j));
      dif[i] = min({dif[i], d1, d2});
      // cout << ite2 - j - t.end() << "    ";
      // cout << i << " : " << k << " : " << j << " = " << d1 << " : " << d2 << " : " << dif[i] << endl;
    }
  }
  rep(i,q) cout << dif[i] << endl;
}
