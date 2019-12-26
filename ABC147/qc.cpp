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

const int N = 1e6+5;
string s;
vector<int> v[N];
ll n,m,b,c,result;
ll a[17];
bool k[17];
vector<pair<ll,bool> > p[17];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  rep(i,n) {
    cin >> a[i];
    rep(j,a[i]) {
      cin >> b >> c;
      p[i].push_back(P(b-1,c==1?true:false));
    }
  }
  ll g = pow(2,n);
  rep(i,g) {
    bool flag = true;
    ll num = 0;
    rep(j,n) {
      // cout << i << " : " << j << " : " << (i >> j) << endl;
      if(i >> j & 1)  {
        k[j] = true;
        num++;
      }
      else k[j] = false;
    }
    // cout << i << " : " << num << endl;
    rep(j,n) {
      if(k[j]) {
        rep(l,p[j].size()) {
          if(k[p[j][l].first] != p[j][l].second) {
            // cout << j << endl;
            flag = false;
            num = 0;
            break;
          }
        }
        if(!flag) break;
      }
    }
    if(flag) result = max(result, num);
    // cout << i << " : " << result << endl;
  }
  cout << result << endl;
}
